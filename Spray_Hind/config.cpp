class CfgPatches {
    class Spray_Hind {
        units[] = {};
        weapons[] = {"Aegis_Autocannon_Heli_Attack_04_F"};
        requiredVersion = 0.100000;
        requiredAddons[] = {"A3_Aegis_Air_F_Aegis_Heli_Attack_04", "rhs_c_a2port_air"};
    };
};
class DefaultVehicleSystemsDisplayManagerLeft {
    class components;
};
class DefaultVehicleSystemsDisplayManagerRight {
    class components;
};
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateDataLink;
class CfgVehicles {
    class Helicopter;
    class Helicopter_Base_F : Helicopter {
        class HitPoints;
    };
    class Heli_Attack_02_base_F : Helicopter_Base_F {
        class AnimationSources;
        class EventHandlers;
        class Components;
        class CargoTurret;
        class Turrets {
            class MainTurret;
        };
        class HitPoints : HitPoints {
            class HitLight;
            class HitStarter1;
            class HitStarter2;
            class HitStarter3;
        };
        class RotorLibHelicopterProperties;
    };
    class Aegis_Heli_Attack_04_base_F : Heli_Attack_02_base_F {
        class AnimationSources : AnimationSources {
            class hideairfilter {
                animPeriod = 1e-05;
                displayName = "Hide Air Filters";
                source = "user";
                initPhase = 0;
                mass = 1;
            };
            class exhaust_hide {
                displayName = "Hide Exhaust";
            };
            // Can't get the selection working, always moves with other selection
            /* class benches_hide {
                animPeriod = 1e-05;
                displayName = "Hide Benches";
                source = "user";
                initPhase = 1;
                mass = -50;
                lockCargo[] = {0,1,2,3,4,5,6,7};
                lockCargoAnimationPhase = 1;
                forceAnimatePhase = 0;
                forceAnimate[] = {"floorsitting_hide", 1};
            };
            class floorsitting_hide {
                animPeriod = 1e-05;
                initPhase = 0;
                displayName = "Hide Floor Sitting";
                lockCargo[] = {8, 9};
                lockCargoAnimationPhase = 1;
                forceAnimatePhase = 0;
                forceAnimate[] = {"benches_hide", 1};
                source = "user";
            }; */
        };
        class EventHandlers : EventHandlers {
            class GunnerZoom {
                init = "_this execVM 'Spray_Hind\gunnerZoom.sqf'";
            };
            class Paradrop {
                init = "[_this select 0, true] execVM 'Spray_Hind\Paradrop.sqf'";
            };
        };
        class Components : Components {
            class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
                class Components {
                    class SlingLoadDisplay {
                        componentType = "SlingLoadDisplayComponent";
                        resource = "RscCustomInfoSlingLoad";
                    };
                    class VehicleDriverDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "Driver";
                    };
                    class SensorDisplay {
                        range[] = {8000, 4000, 2000, 32000, 16000};
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight {
                class Components {
                    class SlingLoadDisplay {
                        componentType = "SlingLoadDisplayComponent";
                        resource = "RscCustomInfoSlingLoad";
                    };
                    class VehicleDriverDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "Driver";
                    };
                    class SensorDisplay {
                        range[] = {8000, 4000, 2000, 32000, 16000};
                    };
                };
            };
            class SensorsManagerComponent {
                class Components {
                    class IRSensorComponent : SensorTemplateIR {
                        animDirection = "Gun_VRot";
                    };
                    class VisualSensorComponent : SensorTemplateVisual {
                        animDirection = "Gun_VRot";
                    };
                    delete ActiveRadarSensorComponent;
                    class DataLinkSensorComponent : SensorTemplateDataLink {
                        typeRecognitionDistance = 8000;
                        class AirTarget {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                    };
                };
            };
            class TransportPylonsComponent {
                class pylons {
                    class PylonLeft1 {
                        hardpoints[] = {"O_MISSILE_PYLON", "O_BOMB_PYLON_HELI", "DAR", "DAGR", "B_SHIEKER", "UNI_SCALPEL", "20MM_TWIN_CANNON", "20MM_CANNON",
                                        "DAGRM", "B_MISSILE_PYLON", "B_BOMB_PYLON", "O_BOMB_PYLON_HELI", "O_BOMB_PYLON", "TITAN_NLOS_1RND", "TITAN_NLOS_2RND",
                                        "B_BIM9X_RAIL", "B_BIM9X_DUAL_RAIL", "B_AMRAAM_D_RAIL", "B_AGM65_RAIL", "B_HARM_RAIL", "B_GBU12", "B_SDB_QUAD_RAIL", "B_AGM_154",
                                        "I_BIM9X_RAIL", "I_BIM9X_DUAL_RAIL", "I_AMRAAM_C_RAIL", "I_AGM65_RAIL", "I_GBU12",
                                        "O_R73", "O_R77", "O_KH25", "O_KAB250_BOMB", "O_KH58"};
                        priority = 2;
                    };
                    class PylonLeft2 : PylonLeft1 {
                        hardpoints[] = {"O_MISSILE_PYLON", "O_BOMB_PYLON_HELI", "DAR", "DAGR", "B_SHIEKER", "UNI_SCALPEL", "20MM_TWIN_CANNON", "20MM_CANNON",
                                        "DAGRM", "B_MISSILE_PYLON", "B_BOMB_PYLON", "O_BOMB_PYLON_HELI", "O_BOMB_PYLON", "TITAN_NLOS_1RND", "TITAN_NLOS_2RND",
                                        "B_BIM9X_RAIL", "B_BIM9X_DUAL_RAIL", "B_AMRAAM_D_RAIL", "B_AGM65_RAIL", "B_HARM_RAIL", "B_GBU12", "B_SDB_QUAD_RAIL", "B_AGM_154",
                                        "I_BIM9X_RAIL", "I_BIM9X_DUAL_RAIL", "I_AMRAAM_C_RAIL", "I_AGM65_RAIL", "I_GBU12",
                                        "O_R73", "O_R77", "O_KH25", "O_KAB250_BOMB", "O_KH58"};
                        priority = 3;
                    };
                    class PylonLeft3 : PylonLeft1 {
                        hardpoints[] = {"O_MISSILE_PYLON", "O_BOMB_PYLON_HELI", "DAR", "DAGR", "B_SHIEKER", "UNI_SCALPEL", "20MM_TWIN_CANNON", "20MM_CANNON",
                                        "DAGRM", "B_MISSILE_PYLON", "B_BOMB_PYLON", "O_MISSILE_PYLON", "TITAN_NLOS_1RND", "TITAN_NLOS_2RND", "ECM_POD_L"};
                        priority = 4;
                    };
                    class PylonRight1;
                    class PylonRight2;
                    class PylonRight3 : PylonLeft3 {
                        hardpoints[] = {"O_MISSILE_PYLON", "O_BOMB_PYLON_HELI", "DAR", "DAGR", "B_SHIEKER", "UNI_SCALPEL", "20MM_TWIN_CANNON", "20MM_CANNON",
                                        "DAGRM", "B_MISSILE_PYLON", "B_BOMB_PYLON", "O_MISSILE_PYLON", "TITAN_NLOS_1RND", "TITAN_NLOS_2RND", "ECM_POD_R"};
                    };
                    class PylonLeft4 {
                        hardpoints[] = {"O_MISSILE_PYLON", "B_MISSILE_PYLON", "B_BIM9X_RAIL", "B_AMRAAM_D_RAIL",
                                        "I_BIM9X_RAIL", "I_AMRAAM_C_RAIL",
                                        "O_R73", "O_R77"};
                        attachment = "";
                        priority = 1;
                        turret[] = {0};
                        UIposition[] = {0.628, 0.45};
                    };
                    class PylonRight4 : PylonLeft4 {
                        mirroredMissilePos = 7;
                        UIposition[] = {0.04, 0.45};
                    };
                    class PylonRadar {
                        hardpoints[] = {"MastRadar_Pylon"};
                        UIposition[] = {0.35, 0.1};
                        attachment = "MastRadar";
                        priority = 9;
                    };
                };
                class Presets {
                    class Default {
                        attachment[] = {"PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_4Rnd_LG_scalpel", "PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_4Rnd_LG_scalpel", "", "", "MastRadar"};
                    };
                    class AT {
                        attachment[] = {"PylonRack_4Rnd_LG_scalpel", "PylonRack_4Rnd_LG_scalpel", "PylonRack_4Rnd_LG_scalpel", "PylonRack_4Rnd_LG_scalpel", "PylonRack_4Rnd_LG_scalpel", "PylonRack_4Rnd_LG_scalpel", "", "", "MastRadar"};
                    };
                    class CAS {
                        attachment[] = {"PylonRack_19Rnd_Rocket_Skyfire", "PylonMissile_1Rnd_Bomb_03_F", "PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_19Rnd_Rocket_Skyfire", "PylonMissile_1Rnd_Bomb_03_F", "PylonRack_19Rnd_Rocket_Skyfire", "", "", "MastRadar"};
                    };
                    class HAT {
                        attachment[] = {"PylonRack_1Rnd_Missile_AGM_01_F", "PylonRack_1Rnd_Missile_AGM_01_F", "PylonRack_4Rnd_LG_scalpel", "PylonRack_1Rnd_Missile_AGM_01_F", "PylonRack_1Rnd_Missile_AGM_01_F", "PylonRack_4Rnd_LG_scalpel", "", "", "MastRadar"};
                    };
                };
            };
        };
        class HitPoints : HitPoints {
            class HitLight : HitLight {
                visual = "-";
            };
            class HitStarter1 : HitStarter1 {
                visual = "-";
            };
            class HitStarter2 : HitStarter2 {
                visual = "-";
            };
            class HitStarter3 : HitStarter3 {
                visual = "-";
            };
        };
        class UserActions {
            class OpenDoors {
                displayName = "Open Cargo Door";
                position = "";
                radius = 3;
                onlyForplayer = 0;
                condition = "this doorPhase 'Door_Cargo' < 0.5 AND Alive(this)";
                statement = "this animateDoor ['Door_Cargo', 1];";
                userActionID = 50;
            };
            class CloseDoors {
                displayName = "Close Cargo Door";
                position = "";
                radius = 3;
                onlyForplayer = 0;
                condition = "this doorPhase 'Door_Cargo' > 0.5 AND Alive(this)";
                statement = "this animateDoor ['Door_Cargo', 0];";
                userActionID = 50;
            };
        };
        class Turrets : Turrets {
            class CargoTurret_01 : CargoTurret {
                gunnerAction = "passenger_inside_1";
                gunnerGetInAction = "GetInLow";
                gunnerGetOutAction = "GetOutLow";
                memoryPointsGetInGunner = "pos cargo R2";
                memoryPointsGetInGunnerDir = "pos cargo R2 dir";
                gunnerName = "Passenger (Right Bench 2)";
                gunnerCompartments = "Compartment3";
                proxyIndex = 5;
                maxElev = 15;
                minElev = -45;
                maxTurn = 40;
                minTurn = -15;
                lodTurnedIn = 1200;
                lodTurnedOut = 1200;
                lodOpticsIn = 1200;
                lodOpticsOut = 1200;
                selectionFireAnim = "";
                gunnerUsesPilotView = 0;
                playerPosition = 2;
                soundAttenuationTurret = "HeliAttenuationRamp";
                isPersonTurret = 1;
                commanding = -2;
                gunnerDoor = "Door_Cargo";
                disableSoundAttenuation = 0;
                enabledByAnimationSource = "Door_Cargo";
            };
            class CargoTurret_02 : CargoTurret_01 {
                gunnerName = "Passenger (Right Bench 1)";
                memoryPointsGetInGunner = "pos cargo R";
                memoryPointsGetInGunnerDir = "pos cargo R dir";
                proxyIndex = 7;
                maxTurn = 34;
                minTurn = -30;
            };
            class CargoTurret_03 : CargoTurret_01 {
                memoryPointsGetInGunner = "pos cargo L2";
                memoryPointsGetInGunnerDir = "pos cargo L2 dir";
                gunnerName = "Passenger (Left Bench 2)";
                proxyIndex = 6;
                maxTurn = 25;
                minTurn = -44;
            };
            class CargoTurret_04 : CargoTurret_01 {
                gunnerName = "Passenger (Left Bench 1)";
                memoryPointsGetInGunner = "pos cargo L";
                memoryPointsGetInGunnerDir = "pos cargo L dir";
                proxyIndex = 8;
                maxTurn = 31;
                minTurn = -25;
            };
            class MainTurret : MainTurret {
                discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000};
                weapons[] = {"Aegis_Autocannon_Heli_Attack_04_F", "Laserdesignator_mounted"};
                gunnerGetInAction = "GetInHelicopterCargo";
                gunnerGetOutAction = "GetOutHelicopterCargo";
                allowTabLock = 1;
                usePiP = 0;
                LODTurnedIn = -1;
                LODTurnedOut = -1;
                class OpticsIn {
                    class Wide {
                        visionMode[] = {"Ti", "Normal", "NVG"};
                    };
                };
                class Components {
                    class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
                        class Components {
                            class VehiclePrimaryGunnerDisplay {
                                componentType = "TransportFeedDisplayComponent";
                                source = "PrimaryGunner";
                            };
                            class SensorDisplay {
                                range[] = {8000, 4000, 2000, 32000, 16000};
                                componentType = "SensorsDisplayComponent";
                                resource = "RscCustomInfoSensors";
                            };
                            class SlingLoadDisplay {
                                componentType = "SlingLoadDisplayComponent";
                                resource = "RscCustomInfoSlingLoad";
                            };
                            class VehicleDriverDisplay {
                                componentType = "TransportFeedDisplayComponent";
                                source = "Driver";
                            };
                            class VehicleMissileDisplay {
                                componentType = "TransportFeedDisplayComponent";
                                source = "Missile";
                            };
                            class EmptyDisplay {
                                componentType = "EmptyDisplayComponent";
                            };
                            class MinimapDisplay {
                                componentType = "MinimapDisplayComponent";
                                resource = "RscCustomInfoAirborneMiniMap";
                            };
                            class CrewDisplay {
                                componentType = "CrewDisplayComponent";
                                resource = "RscCustomInfoCrew";
                            };
                            class UAVDisplay {
                                componentType = "UAVFeedDisplayComponent";
                            };
                        };
                    };
                    class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight {
                        class Components {
                            class VehiclePrimaryGunnerDisplay {
                                componentType = "TransportFeedDisplayComponent";
                                source = "PrimaryGunner";
                            };
                            class SensorDisplay {
                                range[] = {8000, 4000, 2000, 32000, 16000};
                                componentType = "SensorsDisplayComponent";
                                resource = "RscCustomInfoSensors";
                            };
                            class SlingLoadDisplay {
                                componentType = "SlingLoadDisplayComponent";
                                resource = "RscCustomInfoSlingLoad";
                            };
                            class VehicleDriverDisplay {
                                componentType = "TransportFeedDisplayComponent";
                                source = "Driver";
                            };
                            class VehicleMissileDisplay {
                                componentType = "TransportFeedDisplayComponent";
                                source = "Missile";
                            };
                            class EmptyDisplay {
                                componentType = "EmptyDisplayComponent";
                            };
                            class MinimapDisplay {
                                componentType = "MinimapDisplayComponent";
                                resource = "RscCustomInfoAirborneMiniMap";
                            };
                            class CrewDisplay {
                                componentType = "CrewDisplayComponent";
                                resource = "RscCustomInfoCrew";
                            };
                            class UAVDisplay {
                                componentType = "UAVFeedDisplayComponent";
                            };
                        };
                    };
                };
                class MFD {
                    class AirplaneHUD {
                        enableParallax = 0;
                        topLeft = "HUD_top_left";
                        topRight = "HUD_top_right";
                        bottomLeft = "HUD_bottom_left";
                        borderLeft = 0;
                        borderRight = 0;
                        borderTop = 0;
                        borderBottom = 0;
                        color[] = {1, 1, 1, 1};
                        helmetMountedDisplay = 1;
                        helmetPosition[] = {-0.0375, 0.0375, 0.1};
                        helmetRight[] = {0.075, 0, 0};
                        helmetDown[] = {0, -0.075, 0};
                        font = "LucidaConsoleB";
                        turret[] = {-2};
                        class Bones {
                            class HUDCenter {
                                type = "fixed";
                                pos[] = {0.5, 0.5};
                            };
                            class WeaponAim {
                                type = "vector";
                                source = "weapon";
                                pos0[] = {0.5, 0.5};
                                pos10[] = {0.734, 0.73};
                            };
                            class WeaponAimRelative : WeaponAim {
                                source = "weapontoview";
                            };
                            class VelocityVector {
                                type = "vector";
                                source = "velocityToView";
                                pos0[] = {0.5, 0.5};
                                pos10[] = {0.734, 0.73};
                            };
                            class ForwardVector {
                                type = "vector";
                                source = "forward";
                                pos0[] = {0, 0};
                                pos10[] = {0.234, 0.23};
                            };
                            class HorizonVector {
                                type = "horizontoview";
                                pos0[] = {0.5, 0.5};
                                pos10[] = {0.830923, 0.825266};
                                angle = 0;
                            };
                            class GunnerAim {
                                type = "vector";
                                source = "turret";
                                pos0[] = {0, -2};
                                pos10[] = {0.0068, -0.01};
                                projection = 0;
                            };
                            class VerticalSpeedBone {
                                type = "linear";
                                source = "vspeed";
                                sourceScale = 1;
                                min = -10;
                                max = 10;
                                minPos[] = {0, -0.32};
                                maxPos[] = {0, 0.32};
                            };
                            class HorizonBankRot {
                                type = "linear";
                                source = "horizonBank";
                                min = -0.5236;
                                max = 0.5236;
                                minPos[] = {0.41, 0.84};
                                maxPos[] = {0.59, 0.84};
                                aspectRatio = 1;
                            };
                            class ImpactPoint {
                                type = "vector";
                                source = "ImpactPointToView";
                                pos[] = {};
                                pos0[] = {0.5, 0.5};
                                pos10[] = {0.734, 0.73};
                            };
                            class Target {
                                source = "targettoview";
                                type = "vector";
                                pos0[] = {0.5, 0.5};
                                pos10[] = {0.734, 0.73};
                            };
                            class Limit0109 {
                                type = "limit";
                                limits[] = {0.1, 0.1, 0.9, 0.9};
                            };
                            class LimitWaypoint {
                                type = "limit";
                                limits[] = {0.2, 0.1, 0.8, 0.1};
                            };
                            class WPPoint {
                                type = "vector";
                                source = "WPPoint";
                                pos0[] = {0.5, 0.5};
                                pos10[] = {0.734, 0.73};
                            };
                            class WPPointToView : WPPoint {
                                source = "WPPointToView";
                            };
                            class RadarHeight {
                                type = "linear";
                                source = "altitudeAGL";
                                sourceScale = 1;
                                sourceOffset = -2;
                                min = 0;
                                max = 100;
                                minPos[] = {0.903, 0.18};
                                maxPos[] = {0.903, 0.82};
                            };
                            class HorizonBankRotFull {
                                type = "rotational";
                                source = "horizonBank";
                                center[] = {0, 0};
                                min = -3.1416;
                                max = 3.1416;
                                minAngle = -180;
                                maxAngle = 180;
                                aspectRatio = 1;
                            };
                            class LarAmmoMax {
                                type = "linear";
                                source = "LarAmmoMax";
                                sourceScale = 1;
                                min = 0;
                                max = 1;
                                minPos[] = {0, 1};
                                maxPos[] = {0, 0};
                            };
                            class LarAmmoMin : LarAmmoMax {
                                source = "LarAmmoMin";
                            };
                            class LarTargetDist : LarAmmoMax {
                                source = "LarTargetDist";
                            };
                            class MissileFlightTimeRot1 {
                                type = "rotational";
                                source = "MissileFlightTime";
                                sourceScale = 0.46000001;
                                center[] = {0, 0};
                                min = 0;
                                max = 0.5;
                                minAngle = 0;
                                maxAngle = 18;
                                aspectRatio = 0.98290598;
                            };
                            class MissileFlightTimeRot2 : MissileFlightTimeRot1 {
                                maxAngle = 36;
                                max = 1;
                            };
                            class MissileFlightTimeRot3 : MissileFlightTimeRot1 {
                                maxAngle = 54;
                                max = 1.5;
                            };
                            class MissileFlightTimeRot4 : MissileFlightTimeRot1 {
                                maxAngle = 72;
                                max = 2;
                            };
                            class MissileFlightTimeRot5 : MissileFlightTimeRot1 {
                                maxAngle = 90;
                                max = 2.5;
                            };
                            class MissileFlightTimeRot6 : MissileFlightTimeRot1 {
                                maxAngle = 108;
                                max = 3;
                            };
                            class MissileFlightTimeRot7 : MissileFlightTimeRot1 {
                                maxAngle = 126;
                                max = 3.5;
                            };
                            class MissileFlightTimeRot8 : MissileFlightTimeRot1 {
                                maxAngle = 144;
                                max = 4;
                            };
                            class MissileFlightTimeRot9 : MissileFlightTimeRot1 {
                                maxAngle = 162;
                                max = 4.5;
                            };
                            class MissileFlightTimeRot10 : MissileFlightTimeRot1 {
                                maxAngle = 180;
                                max = 5;
                            };
                            class MissileFlightTimeRot11 : MissileFlightTimeRot1 {
                                maxAngle = 198;
                                max = 5.5;
                            };
                            class MissileFlightTimeRot12 : MissileFlightTimeRot1 {
                                maxAngle = 216;
                                max = 6;
                            };
                            class MissileFlightTimeRot13 : MissileFlightTimeRot1 {
                                maxAngle = 234;
                                max = 6.5;
                            };
                            class MissileFlightTimeRot14 : MissileFlightTimeRot1 {
                                maxAngle = 252;
                                max = 7;
                            };
                            class MissileFlightTimeRot15 : MissileFlightTimeRot1 {
                                maxAngle = 270;
                                max = 7.5;
                            };
                            class MissileFlightTimeRot16 : MissileFlightTimeRot1 {
                                maxAngle = 288;
                                max = 8;
                            };
                            class MissileFlightTimeRot17 : MissileFlightTimeRot1 {
                                maxAngle = 306;
                                max = 8.5;
                            };
                            class MissileFlightTimeRot18 : MissileFlightTimeRot1 {
                                maxAngle = 324;
                                max = 9;
                            };
                            class MissileFlightTimeRot19 : MissileFlightTimeRot1 {
                                maxAngle = 342;
                                max = 9.5;
                            };
                            class MissileFlightTimeRot20 : MissileFlightTimeRot1 {
                                maxAngle = 360;
                                max = 10;
                            };
                        };
                        class Draw {
                            alpha = "user3";
                            color[] = {"user0", "user1", "user2"};
                            condition = "on";
                            delete ImpactCross;
                            class Static {
                                type = "line";
                                width = 4;
                                points[] = {{{0.5, 0.11}, 1}, {{0.5, 0.14}, 1}, {}, {{0.4, 0.86}, 1}, {{0.4, 0.94}, 1}, {{0.6, 0.94}, 1}, {{0.6, 0.86}, 1}, {{0.4, 0.86}, 1}, {}, {{0.4, 0.885}, 1}, {{0.408, 0.885}, 1}, {}, {{0.6, 0.885}, 1}, {{0.592, 0.885}, 1}, {}, {{0.5, 0.86}, 1}, {{0.5, 0.868}, 1}, {}, {{0.5, 0.94}, 1}, {{0.5, 0.932}, 1}, {}, {{0.52, 0.86}, 1}, {{0.52, 0.82}, 1}, {}, {{0.48, 0.86}, 1}, {{0.48, 0.82}, 1}, {}, {{0.55, 0}, 1}, {{0.55, 0.04}, 1}, {{0.45, 0.04}, 1}, {{0.45, 0}, 1}, {{0.55, 0}, 1}};
                            };
                            class HeadingNumber {
                                type = "text";
                                source = "Heading";
                                sourceScale = 1;
                                align = "center";
                                scale = 1;
                                pos[] = {{0.5, 0.006}, 1};
                                right[] = {{0.55, 0.006}, 1};
                                down[] = {{0.5, 0.046}, 1};
                            };
                            class HeadingRotation {
                                condition = "abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)-5";
                                class HeadingHeadNumber {
                                    type = "text";
                                    source = "cameraDir";
                                    sourceScale = 1;
                                    align = "center";
                                    scale = 1;
                                    pos[] = {{"0.80-0.302", "0.082-0.025"}, 1};
                                    right[] = {{"0.83-0.302", "0.082-0.025"}, 1};
                                    down[] = {{"0.80-0.302", "0.113-0.025"}, 1};
                                };
                                class HeadingArrow {
                                    type = "line";
                                    width = 3;
                                    points[] = {{{0.478, 0.045}, 1}, {{0.522, 0.045}, 1}, {{0.552, 0.07}, 1}, {{0.522, 0.095}, 1}, {{0.478, 0.095}, 1}, {{0.448, 0.07}, 1}, {{0.478, 0.045}, 1}, {}};
                                };
                                class HeadingScaleRight {
                                    clipTL[] = {0.55, 0.05};
                                    clipBR[] = {0.83, 0.11};
                                    class lines {
                                        type = "scale";
                                        horizontal = 1;
                                        source = "heading";
                                        sourceScale = 1;
                                        width = 4;
                                        top = 0.5;
                                        center = 0.5;
                                        bottom = 0.85;
                                        lineXleft = 0.11;
                                        lineYright = 0.1;
                                        lineXleftMajor = 0.11;
                                        lineYrightMajor = 0.09;
                                        majorLineEach = 2;
                                        numberEach = 2;
                                        step = 22.5;
                                        stepSize = 0.075;
                                        align = "center";
                                        scale = 1;
                                        pos[] = {0.496, 0.05};
                                        right[] = {0.536, 0.05};
                                        down[] = {0.496, 0.09};
                                    };
                                };
                                class HeadingScaleMidle {
                                    type = "scale";
                                    horizontal = 1;
                                    source = "heading";
                                    sourceScale = 1;
                                    width = 4;
                                    top = 0.45;
                                    center = 0.5;
                                    bottom = 0.55;
                                    lineXleft = 0.11;
                                    lineYright = 0.1;
                                    lineXleftMajor = 0.11;
                                    lineYrightMajor = 0.1;
                                    majorLineEach = 2;
                                    step = 22.5;
                                    stepSize = 0.075;
                                    align = "center";
                                    scale = 1;
                                    numberEach = 0;
                                    pos[] = {0.47, 0.05};
                                    right[] = {0.5, 0.05};
                                    down[] = {0.45, 0.09};
                                };
                                class HeadingScaleLeft {
                                    clipTL[] = {0.18, 0.05};
                                    clipBR[] = {0.45, 0.11};
                                    class lines {
                                        type = "scale";
                                        horizontal = 1;
                                        source = "heading";
                                        sourceScale = 1;
                                        width = 4;
                                        top = 0.15;
                                        center = 0.5;
                                        bottom = 0.55;
                                        lineXleft = 0.11;
                                        lineYright = 0.1;
                                        lineXleftMajor = 0.11;
                                        lineYrightMajor = 0.09;
                                        majorLineEach = 2;
                                        numberEach = 2;
                                        step = 22.5;
                                        stepSize = 0.075;
                                        align = "center";
                                        scale = 1;
                                        pos[] = {0.146, 0.05};
                                        right[] = {0.186, 0.05};
                                        down[] = {0.146, 0.09};
                                    };
                                };
                            };
                            class HeadingScaleFull {
                                condition = "4-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)";
                                class HeadingScale {
                                    clipTL[] = {0.18, 0};
                                    clipBR[] = {0.83, 1};
                                    class lines {
                                        type = "scale";
                                        horizontal = 1;
                                        source = "heading";
                                        sourceScale = 1;
                                        width = 4;
                                        top = 0.15;
                                        center = 0.5;
                                        bottom = 0.85;
                                        lineXleft = 0.11;
                                        lineYright = 0.1;
                                        lineXleftMajor = 0.11;
                                        lineYrightMajor = 0.09;
                                        majorLineEach = 2;
                                        numberEach = 2;
                                        step = 22.5;
                                        stepSize = 0.075;
                                        align = "center";
                                        scale = 1;
                                        pos[] = {0.146, 0.05};
                                        right[] = {0.186, 0.05};
                                        down[] = {0.146, 0.09};
                                    };
                                };
                            };
                            class HorizonBankRot {
                                type = "polygon";
                                width = 4;
                                points[] = {{{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.00260472, -0.0145196}, 1}, {"HorizonBankRot", {0.0051303, -0.0138544}, 1}, {"HorizonBankRot", {0.0075, -0.0127683}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.0075, -0.0127683}, 1}, {"HorizonBankRot", {0.00964181, -0.0112942}, 1}, {"HorizonBankRot", {0.0114907, -0.009477}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.0114907, -0.009477}, 1}, {"HorizonBankRot", {0.0129904, -0.00737179}, 1}, {"HorizonBankRot", {0.0140954, -0.0050426}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.0140954, -0.0050426}, 1}, {"HorizonBankRot", {0.0147721, -0.0025602}, 1}, {"HorizonBankRot", {0.015, 6.44463e-10}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.015, 6.44463e-10}, 1}, {"HorizonBankRot", {0.0147721, 0.0025602}, 1}, {"HorizonBankRot", {0.0140954, 0.0050426}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.0140954, 0.0050426}, 1}, {"HorizonBankRot", {0.0129904, 0.0073718}, 1}, {"HorizonBankRot", {0.0114907, 0.009477}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.0114907, 0.009477}, 1}, {"HorizonBankRot", {0.00964181, 0.0112942}, 1}, {"HorizonBankRot", {0.0075, 0.0127683}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.0075, 0.0127683}, 1}, {"HorizonBankRot", {0.0051303, 0.0138544}, 1}, {"HorizonBankRot", {0.00260472, 0.0145196}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.00260472, 0.0145196}, 1}, {"HorizonBankRot", {-1.31134e-09, 0.0147436}, 1}, {"HorizonBankRot", {-0.00260473, 0.0145196}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.00260473, 0.0145196}, 1}, {"HorizonBankRot", {-0.0051303, 0.0138544}, 1}, {"HorizonBankRot", {-0.0075, 0.0127683}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.0075, 0.0127683}, 1}, {"HorizonBankRot", {-0.00964181, 0.0112942}, 1}, {"HorizonBankRot", {-0.0114907, 0.009477}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.0114907, 0.009477}, 1}, {"HorizonBankRot", {-0.0129904, 0.00737179}, 1}, {"HorizonBankRot", {-0.0140954, 0.0050426}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.0140954, 0.0050426}, 1}, {"HorizonBankRot", {-0.0147721, 0.0025602}, 1}, {"HorizonBankRot", {-0.015, -1.75816e-10}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.015, -1.75816e-10}, 1}, {"HorizonBankRot", {-0.0147721, -0.0025602}, 1}, {"HorizonBankRot", {-0.0140954, -0.0050426}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.0140954, -0.0050426}, 1}, {"HorizonBankRot", {-0.0129904, -0.0073718}, 1}, {"HorizonBankRot", {-0.0114907, -0.009477}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.0114907, -0.009477}, 1}, {"HorizonBankRot", {-0.00964181, -0.0112942}, 1}, {"HorizonBankRot", {-0.0075, -0.0127683}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.0075, -0.0127683}, 1}, {"HorizonBankRot", {-0.00513031, -0.0138544}, 1}, {"HorizonBankRot", {-0.00260472, -0.0145196}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.00260472, -0.0145196}, 1}, {"HorizonBankRot", {2.62268e-09, -0.0147436}, 1}, {"HorizonBankRot", {0.00260472, -0.0145196}, 1}}};
                            };
                            class CollectiveGroup {
                                condition = "simulRTD";
                                class CollectiveText {
                                    type = "text";
                                    source = "static";
                                    text = "%";
                                    align = "right";
                                    scale = 1;
                                    pos[] = {{0.22, 0.2}, 1};
                                    right[] = {{0.28, 0.2}, 1};
                                    down[] = {{0.22, 0.24}, 1};
                                };
                                class CollectiveNumber {
                                    type = "text";
                                    source = "rtdCollective";
                                    sourceScale = 100;
                                    align = "left";
                                    scale = 1;
                                    pos[] = {{0.22, 0.2}, 1};
                                    right[] = {{0.28, 0.2}, 1};
                                    down[] = {{0.22, 0.24}, 1};
                                };
                            };
                            class SpeedNumber {
                                type = "text";
                                source = "speed";
                                sourceScale = 3.6;
                                align = "right";
                                scale = 1;
                                pos[] = {{0.16, 0.48}, 1};
                                right[] = {{0.22, 0.48}, 1};
                                down[] = {{0.16, 0.52}, 1};
                            };
                            class AltNumber {
                                type = "text";
                                source = "altitudeAGL";
                                sourceScale = 1;
                                sourceOffset = -2;
                                align = "left";
                                scale = 1;
                                pos[] = {{0.81, 0.48}, 1};
                                right[] = {{0.87, 0.48}, 1};
                                down[] = {{0.81, 0.52}, 1};
                            };
                            class HoverMode {
                                condition = "autohover";
                                class HoverText {
                                    type = "text";
                                    source = "static";
                                    text = "HOVER";
                                    scale = 1;
                                    sourceScale = 1;
                                    align = "right";
                                    pos[] = {{0.005, 0.075}, 1};
                                    right[] = {{0.045, 0.075}, 1};
                                    down[] = {{0.005, 0.11}, 1};
                                };
                            };
                            class CruiseMode {
                                condition = "((altitudeASL-27) min 1) - autohover";
                                class CruiseText {
                                    type = "text";
                                    source = "static";
                                    text = "CRUISE";
                                    scale = 1;
                                    sourceScale = 1;
                                    align = "right";
                                    pos[] = {{0.005, 0.075}, 1};
                                    right[] = {{0.045, 0.075}, 1};
                                    down[] = {{0.005, 0.11}, 1};
                                };
                                class AltNumberASL {
                                    type = "text";
                                    source = "altitudeASL";
                                    sourceScale = 1;
                                    align = "left";
                                    scale = 1;
                                    pos[] = {{0.81, 0.16}, 1};
                                    right[] = {{0.87, 0.16}, 1};
                                    down[] = {{0.81, 0.2}, 1};
                                };
                            };
                            class TransitionMode {
                                condition = "((27-altitudeASL) min 1) - autohover";
                                class TransText {
                                    type = "text";
                                    source = "static";
                                    text = "TRANS";
                                    scale = 1;
                                    sourceScale = 1;
                                    align = "right";
                                    pos[] = {{0.005, 0.075}, 1};
                                    right[] = {{0.045, 0.075}, 1};
                                    down[] = {{0.005, 0.11}, 1};
                                };
                            };
                            class HoverModeHide {
                                condition = "1-autohover";
                                class VelocityLine {
                                    type = "line";
                                    width = 4;
                                    points[] = {{"VelocityVector", {0, -0.0196581}, 1}, {"VelocityVector", {0.01, -0.0170239}, 1}, {"VelocityVector", {0.01732, -0.00982906}, 1}, {"VelocityVector", {0.02, 0}, 1}, {"VelocityVector", {0.01732, 0.00982906}, 1}, {"VelocityVector", {0.01, 0.0170239}, 1}, {"VelocityVector", {0, 0.0196581}, 1}, {"VelocityVector", {-0.01, 0.0170239}, 1}, {"VelocityVector", {-0.01732, 0.00982906}, 1}, {"VelocityVector", {-0.02, 0}, 1}, {"VelocityVector", {-0.01732, -0.00982906}, 1}, {"VelocityVector", {-0.01, -0.0170239}, 1}, {"VelocityVector", {0, -0.0196581}, 1}, {}, {"VelocityVector", {0.04, 0}, 1}, {"VelocityVector", {0.02, 0}, 1}, {}, {"VelocityVector", {-0.04, 0}, 1}, {"VelocityVector", {-0.02, 0}, 1}, {}, {"VelocityVector", {0, -0.0393162}, 1}, {"VelocityVector", {0, -0.0196581}, 1}, {}};
                                };
                            };
                            class GearGroup {
                                type = "group";
                                condition = "ils";
                                class GearText {
                                    type = "text";
                                    source = "static";
                                    text = "GEAR";
                                    align = "right";
                                    scale = 1;
                                    pos[] = {{0.015, 0.334188}, 1};
                                    right[] = {{0.055, 0.334188}, 1};
                                    down[] = {{0.015, 0.363675}, 1};
                                };
                            };
                            class LaserGroup {
                                condition = "laseron";
                                class laserText {
                                    type = "text";
                                    source = "static";
                                    text = "LASER";
                                    scale = 1;
                                    sourceScale = 1;
                                    align = "right";
                                    pos[] = {{0.015, 0.37}, 1};
                                    right[] = {{0.055, 0.37}, 1};
                                    down[] = {{0.015, 0.405}, 1};
                                };
                            };
                            class RadarGroup {
                                condition = "activeSensorsOn";
                                class radarText {
                                    type = "text";
                                    source = "static";
                                    text = "RADAR";
                                    scale = 1;
                                    sourceScale = 1;
                                    align = "right";
                                    pos[] = {{0.015, 0.41}, 1};
                                    right[] = {{0.055, 0.41}, 1};
                                    down[] = {{0.015, 0.445}, 1};
                                };
                            };
                            class VerticalSpeedScale {
                                type = "line";
                                width = 4;
                                points[] = {{"HUDCenter", 1, {-0.03, 0}, 1}, {"HUDCenter", 1, {-0.01, 0}, 1}, {}, {"HUDCenter", 1, {0.01, 0}, 1}, {"HUDCenter", 1, {0.03, 0}, 1}, {}, {"HUDCenter", 1, {0, -0.01}, 1}, {"HUDCenter", 1, {0, -0.03}, 1}, {}, {"HUDCenter", 1, {0, 0.01}, 1}, {"HUDCenter", 1, {0, 0.03}, 1}, {}, {{0.915, 0.18}, 1}, {{0.935, 0.18}, 1}, {}, {{0.87, 0.18}, 1}, {{0.89, 0.18}, 1}, {}, {{0.915, 0.34}, 1}, {{0.935, 0.34}, 1}, {}, {{0.87, 0.34}, 1}, {{0.89, 0.34}, 1}, {}, {{0.875, 0.372}, 1}, {{0.885, 0.372}, 1}, {}, {{0.875, 0.404}, 1}, {{0.885, 0.404}, 1}, {}, {{0.875, 0.436}, 1}, {{0.885, 0.436}, 1}, {}, {{0.875, 0.468}, 1}, {{0.885, 0.468}, 1}, {}, {{0.87, 0.5}, 1}, {{0.89, 0.5}, 1}, {}, {{0.915, 0.5}, 1}, {{0.935, 0.5}, 1}, {}, {{0.915, 0.66}, 1}, {{0.935, 0.66}, 1}, {}, {{0.87, 0.66}, 1}, {{0.89, 0.66}, 1}, {}, {{0.875, 0.628}, 1}, {{0.885, 0.628}, 1}, {}, {{0.875, 0.596}, 1}, {{0.885, 0.596}, 1}, {}, {{0.875, 0.564}, 1}, {{0.885, 0.564}, 1}, {}, {{0.875, 0.532}, 1}, {{0.885, 0.532}, 1}, {}, {{0.92, 0.692}, 1}, {{0.93, 0.692}, 1}, {}, {{0.92, 0.724}, 1}, {{0.93, 0.724}, 1}, {}, {{0.92, 0.756}, 1}, {{0.93, 0.756}, 1}, {}, {{0.92, 0.788}, 1}, {{0.93, 0.788}, 1}, {}, {{0.915, 0.82}, 1}, {{0.935, 0.82}, 1}, {}, {{0.87, 0.82}, 1}, {{0.89, 0.82}, 1}, {}};
                            };
                            class GunnerAimWorld {
                                condition = "1-mgun";
                                class Cross {
                                    type = "line";
                                    width = 4;
                                    points[] = {{"WeaponAimRelative", 1, {-0.03, 0}, 1}, {"WeaponAimRelative", 1, {-0.02, 0}, 1}, {}, {"WeaponAimRelative", 1, {0.02, 0}, 1}, {"WeaponAimRelative", 1, {0.03, 0}, 1}, {}, {"WeaponAimRelative", 1, {0, -0.02}, 1}, {"WeaponAimRelative", 1, {0, -0.03}, 1}, {}, {"WeaponAimRelative", 1, {0, 0.02}, 1}, {"WeaponAimRelative", 1, {0, 0.03}, 1}};
                                };
                            };
                            class VerticalSpeedArrow {
                                type = "polygon";
                                points[] = {{{"VerticalSpeedBone", {0.85, 0.488}, 1}, {"VerticalSpeedBone", {0.87, 0.5}, 1}, {"VerticalSpeedBone", {0.85, 0.512}, 1}}};
                            };
                            class RadarAltitude {
                                condition = "101-altitudeAGL";
                                class RadarHeight {
                                    type = "line";
                                    width = 15;
                                    points[] = {{{0.903, 0.82}, 1}, {"RadarHeight", {0, 0}, 1}, {}};
                                };
                            };
                            class HorizonLine {
                                condition = "1-autohover";
                                clipTL[] = {0.2, 0.145};
                                clipBR[] = {0.8, 0.855};
                                class HorizonLineDraw {
                                    type = "line";
                                    width = 4;
                                    points[] = {{"HorizonVector", {-0.225, 0}, 1}, {"HorizonVector", {-0.1875, 0}, 1}, {}, {"HorizonVector", {-0.15, 0}, 1}, {"HorizonVector", {-0.1125, 0}, 1}, {}, {"HorizonVector", {-0.075, 0}, 1}, {"HorizonVector", {-0.0375, 0}, 1}, {}, {"HorizonVector", {0.0375, 0}, 1}, {"HorizonVector", {0.075, 0}, 1}, {}, {"HorizonVector", {0.1125, 0}, 1}, {"HorizonVector", {0.15, 0}, 1}, {}, {"HorizonVector", {0.1875, 0}, 1}, {"HorizonVector", {0.225, 0}, 1}};
                                };
                            };
                            class Gunner {
                                type = "line";
                                width = 4;
                                points[] = {{"GunnerAim", {0.485, 0.892}, 1}, {"GunnerAim", {0.485, 0.908}, 1}, {"GunnerAim", {0.515, 0.908}, 1}, {"GunnerAim", {0.515, 0.892}, 1}, {"GunnerAim", {0.485, 0.892}, 1}};
                            };
                            class WeaponsText {
                                type = "text";
                                source = "weapon";
                                sourceScale = 1;
                                align = "left";
                                scale = 0.5;
                                pos[] = {{0.38, 0.869}, 1};
                                right[] = {{0.415, 0.869}, 1};
                                down[] = {{0.38, 0.904}, 1};
                            };
                            class Ammo {
                                type = "text";
                                source = "ammo";
                                sourceScale = 1;
                                align = "left";
                                scale = 0.5;
                                pos[] = {{0.38, 0.901}, 1};
                                right[] = {{0.415, 0.901}, 1};
                                down[] = {{0.38, 0.936}, 1};
                            };
                            class MGun {
                                condition = "-2+mgun*ImpactDistance";
                                class Cross {
                                    type = "line";
                                    width = 3;
                                    points[] = {{"ImpactPoint", {0, -0.0294872}, 1}, {"ImpactPoint", {0, -0.0393162}, 1}, {}, {"ImpactPoint", {0.02, -0.024}, 1}, {"ImpactPoint", {0.025, -0.030999999}, 1}, {}, {"ImpactPoint", {0, -0.0020000001}, 1}, {"ImpactPoint", {0, 0.0020000001}, 1}, {}, {"ImpactPoint", {-0.0020000001, 0}, 1}, {"ImpactPoint", {0.0020000001, 0}, 1}, {}};
                                };
                                class Circle {
                                    type = "line";
                                    width = 3;
                                    points[] = {{"ImpactPoint", {0, -0.0275214}, 1}, {"ImpactPoint", {0, -0.0344017}, 1}, {"MissileFlightTimeRot1", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot2", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot3", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot4", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot5", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot6", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot7", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot8", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot9", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot10", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot11", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot12", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot13", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot14", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot15", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot16", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot17", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot18", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot19", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot20", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot20", {0, 0.028000001}, 1, "ImpactPoint", 1}};
                                };
                                class Circle_Min_Range {
                                    type = "line";
                                    width = 3;
                                    points[] = {{"ImpactPoint", {0, -0.0294872}, 1}, {"ImpactPoint", {0.0052080001, -0.029038999}, 1}, {"ImpactPoint", {0.01026, -0.0277091}, 1}, {"ImpactPoint", {0.015, -0.0255359}, 1}, {"ImpactPoint", {0.019284001, -0.022587201}, 1}, {"ImpactPoint", {0.022980001, -0.0189544}, 1}, {"ImpactPoint", {0.025979999, -0.0147436}, 1}, {"ImpactPoint", {0.028191, -0.0100846}, 1}, {"ImpactPoint", {0.029544, -0.0051189698}, 1}, {"ImpactPoint", {0.029999999, 0}, 1}, {"ImpactPoint", {0.029544, 0.0051189698}, 1}, {"ImpactPoint", {0.028191, 0.0100846}, 1}, {"ImpactPoint", {0.025979999, 0.0147436}, 1}, {"ImpactPoint", {0.022980001, 0.0189544}, 1}, {"ImpactPoint", {0.019284001, 0.022587201}, 1}, {"ImpactPoint", {0.015, 0.0255359}, 1}, {"ImpactPoint", {0.01026, 0.0277091}, 1}, {"ImpactPoint", {0.0052080001, 0.029038999}, 1}, {"ImpactPoint", {0, 0.0294872}, 1}, {"ImpactPoint", {-0.0052080001, 0.029038999}, 1}, {"ImpactPoint", {-0.01026, 0.0277091}, 1}, {"ImpactPoint", {-0.015, 0.0255359}, 1}, {"ImpactPoint", {-0.019284001, 0.022587201}, 1}, {"ImpactPoint", {-0.022980001, 0.0189544}, 1}, {"ImpactPoint", {-0.025979999, 0.0147436}, 1}, {"ImpactPoint", {-0.028191, 0.0100846}, 1}, {"ImpactPoint", {-0.029544, 0.0051189698}, 1}, {"ImpactPoint", {-0.029999999, 0}, 1}, {"ImpactPoint", {-0.029544, -0.0051189698}, 1}, {"ImpactPoint", {-0.028191, -0.0100846}, 1}, {"ImpactPoint", {-0.025979999, -0.0147436}, 1}, {"ImpactPoint", {-0.022980001, -0.0189544}, 1}, {"ImpactPoint", {-0.019284001, -0.022587201}, 1}, {"ImpactPoint", {-0.015, -0.0255359}, 1}, {"ImpactPoint", {-0.01026, -0.0277091}, 1}, {"ImpactPoint", {-0.0052080001, -0.029038999}, 1}, {"ImpactPoint", {0, -0.0294872}, 1}};
                                };
                                class Distance {
                                    type = "text";
                                    source = "ImpactDistance";
                                    sourceScale = 0.001;
                                    sourcePrecision = 2;
                                    max = 99;
                                    align = "center";
                                    scale = 1;
                                    pos[] = {"ImpactPoint", {-0.0020000001, -0.079999998}, 1};
                                    right[] = {"ImpactPoint", {0.045000002, -0.079999998}, 1};
                                    down[] = {"ImpactPoint", {-0.0020000001, -0.039999999}, 1};
                                };
                            };
                            class Rockets {
                                condition = "-2+rocket*ImpactDistance";
                                class Cross {
                                    type = "line";
                                    width = 3;
                                    points[] = {{"ImpactPoint", {0, -0.0294872}, 1}, {"ImpactPoint", {0, -0.0393162}, 1}, {}, {"ImpactPoint", {0.02, -0.024}, 1}, {"ImpactPoint", {0.025, -0.030999999}, 1}, {}, {"ImpactPoint", {0, -0.0020000001}, 1}, {"ImpactPoint", {0, 0.0020000001}, 1}, {}, {"ImpactPoint", {-0.0020000001, 0}, 1}, {"ImpactPoint", {0.0020000001, 0}, 1}, {}};
                                };
                                class Circle {
                                    type = "line";
                                    width = 3;
                                    points[] = {{"ImpactPoint", {0, -0.0275214}, 1}, {"ImpactPoint", {0, -0.0344017}, 1}, {"MissileFlightTimeRot1", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot2", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot3", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot4", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot5", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot6", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot7", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot8", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot9", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot10", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot11", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot12", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot13", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot14", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot15", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot16", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot17", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot18", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot19", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot20", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot20", {0, 0.028000001}, 1, "ImpactPoint", 1}};
                                };
                                class Circle_Min_Range {
                                    type = "line";
                                    width = 3;
                                    points[] = {{"ImpactPoint", {0, -0.0294872}, 1}, {"ImpactPoint", {0.0052080001, -0.029038999}, 1}, {"ImpactPoint", {0.01026, -0.0277091}, 1}, {"ImpactPoint", {0.015, -0.0255359}, 1}, {"ImpactPoint", {0.019284001, -0.022587201}, 1}, {"ImpactPoint", {0.022980001, -0.0189544}, 1}, {"ImpactPoint", {0.025979999, -0.0147436}, 1}, {"ImpactPoint", {0.028191, -0.0100846}, 1}, {"ImpactPoint", {0.029544, -0.0051189698}, 1}, {"ImpactPoint", {0.029999999, 0}, 1}, {"ImpactPoint", {0.029544, 0.0051189698}, 1}, {"ImpactPoint", {0.028191, 0.0100846}, 1}, {"ImpactPoint", {0.025979999, 0.0147436}, 1}, {"ImpactPoint", {0.022980001, 0.0189544}, 1}, {"ImpactPoint", {0.019284001, 0.022587201}, 1}, {"ImpactPoint", {0.015, 0.0255359}, 1}, {"ImpactPoint", {0.01026, 0.0277091}, 1}, {"ImpactPoint", {0.0052080001, 0.029038999}, 1}, {"ImpactPoint", {0, 0.0294872}, 1}, {"ImpactPoint", {-0.0052080001, 0.029038999}, 1}, {"ImpactPoint", {-0.01026, 0.0277091}, 1}, {"ImpactPoint", {-0.015, 0.0255359}, 1}, {"ImpactPoint", {-0.019284001, 0.022587201}, 1}, {"ImpactPoint", {-0.022980001, 0.0189544}, 1}, {"ImpactPoint", {-0.025979999, 0.0147436}, 1}, {"ImpactPoint", {-0.028191, 0.0100846}, 1}, {"ImpactPoint", {-0.029544, 0.0051189698}, 1}, {"ImpactPoint", {-0.029999999, 0}, 1}, {"ImpactPoint", {-0.029544, -0.0051189698}, 1}, {"ImpactPoint", {-0.028191, -0.0100846}, 1}, {"ImpactPoint", {-0.025979999, -0.0147436}, 1}, {"ImpactPoint", {-0.022980001, -0.0189544}, 1}, {"ImpactPoint", {-0.019284001, -0.022587201}, 1}, {"ImpactPoint", {-0.015, -0.0255359}, 1}, {"ImpactPoint", {-0.01026, -0.0277091}, 1}, {"ImpactPoint", {-0.0052080001, -0.029038999}, 1}, {"ImpactPoint", {0, -0.0294872}, 1}};
                                };
                                class Distance {
                                    type = "text";
                                    source = "ImpactDistance";
                                    sourceScale = 0.001;
                                    sourcePrecision = 2;
                                    max = 99;
                                    align = "center";
                                    scale = 1;
                                    pos[] = {"ImpactPoint", {-0.0020000001, -0.079999998}, 1};
                                    right[] = {"ImpactPoint", {0.045000002, -0.079999998}, 1};
                                    down[] = {"ImpactPoint", {-0.0020000001, -0.039999999}, 1};
                                };
                            };
                            class BombCrosshairGroup {
                                type = "group";
                                condition = "bomb";
                                class BombCrosshair {
                                    type = "line";
                                    width = 4;
                                    points[] = {{"ImpactPoint", {0, -0.0982906}, 1}, {"ImpactPoint", {0.01736, -0.096796602}, 1}, {"ImpactPoint", {0.034200002, -0.0923637}, 1}, {"ImpactPoint", {0.050000001, -0.085119702}, 1}, {"ImpactPoint", {0.064280003, -0.075290598}, 1}, {"ImpactPoint", {0.0766, -0.063181199}, 1}, {"ImpactPoint", {0.086599998, -0.0491453}, 1}, {"ImpactPoint", {0.093970001, -0.033615399}, 1}, {"ImpactPoint", {0.098480001, -0.0170632}, 1}, {"ImpactPoint", {0.1, 0}, 1}, {"ImpactPoint", {0.098480001, 0.0170632}, 1}, {"ImpactPoint", {0.093970001, 0.033615399}, 1}, {"ImpactPoint", {0.086599998, 0.0491453}, 1}, {"ImpactPoint", {0.0766, 0.063181199}, 1}, {"ImpactPoint", {0.064280003, 0.075290598}, 1}, {"ImpactPoint", {0.050000001, 0.085119702}, 1}, {"ImpactPoint", {0.034200002, 0.0923637}, 1}, {"ImpactPoint", {0.01736, 0.096796602}, 1}, {"ImpactPoint", {0, 0.0982906}, 1}, {"ImpactPoint", {-0.01736, 0.096796602}, 1}, {"ImpactPoint", {-0.034200002, 0.0923637}, 1}, {"ImpactPoint", {-0.050000001, 0.085119702}, 1}, {"ImpactPoint", {-0.064280003, 0.075290598}, 1}, {"ImpactPoint", {-0.0766, 0.063181199}, 1}, {"ImpactPoint", {-0.086599998, 0.0491453}, 1}, {"ImpactPoint", {-0.093970001, 0.033615399}, 1}, {"ImpactPoint", {-0.098480001, 0.0170632}, 1}, {"ImpactPoint", {-0.1, 0}, 1}, {"ImpactPoint", {-0.098480001, -0.0170632}, 1}, {"ImpactPoint", {-0.093970001, -0.033615399}, 1}, {"ImpactPoint", {-0.086599998, -0.0491453}, 1}, {"ImpactPoint", {-0.0766, -0.063181199}, 1}, {"ImpactPoint", {-0.064280003, -0.075290598}, 1}, {"ImpactPoint", {-0.050000001, -0.085119702}, 1}, {"ImpactPoint", {-0.034200002, -0.0923637}, 1}, {"ImpactPoint", {-0.01736, -0.096796602}, 1}, {"ImpactPoint", {0, -0.0982906}, 1}, {}, {"ImpactPoint", 1, "Limit0109", 1, {0, -0.0196581}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {0.014, -0.0137607}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {"+ 0.02", 0}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {0.014, 0.0137607}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {0, 0.0196581}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {-0.014, 0.0137607}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {"- 0.02", 0}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {-0.014, -0.0137607}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {0, -0.0196581}, 1}, {}, {"VelocityVector", 0.001, "ImpactPoint", 1, "Limit0109", 1, {0, 0}, 1}, {"VelocityVector", 1, "Limit0109", 1, {0, 0}, 1}};
                                };
                                class Distance {
                                    type = "text";
                                    source = "ImpactDistance";
                                    sourceScale = 0.001;
                                    sourcePrecision = 2;
                                    max = 99;
                                    align = "center";
                                    scale = 1;
                                    pos[] = {"ImpactPoint", {-0.0020000001, 0.11}, 1};
                                    right[] = {"ImpactPoint", {0.045000002, 0.11}, 1};
                                    down[] = {"ImpactPoint", {-0.0020000001, 0.15000001}, 1};
                                };
                            };
                            class AAMissile {
                                condition = "AAmissile";
                                class Circle {
                                    type = "line";
                                    width = 4;
                                    points[] = {{"ForwardVector", 1, "HUDCenter", {0, -0.245726}, 1}, {"ForwardVector", 1, "HUDCenter", {0.0434, -0.241991}, 1}, {"ForwardVector", 1, "HUDCenter", {0.0855, -0.230909}, 1}, {"ForwardVector", 1, "HUDCenter", {0.125, -0.212799}, 1}, {"ForwardVector", 1, "HUDCenter", {0.1607, -0.188226}, 1}, {"ForwardVector", 1, "HUDCenter", {0.1915, -0.157953}, 1}, {"ForwardVector", 1, "HUDCenter", {0.2165, -0.122863}, 1}, {"ForwardVector", 1, "HUDCenter", {0.234925, -0.0840385}, 1}, {"ForwardVector", 1, "HUDCenter", {0.2462, -0.0426581}, 1}, {"ForwardVector", 1, "HUDCenter", {0.25, 0}, 1}, {"ForwardVector", 1, "HUDCenter", {0.2462, 0.0426581}, 1}, {"ForwardVector", 1, "HUDCenter", {0.234925, 0.0840385}, 1}, {"ForwardVector", 1, "HUDCenter", {0.2165, 0.122863}, 1}, {"ForwardVector", 1, "HUDCenter", {0.1915, 0.157953}, 1}, {"ForwardVector", 1, "HUDCenter", {0.1607, 0.188226}, 1}, {"ForwardVector", 1, "HUDCenter", {0.125, 0.212799}, 1}, {"ForwardVector", 1, "HUDCenter", {0.0855, 0.230909}, 1}, {"ForwardVector", 1, "HUDCenter", {0.0434, 0.241991}, 1}, {"ForwardVector", 1, "HUDCenter", {0, 0.245726}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.0434, 0.241991}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.0855, 0.230909}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.125, 0.212799}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.1607, 0.188226}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.1915, 0.157953}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.2165, 0.122863}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.234925, 0.0840385}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.2462, 0.0426581}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.25, 0}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.2462, -0.0426581}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.234925, -0.0840385}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.2165, -0.122863}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.1915, -0.157953}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.1607, -0.188226}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.125, -0.212799}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.0855, -0.230909}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.0434, -0.241991}, 1}, {"ForwardVector", 1, "HUDCenter", {0, -0.245726}, 1}};
                                };
                                class Lines {
                                    type = "line";
                                    width = 4;
                                    points[] = {{{0.21, 0.55}, 1}, {{0.19, 0.55}, 1}, {{0.19, 0.71}, 1}, {{0.21, 0.71}, 1}, {}, {{0.21, 0.67}, 1}, {{0.19, 0.67}, 1}, {}, {{0.21, 0.63}, 1}, {{0.19, 0.63}, 1}, {}, {{0.21, 0.59}, 1}, {{0.19, 0.59}, 1}, {}, {"LarTargetDist", -0.16, {0.17, 0.73}, 1}, {"LarTargetDist", -0.16, {0.19, 0.71}, 1}, {"LarTargetDist", -0.16, {0.17, 0.69}, 1}, {}};
                                };
                                class Poly {
                                    type = "polygon";
                                    points[] = {{{"LarAmmoMin", -0.16, {0.191, 0.71}, 1}, {"LarAmmoMax", -0.16, {0.191, 0.71}, 1}, {"LarAmmoMax", -0.16, {0.208, 0.71}, 1}, {"LarAmmoMin", -0.16, {0.208, 0.71}, 1}}};
                                };
                                class TopText {
                                    type = "text";
                                    source = "LarTop";
                                    sourceScale = 0.001;
                                    scale = 1;
                                    pos[] = {{0.22, 0.53}, 1};
                                    right[] = {{0.26, 0.53}, 1};
                                    down[] = {{0.22, 0.57}, 1};
                                    align = "right";
                                };
                                class MiddleText : TopText {
                                    source = "LarTop";
                                    sourcePrecision = -1;
                                    sourceScale = 0.0005;
                                    pos[] = {{0.22, 0.61}, 1};
                                    right[] = {{0.26, 0.61}, 1};
                                    down[] = {{0.22, 0.65}, 1};
                                };
                                class SpeedText : TopText {
                                    source = "LarTargetSpeed";
                                    align = "left";
                                    sourceScale = 3.6;
                                    pos[] = {"LarTargetDist", -0.16, {0.16, 0.69}, 1};
                                    right[] = {"LarTargetDist", -0.16, {0.2, 0.69}, 1};
                                    down[] = {"LarTargetDist", -0.16, {0.16, 0.73}, 1};
                                };
                            };
                            class ATMissile {
                                condition = "ATmissile";
                                class Circle {
                                    type = "line";
                                    width = 4;
                                    points[] = {{"ForwardVector", 1, "HUDCenter", {-0.15, -0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.15, -0.127778}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {-0.15, 0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.15, 0.127778}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {0.15, -0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {0.15, -0.127778}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {0.15, 0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {0.15, 0.127778}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {-0.15, -0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.13, -0.147436}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {-0.15, 0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.13, 0.147436}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {0.15, -0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {0.13, -0.147436}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {0.15, 0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {0.13, 0.147436}, 1}};
                                };
                                class Lines {
                                    type = "line";
                                    width = 4;
                                    points[] = {{{0.21, 0.55}, 1}, {{0.19, 0.55}, 1}, {{0.19, 0.71}, 1}, {{0.21, 0.71}, 1}, {}, {{0.21, 0.67}, 1}, {{0.19, 0.67}, 1}, {}, {{0.21, 0.63}, 1}, {{0.19, 0.63}, 1}, {}, {{0.21, 0.59}, 1}, {{0.19, 0.59}, 1}, {}, {"LarTargetDist", -0.16, {0.17, 0.73}, 1}, {"LarTargetDist", -0.16, {0.19, 0.71}, 1}, {"LarTargetDist", -0.16, {0.17, 0.69}, 1}, {}};
                                };
                                class Poly {
                                    type = "polygon";
                                    points[] = {{{"LarAmmoMin", -0.16, {0.191, 0.71}, 1}, {"LarAmmoMax", -0.16, {0.191, 0.71}, 1}, {"LarAmmoMax", -0.16, {0.208, 0.71}, 1}, {"LarAmmoMin", -0.16, {0.208, 0.71}, 1}}};
                                };
                                class TopText {
                                    type = "text";
                                    source = "LarTop";
                                    sourceScale = 0.001;
                                    scale = 1;
                                    pos[] = {{0.22, 0.53}, 1};
                                    right[] = {{0.26, 0.53}, 1};
                                    down[] = {{0.22, 0.57}, 1};
                                    align = "right";
                                };
                                class MiddleText : TopText {
                                    source = "LarTop";
                                    sourcePrecision = -1;
                                    sourceScale = 0.0005;
                                    pos[] = {{0.22, 0.61}, 1};
                                    right[] = {{0.26, 0.61}, 1};
                                    down[] = {{0.22, 0.65}, 1};
                                };
                                class SpeedText : TopText {
                                    source = "LarTargetSpeed";
                                    align = "left";
                                    sourceScale = 3.6;
                                    pos[] = {"LarTargetDist", -0.16, {0.16, 0.69}, 1};
                                    right[] = {"LarTargetDist", -0.16, {0.2, 0.69}, 1};
                                    down[] = {"LarTargetDist", -0.16, {0.16, 0.73}, 1};
                                };
                            };
                            class WP {
                                condition = "wpvalid";
                                class WPdist {
                                    type = "text";
                                    source = "wpdist";
                                    sourceScale = 0.001;
                                    sourcePrecision = 2;
                                    align = "left";
                                    scale = 1;
                                    pos[] = {{0.235, 0.774038}, 1};
                                    right[] = {{0.275, 0.774038}, 1};
                                    down[] = {{0.235, 0.80156}, 1};
                                };
                                class WPIndex {
                                    type = "text";
                                    source = "wpIndex";
                                    sourceScale = 1;
                                    sourceLength = 2;
                                    align = "right";
                                    scale = 1;
                                    pos[] = {{0.096, 0.776004}, 1};
                                    right[] = {{0.126, 0.776004}, 1};
                                    down[] = {{0.096, 0.799594}, 1};
                                };
                                class WPstatic {
                                    type = "text";
                                    source = "static";
                                    text = "W";
                                    scale = 1;
                                    sourceScale = 1;
                                    align = "right";
                                    pos[] = {{0.075, 0.775}, 1};
                                    right[] = {{0.105, 0.775}, 1};
                                    down[] = {{0.075, 0.8}, 1};
                                };
                                class WPKM {
                                    type = "text";
                                    source = "static";
                                    text = "KM";
                                    scale = 1;
                                    sourceScale = 1;
                                    align = "right";
                                    pos[] = {{"0.075 +0.16", 0.775}, 1};
                                    right[] = {{0.265, 0.775}, 1};
                                    down[] = {{"0.075 +0.16", 0.803}, 1};
                                };
                                class WP {
                                    width = 2;
                                    type = "line";
                                    points[] = {{"WPPoint", 1, "LimitWaypoint", 1, {-0.02, 0.04}, 1}, {"WPPoint", 1, "LimitWaypoint", 1, {0, 0.02}, 1}, {"WPPoint", 1, "LimitWaypoint", 1, {0.02, 0.04}, 1}, {}};
                                };
                            };
                            class WeaponsLocking {
                                condition = "missilelocking";
                                blinkingPattern[] = {0.2, 0.2};
                                blinkingStartsOn = 1;
                                class shape {
                                    type = "line";
                                    width = 4;
                                    points[] = {{"Target", 1, "Limit0109", 1, {0, -0.0294872}, 1}, {"Target", 1, "Limit0109", 1, {0.029999999, 0}, 1}, {"Target", 1, "Limit0109", 1, {0, 0.0294872}, 1}, {"Target", 1, "Limit0109", 1, {-0.029999999, 0}, 1}, {"Target", 1, "Limit0109", 1, {0, -0.0294872}, 1}};
                                };
                            };
                            class IncomingMissile {
                                condition = "incomingmissile";
                                blinkingPattern[] = {0.3, 0.3};
                                blinkingStartsOn = 1;
                                class Text {
                                    type = "text";
                                    source = "static";
                                    text = "!INCOMING MISSILE!";
                                    align = "center";
                                    scale = 1;
                                    pos[] = {{0.485, 0.216239}, 1};
                                    right[] = {{0.545, 0.216239}, 1};
                                    down[] = {{0.485, 0.265385}, 1};
                                };
                            };
                            class RadarTargets {
                                class RadarBoxes {
                                    type = "radartoview";
                                    pos0[] = {0.5, 0.5};
                                    pos10[] = {0.734, 0.73};
                                    width = 4;
                                    points[] = {{{-0.0035, -0.00344017}, 1}, {{0.0035, -0.00344017}, 1}, {{0.0035, 0.00344017}, 1}, {{-0.0035, 0.00344017}, 1}, {{-0.0035, -0.00344017}, 1}};
                                };
                            };
                            class TargetDiamond {
                                class shape {
                                    type = "line";
                                    width = 4;
                                    points[] = {{"Target", 1, "Limit0109", 1, {0.02, 0.0196581}, 1}, {"Target", 1, "Limit0109", 1, {-0.02, 0.0196581}, 1}, {"Target", 1, "Limit0109", 1, {-0.02, -0.0196581}, 1}, {"Target", 1, "Limit0109", 1, {0.02, -0.0196581}, 1}, {"Target", 1, "Limit0109", 1, {0.02, 0.0196581}, 1}};
                                };
                            };
                            class TargetLocked {
                                condition = "missilelocked";
                                class shape {
                                    type = "line";
                                    width = 4;
                                    points[] = {{"Target", 1, "Limit0109", 1, {0, -0.0294872}, 1}, {"Target", 1, "Limit0109", 1, {0.029999999, 0}, 1}, {"Target", 1, "Limit0109", 1, {0, 0.0294872}, 1}, {"Target", 1, "Limit0109", 1, {-0.029999999, 0}, 1}, {"Target", 1, "Limit0109", 1, {0, -0.0294872}, 1}};
                                };
                                class TimeOfFlightText {
                                    type = "text";
                                    source = "static";
                                    text = "TOF:";
                                    scale = 1;
                                    sourceScale = 1;
                                    align = "right";
                                    pos[] = {{"0.127+0.49", 0.869}, 1};
                                    right[] = {{0.652, 0.869}, 1};
                                    down[] = {{"0.127+0.49", 0.904}, 1};
                                };
                                class TOF_source {
                                    type = "text";
                                    scale = 1;
                                    sourceScale = 1;
                                    source = "missileflighttime";
                                    align = "right";
                                    pos[] = {{0.739, 0.869}, 1};
                                    right[] = {{0.774, 0.869}, 1};
                                    down[] = {{0.739, 0.904}, 1};
                                };
                            };
                            class TargetDist {
                                class DistanceText {
                                    type = "text";
                                    source = "static";
                                    text = "DIST:";
                                    scale = 1;
                                    sourceScale = 1;
                                    align = "right";
                                    pos[] = {{"0.125+0.49", 0.901}, 1};
                                    right[] = {{0.65, 0.901}, 1};
                                    down[] = {{"0.125+0.49", 0.936}, 1};
                                };
                                class TargetDistance {
                                    type = "text";
                                    scale = 1;
                                    source = "targetDist";
                                    sourceLength = 0;
                                    sourcePrecision = 2;
                                    sourceScale = 0.001;
                                    align = "right";
                                    pos[] = {{0.739, 0.901}, 1};
                                    right[] = {{0.774, 0.901}, 1};
                                    down[] = {{0.739, 0.936}, 1};
                                };
                            };
                        };
                    };
                    class HMD_CMPilot : AirplaneHUD {
                        turret[] = {-1};
                        class Draw {
                            alpha = "user3";
                            color[] = {"user0", "user1", "user2"};
                            condition = "on";
                            class cmWeapons {
                                type = "text";
                                source = "cmweapon";
                                sourceScale = 1;
                                align = "right";
                                scale = 0.5;
                                pos[] = {{0.001, 0.869}, 1};
                                right[] = {{0.036, 0.869}, 1};
                                down[] = {{0.001, 0.904}, 1};
                            };
                            class cmAmmo {
                                type = "text";
                                source = "cmammo";
                                sourceScale = 1;
                                align = "right";
                                scale = 0.5;
                                pos[] = {{0.001, 0.901}, 1};
                                right[] = {{0.036, 0.901}, 1};
                                down[] = {{0.001, 0.936}, 1};
                            };
                        };
                    };
                };
            };
        };
        class MFD {
            class AirplaneHUD {
                enableParallax = 0;
                topLeft = "HUD_top_left";
                topRight = "HUD_top_right";
                bottomLeft = "HUD_bottom_left";
                borderLeft = 0;
                borderRight = 0;
                borderTop = 0;
                borderBottom = 0;
                color[] = {1, 1, 1, 1};
                helmetMountedDisplay = 1;
                helmetPosition[] = {-0.0375, 0.0375, 0.1};
                helmetRight[] = {0.075, 0, 0};
                helmetDown[] = {0, -0.075, 0};
                font = "LucidaConsoleB";
                turret[] = {-2};
                class Bones {
                    class HUDCenter {
                        type = "fixed";
                        pos[] = {0.5, 0.5};
                    };
                    class WeaponAim {
                        type = "vector";
                        source = "weapon";
                        pos0[] = {0.5, 0.5};
                        pos10[] = {0.734, 0.73};
                    };
                    class WeaponAimRelative : WeaponAim {
                        source = "weapontoview";
                    };
                    class VelocityVector {
                        type = "vector";
                        source = "velocityToView";
                        pos0[] = {0.5, 0.5};
                        pos10[] = {0.734, 0.73};
                    };
                    class ForwardVector {
                        type = "vector";
                        source = "forward";
                        pos0[] = {0, 0};
                        pos10[] = {0.234, 0.23};
                    };
                    class HorizonVector {
                        type = "horizontoview";
                        pos0[] = {0.5, 0.5};
                        pos10[] = {0.830923, 0.825266};
                        angle = 0;
                    };
                    class GunnerAim {
                        type = "vector";
                        source = "turret";
                        pos0[] = {0, -2};
                        pos10[] = {0.0068, -0.01};
                        projection = 0;
                    };
                    class VerticalSpeedBone {
                        type = "linear";
                        source = "vspeed";
                        sourceScale = 1;
                        min = -10;
                        max = 10;
                        minPos[] = {0, -0.32};
                        maxPos[] = {0, 0.32};
                    };
                    class HorizonBankRot {
                        type = "linear";
                        source = "horizonBank";
                        min = -0.5236;
                        max = 0.5236;
                        minPos[] = {0.41, 0.84};
                        maxPos[] = {0.59, 0.84};
                        aspectRatio = 1;
                    };
                    class ImpactPoint {
                        type = "vector";
                        source = "ImpactPointToView";
                        pos[] = {};
                        pos0[] = {0.5, 0.5};
                        pos10[] = {0.734, 0.73};
                    };
                    class Target {
                        source = "targettoview";
                        type = "vector";
                        pos0[] = {0.5, 0.5};
                        pos10[] = {0.734, 0.73};
                    };
                    class Limit0109 {
                        type = "limit";
                        limits[] = {0.1, 0.1, 0.9, 0.9};
                    };
                    class LimitWaypoint {
                        type = "limit";
                        limits[] = {0.2, 0.1, 0.8, 0.1};
                    };
                    class WPPoint {
                        type = "vector";
                        source = "WPPoint";
                        pos0[] = {0.5, 0.5};
                        pos10[] = {0.734, 0.73};
                    };
                    class WPPointToView : WPPoint {
                        source = "WPPointToView";
                    };
                    class RadarHeight {
                        type = "linear";
                        source = "altitudeAGL";
                        sourceScale = 1;
                        sourceOffset = -2;
                        min = 0;
                        max = 100;
                        minPos[] = {0.903, 0.18};
                        maxPos[] = {0.903, 0.82};
                    };
                    class HorizonBankRotFull {
                        type = "rotational";
                        source = "horizonBank";
                        center[] = {0, 0};
                        min = -3.1416;
                        max = 3.1416;
                        minAngle = -180;
                        maxAngle = 180;
                        aspectRatio = 1;
                    };
                    class LarAmmoMax {
                        type = "linear";
                        source = "LarAmmoMax";
                        sourceScale = 1;
                        min = 0;
                        max = 1;
                        minPos[] = {0, 1};
                        maxPos[] = {0, 0};
                    };
                    class LarAmmoMin : LarAmmoMax {
                        source = "LarAmmoMin";
                    };
                    class LarTargetDist : LarAmmoMax {
                        source = "LarTargetDist";
                    };
                    class MissileFlightTimeRot1 {
                        type = "rotational";
                        source = "MissileFlightTime";
                        sourceScale = 0.46000001;
                        center[] = {0, 0};
                        min = 0;
                        max = 0.5;
                        minAngle = 0;
                        maxAngle = 18;
                        aspectRatio = 0.98290598;
                    };
                    class MissileFlightTimeRot2 : MissileFlightTimeRot1 {
                        maxAngle = 36;
                        max = 1;
                    };
                    class MissileFlightTimeRot3 : MissileFlightTimeRot1 {
                        maxAngle = 54;
                        max = 1.5;
                    };
                    class MissileFlightTimeRot4 : MissileFlightTimeRot1 {
                        maxAngle = 72;
                        max = 2;
                    };
                    class MissileFlightTimeRot5 : MissileFlightTimeRot1 {
                        maxAngle = 90;
                        max = 2.5;
                    };
                    class MissileFlightTimeRot6 : MissileFlightTimeRot1 {
                        maxAngle = 108;
                        max = 3;
                    };
                    class MissileFlightTimeRot7 : MissileFlightTimeRot1 {
                        maxAngle = 126;
                        max = 3.5;
                    };
                    class MissileFlightTimeRot8 : MissileFlightTimeRot1 {
                        maxAngle = 144;
                        max = 4;
                    };
                    class MissileFlightTimeRot9 : MissileFlightTimeRot1 {
                        maxAngle = 162;
                        max = 4.5;
                    };
                    class MissileFlightTimeRot10 : MissileFlightTimeRot1 {
                        maxAngle = 180;
                        max = 5;
                    };
                    class MissileFlightTimeRot11 : MissileFlightTimeRot1 {
                        maxAngle = 198;
                        max = 5.5;
                    };
                    class MissileFlightTimeRot12 : MissileFlightTimeRot1 {
                        maxAngle = 216;
                        max = 6;
                    };
                    class MissileFlightTimeRot13 : MissileFlightTimeRot1 {
                        maxAngle = 234;
                        max = 6.5;
                    };
                    class MissileFlightTimeRot14 : MissileFlightTimeRot1 {
                        maxAngle = 252;
                        max = 7;
                    };
                    class MissileFlightTimeRot15 : MissileFlightTimeRot1 {
                        maxAngle = 270;
                        max = 7.5;
                    };
                    class MissileFlightTimeRot16 : MissileFlightTimeRot1 {
                        maxAngle = 288;
                        max = 8;
                    };
                    class MissileFlightTimeRot17 : MissileFlightTimeRot1 {
                        maxAngle = 306;
                        max = 8.5;
                    };
                    class MissileFlightTimeRot18 : MissileFlightTimeRot1 {
                        maxAngle = 324;
                        max = 9;
                    };
                    class MissileFlightTimeRot19 : MissileFlightTimeRot1 {
                        maxAngle = 342;
                        max = 9.5;
                    };
                    class MissileFlightTimeRot20 : MissileFlightTimeRot1 {
                        maxAngle = 360;
                        max = 10;
                    };
                };
                class Draw {
                    alpha = "user3";
                    color[] = {"user0", "user1", "user2"};
                    condition = "on";
                    delete ImpactCross;
                    class Static {
                        type = "line";
                        width = 4;
                        points[] = {{{0.5, 0.11}, 1}, {{0.5, 0.14}, 1}, {}, {{0.4, 0.86}, 1}, {{0.4, 0.94}, 1}, {{0.6, 0.94}, 1}, {{0.6, 0.86}, 1}, {{0.4, 0.86}, 1}, {}, {{0.4, 0.885}, 1}, {{0.408, 0.885}, 1}, {}, {{0.6, 0.885}, 1}, {{0.592, 0.885}, 1}, {}, {{0.5, 0.86}, 1}, {{0.5, 0.868}, 1}, {}, {{0.5, 0.94}, 1}, {{0.5, 0.932}, 1}, {}, {{0.52, 0.86}, 1}, {{0.52, 0.82}, 1}, {}, {{0.48, 0.86}, 1}, {{0.48, 0.82}, 1}, {}, {{0.55, 0}, 1}, {{0.55, 0.04}, 1}, {{0.45, 0.04}, 1}, {{0.45, 0}, 1}, {{0.55, 0}, 1}};
                    };
                    class HeadingNumber {
                        type = "text";
                        source = "Heading";
                        sourceScale = 1;
                        align = "center";
                        scale = 1;
                        pos[] = {{0.5, 0.006}, 1};
                        right[] = {{0.55, 0.006}, 1};
                        down[] = {{0.5, 0.046}, 1};
                    };
                    class HeadingRotation {
                        condition = "abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)-5";
                        class HeadingHeadNumber {
                            type = "text";
                            source = "cameraDir";
                            sourceScale = 1;
                            align = "center";
                            scale = 1;
                            pos[] = {{"0.80-0.302", "0.082-0.025"}, 1};
                            right[] = {{"0.83-0.302", "0.082-0.025"}, 1};
                            down[] = {{"0.80-0.302", "0.113-0.025"}, 1};
                        };
                        class HeadingArrow {
                            type = "line";
                            width = 3;
                            points[] = {{{0.478, 0.045}, 1}, {{0.522, 0.045}, 1}, {{0.552, 0.07}, 1}, {{0.522, 0.095}, 1}, {{0.478, 0.095}, 1}, {{0.448, 0.07}, 1}, {{0.478, 0.045}, 1}, {}};
                        };
                        class HeadingScaleRight {
                            clipTL[] = {0.55, 0.05};
                            clipBR[] = {0.83, 0.11};
                            class lines {
                                type = "scale";
                                horizontal = 1;
                                source = "heading";
                                sourceScale = 1;
                                width = 4;
                                top = 0.5;
                                center = 0.5;
                                bottom = 0.85;
                                lineXleft = 0.11;
                                lineYright = 0.1;
                                lineXleftMajor = 0.11;
                                lineYrightMajor = 0.09;
                                majorLineEach = 2;
                                numberEach = 2;
                                step = 22.5;
                                stepSize = 0.075;
                                align = "center";
                                scale = 1;
                                pos[] = {0.496, 0.05};
                                right[] = {0.536, 0.05};
                                down[] = {0.496, 0.09};
                            };
                        };
                        class HeadingScaleMidle {
                            type = "scale";
                            horizontal = 1;
                            source = "heading";
                            sourceScale = 1;
                            width = 4;
                            top = 0.45;
                            center = 0.5;
                            bottom = 0.55;
                            lineXleft = 0.11;
                            lineYright = 0.1;
                            lineXleftMajor = 0.11;
                            lineYrightMajor = 0.1;
                            majorLineEach = 2;
                            step = 22.5;
                            stepSize = 0.075;
                            align = "center";
                            scale = 1;
                            numberEach = 0;
                            pos[] = {0.47, 0.05};
                            right[] = {0.5, 0.05};
                            down[] = {0.45, 0.09};
                        };
                        class HeadingScaleLeft {
                            clipTL[] = {0.18, 0.05};
                            clipBR[] = {0.45, 0.11};
                            class lines {
                                type = "scale";
                                horizontal = 1;
                                source = "heading";
                                sourceScale = 1;
                                width = 4;
                                top = 0.15;
                                center = 0.5;
                                bottom = 0.55;
                                lineXleft = 0.11;
                                lineYright = 0.1;
                                lineXleftMajor = 0.11;
                                lineYrightMajor = 0.09;
                                majorLineEach = 2;
                                numberEach = 2;
                                step = 22.5;
                                stepSize = 0.075;
                                align = "center";
                                scale = 1;
                                pos[] = {0.146, 0.05};
                                right[] = {0.186, 0.05};
                                down[] = {0.146, 0.09};
                            };
                        };
                    };
                    class HeadingScaleFull {
                        condition = "4-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)";
                        class HeadingScale {
                            clipTL[] = {0.18, 0};
                            clipBR[] = {0.83, 1};
                            class lines {
                                type = "scale";
                                horizontal = 1;
                                source = "heading";
                                sourceScale = 1;
                                width = 4;
                                top = 0.15;
                                center = 0.5;
                                bottom = 0.85;
                                lineXleft = 0.11;
                                lineYright = 0.1;
                                lineXleftMajor = 0.11;
                                lineYrightMajor = 0.09;
                                majorLineEach = 2;
                                numberEach = 2;
                                step = 22.5;
                                stepSize = 0.075;
                                align = "center";
                                scale = 1;
                                pos[] = {0.146, 0.05};
                                right[] = {0.186, 0.05};
                                down[] = {0.146, 0.09};
                            };
                        };
                    };
                    class HorizonBankRot {
                        type = "polygon";
                        width = 4;
                        points[] = {{{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.00260472, -0.0145196}, 1}, {"HorizonBankRot", {0.0051303, -0.0138544}, 1}, {"HorizonBankRot", {0.0075, -0.0127683}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.0075, -0.0127683}, 1}, {"HorizonBankRot", {0.00964181, -0.0112942}, 1}, {"HorizonBankRot", {0.0114907, -0.009477}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.0114907, -0.009477}, 1}, {"HorizonBankRot", {0.0129904, -0.00737179}, 1}, {"HorizonBankRot", {0.0140954, -0.0050426}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.0140954, -0.0050426}, 1}, {"HorizonBankRot", {0.0147721, -0.0025602}, 1}, {"HorizonBankRot", {0.015, 6.44463e-10}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.015, 6.44463e-10}, 1}, {"HorizonBankRot", {0.0147721, 0.0025602}, 1}, {"HorizonBankRot", {0.0140954, 0.0050426}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.0140954, 0.0050426}, 1}, {"HorizonBankRot", {0.0129904, 0.0073718}, 1}, {"HorizonBankRot", {0.0114907, 0.009477}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.0114907, 0.009477}, 1}, {"HorizonBankRot", {0.00964181, 0.0112942}, 1}, {"HorizonBankRot", {0.0075, 0.0127683}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.0075, 0.0127683}, 1}, {"HorizonBankRot", {0.0051303, 0.0138544}, 1}, {"HorizonBankRot", {0.00260472, 0.0145196}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {0.00260472, 0.0145196}, 1}, {"HorizonBankRot", {-1.31134e-09, 0.0147436}, 1}, {"HorizonBankRot", {-0.00260473, 0.0145196}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.00260473, 0.0145196}, 1}, {"HorizonBankRot", {-0.0051303, 0.0138544}, 1}, {"HorizonBankRot", {-0.0075, 0.0127683}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.0075, 0.0127683}, 1}, {"HorizonBankRot", {-0.00964181, 0.0112942}, 1}, {"HorizonBankRot", {-0.0114907, 0.009477}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.0114907, 0.009477}, 1}, {"HorizonBankRot", {-0.0129904, 0.00737179}, 1}, {"HorizonBankRot", {-0.0140954, 0.0050426}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.0140954, 0.0050426}, 1}, {"HorizonBankRot", {-0.0147721, 0.0025602}, 1}, {"HorizonBankRot", {-0.015, -1.75816e-10}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.015, -1.75816e-10}, 1}, {"HorizonBankRot", {-0.0147721, -0.0025602}, 1}, {"HorizonBankRot", {-0.0140954, -0.0050426}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.0140954, -0.0050426}, 1}, {"HorizonBankRot", {-0.0129904, -0.0073718}, 1}, {"HorizonBankRot", {-0.0114907, -0.009477}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.0114907, -0.009477}, 1}, {"HorizonBankRot", {-0.00964181, -0.0112942}, 1}, {"HorizonBankRot", {-0.0075, -0.0127683}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.0075, -0.0127683}, 1}, {"HorizonBankRot", {-0.00513031, -0.0138544}, 1}, {"HorizonBankRot", {-0.00260472, -0.0145196}, 1}}, {{"HorizonBankRot", 1, {0, 0}, 1}, {"HorizonBankRot", {-0.00260472, -0.0145196}, 1}, {"HorizonBankRot", {2.62268e-09, -0.0147436}, 1}, {"HorizonBankRot", {0.00260472, -0.0145196}, 1}}};
                    };
                    class CollectiveGroup {
                        condition = "simulRTD";
                        class CollectiveText {
                            type = "text";
                            source = "static";
                            text = "%";
                            align = "right";
                            scale = 1;
                            pos[] = {{0.22, 0.2}, 1};
                            right[] = {{0.28, 0.2}, 1};
                            down[] = {{0.22, 0.24}, 1};
                        };
                        class CollectiveNumber {
                            type = "text";
                            source = "rtdCollective";
                            sourceScale = 100;
                            align = "left";
                            scale = 1;
                            pos[] = {{0.22, 0.2}, 1};
                            right[] = {{0.28, 0.2}, 1};
                            down[] = {{0.22, 0.24}, 1};
                        };
                    };
                    class SpeedNumber {
                        type = "text";
                        source = "speed";
                        sourceScale = 3.6;
                        align = "right";
                        scale = 1;
                        pos[] = {{0.16, 0.48}, 1};
                        right[] = {{0.22, 0.48}, 1};
                        down[] = {{0.16, 0.52}, 1};
                    };
                    class AltNumber {
                        type = "text";
                        source = "altitudeAGL";
                        sourceScale = 1;
                        sourceOffset = -2;
                        align = "left";
                        scale = 1;
                        pos[] = {{0.81, 0.48}, 1};
                        right[] = {{0.87, 0.48}, 1};
                        down[] = {{0.81, 0.52}, 1};
                    };
                    class HoverMode {
                        condition = "autohover";
                        class HoverText {
                            type = "text";
                            source = "static";
                            text = "HOVER";
                            scale = 1;
                            sourceScale = 1;
                            align = "right";
                            pos[] = {{0.005, 0.075}, 1};
                            right[] = {{0.045, 0.075}, 1};
                            down[] = {{0.005, 0.11}, 1};
                        };
                    };
                    class CruiseMode {
                        condition = "((altitudeASL-27) min 1) - autohover";
                        class CruiseText {
                            type = "text";
                            source = "static";
                            text = "CRUISE";
                            scale = 1;
                            sourceScale = 1;
                            align = "right";
                            pos[] = {{0.005, 0.075}, 1};
                            right[] = {{0.045, 0.075}, 1};
                            down[] = {{0.005, 0.11}, 1};
                        };
                        class AltNumberASL {
                            type = "text";
                            source = "altitudeASL";
                            sourceScale = 1;
                            align = "left";
                            scale = 1;
                            pos[] = {{0.81, 0.16}, 1};
                            right[] = {{0.87, 0.16}, 1};
                            down[] = {{0.81, 0.2}, 1};
                        };
                    };
                    class TransitionMode {
                        condition = "((27-altitudeASL) min 1) - autohover";
                        class TransText {
                            type = "text";
                            source = "static";
                            text = "TRANS";
                            scale = 1;
                            sourceScale = 1;
                            align = "right";
                            pos[] = {{0.005, 0.075}, 1};
                            right[] = {{0.045, 0.075}, 1};
                            down[] = {{0.005, 0.11}, 1};
                        };
                    };
                    class HoverModeHide {
                        condition = "1-autohover";
                        class VelocityLine {
                            type = "line";
                            width = 4;
                            points[] = {{"VelocityVector", {0, -0.0196581}, 1}, {"VelocityVector", {0.01, -0.0170239}, 1}, {"VelocityVector", {0.01732, -0.00982906}, 1}, {"VelocityVector", {0.02, 0}, 1}, {"VelocityVector", {0.01732, 0.00982906}, 1}, {"VelocityVector", {0.01, 0.0170239}, 1}, {"VelocityVector", {0, 0.0196581}, 1}, {"VelocityVector", {-0.01, 0.0170239}, 1}, {"VelocityVector", {-0.01732, 0.00982906}, 1}, {"VelocityVector", {-0.02, 0}, 1}, {"VelocityVector", {-0.01732, -0.00982906}, 1}, {"VelocityVector", {-0.01, -0.0170239}, 1}, {"VelocityVector", {0, -0.0196581}, 1}, {}, {"VelocityVector", {0.04, 0}, 1}, {"VelocityVector", {0.02, 0}, 1}, {}, {"VelocityVector", {-0.04, 0}, 1}, {"VelocityVector", {-0.02, 0}, 1}, {}, {"VelocityVector", {0, -0.0393162}, 1}, {"VelocityVector", {0, -0.0196581}, 1}, {}};
                        };
                    };
                    class GearGroup {
                        type = "group";
                        condition = "ils";
                        class GearText {
                            type = "text";
                            source = "static";
                            text = "GEAR";
                            align = "right";
                            scale = 1;
                            pos[] = {{0.015, 0.334188}, 1};
                            right[] = {{0.055, 0.334188}, 1};
                            down[] = {{0.015, 0.363675}, 1};
                        };
                    };
                    class LaserGroup {
                        condition = "laseron";
                        class laserText {
                            type = "text";
                            source = "static";
                            text = "LASER";
                            scale = 1;
                            sourceScale = 1;
                            align = "right";
                            pos[] = {{0.015, 0.37}, 1};
                            right[] = {{0.055, 0.37}, 1};
                            down[] = {{0.015, 0.405}, 1};
                        };
                    };
                    class RadarGroup {
                        condition = "activeSensorsOn";
                        class radarText {
                            type = "text";
                            source = "static";
                            text = "RADAR";
                            scale = 1;
                            sourceScale = 1;
                            align = "right";
                            pos[] = {{0.015, 0.41}, 1};
                            right[] = {{0.055, 0.41}, 1};
                            down[] = {{0.015, 0.445}, 1};
                        };
                    };
                    class VerticalSpeedScale {
                        type = "line";
                        width = 4;
                        points[] = {{"HUDCenter", 1, {-0.03, 0}, 1}, {"HUDCenter", 1, {-0.01, 0}, 1}, {}, {"HUDCenter", 1, {0.01, 0}, 1}, {"HUDCenter", 1, {0.03, 0}, 1}, {}, {"HUDCenter", 1, {0, -0.01}, 1}, {"HUDCenter", 1, {0, -0.03}, 1}, {}, {"HUDCenter", 1, {0, 0.01}, 1}, {"HUDCenter", 1, {0, 0.03}, 1}, {}, {{0.915, 0.18}, 1}, {{0.935, 0.18}, 1}, {}, {{0.87, 0.18}, 1}, {{0.89, 0.18}, 1}, {}, {{0.915, 0.34}, 1}, {{0.935, 0.34}, 1}, {}, {{0.87, 0.34}, 1}, {{0.89, 0.34}, 1}, {}, {{0.875, 0.372}, 1}, {{0.885, 0.372}, 1}, {}, {{0.875, 0.404}, 1}, {{0.885, 0.404}, 1}, {}, {{0.875, 0.436}, 1}, {{0.885, 0.436}, 1}, {}, {{0.875, 0.468}, 1}, {{0.885, 0.468}, 1}, {}, {{0.87, 0.5}, 1}, {{0.89, 0.5}, 1}, {}, {{0.915, 0.5}, 1}, {{0.935, 0.5}, 1}, {}, {{0.915, 0.66}, 1}, {{0.935, 0.66}, 1}, {}, {{0.87, 0.66}, 1}, {{0.89, 0.66}, 1}, {}, {{0.875, 0.628}, 1}, {{0.885, 0.628}, 1}, {}, {{0.875, 0.596}, 1}, {{0.885, 0.596}, 1}, {}, {{0.875, 0.564}, 1}, {{0.885, 0.564}, 1}, {}, {{0.875, 0.532}, 1}, {{0.885, 0.532}, 1}, {}, {{0.92, 0.692}, 1}, {{0.93, 0.692}, 1}, {}, {{0.92, 0.724}, 1}, {{0.93, 0.724}, 1}, {}, {{0.92, 0.756}, 1}, {{0.93, 0.756}, 1}, {}, {{0.92, 0.788}, 1}, {{0.93, 0.788}, 1}, {}, {{0.915, 0.82}, 1}, {{0.935, 0.82}, 1}, {}, {{0.87, 0.82}, 1}, {{0.89, 0.82}, 1}, {}};
                    };
                    class GunnerAimWorld {
                        condition = "1-mgun";
                        class Cross {
                            type = "line";
                            width = 4;
                            points[] = {{"WeaponAimRelative", 1, {-0.03, 0}, 1}, {"WeaponAimRelative", 1, {-0.02, 0}, 1}, {}, {"WeaponAimRelative", 1, {0.02, 0}, 1}, {"WeaponAimRelative", 1, {0.03, 0}, 1}, {}, {"WeaponAimRelative", 1, {0, -0.02}, 1}, {"WeaponAimRelative", 1, {0, -0.03}, 1}, {}, {"WeaponAimRelative", 1, {0, 0.02}, 1}, {"WeaponAimRelative", 1, {0, 0.03}, 1}};
                        };
                    };
                    class VerticalSpeedArrow {
                        type = "polygon";
                        points[] = {{{"VerticalSpeedBone", {0.85, 0.488}, 1}, {"VerticalSpeedBone", {0.87, 0.5}, 1}, {"VerticalSpeedBone", {0.85, 0.512}, 1}}};
                    };
                    class RadarAltitude {
                        condition = "101-altitudeAGL";
                        class RadarHeight {
                            type = "line";
                            width = 15;
                            points[] = {{{0.903, 0.82}, 1}, {"RadarHeight", {0, 0}, 1}, {}};
                        };
                    };
                    class HorizonLine {
                        condition = "1-autohover";
                        clipTL[] = {0.2, 0.145};
                        clipBR[] = {0.8, 0.855};
                        class HorizonLineDraw {
                            type = "line";
                            width = 4;
                            points[] = {{"HorizonVector", {-0.225, 0}, 1}, {"HorizonVector", {-0.1875, 0}, 1}, {}, {"HorizonVector", {-0.15, 0}, 1}, {"HorizonVector", {-0.1125, 0}, 1}, {}, {"HorizonVector", {-0.075, 0}, 1}, {"HorizonVector", {-0.0375, 0}, 1}, {}, {"HorizonVector", {0.0375, 0}, 1}, {"HorizonVector", {0.075, 0}, 1}, {}, {"HorizonVector", {0.1125, 0}, 1}, {"HorizonVector", {0.15, 0}, 1}, {}, {"HorizonVector", {0.1875, 0}, 1}, {"HorizonVector", {0.225, 0}, 1}};
                        };
                    };
                    class Gunner {
                        type = "line";
                        width = 4;
                        points[] = {{"GunnerAim", {0.485, 0.892}, 1}, {"GunnerAim", {0.485, 0.908}, 1}, {"GunnerAim", {0.515, 0.908}, 1}, {"GunnerAim", {0.515, 0.892}, 1}, {"GunnerAim", {0.485, 0.892}, 1}};
                    };
                    class WeaponsText {
                        type = "text";
                        source = "weapon";
                        sourceScale = 1;
                        align = "left";
                        scale = 0.5;
                        pos[] = {{0.38, 0.869}, 1};
                        right[] = {{0.415, 0.869}, 1};
                        down[] = {{0.38, 0.904}, 1};
                    };
                    class Ammo {
                        type = "text";
                        source = "ammo";
                        sourceScale = 1;
                        align = "left";
                        scale = 0.5;
                        pos[] = {{0.38, 0.901}, 1};
                        right[] = {{0.415, 0.901}, 1};
                        down[] = {{0.38, 0.936}, 1};
                    };
                    class MGun {
                        condition = "-2+mgun*ImpactDistance";
                        class Cross {
                            type = "line";
                            width = 3;
                            points[] = {{"ImpactPoint", {0, -0.0294872}, 1}, {"ImpactPoint", {0, -0.0393162}, 1}, {}, {"ImpactPoint", {0.02, -0.024}, 1}, {"ImpactPoint", {0.025, -0.030999999}, 1}, {}, {"ImpactPoint", {0, -0.0020000001}, 1}, {"ImpactPoint", {0, 0.0020000001}, 1}, {}, {"ImpactPoint", {-0.0020000001, 0}, 1}, {"ImpactPoint", {0.0020000001, 0}, 1}, {}};
                        };
                        class Circle {
                            type = "line";
                            width = 3;
                            points[] = {{"ImpactPoint", {0, -0.0275214}, 1}, {"ImpactPoint", {0, -0.0344017}, 1}, {"MissileFlightTimeRot1", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot2", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot3", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot4", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot5", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot6", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot7", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot8", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot9", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot10", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot11", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot12", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot13", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot14", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot15", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot16", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot17", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot18", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot19", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot20", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot20", {0, 0.028000001}, 1, "ImpactPoint", 1}};
                        };
                        class Circle_Min_Range {
                            type = "line";
                            width = 3;
                            points[] = {{"ImpactPoint", {0, -0.0294872}, 1}, {"ImpactPoint", {0.0052080001, -0.029038999}, 1}, {"ImpactPoint", {0.01026, -0.0277091}, 1}, {"ImpactPoint", {0.015, -0.0255359}, 1}, {"ImpactPoint", {0.019284001, -0.022587201}, 1}, {"ImpactPoint", {0.022980001, -0.0189544}, 1}, {"ImpactPoint", {0.025979999, -0.0147436}, 1}, {"ImpactPoint", {0.028191, -0.0100846}, 1}, {"ImpactPoint", {0.029544, -0.0051189698}, 1}, {"ImpactPoint", {0.029999999, 0}, 1}, {"ImpactPoint", {0.029544, 0.0051189698}, 1}, {"ImpactPoint", {0.028191, 0.0100846}, 1}, {"ImpactPoint", {0.025979999, 0.0147436}, 1}, {"ImpactPoint", {0.022980001, 0.0189544}, 1}, {"ImpactPoint", {0.019284001, 0.022587201}, 1}, {"ImpactPoint", {0.015, 0.0255359}, 1}, {"ImpactPoint", {0.01026, 0.0277091}, 1}, {"ImpactPoint", {0.0052080001, 0.029038999}, 1}, {"ImpactPoint", {0, 0.0294872}, 1}, {"ImpactPoint", {-0.0052080001, 0.029038999}, 1}, {"ImpactPoint", {-0.01026, 0.0277091}, 1}, {"ImpactPoint", {-0.015, 0.0255359}, 1}, {"ImpactPoint", {-0.019284001, 0.022587201}, 1}, {"ImpactPoint", {-0.022980001, 0.0189544}, 1}, {"ImpactPoint", {-0.025979999, 0.0147436}, 1}, {"ImpactPoint", {-0.028191, 0.0100846}, 1}, {"ImpactPoint", {-0.029544, 0.0051189698}, 1}, {"ImpactPoint", {-0.029999999, 0}, 1}, {"ImpactPoint", {-0.029544, -0.0051189698}, 1}, {"ImpactPoint", {-0.028191, -0.0100846}, 1}, {"ImpactPoint", {-0.025979999, -0.0147436}, 1}, {"ImpactPoint", {-0.022980001, -0.0189544}, 1}, {"ImpactPoint", {-0.019284001, -0.022587201}, 1}, {"ImpactPoint", {-0.015, -0.0255359}, 1}, {"ImpactPoint", {-0.01026, -0.0277091}, 1}, {"ImpactPoint", {-0.0052080001, -0.029038999}, 1}, {"ImpactPoint", {0, -0.0294872}, 1}};
                        };
                        class Distance {
                            type = "text";
                            source = "ImpactDistance";
                            sourceScale = 0.001;
                            sourcePrecision = 2;
                            max = 99;
                            align = "center";
                            scale = 1;
                            pos[] = {"ImpactPoint", {-0.0020000001, -0.079999998}, 1};
                            right[] = {"ImpactPoint", {0.045000002, -0.079999998}, 1};
                            down[] = {"ImpactPoint", {-0.0020000001, -0.039999999}, 1};
                        };
                    };
                    class Rockets {
                        condition = "-2+rocket*ImpactDistance";
                        class Cross {
                            type = "line";
                            width = 3;
                            points[] = {{"ImpactPoint", {0, -0.0294872}, 1}, {"ImpactPoint", {0, -0.0393162}, 1}, {}, {"ImpactPoint", {0.02, -0.024}, 1}, {"ImpactPoint", {0.025, -0.030999999}, 1}, {}, {"ImpactPoint", {0, -0.0020000001}, 1}, {"ImpactPoint", {0, 0.0020000001}, 1}, {}, {"ImpactPoint", {-0.0020000001, 0}, 1}, {"ImpactPoint", {0.0020000001, 0}, 1}, {}};
                        };
                        class Circle {
                            type = "line";
                            width = 3;
                            points[] = {{"ImpactPoint", {0, -0.0275214}, 1}, {"ImpactPoint", {0, -0.0344017}, 1}, {"MissileFlightTimeRot1", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot2", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot3", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot4", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot5", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot6", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot7", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot8", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot9", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot10", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot11", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot12", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot13", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot14", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot15", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot16", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot17", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot18", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot19", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot20", {0, 0.035}, 1, "ImpactPoint", 1}, {"MissileFlightTimeRot20", {0, 0.028000001}, 1, "ImpactPoint", 1}};
                        };
                        class Circle_Min_Range {
                            type = "line";
                            width = 3;
                            points[] = {{"ImpactPoint", {0, -0.0294872}, 1}, {"ImpactPoint", {0.0052080001, -0.029038999}, 1}, {"ImpactPoint", {0.01026, -0.0277091}, 1}, {"ImpactPoint", {0.015, -0.0255359}, 1}, {"ImpactPoint", {0.019284001, -0.022587201}, 1}, {"ImpactPoint", {0.022980001, -0.0189544}, 1}, {"ImpactPoint", {0.025979999, -0.0147436}, 1}, {"ImpactPoint", {0.028191, -0.0100846}, 1}, {"ImpactPoint", {0.029544, -0.0051189698}, 1}, {"ImpactPoint", {0.029999999, 0}, 1}, {"ImpactPoint", {0.029544, 0.0051189698}, 1}, {"ImpactPoint", {0.028191, 0.0100846}, 1}, {"ImpactPoint", {0.025979999, 0.0147436}, 1}, {"ImpactPoint", {0.022980001, 0.0189544}, 1}, {"ImpactPoint", {0.019284001, 0.022587201}, 1}, {"ImpactPoint", {0.015, 0.0255359}, 1}, {"ImpactPoint", {0.01026, 0.0277091}, 1}, {"ImpactPoint", {0.0052080001, 0.029038999}, 1}, {"ImpactPoint", {0, 0.0294872}, 1}, {"ImpactPoint", {-0.0052080001, 0.029038999}, 1}, {"ImpactPoint", {-0.01026, 0.0277091}, 1}, {"ImpactPoint", {-0.015, 0.0255359}, 1}, {"ImpactPoint", {-0.019284001, 0.022587201}, 1}, {"ImpactPoint", {-0.022980001, 0.0189544}, 1}, {"ImpactPoint", {-0.025979999, 0.0147436}, 1}, {"ImpactPoint", {-0.028191, 0.0100846}, 1}, {"ImpactPoint", {-0.029544, 0.0051189698}, 1}, {"ImpactPoint", {-0.029999999, 0}, 1}, {"ImpactPoint", {-0.029544, -0.0051189698}, 1}, {"ImpactPoint", {-0.028191, -0.0100846}, 1}, {"ImpactPoint", {-0.025979999, -0.0147436}, 1}, {"ImpactPoint", {-0.022980001, -0.0189544}, 1}, {"ImpactPoint", {-0.019284001, -0.022587201}, 1}, {"ImpactPoint", {-0.015, -0.0255359}, 1}, {"ImpactPoint", {-0.01026, -0.0277091}, 1}, {"ImpactPoint", {-0.0052080001, -0.029038999}, 1}, {"ImpactPoint", {0, -0.0294872}, 1}};
                        };
                        class Distance {
                            type = "text";
                            source = "ImpactDistance";
                            sourceScale = 0.001;
                            sourcePrecision = 2;
                            max = 99;
                            align = "center";
                            scale = 1;
                            pos[] = {"ImpactPoint", {-0.0020000001, -0.079999998}, 1};
                            right[] = {"ImpactPoint", {0.045000002, -0.079999998}, 1};
                            down[] = {"ImpactPoint", {-0.0020000001, -0.039999999}, 1};
                        };
                    };
                    class BombCrosshairGroup {
                        type = "group";
                        condition = "bomb";
                        class BombCrosshair {
                            type = "line";
                            width = 4;
                            points[] = {{"ImpactPoint", {0, -0.0982906}, 1}, {"ImpactPoint", {0.01736, -0.096796602}, 1}, {"ImpactPoint", {0.034200002, -0.0923637}, 1}, {"ImpactPoint", {0.050000001, -0.085119702}, 1}, {"ImpactPoint", {0.064280003, -0.075290598}, 1}, {"ImpactPoint", {0.0766, -0.063181199}, 1}, {"ImpactPoint", {0.086599998, -0.0491453}, 1}, {"ImpactPoint", {0.093970001, -0.033615399}, 1}, {"ImpactPoint", {0.098480001, -0.0170632}, 1}, {"ImpactPoint", {0.1, 0}, 1}, {"ImpactPoint", {0.098480001, 0.0170632}, 1}, {"ImpactPoint", {0.093970001, 0.033615399}, 1}, {"ImpactPoint", {0.086599998, 0.0491453}, 1}, {"ImpactPoint", {0.0766, 0.063181199}, 1}, {"ImpactPoint", {0.064280003, 0.075290598}, 1}, {"ImpactPoint", {0.050000001, 0.085119702}, 1}, {"ImpactPoint", {0.034200002, 0.0923637}, 1}, {"ImpactPoint", {0.01736, 0.096796602}, 1}, {"ImpactPoint", {0, 0.0982906}, 1}, {"ImpactPoint", {-0.01736, 0.096796602}, 1}, {"ImpactPoint", {-0.034200002, 0.0923637}, 1}, {"ImpactPoint", {-0.050000001, 0.085119702}, 1}, {"ImpactPoint", {-0.064280003, 0.075290598}, 1}, {"ImpactPoint", {-0.0766, 0.063181199}, 1}, {"ImpactPoint", {-0.086599998, 0.0491453}, 1}, {"ImpactPoint", {-0.093970001, 0.033615399}, 1}, {"ImpactPoint", {-0.098480001, 0.0170632}, 1}, {"ImpactPoint", {-0.1, 0}, 1}, {"ImpactPoint", {-0.098480001, -0.0170632}, 1}, {"ImpactPoint", {-0.093970001, -0.033615399}, 1}, {"ImpactPoint", {-0.086599998, -0.0491453}, 1}, {"ImpactPoint", {-0.0766, -0.063181199}, 1}, {"ImpactPoint", {-0.064280003, -0.075290598}, 1}, {"ImpactPoint", {-0.050000001, -0.085119702}, 1}, {"ImpactPoint", {-0.034200002, -0.0923637}, 1}, {"ImpactPoint", {-0.01736, -0.096796602}, 1}, {"ImpactPoint", {0, -0.0982906}, 1}, {}, {"ImpactPoint", 1, "Limit0109", 1, {0, -0.0196581}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {0.014, -0.0137607}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {"+ 0.02", 0}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {0.014, 0.0137607}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {0, 0.0196581}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {-0.014, 0.0137607}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {"- 0.02", 0}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {-0.014, -0.0137607}, 1}, {"ImpactPoint", 1, "Limit0109", 1, {0, -0.0196581}, 1}, {}, {"VelocityVector", 0.001, "ImpactPoint", 1, "Limit0109", 1, {0, 0}, 1}, {"VelocityVector", 1, "Limit0109", 1, {0, 0}, 1}};
                        };
                        class Distance {
                            type = "text";
                            source = "ImpactDistance";
                            sourceScale = 0.001;
                            sourcePrecision = 2;
                            max = 99;
                            align = "center";
                            scale = 1;
                            pos[] = {"ImpactPoint", {-0.0020000001, 0.11}, 1};
                            right[] = {"ImpactPoint", {0.045000002, 0.11}, 1};
                            down[] = {"ImpactPoint", {-0.0020000001, 0.15000001}, 1};
                        };
                    };
                    class AAMissile {
                        condition = "AAmissile";
                        class Circle {
                            type = "line";
                            width = 4;
                            points[] = {{"ForwardVector", 1, "HUDCenter", {0, -0.245726}, 1}, {"ForwardVector", 1, "HUDCenter", {0.0434, -0.241991}, 1}, {"ForwardVector", 1, "HUDCenter", {0.0855, -0.230909}, 1}, {"ForwardVector", 1, "HUDCenter", {0.125, -0.212799}, 1}, {"ForwardVector", 1, "HUDCenter", {0.1607, -0.188226}, 1}, {"ForwardVector", 1, "HUDCenter", {0.1915, -0.157953}, 1}, {"ForwardVector", 1, "HUDCenter", {0.2165, -0.122863}, 1}, {"ForwardVector", 1, "HUDCenter", {0.234925, -0.0840385}, 1}, {"ForwardVector", 1, "HUDCenter", {0.2462, -0.0426581}, 1}, {"ForwardVector", 1, "HUDCenter", {0.25, 0}, 1}, {"ForwardVector", 1, "HUDCenter", {0.2462, 0.0426581}, 1}, {"ForwardVector", 1, "HUDCenter", {0.234925, 0.0840385}, 1}, {"ForwardVector", 1, "HUDCenter", {0.2165, 0.122863}, 1}, {"ForwardVector", 1, "HUDCenter", {0.1915, 0.157953}, 1}, {"ForwardVector", 1, "HUDCenter", {0.1607, 0.188226}, 1}, {"ForwardVector", 1, "HUDCenter", {0.125, 0.212799}, 1}, {"ForwardVector", 1, "HUDCenter", {0.0855, 0.230909}, 1}, {"ForwardVector", 1, "HUDCenter", {0.0434, 0.241991}, 1}, {"ForwardVector", 1, "HUDCenter", {0, 0.245726}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.0434, 0.241991}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.0855, 0.230909}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.125, 0.212799}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.1607, 0.188226}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.1915, 0.157953}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.2165, 0.122863}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.234925, 0.0840385}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.2462, 0.0426581}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.25, 0}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.2462, -0.0426581}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.234925, -0.0840385}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.2165, -0.122863}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.1915, -0.157953}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.1607, -0.188226}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.125, -0.212799}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.0855, -0.230909}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.0434, -0.241991}, 1}, {"ForwardVector", 1, "HUDCenter", {0, -0.245726}, 1}};
                        };
                        class Lines {
                            type = "line";
                            width = 4;
                            points[] = {{{0.21, 0.55}, 1}, {{0.19, 0.55}, 1}, {{0.19, 0.71}, 1}, {{0.21, 0.71}, 1}, {}, {{0.21, 0.67}, 1}, {{0.19, 0.67}, 1}, {}, {{0.21, 0.63}, 1}, {{0.19, 0.63}, 1}, {}, {{0.21, 0.59}, 1}, {{0.19, 0.59}, 1}, {}, {"LarTargetDist", -0.16, {0.17, 0.73}, 1}, {"LarTargetDist", -0.16, {0.19, 0.71}, 1}, {"LarTargetDist", -0.16, {0.17, 0.69}, 1}, {}};
                        };
                        class Poly {
                            type = "polygon";
                            points[] = {{{"LarAmmoMin", -0.16, {0.191, 0.71}, 1}, {"LarAmmoMax", -0.16, {0.191, 0.71}, 1}, {"LarAmmoMax", -0.16, {0.208, 0.71}, 1}, {"LarAmmoMin", -0.16, {0.208, 0.71}, 1}}};
                        };
                        class TopText {
                            type = "text";
                            source = "LarTop";
                            sourceScale = 0.001;
                            scale = 1;
                            pos[] = {{0.22, 0.53}, 1};
                            right[] = {{0.26, 0.53}, 1};
                            down[] = {{0.22, 0.57}, 1};
                            align = "right";
                        };
                        class MiddleText : TopText {
                            source = "LarTop";
                            sourcePrecision = -1;
                            sourceScale = 0.0005;
                            pos[] = {{0.22, 0.61}, 1};
                            right[] = {{0.26, 0.61}, 1};
                            down[] = {{0.22, 0.65}, 1};
                        };
                        class SpeedText : TopText {
                            source = "LarTargetSpeed";
                            align = "left";
                            sourceScale = 3.6;
                            pos[] = {"LarTargetDist", -0.16, {0.16, 0.69}, 1};
                            right[] = {"LarTargetDist", -0.16, {0.2, 0.69}, 1};
                            down[] = {"LarTargetDist", -0.16, {0.16, 0.73}, 1};
                        };
                    };
                    class ATMissile {
                        condition = "ATmissile";
                        class Circle {
                            type = "line";
                            width = 4;
                            points[] = {{"ForwardVector", 1, "HUDCenter", {-0.15, -0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.15, -0.127778}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {-0.15, 0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.15, 0.127778}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {0.15, -0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {0.15, -0.127778}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {0.15, 0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {0.15, 0.127778}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {-0.15, -0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.13, -0.147436}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {-0.15, 0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {-0.13, 0.147436}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {0.15, -0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {0.13, -0.147436}, 1}, {}, {"ForwardVector", 1, "HUDCenter", {0.15, 0.147436}, 1}, {"ForwardVector", 1, "HUDCenter", {0.13, 0.147436}, 1}};
                        };
                        class Lines {
                            type = "line";
                            width = 4;
                            points[] = {{{0.21, 0.55}, 1}, {{0.19, 0.55}, 1}, {{0.19, 0.71}, 1}, {{0.21, 0.71}, 1}, {}, {{0.21, 0.67}, 1}, {{0.19, 0.67}, 1}, {}, {{0.21, 0.63}, 1}, {{0.19, 0.63}, 1}, {}, {{0.21, 0.59}, 1}, {{0.19, 0.59}, 1}, {}, {"LarTargetDist", -0.16, {0.17, 0.73}, 1}, {"LarTargetDist", -0.16, {0.19, 0.71}, 1}, {"LarTargetDist", -0.16, {0.17, 0.69}, 1}, {}};
                        };
                        class Poly {
                            type = "polygon";
                            points[] = {{{"LarAmmoMin", -0.16, {0.191, 0.71}, 1}, {"LarAmmoMax", -0.16, {0.191, 0.71}, 1}, {"LarAmmoMax", -0.16, {0.208, 0.71}, 1}, {"LarAmmoMin", -0.16, {0.208, 0.71}, 1}}};
                        };
                        class TopText {
                            type = "text";
                            source = "LarTop";
                            sourceScale = 0.001;
                            scale = 1;
                            pos[] = {{0.22, 0.53}, 1};
                            right[] = {{0.26, 0.53}, 1};
                            down[] = {{0.22, 0.57}, 1};
                            align = "right";
                        };
                        class MiddleText : TopText {
                            source = "LarTop";
                            sourcePrecision = -1;
                            sourceScale = 0.0005;
                            pos[] = {{0.22, 0.61}, 1};
                            right[] = {{0.26, 0.61}, 1};
                            down[] = {{0.22, 0.65}, 1};
                        };
                        class SpeedText : TopText {
                            source = "LarTargetSpeed";
                            align = "left";
                            sourceScale = 3.6;
                            pos[] = {"LarTargetDist", -0.16, {0.16, 0.69}, 1};
                            right[] = {"LarTargetDist", -0.16, {0.2, 0.69}, 1};
                            down[] = {"LarTargetDist", -0.16, {0.16, 0.73}, 1};
                        };
                    };
                    class WP {
                        condition = "wpvalid";
                        class WPdist {
                            type = "text";
                            source = "wpdist";
                            sourceScale = 0.001;
                            sourcePrecision = 2;
                            align = "left";
                            scale = 1;
                            pos[] = {{0.235, 0.774038}, 1};
                            right[] = {{0.275, 0.774038}, 1};
                            down[] = {{0.235, 0.80156}, 1};
                        };
                        class WPIndex {
                            type = "text";
                            source = "wpIndex";
                            sourceScale = 1;
                            sourceLength = 2;
                            align = "right";
                            scale = 1;
                            pos[] = {{0.096, 0.776004}, 1};
                            right[] = {{0.126, 0.776004}, 1};
                            down[] = {{0.096, 0.799594}, 1};
                        };
                        class WPstatic {
                            type = "text";
                            source = "static";
                            text = "W";
                            scale = 1;
                            sourceScale = 1;
                            align = "right";
                            pos[] = {{0.075, 0.775}, 1};
                            right[] = {{0.105, 0.775}, 1};
                            down[] = {{0.075, 0.8}, 1};
                        };
                        class WPKM {
                            type = "text";
                            source = "static";
                            text = "KM";
                            scale = 1;
                            sourceScale = 1;
                            align = "right";
                            pos[] = {{"0.075 +0.16", 0.775}, 1};
                            right[] = {{0.265, 0.775}, 1};
                            down[] = {{"0.075 +0.16", 0.803}, 1};
                        };
                        class WP {
                            width = 2;
                            type = "line";
                            points[] = {{"WPPoint", 1, "LimitWaypoint", 1, {-0.02, 0.04}, 1}, {"WPPoint", 1, "LimitWaypoint", 1, {0, 0.02}, 1}, {"WPPoint", 1, "LimitWaypoint", 1, {0.02, 0.04}, 1}, {}};
                        };
                    };
                    class WeaponsLocking {
                        condition = "missilelocking";
                        blinkingPattern[] = {0.2, 0.2};
                        blinkingStartsOn = 1;
                        class shape {
                            type = "line";
                            width = 4;
                            points[] = {{"Target", 1, "Limit0109", 1, {0, -0.0294872}, 1}, {"Target", 1, "Limit0109", 1, {0.029999999, 0}, 1}, {"Target", 1, "Limit0109", 1, {0, 0.0294872}, 1}, {"Target", 1, "Limit0109", 1, {-0.029999999, 0}, 1}, {"Target", 1, "Limit0109", 1, {0, -0.0294872}, 1}};
                        };
                    };
                    class IncomingMissile {
                        condition = "incomingmissile";
                        blinkingPattern[] = {0.3, 0.3};
                        blinkingStartsOn = 1;
                        class Text {
                            type = "text";
                            source = "static";
                            text = "!INCOMING MISSILE!";
                            align = "center";
                            scale = 1;
                            pos[] = {{0.485, 0.216239}, 1};
                            right[] = {{0.545, 0.216239}, 1};
                            down[] = {{0.485, 0.265385}, 1};
                        };
                    };
                    class RadarTargets {
                        class RadarBoxes {
                            type = "radartoview";
                            pos0[] = {0.5, 0.5};
                            pos10[] = {0.734, 0.73};
                            width = 4;
                            points[] = {{{-0.0035, -0.00344017}, 1}, {{0.0035, -0.00344017}, 1}, {{0.0035, 0.00344017}, 1}, {{-0.0035, 0.00344017}, 1}, {{-0.0035, -0.00344017}, 1}};
                        };
                    };
                    class TargetDiamond {
                        class shape {
                            type = "line";
                            width = 4;
                            points[] = {{"Target", 1, "Limit0109", 1, {0.02, 0.0196581}, 1}, {"Target", 1, "Limit0109", 1, {-0.02, 0.0196581}, 1}, {"Target", 1, "Limit0109", 1, {-0.02, -0.0196581}, 1}, {"Target", 1, "Limit0109", 1, {0.02, -0.0196581}, 1}, {"Target", 1, "Limit0109", 1, {0.02, 0.0196581}, 1}};
                        };
                    };
                    class TargetLocked {
                        condition = "missilelocked";
                        class shape {
                            type = "line";
                            width = 4;
                            points[] = {{"Target", 1, "Limit0109", 1, {0, -0.0294872}, 1}, {"Target", 1, "Limit0109", 1, {0.029999999, 0}, 1}, {"Target", 1, "Limit0109", 1, {0, 0.0294872}, 1}, {"Target", 1, "Limit0109", 1, {-0.029999999, 0}, 1}, {"Target", 1, "Limit0109", 1, {0, -0.0294872}, 1}};
                        };
                        class TimeOfFlightText {
                            type = "text";
                            source = "static";
                            text = "TOF:";
                            scale = 1;
                            sourceScale = 1;
                            align = "right";
                            pos[] = {{"0.127+0.49", 0.869}, 1};
                            right[] = {{0.652, 0.869}, 1};
                            down[] = {{"0.127+0.49", 0.904}, 1};
                        };
                        class TOF_source {
                            type = "text";
                            scale = 1;
                            sourceScale = 1;
                            source = "missileflighttime";
                            align = "right";
                            pos[] = {{0.739, 0.869}, 1};
                            right[] = {{0.774, 0.869}, 1};
                            down[] = {{0.739, 0.904}, 1};
                        };
                    };
                    class TargetDist {
                        class DistanceText {
                            type = "text";
                            source = "static";
                            text = "DIST:";
                            scale = 1;
                            sourceScale = 1;
                            align = "right";
                            pos[] = {{"0.125+0.49", 0.901}, 1};
                            right[] = {{0.65, 0.901}, 1};
                            down[] = {{"0.125+0.49", 0.936}, 1};
                        };
                        class TargetDistance {
                            type = "text";
                            scale = 1;
                            source = "targetDist";
                            sourceLength = 0;
                            sourcePrecision = 2;
                            sourceScale = 0.001;
                            align = "right";
                            pos[] = {{0.739, 0.901}, 1};
                            right[] = {{0.774, 0.901}, 1};
                            down[] = {{0.739, 0.936}, 1};
                        };
                    };
                };
            };
            class HMD_CMPilot : AirplaneHUD {
                turret[] = {-1};
                class Draw {
                    alpha = "user3";
                    color[] = {"user0", "user1", "user2"};
                    condition = "on";
                    class cmWeapons {
                        type = "text";
                        source = "cmweapon";
                        sourceScale = 1;
                        align = "right";
                        scale = 0.5;
                        pos[] = {{0.001, 0.869}, 1};
                        right[] = {{0.036, 0.869}, 1};
                        down[] = {{0.001, 0.904}, 1};
                    };
                    class cmAmmo {
                        type = "text";
                        source = "cmammo";
                        sourceScale = 1;
                        align = "right";
                        scale = 0.5;
                        pos[] = {{0.001, 0.901}, 1};
                        right[] = {{0.036, 0.901}, 1};
                        down[] = {{0.001, 0.936}, 1};
                    };
                };
            };
        };
        class RotorLibHelicopterProperties : RotorLibHelicopterProperties {
            rtd_center = "rtd_center";
            RTDconfig = "rhsafrf\addons\rhs_c_a2port_air\Mi35\RTD_mi24.xml";
            maxTorque = 201754;
            maxMainRotorStress = 320000;
            maxTailRotorStress = 60000;
            maxHorizontalStabilizerLeftStress = 12000;
            maxHorizontalStabilizerRightStress = 12000;
            maxVerticalStabilizerStress = 8000;
            defaultCollective = 0.75;
            autoHoverCorrection[] = {3.5, -1.5, 0};
            retreatBladeStallWarningSpeed = 93.056;
            horizontalWingsAngleCollMin = -12.5;
            horizontalWingsAngleCollMax = 7.5;
            stressDamagePerSec = 0.0033333332;
        };
        defaultUserMFDvalues[] = {0.25, 1, 0.25, 1};
        envelope[] = {0, 0.2, 0.9, 2.1, 2.5, 3.3, 3.5, 3.6, 3.7, 3.8, 3.8, 3.8, 3.8, 3.8, 3.8};
        maxSpeed = 365;
        slingLoadMaxCargoMass = 4000;
        magazines[] = {"240Rnd_CMFlare_Chaff_Magazine"};
        cargoCompartments[] = {"Compartment3"};
        transportsoldier = 11;
        cargoProxyIndexes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
        gearUpExt[] = {"A3\Sounds_F\vehicles\air\Heli_Attack_01\blackfoot_gear_up_ext", 1, 1, 1000};
        gearUpInt[] = {"A3\Sounds_F\vehicles\air\Heli_Attack_01\blackfoot_gear_up_int", 1, 1, 100};
        gearUp[] = {"gearUpInt", "gearUpExt"};
        gearDownInt[] = {"A3\Sounds_F\vehicles\air\Heli_Attack_01\blackfoot_gear_down_int", 1, 1, 100};
        gearDownExt[] = {"A3\Sounds_F\vehicles\air\Heli_Attack_01\blackfoot_gear_down_ext", 1, 1, 1000};
        gearDown[] = {"gearDownInt", "gearDownExt"};
        weaponsGroup1 = 1 + 2;
        weaponsGroup2 = 8;
        weaponsGroup3 = 16 + 32;
        weaponsGroup4 = 4 + 64 + 128;
        lockDetectionSystem = 4 + 8;
        driverDoor = "Door_Pilot";
        getInAction = "pilot_Heli_Light_02_Enter";
        getOutAction = "pilot_Heli_Light_02_Exit";
        model = "Spray_Hind\Heli_Attack_04_F.p3d";
        cargoDoors[] = {"Door_Cargo"};
        memoryPointDriverOptics = "pos driver";
        class PilotCamera {
            class OpticsIn {
                class Wide {
                    opticsDisplayName = "W";
                    initAngleX = 0;
                    minAngleX = 0;
                    maxAngleX = 0;
                    initAngleY = 0;
                    minAngleY = 0;
                    maxAngleY = 0;
                    initFov = 2;
                    minFov = 2;
                    maxFov = 2;
                    directionStabilized = 1;
                    visionMode[] = {"Normal", "NVG", "Ti"};
                    thermalMode[] = {0, 1};
                    gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
                };
                showSlingLoadManagerInOptics = 1;
            };
            minTurn = -180;
            maxTurn = 180;
            initTurn = 0;
            minElev = 55;
            maxElev = 90;
            initElev = 90;
            maxXRotSpeed = 0.5;
            maxYRotSpeed = 0.5;
            pilotOpticsShowCursor = 1;
            controllable = 1;
        };
        // Fix the gunner repeater vision mode
        class RenderTargets {
            class LeftMirror {
                class CameraView1 {
                    renderVisionMode = 2;
                    turret[] = {0};
                };
            };
            class RightMirror {
                class CameraView1 {
                    renderVisionMode = 2;
                    turret[] = {0};
                };
            };
        };
    };
    class Aegis_I_EAF_Heli_Attack_04_F : Aegis_Heli_Attack_04_base_F {
        class Components : Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class Pylons : pylons {
                    class PylonLeft1 : PylonLeft1 {
                        attachment = "PylonRack_12Rnd_missiles";
                    };
                    class PylonLeft2 : PylonLeft2 {
                        attachment = "PylonRack_12Rnd_missiles";
                    };
                    class PylonLeft3 : PylonLeft3 {
                        attachment = "PylonRack_4Rnd_LG_scalpel";
                        turret[] = {0};
                    };
                    class PylonRight1 : PylonRight1 {
                        attachment = "PylonRack_12Rnd_missiles";
                    };
                    class PylonRight2 : PylonRight2 {
                        attachment = "PylonRack_12Rnd_missiles";
                    };
                    class PylonRight3 : PylonRight3 {
                        attachment = "PylonRack_4Rnd_LG_scalpel";
                        turret[] = {0};
                    };
                    class PylonLeft4 : PylonLeft4 {
                    };
                    class PylonRight4 : PylonRight4 {
                    };
                    class PylonRadar : PylonRadar {
                    };
                };
                class Presets : Presets {
                    class Default : Default {
                        attachment[] = {"PylonRack_12Rnd_missiles", "PylonRack_12Rnd_missiles", "PylonRack_4Rnd_LG_scalpel", "PylonRack_12Rnd_missiles", "PylonRack_12Rnd_missiles", "PylonRack_4Rnd_LG_scalpel", "", "", "MastRadar"};
                    };
                    class AT : AT {
                        attachment[] = {"PylonRack_12Rnd_missiles", "PylonRack_4Rnd_LG_scalpel", "PylonRack_4Rnd_LG_scalpel", "PylonRack_12Rnd_missiles", "PylonRack_4Rnd_LG_scalpel", "PylonRack_4Rnd_LG_scalpel", "", "", "MastRadar"};
                    };
                    class CAS : CAS {
                        attachment[] = {"PylonRack_12Rnd_missiles", "PylonMissile_1Rnd_Bomb_03_F", "PylonRack_4Rnd_LG_scalpel", "PylonRack_12Rnd_missiles", "PylonMissile_1Rnd_Bomb_03_F", "PylonRack_4Rnd_LG_scalpel", "", "", "MastRadar"};
                    };
                };
            };
        };
        cargoProxyIndexes[] = {1, 2, 3, 4, 9, 10, 11};
        transportsoldier = 7;
        cargoAction[] = {"Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "passenger_flatground_generic02", "passenger_flatground_generic05", "passenger_flatground_leanleft"};
        // It has to be re-declared(?), otherwise won't work
        class Turrets : Turrets {
            class CargoTurret_01 : CargoTurret_01 {
            };
            class CargoTurret_02 : CargoTurret_02 {
            };
            class CargoTurret_03 : CargoTurret_03 {
            };
            class CargoTurret_04 : CargoTurret_04 {
            };
        };
    };
    class Aegis_B_ION_Heli_Attack_04_F : Aegis_Heli_Attack_04_base_F {
        cargoProxyIndexes[] = {1, 2, 3, 4, 9, 10, 11};
        transportsoldier = 7;
        cargoAction[] = {"Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "passenger_flatground_generic02", "passenger_flatground_generic05", "passenger_flatground_leanleft"};
        class Turrets : Turrets {
            class CargoTurret_01 : CargoTurret_01 {
            };
            class CargoTurret_02 : CargoTurret_02 {
            };
            class CargoTurret_03 : CargoTurret_03 {
            };
            class CargoTurret_04 : CargoTurret_04 {
            };
        };
        class Components : Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class Pylons : pylons {
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
                    class PylonLeft4 : PylonLeft4 {
                    };
                    class PylonRight4 : PylonRight4 {
                    };
                    class PylonRadar : PylonRadar {
                        attachment = "";
                    };
                };
                class Presets : Presets {
                    class Default : Default {
                        attachment[] = {"PylonRack_12Rnd_PG_missiles", "PylonRack_12Rnd_PG_missiles", "PylonWeapon_300Rnd_20mm_shells", "PylonRack_12Rnd_PG_missiles", "PylonRack_12Rnd_PG_missiles", "PylonWeapon_300Rnd_20mm_shells", "", "", ""};
                    };
                };
            };
        };
    };
    class Aegis_O_A_Heli_Attack_04_F : Aegis_Heli_Attack_04_base_F {
        cargoProxyIndexes[] = {1, 2, 3, 4, 9, 10, 11};
        transportsoldier = 7;
        cargoAction[] = {"Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "passenger_flatground_generic02", "passenger_flatground_generic05", "passenger_flatground_leanleft"};
        class Turrets : Turrets {
            class CargoTurret_01 : CargoTurret_01 {
            };
            class CargoTurret_02 : CargoTurret_02 {
            };
            class CargoTurret_03 : CargoTurret_03 {
            };
            class CargoTurret_04 : CargoTurret_04 {
            };
        };
    };
    class Aegis_I_Raven_Heli_Attack_04_F : Aegis_Heli_Attack_04_base_F {
        cargoProxyIndexes[] = {1, 2, 3, 4, 9, 10, 11};
        transportsoldier = 7;
        cargoAction[] = {"Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "passenger_flatground_generic02", "passenger_flatground_generic05", "passenger_flatground_leanleft"};
        class Turrets : Turrets {
            class CargoTurret_01 : CargoTurret_01 {
            };
            class CargoTurret_02 : CargoTurret_02 {
            };
            class CargoTurret_03 : CargoTurret_03 {
            };
            class CargoTurret_04 : CargoTurret_04 {
            };
        };
        class Components : Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class Pylons : pylons {
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
                    class PylonLeft4 : PylonLeft4 {
                    };
                    class PylonRight4 : PylonRight4 {
                    };
                    class PylonRadar : PylonRadar {
                        attachment = "";
                    };
                };
                class Presets : Presets {
                    class Default : Default {
                        attachment[] = {"PylonRack_20Rnd_Rocket_80mm", "PylonRack_20Rnd_Rocket_80mm", "PylonWeapon_250Rnd_20mm_shells", "PylonRack_20Rnd_Rocket_80mm", "PylonRack_20Rnd_Rocket_80mm", "PylonWeapon_250Rnd_20mm_shells", "", "", ""};
                    };
                };
            };
        };
    };
    class Aegis_O_R_Heli_Attack_04_F : Aegis_Heli_Attack_04_base_F {
        cargoProxyIndexes[] = {1, 2, 3, 4, 9, 10, 11};
        transportsoldier = 7;
        cargoAction[] = {"Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "passenger_flatground_generic02", "passenger_flatground_generic05", "passenger_flatground_leanleft"};
        class Turrets : Turrets {
            class CargoTurret_01 : CargoTurret_01 {
            };
            class CargoTurret_02 : CargoTurret_02 {
            };
            class CargoTurret_03 : CargoTurret_03 {
            };
            class CargoTurret_04 : CargoTurret_04 {
            };
        };
        class Components : Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class Pylons : pylons {
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
                    class PylonLeft4 : PylonLeft4 {
                    };
                    class PylonRight4 : PylonRight4 {
                    };
                    class PylonRadar : PylonRadar {
                    };
                };
                class Presets : Presets {
                    class Default : Default {
                        attachment[] = {"PylonRack_20Rnd_Rocket_80mm", "PylonRack_20Rnd_Rocket_80mm", "PylonRack_6Rnd_Vikhr_missiles", "PylonRack_20Rnd_Rocket_80mm", "PylonRack_20Rnd_Rocket_80mm", "PylonRack_6Rnd_Vikhr_missiles", "", "", "MastRadar"};
                    };
                    class AT : AT {
                        attachment[] = {"PylonRack_6Rnd_Vikhr_missiles", "PylonRack_6Rnd_Vikhr_missiles", "PylonRack_6Rnd_Vikhr_missiles", "PylonRack_6Rnd_Vikhr_missiles", "PylonRack_6Rnd_Vikhr_missiles", "PylonRack_6Rnd_Vikhr_missiles", "", "", "MastRadar"};
                    };
                    class HAT : HAT {
                        attachment[] = {"PylonRack_1Rnd_Missile_AGM_01_F", "PylonRack_1Rnd_Missile_AGM_01_F", "PylonRack_6Rnd_Vikhr_missiles", "PylonRack_1Rnd_Missile_AGM_01_F", "PylonRack_1Rnd_Missile_AGM_01_F", "PylonRack_6Rnd_Vikhr_missiles", "", "", "MastRadar"};
                    };
                    class CAS : CAS {
                        attachment[] = {"PylonRack_20Rnd_Rocket_80mm", "PylonMissile_1Rnd_Bomb_03_F", "PylonRack_20Rnd_Rocket_80mm", "PylonRack_20Rnd_Rocket_80mm", "PylonMissile_1Rnd_Bomb_03_F", "PylonRack_20Rnd_Rocket_80mm", "", "", "MastRadar"};
                    };
                };
            };
        };
    };
    class Aegis_O_SFIA_Heli_Attack_04_F : Aegis_Heli_Attack_04_base_F {
        cargoProxyIndexes[] = {1, 2, 3, 4, 9, 10, 11};
        transportsoldier = 7;
        cargoAction[] = {"Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "passenger_flatground_generic02", "passenger_flatground_generic05", "passenger_flatground_leanleft"};
        class Turrets : Turrets {
            class CargoTurret_01 : CargoTurret_01 {
            };
            class CargoTurret_02 : CargoTurret_02 {
            };
            class CargoTurret_03 : CargoTurret_03 {
            };
            class CargoTurret_04 : CargoTurret_04 {
            };
        };
        class Components : Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class Pylons : pylons {
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
                    class PylonLeft4 : PylonLeft4 {
                    };
                    class PylonRight4 : PylonRight4 {
                    };
                    class PylonRadar : PylonRadar {
                    };
                };
                class Presets : Presets {
                    class Default : Default {
                        attachment[] = {"PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_3Rnd_LG_scalpel", "PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_3Rnd_LG_scalpel", "", "", "MastRadar"};
                    };
                    class AT : AT {
                        attachment[] = {"PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_3Rnd_LG_scalpel", "PylonRack_3Rnd_LG_scalpel", "PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_3Rnd_LG_scalpel", "PylonRack_3Rnd_LG_scalpel", "", "", "MastRadar"};
                    };
                    class CAS : CAS {
                        attachment[] = {"PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_19Rnd_Rocket_Skyfire", "PylonWeapon_250Rnd_20mm_shells", "PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_19Rnd_Rocket_Skyfire", "PylonWeapon_250Rnd_20mm_shells", "", "", "MastRadar"};
                    };
                };
            };
        };
    };
};