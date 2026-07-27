class CfgPatches {
    class Spray_AutoCM_Hind {
        addonRootClass = "patch";
        units[] = {};
        magazines[] = {};
        weapons[] = {};
        requiredVersion = 0.100000;
        skipWhenMissingDependencies = 1;
        requiredAddons[] = {"A3_Aegis_Air_F_Aegis_Heli_Attack_04", "Spray_Hind"};
    };
};

class CfgVehicles {
	class Helicopter;
    class Helicopter_Base_F;
    class Heli_Attack_02_base_F : Helicopter_Base_F {
        class EventHandlers;
    };
    class Aegis_Heli_Attack_04_base_F : Heli_Attack_02_base_F {
        class EventHandlers : EventHandlers {
            class AutoCM {
                init = "[_this select 0, true] call Spray_AutoCM_fnc_addAction";
            };
        };
    };
};