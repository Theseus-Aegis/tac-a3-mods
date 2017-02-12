/*
 * Author: Jonpas
 * Saves a player object and necessary variables.
 *
 * Arguments:
 * 0: Player <OBJECT>
 * 1: Player UID <STRING>
 * 2: Type ("save" or "validate") <STRING>
 * 3: Cause ("loaded" or "respawned") <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, "36182159512951925", "save", "loaded"] call tac_apollo_fnc_playerSingletonSave
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_player", "_uid", "_type", "_cause"];

// Base
private _name = name _player;
private _playerPos = getPosASL _player;
private _playerDir = getDir _player;

private _loadout = getUnitLoadout _player;

// Other
private _alive = alive _player;
private _selectedWeapon = currentWeapon _player;
private _currentStance = animationState _player;

// Variables
private _playerVariables = [];
/*{ //Disable until we decide on ACE medical vars
    if ((toLower (_x select [0, 3])) isEqualTo "ace") then {
        _playerVariables pushBack [_x, _playerObject getVariable [_x, "None"]];
    };
} forEach (allVariables _playerObject);*/

private _serverReply = ["storeInfantry", _type, _uid, _name, _playerPos, _playerDir, _loadout, _alive, _selectedWeapon, _currentStance, _playerVariables] call FUNC(invokeJavaMethod);

TRACE_2("Singleton Save",_type,_serverReply);

if (_type == "validate" && {_serverReply == "success"}) exitWith {
    // No simulation toggling due to possible lag breaking correct position and direction setting
    ["infantryLoaded", _uid] call FUNC(invokeJavaMethod);
};

if (_serverReply == "terminated") then {
    [QGVAR(terminatePlayer), [], _player] call CBA_fnc_targetEvent;
};
