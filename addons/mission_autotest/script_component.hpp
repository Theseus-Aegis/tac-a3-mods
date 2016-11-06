#define COMPONENT mission_autotest
#define COMPONENT_BEAUTIFIED Mission Autotest
#include "\x\tac\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_MISSION_AUTOTEST
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_MISSION_AUTOTEST
    #define DEBUG_SETTINGS DEBUG_SETTINGS_MISSION_AUTOTEST
#endif

#include "\x\tac\addons\main\script_macros.hpp"


#define ERROR_CODE -1
#define WARNING_CODE 0
#define PASS_CODE 1
#define MESSAGE_CODE 2

#define ERROR_PICTURE QPATHTOF(UI\error.paa)
#define WARNING_PICTURE QPATHTOF(UI\warning.paa)
#define PASS_PICTURE QPATHTOF(UI\pass.paa)
#define MESSAGE_PICTURE QPATHTOF(UI\message.paa)

#define CTRL_VALUE 100
#define CTRL_PICTURE 101
#define FINDINGS_COLUMN_SIZE 0, 0.05

// Limits
#define GROUP_SIZE_WARNING 100
#define AI_AMOUNT_WARNING 100
#define AI_AMOUNT_ERROR 150
