class RscText;
class RscListbox;
class RscButtonMenu;
class CfgPatches {
    class Spray_Laser {
        units[] = {};
        weapons[] = {};
        magazines[] = {};
        requiredVersion = 0.100000;
        skipWhenMissingDependencies = 1;
        requiredAddons[] = {};
    };
};
class CfgFunctions {
    class Spray_Laser {
        class Spray_Laser {
            file = "Spray_Laser\functions";
            class addAction {
            };
            class add {
            };
            class remove {
            };
            class dialog {
            };
        };
    };
};
class Spray_Laser_Dialog {
    movingEnable = true;
    idd = 13000;
    class control {
        class RscText_1000 : RscText {
            idc = 1000;
            x = 0.396875 * safezoneW + safezoneX;
            y = 0.335 * safezoneH + safezoneY;
            w = 0.211406 * safezoneW;
            h = 0.374 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.8};
        };
        class RscText_1001 : RscText {
            idc = 1001;
            text = "Laser Targets";  //--- ToDo: Localize;
            x = 0.407187 * safezoneW + safezoneX;
            y = 0.346 * safezoneH + safezoneY;
            w = 0.0773437 * safezoneW;
            h = 0.033 * safezoneH;
            sizeEx = 1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25);
        };
        class RscListbox_Targets : RscListbox {
            idc = 1500;
            x = 0.407187 * safezoneW + safezoneX;
            y = 0.39 * safezoneH + safezoneY;
            w = 0.185625 * safezoneW;
            h = 0.264 * safezoneH;
        };
        class RscButtonMenu_Add : RscButtonMenu {
            idc = 2400;
            text = "Add Target";  //--- ToDo: Localize;
            x = 0.407187 * safezoneW + safezoneX;
            y = 0.665 * safezoneH + safezoneY;
            w = 0.061875 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscButtonMenu_Remove : RscButtonMenu {
            idc = 2401;
            text = "Remove Target";  //--- ToDo: Localize;
            x = 0.474219 * safezoneW + safezoneX;
            y = 0.665 * safezoneH + safezoneY;
            w = 0.0773437 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscButtonMenu_Cancel : RscButtonMenu {
            idc = 2402;
            text = "Cancel";  //--- ToDo: Localize;
            x = 0.556719 * safezoneW + safezoneX;
            y = 0.665 * safezoneH + safezoneY;
            w = 0.04125 * safezoneW;
            h = 0.022 * safezoneH;
        };
    };
};