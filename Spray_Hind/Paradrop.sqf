params ["_veh", "_add"];
_veh removeAction (_veh getVariable ["Spray_ParadropID", -1]);
private _ParadropID = nil;
if _add then {
    _ParadropID = [_this select 0,
        "Paradrop passenger",
        "\a3\ui_f\data\igui\cfg\actions\getout_ca.paa",
        "\a3\ui_f\data\igui\cfg\actions\getout_ca.paa",
        "(_this in _target) &&
        (getPosATL _target select 2 > 20) && 
        (count (fullCrew _target select {_x select 2 != -1} apply {_x select 0}) > 0)", "true",
        {},
        {},
        {
            {
                [[_x], {
                    params ["_x"];
                    moveOut _x;
                    unassignVehicle _x;
                    sleep (0.25 + random 0.5); 
                    private _chute = createVehicle ["Steerable_Parachute_F", getPosATL _x];
                    _x moveInDriver _chute;
                }] remoteExec ["spawn", _x];
                sleep 0.75;
            } forEach (fullCrew _target select {_x select 2 != -1} apply {_x select 0});
        },
        {},
        [],
        2,
        1,
        false,
        false,
        false
    ] call BIS_fnc_holdActionAdd;
};
_veh setVariable ["Spray_ParadropID", _ParadropID, true];
