params ["_lb", "_text"];
private _result = -1;
for "_i" from 0 to (lbSize _lb - 1) do {
	if (_text == lbText [_lb, _i]) exitWith {
		_result = _i;
		break;
	};
};
_result;
