#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"TAC_painkillersItem"};
        weapons[] = {"TAC_painkillers"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"tac_main"};
        author = ECSTRING(main,Author);
        authors[] = {"Alganthe"};
        url = ECSTRING(main,URL);
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "ACE_Medical_Actions.hpp"