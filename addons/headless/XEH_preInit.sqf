#include "script_component.hpp"

ADDON = false;

PREP(handleConnectHC);
PREP(handleDisconnect);
PREP(handleInitPost);
PREP(moduleInit);
PREP(rebalance);
PREP(transferGroups);

if (isServer) then {
    GVAR(headlessClients) = [];
    GVAR(inRebalance) = false;
    ["TAC_HeadlessClientJoined", FUNC(handleConnectHC)] call ACE_Common_fnc_addEventHandler;
};

ADDON = true;
