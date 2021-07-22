#include "script_component.hpp"

// Exit on Headless
if (!hasInterface) exitWith {};

[QGVAR(setTraits), {
    params ["_player", "_trait"];

    _player setUnitTrait [_trait, true];
}] call CBA_fnc_addEventHandler;

[QGVAR(loadTraits), ace_player] call CBA_fnc_serverEvent;

// Lootbox functionality
private _lootBoxClasses = [
    "tacgt_Lootbox_Handgun",
    "tacgt_Lootbox_SMG",
    "tacgt_Lootbox_Rifle",
    "tacgt_Lootbox_GL",
    "tacgt_Lootbox_LMG",
    "tacgt_Lootbox_Marksman"
];

{
    [
        _x,
        "CONTAINER",
        LLSTRING(OpenLootbox),
        [],
        "",
        {true},
        {
            params ["_unit", "", "_item", "_slot"];

            private _container = switch (_slot) do { // This is temporary due to weapons getting replaced see ACE3 issue #8328
                case "UNIFORM_CONTAINER": {"uniform"};
                case "VEST_CONTAINER": {"vest"};
                case "BACKPACK_CONTAINER": {"backpack"};
            };

            private _itemList = getArray (configFile >> "CfgWeapons" >> _item >> "tacgt_lootbox_list");

            [_unit, selectRandom _itemList, _container] call ACEFUNC(common,addToInventory);
        },
        true
    ] call CBA_fnc_addItemContextMenuOption;
} forEach _lootBoxClasses;
