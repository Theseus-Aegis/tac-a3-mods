PREFIX = tac
BIN = @tac_mods
ZIP = tac_mods
FLAGS = -i include -w redefinition-wo-undef -w unquoted-string -w excessive-concatenation
VERSION_FILES = "README.md" "mod.cpp"

MAJOR = $(shell grep "^\#define[[:space:]]*MAJOR" addons/main/script_version.hpp | egrep -m 1 -o '[[:digit:]]+')
MINOR = $(shell grep "^\#define[[:space:]]*MINOR" addons/main/script_version.hpp | egrep -m 1 -o '[[:digit:]]+')
PATCH = $(shell grep "^\#define[[:space:]]*PATCHLVL" addons/main/script_version.hpp | egrep -m 1 -o '[[:digit:]]+')
BUILD = $(shell grep "^\#define[[:space:]]*BUILD" addons/main/script_version.hpp | egrep -m 1 -o '[[:digit:]]+')
VERSION = $(MAJOR).$(MINOR).$(PATCH)
VERSION_FULL = $(VERSION).$(BUILD)
GIT_HASH = $(shell git log -1 --pretty=format:"%H" | head -c 8)

ifeq ($(OS), Windows_NT)
	ifeq ($(PROCESSOR_ARCHITEW6432), AMD64)
		ARMAKE = ./tools/armake_w64.exe
	else
		ifeq ($(PROCESSOR_ARCHITECTURE), AMD64)
			ARMAKE = ./tools/armake_w64.exe
		else
			ARMAKE = ./tools/armake_w32.exe
		endif
	endif
else
	ARMAKE = armake
endif

$(BIN)/addons/$(PREFIX)_%.pbo: addons/%
	@mkdir -p $(BIN)/addons
	@echo "  PBO  $@"
	@${ARMAKE} build ${FLAGS} -f $< $@

$(BIN)/optionals/$(PREFIX)_%.pbo: optionals/%
	@mkdir -p $(BIN)/optionals
	@echo "  PBO  $@"
	@${ARMAKE} build ${FLAGS} -f $< $@

# Shortcut for building single addons (eg. "make <component>.pbo")
%.pbo:
	"$(MAKE)" $(MAKEFLAGS) $(patsubst %, $(BIN)/addons/$(PREFIX)_%, $@)

all: $(patsubst addons/%, $(BIN)/addons/$(PREFIX)_%.pbo, $(wildcard addons/*)) \
		$(patsubst optionals/%, $(BIN)/optionals/$(PREFIX)_%.pbo, $(wildcard optionals/*))

filepatching:
	"$(MAKE)" $(MAKEFLAGS) FLAGS="-w unquoted-string -p"

$(BIN)/keys/%.biprivatekey:
	@mkdir -p $(BIN)/keys
	@echo "  KEY  $@"
	@${ARMAKE} keygen -f $(patsubst $(BIN)/keys/%.biprivatekey, $(BIN)/keys/%, $@)

$(BIN)/addons/$(PREFIX)_%.pbo.$(PREFIX)_$(VERSION_FULL)-$(GIT_HASH).bisign: $(BIN)/addons/$(PREFIX)_%.pbo $(BIN)/keys/$(PREFIX)_$(VERSION_FULL).biprivatekey
	@echo "  SIG  $@"
	@${ARMAKE} sign -f $(BIN)/keys/$(PREFIX)_$(VERSION_FULL).biprivatekey $<
	@mv "$(subst -$(GIT_HASH),,$@)" $@ # armake does not take bisign name as parameter yet

$(BIN)/optionals/$(PREFIX)_%.pbo.$(PREFIX)_$(VERSION_FULL)-$(GIT_HASH).bisign: $(BIN)/optionals/$(PREFIX)_%.pbo $(BIN)/keys/$(PREFIX)_$(VERSION_FULL).biprivatekey
	@echo "  SIG  $@"
	@${ARMAKE} sign -f $(BIN)/keys/$(PREFIX)_$(VERSION_FULL).biprivatekey $<
	@mv "$(subst -$(GIT_HASH),,$@)" $@ # armake does not take bisign name as parameter yet

signatures: $(patsubst addons/%, $(BIN)/addons/$(PREFIX)_%.pbo.$(PREFIX)_$(VERSION_FULL)-$(GIT_HASH).bisign, $(wildcard addons/*)) \
		$(patsubst optionals/%, $(BIN)/optionals/$(PREFIX)_%.pbo.$(PREFIX)_$(VERSION_FULL)-$(GIT_HASH).bisign, $(wildcard optionals/*))

extensions: $(wildcard extensions/*/*)
	cd extensions/build && cmake .. && make
	find ./extensions/build/ \( -name "*.so" -o -name "*.dll" \) -exec cp {} ./ \;

extensions-win64: $(wildcard extensions/*/*)
	cd extensions/build && CXX=$(eval $(which g++-w64-mingw-i686)) cmake .. && make

version:
	@echo "  VER  $(VERSION)"
	$(shell sed -i -r -s 's/[0-9]+\.[0-9]+\.[0-9]+\.?[0-9]?+/$(VERSION)/g' $(VERSION_FILES))
	@echo "#define TAC_VERSION_MAJOR $(MAJOR)\n#define TAC_VERSION_MINOR $(MINOR)\n#define TAC_VERSION_PATCH $(PATCH)\n#define TAC_VERSION_BUILD $(BUILD)" > "extensions/src/common/version.h"

commit:
	@echo "  GIT  commit release preparation"
	@git add -A
	@git diff-index --quiet HEAD || git commit -am "Prepare release $(VERSION)" -q

push: commit
	@echo "  GIT  push release preparation"
	@git push -q

release: clean version commit
	@"$(MAKE)" $(MAKEFLAGS) signatures
	@echo "  ZIP  $(ZIP)_$(VERSION_FULL).zip"
	@cp *.dll AUTHORS.txt LICENSE logo_tac_ca.paa logo_tac_small_ca.paa mod.cpp README.md $(BIN)
	@zip -qr $(ZIP)_$(VERSION).zip $(BIN)

clean:
	rm -rf $(BIN) $(ZIP)_*.zip

.PHONY: all filepatching signatures extensions extensions-win64 version commit push release clean
