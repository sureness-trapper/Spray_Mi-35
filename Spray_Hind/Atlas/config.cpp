class CfgPatches {
    class Spray_Hind_Atlas {
        addonRootClass = "Spray_Hind";
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.100000;
        skipWhenMissingDependencies = 1;
        requiredAddons[] = {"A3_Atlas_Air_F_Atlas_Heli_Attack_04"};
    };
};

class CfgVehicles {
    class Helicopter_Base_F;
    class Heli_Attack_02_base_F: Helicopter_Base_F {
        class Turrets;
        class Components;
    };
    class Aegis_Heli_Attack_04_base_F : Heli_Attack_02_base_F {
        class Turrets : Turrets {
			class CargoTurret_01;
			class CargoTurret_02;
			class CargoTurret_03;
			class CargoTurret_04;
        };
        class Components : Components {
            class TransportPylonsComponent {
                class Pylons {
                    class PylonLeft1;
                    class PylonLeft2;
                    class PylonLeft3;
                    class PylonRight1;
                    class PylonRight2;
                    class PylonRight3;
                    class PylonLeft4;
                    class PylonRight4;
                    class PylonRadar;
                };
                class Presets {
                    class Default;
                    class AT;
                    class CAS;
                    class HAT;
                };
            };
        };
   };
    class Atlas_I_AR_Heli_Attack_04_F : Aegis_Heli_Attack_04_base_F {
        cargoProxyIndexes[] = {1,2,3,4,9,10,11};
        transportsoldier = 7;
        cargoAction[] = {"Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "passenger_flatground_generic02", "passenger_flatground_generic05", "passenger_flatground_leanleft"};
        class Turrets: Turrets {
            class CargoTurret_01: CargoTurret_01 {

            };
            class CargoTurret_02: CargoTurret_02 {

            };
            class CargoTurret_03: CargoTurret_03 {

            };
            class CargoTurret_04: CargoTurret_04 {

            };
        };
        class Components: Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class pylons : pylons {
                    class PylonLeft1 : PylonLeft1 {
                    };
                    class PylonLeft2 : PylonLeft2 {
                    };
                    class PylonLeft3 : PylonLeft3 {
                    };
                    class PylonRight1 : PylonRight1 {
                    };
                    class PylonRight2 : PylonRight2 {
                    };
                    class PylonRight3 : PylonRight3 {
                    };
                    class PylonLeft4: PylonLeft4 {
                    };
                    class PylonRight4 : PylonRight4 {
                    };
                    class PylonRadar: PylonRadar {
                    };
                };
                class Presets : Presets {
                    class Default: Default {
                        attachment[] = {"PylonRack_20Rnd_Rocket_80mm","PylonRack_20Rnd_Rocket_80mm","PylonRack_6Rnd_Vikhr_missiles","PylonRack_20Rnd_Rocket_80mm","PylonRack_20Rnd_Rocket_80mm","PylonRack_6Rnd_Vikhr_missiles", "", "", "MastRadar"};
                    };
                    class AT: AT {
                        attachment[] = {"PylonRack_6Rnd_Vikhr_missiles","PylonRack_6Rnd_Vikhr_missiles","PylonRack_6Rnd_Vikhr_missiles","PylonRack_6Rnd_Vikhr_missiles","PylonRack_6Rnd_Vikhr_missiles","PylonRack_6Rnd_Vikhr_missiles", "", "", "MastRadar"};
                    };
                    class HAT: HAT {
                        attachment[] = {"PylonRack_1Rnd_Missile_AGM_01_F","PylonRack_1Rnd_Missile_AGM_01_F","PylonRack_6Rnd_Vikhr_missiles","PylonRack_1Rnd_Missile_AGM_01_F","PylonRack_1Rnd_Missile_AGM_01_F","PylonRack_6Rnd_Vikhr_missiles", "", "", "MastRadar"};
                    };
                    class CAS: CAS {
                        attachment[] = {"PylonRack_20Rnd_Rocket_80mm","PylonMissile_1Rnd_Bomb_03_F","PylonRack_20Rnd_Rocket_80mm","PylonRack_20Rnd_Rocket_80mm","PylonMissile_1Rnd_Bomb_03_F","PylonRack_20Rnd_Rocket_80mm", "", "", "MastRadar"};
                    };
                };
            };
        };
    };
    class Atlas_I_UNO_Heli_Attack_04_F: Aegis_Heli_Attack_04_base_F {
        cargoProxyIndexes[] = {1,2,3,4,9,10,11};
        transportsoldier = 7;
        cargoAction[] = {"Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "passenger_flatground_generic02", "passenger_flatground_generic05", "passenger_flatground_leanleft"};
        class Turrets: Turrets {
            class CargoTurret_01: CargoTurret_01 {

            };
            class CargoTurret_02: CargoTurret_02 {

            };
            class CargoTurret_03: CargoTurret_03 {

            };
            class CargoTurret_04: CargoTurret_04 {

            };
        };
        class Components: Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class pylons : pylons {
                    class PylonLeft1 : PylonLeft1 {
                    };
                    class PylonLeft2 : PylonLeft2 {
                    };
                    class PylonLeft3 : PylonLeft3 {
                    };
                    class PylonRight1 : PylonRight1 {
                    };
                    class PylonRight2 : PylonRight2 {
                    };
                    class PylonRight3 : PylonRight3 {
                    };
                    class PylonLeft4: PylonLeft4 {
                    };
                    class PylonRight4 : PylonRight4 {
                    };
                    class PylonRadar: PylonRadar {
                    };
                };
                class Presets : Presets {
                    class Default: Default {
                        attachment[] = {"PylonRack_12Rnd_missiles","PylonRack_12Rnd_missiles","PylonRack_3Rnd_LG_scalpel","PylonRack_12Rnd_missiles","PylonRack_12Rnd_missiles","PylonRack_3Rnd_LG_scalpel", "", "", "MastRadar"};
                    };
                    class AT: AT {
                        attachment[] = {"PylonRack_12Rnd_missiles","PylonRack_4Rnd_LG_scalpel","PylonRack_4Rnd_LG_scalpel","PylonRack_12Rnd_missiles","PylonRack_4Rnd_LG_scalpel","PylonRack_4Rnd_LG_scalpel", "", "", "MastRadar"};
                    };
                    class HAT: HAT {
                        attachment[] = {"PylonRack_4Rnd_LG_scalpel","PylonRack_1Rnd_Missile_AGM_02_F","PylonRack_4Rnd_LG_scalpel","PylonRack_4Rnd_LG_scalpel","PylonRack_1Rnd_Missile_AGM_02_F","PylonRack_4Rnd_LG_scalpel", "", "", "MastRadar"};
                    };
                    class CAS: CAS {
                        attachment[] = {"PylonRack_12Rnd_missiles","PylonMissile_1Rnd_Mk82_F","PylonRack_12Rnd_missiles","PylonRack_12Rnd_missiles","PylonMissile_1Rnd_Mk82_F","PylonRack_12Rnd_missiles", "", "", "MastRadar"};
                    };
                };
            };
        };
    };
    class Atlas_O_T_Heli_Attack_04_F: Aegis_Heli_Attack_04_base_F {
        cargoProxyIndexes[] = {1,2,3,4,9,10,11};
        transportsoldier = 7;
        cargoAction[] = {"Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "passenger_flatground_generic02", "passenger_flatground_generic05", "passenger_flatground_leanleft"};
        class Turrets: Turrets {
            class CargoTurret_01: CargoTurret_01 {

            };
            class CargoTurret_02: CargoTurret_02 {

            };
            class CargoTurret_03: CargoTurret_03 {

            };
            class CargoTurret_04: CargoTurret_04 {

            };
        };
    };
    class Atlas_O_W_Heli_Attack_04_F: Aegis_Heli_Attack_04_base_F {
        cargoProxyIndexes[] = {1,2,3,4,9,10,11};
        transportsoldier = 7;
        cargoAction[] = {"Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "passenger_flatground_generic02", "passenger_flatground_generic05", "passenger_flatground_leanleft"};
        class Turrets: Turrets {
            class CargoTurret_01: CargoTurret_01 {

            };
            class CargoTurret_02: CargoTurret_02 {

            };
            class CargoTurret_03: CargoTurret_03 {

            };
            class CargoTurret_04: CargoTurret_04 {

            };
        };
        class Components: Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class pylons : pylons {
                    class PylonLeft1 : PylonLeft1 {
                    };
                    class PylonLeft2 : PylonLeft2 {
                    };
                    class PylonLeft3 : PylonLeft3 {
                    };
                    class PylonRight1 : PylonRight1 {
                    };
                    class PylonRight2 : PylonRight2 {
                    };
                    class PylonRight3 : PylonRight3 {
                    };
                    class PylonLeft4: PylonLeft4 {
                    };
                    class PylonRight4 : PylonRight4 {
                    };
                    class PylonRadar: PylonRadar {
                    };
                };
                class Presets : Presets {
                    class Default: Default {
                        attachment[] = {"PylonRack_20Rnd_Rocket_80mm","PylonRack_20Rnd_Rocket_80mm","PylonRack_6Rnd_Vikhr_missiles","PylonRack_20Rnd_Rocket_80mm","PylonRack_20Rnd_Rocket_80mm","PylonRack_6Rnd_Vikhr_missiles", "", "", "MastRadar"};
                    };
                    class AT: AT {
                        attachment[] = {"PylonRack_6Rnd_Vikhr_missiles","PylonRack_6Rnd_Vikhr_missiles","PylonRack_6Rnd_Vikhr_missiles","PylonRack_6Rnd_Vikhr_missiles","PylonRack_6Rnd_Vikhr_missiles","PylonRack_6Rnd_Vikhr_missiles", "", "", "MastRadar"};
                    };
                    class HAT: HAT {
                        attachment[] = {"PylonRack_1Rnd_Missile_AGM_01_F","PylonRack_1Rnd_Missile_AGM_01_F","PylonRack_6Rnd_Vikhr_missiles","PylonRack_1Rnd_Missile_AGM_01_F","PylonRack_1Rnd_Missile_AGM_01_F","PylonRack_6Rnd_Vikhr_missiles", "", "", "MastRadar"};
                    };
                    class CAS: CAS {
                        attachment[] = {"PylonRack_20Rnd_Rocket_80mm","PylonMissile_1Rnd_Bomb_03_F","PylonRack_20Rnd_Rocket_80mm","PylonRack_20Rnd_Rocket_80mm","PylonMissile_1Rnd_Bomb_03_F","PylonRack_20Rnd_Rocket_80mm", "", "", "MastRadar"};
                    };
                };
            };
        };
    };
};