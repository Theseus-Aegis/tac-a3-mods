#define COMPONENT armory
#define COMPONENT_BEAUTIFIED Armory
#include "\x\tac\addons\main\script_mod.hpp"

// #define ADD_DEBUG_ITEMS
// #define ALLOW_VANILLA_STASH // Not nicely handled, for testing purposes only
// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_ARMORY
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_ARMORY
    #define DEBUG_SETTINGS DEBUG_SETTINGS_ARMORY
#endif

#include "\x\tac\addons\main\script_macros.hpp"

#include "\a3\ui_f\hpp\defineDIKCodes.inc"

/*
 * JNS Tag 3-ID = 333
 * Project 2-ID = 00
 * Control 2-ID = XY
 * IDs: <JNS Tag 6-ID> + <Project 2-ID> + <Control 2-ID>
 */
#define DISPLAYID 3330000
#define STARTPROJECTID 3330001
#define ENDPROJECTID 3330099

// Shared
#define TITLE 3330001
#define DROPDOWN 3330002
#define AMOUNT 3330003
#define NLIST 3330004
#define DROPDOWNAMOUNT 3330005
#define BACKGROUND 3330009

// MAIN
// Row 1
#define MAINPIC1 3330050
#define MAINBTN1 3330051
#define MAINPIC2 3330052
#define MAINBTN2 3330053
#define MAINPIC3 3330054
#define MAINBTN3 3330055
#define MAINPIC4 3330056
#define MAINBTN4 3330057
#define MAINPIC5 3330058
#define MAINBTN5 3330059
#define MAINPIC6 3330060
#define MAINBTN6 3330061
#define MAINPIC7 3330062
#define MAINBTN7 3330063
// Row 2
#define MAINPIC8 3330064
#define MAINBTN8 3330065
#define MAINPIC9 3330066
#define MAINBTN9 3330067
#define MAINPIC10 3330068
#define MAINBTN10 3330069
#define MAINPIC11 3330070
#define MAINBTN11 3330071
#define MAINPIC12 3330072
#define MAINBTN12 3330073

// Exit/Back
#define BACKPIC 3330010
#define BACKBTN 3330011

// Take/Stash
#define TAKESTASHPIC 3330012
#define TAKESTASHBTN 3330013

// Export
#define EXPORTPIC 3330014
#define EXPORTBTN 3330015

// Camera
#define CAMERAAREA 3330090
#define CAMERAHINT 3330091
#define CAMERAEXIT 3330092


// MACROS
#define CTRL(var) ((findDisplay DISPLAYID) displayCtrl var)


// CONSTANTS
#define DISPLAYNAME_LENGTH 35
