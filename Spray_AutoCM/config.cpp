class RscCheckBox;
class RscText;
class RscEdit;
class RscListbox;
class RscButtonMenu;
class CfgPatches {
    class Spray_AutoCM {
        units[] = {};
        weapons[] = {};
        magazines[] = {};
        requiredVersion = 0.100000;
        requiredAddons[] = {};
    };
};
class CfgFunctions {
    class Spray_AutoCM {
        class Spray_AutoCM {
            file = "Spray_AutoCM\functions";
            class addAction {
            };
            class Dialog {
            };
            class findlbItem {
            };
            class init {
            };
            class FireCM {
            };
        };
    };
};
class Spray_AutoCM_Dialog {
    movingEnable = true;
    idd = 12000;
    class controls {
        class RscText_1001 : RscText {
            idc = 1001;
            x = 0.340156 * safezoneW + safezoneX;
            y = 0.291 * safezoneH + safezoneY;
            w = 0.299062 * safezoneW;
            h = 0.396 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.75};
            colorActive[] = {0, 0, 0, 0.75};
        };
        class RscText_1000 : RscText {
            idc = 1000;
            text = "Auto Countermeasures Setting";  //--- ToDo: Localize;
            x = 0.350469 * safezoneW + safezoneX;
            y = 0.313 * safezoneH + safezoneY;
            w = 0.165 * safezoneW;
            h = 0.033 * safezoneH;
            sizeEx = 1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25);
        };
        class RscCheckbox_2800 : RscCheckbox {
            idc = 2800;
            x = 0.5825 * safezoneW + safezoneX;
            y = 0.324 * safezoneH + safezoneY;
            w = 0.0103125 * safezoneW;
            h = 0.022 * safezoneH;
            sizeEx = 1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25);
        };
        class RscText_1002 : RscText {
            idc = 1002;
            text = "Enabled:";  //--- ToDo: Localize;
            x = 0.530937 * safezoneW + safezoneX;
            y = 0.324 * safezoneH + safezoneY;
            w = 0.0433125 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscText_1003 : RscText {
            idc = 1003;
            text = "Launcher:";  //--- ToDo: Localize;
            x = 0.5 * safezoneW + safezoneX;
            y = 0.357 * safezoneH + safezoneY;
            w = 0.0391875 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscText_1004 : RscText {
            idc = 1004;
            text = "Burst  (1 - 5):";  //--- ToDo: Localize;
            x = 0.489687 * safezoneW + safezoneX;
            y = 0.5 * safezoneH + safezoneY;
            w = 0.061875 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscEdit_timer : RscEdit {
            idc = 1400;
            x = 0.577344 * safezoneW + safezoneX;
            y = 0.544 * safezoneH + safezoneY;
            w = 0.0257812 * safezoneW;
            h = 0.022 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        class RscText_1005 : RscText {
            idc = 1005;
            text = "Interval (0.2s - 5s):";  //--- ToDo: Localize;
            x = 0.489687 * safezoneW + safezoneX;
            y = 0.544 * safezoneH + safezoneY;
            w = 0.086625 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscEdit_Burst : RscEdit {
            idc = 1401;
            x = 0.587656 * safezoneW + safezoneX;
            y = 0.5 * safezoneH + safezoneY;
            w = 0.0154688 * safezoneW;
            h = 0.022 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        class RscText_1006 : RscText {
            idc = 1006;
            text = "s";  //--- ToDo: Localize;
            x = 0.608281 * safezoneW + safezoneX;
            y = 0.544 * safezoneH + safezoneY;
            w = 0.0103125 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscListbox_Launcher : RscListbox {
            idc = 1500;
            x = 0.5 * safezoneW + safezoneX;
            y = 0.39 * safezoneH + safezoneY;
            w = 0.12375 * safezoneW;
            h = 0.099 * safezoneH;
        };
        class RscText_1007 : RscText {
            idc = 1007;
            text = "Mode:";  //--- ToDo: Localize;
            x = 0.350469 * safezoneW + safezoneX;
            y = 0.5 * safezoneH + safezoneY;
            w = 0.037125 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class RscListbox_Mode : RscListbox {
            idc = 1501;
            x = 0.355625 * safezoneW + safezoneX;
            y = 0.533 * safezoneH + safezoneY;
            w = 0.12375 * safezoneW;
            h = 0.099 * safezoneH;
        };
        class RscButtonMenuOK_2600 : RscButtonMenu {
            idc = 2600;
            text = "Apply";  //--- ToDo: Localize;
            x = 0.530937 * safezoneW + safezoneX;
            y = 0.588 * safezoneH + safezoneY;
            w = 0.086625 * safezoneW;
            h = 0.0264 * safezoneH;
            colorText[] = {1, 1, 1, 1};
            colorBackground[] = {0, 0, 0, 0.8};
        };
        class RscButtonMenuCancel_2700 : RscButtonMenu {
            idc = 2700;
            text = "Cancel";  //--- ToDo: Localize;
            x = 0.530937 * safezoneW + safezoneX;
            y = 0.632 * safezoneH + safezoneY;
            w = 0.086625 * safezoneW;
            h = 0.0264 * safezoneH;
            colorText[] = {1, 1, 1, 1};
            colorBackground[] = {0, 0, 0, 0.8};
        };
        class RscListbox_Turret : RscListbox {
            idc = 1502;

            x = 0.355625 * safezoneW + safezoneX;
            y = 0.39 * safezoneH + safezoneY;
            w = 0.12375 * safezoneW;
            h = 0.099 * safezoneH;
        };
        class RscText_1008 : RscText {
            idc = 1008;
            text = "Turret:";  //--- ToDo: Localize;
            x = 0.350469 * safezoneW + safezoneX;
            y = 0.357 * safezoneH + safezoneY;
            w = 0.037125 * safezoneW;
            h = 0.022 * safezoneH;
        };
    };
};