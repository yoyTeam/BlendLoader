#ifndef YINPUT_H
#define YINPUT_H

namespace yInput {

    enum yDEVICE_TYPE {
        NONE_DEVICE,
        FORKLIFT,
        BRIDGECRANE,
        MININGTRUCK,
        G27,
        G920,
        T16000_LEFT,
        T16000_RIGHT,
        XBOX, //both xbox one and xbox 360 share same inputs
        PS,
        PS_P2, //player2: ussually PS2 adapters has 2 players and even if one controller is connected its detected as 2
        TILT_SENSOR,
        VIVE_CONTROLLER_LEFT,
        VIVE_CONTROLLER_RIGHT,
        NUM_DEVICE_TYPE
    };

    enum HAT_DIRECTION {
        HAT_NEUTRAL,
        HAT_UP,
        HAT_UP_RIGHT,
        HAT_RIGHT,
        HAT_DOWN_RIGHT,
        HAT_DOWN,
        HAT_DOWN_LEFT,
        HAT_LEFT,
        HAT_UP_LEFT
    };

    enum DEVICE_INPUT {
        UNKNOWN_INPUT, //0

        //MINING TRUCK
        MININGTRUCK_SHIFT_D, //dont change first miningtruck input relative order because its beeing used in iterators and in MININGTRUCK_NUM_BUTTONS
        MININGTRUCK_SHIFT_N,
        MININGTRUCK_SHIFT_R,
        MININGTRUCK_SHIFT_P,
        MININGTRUCK_HOPPER_LIFT, //5
        MININGTRUCK_HOPPER_HOLD,
        MININGTRUCK_HOPPER_FLOAT,
        MININGTRUCK_HOPPER_DOWN,
        MININGTRUCK_HOPPER_OVERRIDE,
        MININGTRUCK_EMERGENCY, //10
        MININGTRUCK_RSC_BUTTON,
        MININGTRUCK_RSC_LEVER,
        MININGTRUCK_RETARDER_LEVER,

        //BRIDGECRANE
        BRIDGECRANE_EMERGENCY,  //dont change first bridgecrane input relative order because its beeing used in iterators and in BRIDGECRANE_NUM_BUTTONS
        BRIDGECRANE_UP, //15
        BRIDGECRANE_UP_FAST,
        BRIDGECRANE_DOWN,
        BRIDGECRANE_DOWN_FAST,
        BRIDGECRANE_EAST,
        BRIDGECRANE_EAST_FAST, //20
        BRIDGECRANE_WEST,
        BRIDGECRANE_WEST_FAST,
        BRIDGECRANE_NORTH,
        BRIDGECRANE_NORTH_FAST,
        BRIDGECRANE_SOUTH, //25
        BRIDGECRANE_SOUTH_FAST,
        BRIDGECRANE_MENU_BUTTON,

        //FORKLIFT
        FORKLIFT_JOYSTICK_LEFT_AXIS_X,
        FORKLIFT_JOYSTICK_LEFT_AXIS_Y,
        FORKLIFT_JOYSTICK_RIGHT_AXIS_X, //30
        FORKLIFT_JOYSTICK_RIGHT_AXIS_Y,

        //VIVE CONTROLLER
        VIVE_MENU,
        VIVE_GRIP,
        VIVE_PAD_TOUCH,
        VIVE_TRIGGER_CLICK, //35
        VIVE_PAD_TOUCH_AXIS_X,
        VIVE_PAD_TOUCH_AXIS_Y,
        VIVE_TRIGGER,

        //G27 and G920 Common
        G27_G920_WHEEL,
        G27_G920_GAZ, //40
        G27_G920_BRAKE,
        G27_G920_CLUTCH,

        //G920
        G920_DPAD,

        //dont change the relative order and quantity of this inputs, they are beeing used in iterators
        G920_BUTTON_A,
        G920_BUTTON_B, //45
        G920_BUTTON_X,
        G920_BUTTON_Y,

        G920_SHIFT_R,
        G920_SHIFT_L,

        G920_THREE_LINES, //50
        G920_TWO_SQAURES,
        G920_RSB,
        G920_LSB,

        G920_XBOX_BUTTON,

        G920_GEAR_R, //55
        G920_GEAR_1,
        G920_GEAR_2,
        G920_GEAR_3,
        G920_GEAR_4,
        G920_GEAR_5, //60
        G920_GEAR_6,

        //G27
        G27_DPAD,

        //dont change the relative order and quantity of this inputs, they are beeing used in iterators
        G27_RED_CIRCLE_1,
        G27_RED_CIRCLE_2,
        G27_RED_CIRCLE_3, //65
        G27_RED_CIRCLE_4,

        G27_SHIFT_R,
        G27_SHIFT_L,

        G27_RED_TRIANGLE_TOP_RIGHT,
        G27_RED_TRIANGLE_TOP_LEFT, //70

        G27_GEAR_1,
        G27_GEAR_2,
        G27_GEAR_3,
        G27_GEAR_4,
        G27_GEAR_5, //75
        G27_GEAR_6,
        G27_GEAR_R,

        G27_BLACK_CIRCLE_UP,
        G27_BLACK_CIRCLE_LEFT,
        G27_BLACK_CIRCLE_DOWN, //80
        G27_BLACK_CIRCLE_RIGHT,

        G27_RED_TRIANGLE_MIDDLE_RIGHT,
        G27_RED_TRIANGLE_MIDDLE_LEFT,
        G27_RED_TRIANGLE_BOTTOM_RIGHT,
        G27_RED_TRIANGLE_BOTTOM_LEFT, //85

        //T16000
        T16000_JOYSTICK_AXIS_NULL,
        T16000_JOYSTICK_AXIS_X,
        T16000_JOYSTICK_AXIS_Y,
        T16000_JOYSTICK_AXIS_SLIDER,
        T16000_JOYSTICK_AXIS_Z, //90

        T16000_DPAD,

        T16000_TRIGGER,
        T16000_BUTTON_CENTER,
        T16000_BUTTON_LEFT,
        T16000_BUTTON_RIGHT, //95
        T16000_BASE_ANY,

        //XBOX 360 AND ONE, both share the same button inputs
        XBOX_JOYSTICK_LEFT_AXIS_Y,
        XBOX_JOYSTICK_LEFT_AXIS_X,
        XBOX_JOYSTICK_RIGHT_AXIS_Y,
        XBOX_JOYSTICK_RIGHT_AXIS_X, //100
        XBOX_TRIGGER_RIGHT,
        XBOX_TRIGGER_LEFT,

        XBOX_DPAD,

        XBOX_BUTTON_A,
        XBOX_BUTTON_B, //105
        XBOX_BUTTON_X,
        XBOX_BUTTON_Y,
        XBOX_SHOULDER_LEFT,
        XBOX_SHOULDER_RIGHT,
        XBOX_BUTTON_SELECT, //110
        XBOX_BUTTON_START,
        XBOX_CLICK_LEFT,
        XBOX_CLICK_RIGHT,
        XBOX_BUTTON_XBOX,

        //PS2 AND PS3, both share the same button inputs
        PS_JOYSTICK_LEFT_AXIS_Y,
        PS_JOYSTICK_LEFT_AXIS_X,
        PS_JOYSTICK_RIGHT_AXIS_X,
        PS_JOYSTICK_RIGHT_AXIS_Y,

        PS_DPAD,

        PS_BUTTON_TRIANGLE,
        PS_BUTTON_CIRCLE,
        PS_BUTTON_X,
        PS_BUTTON_SQUARE,
        PS_BUTTON_L2,
        PS_BUTTON_R2,
        PS_BUTTON_L1,
        PS_BUTTON_R1,
        PS_BUTTON_SELECT,
        PS_BUTTON_START,
        PS_CLICK_L3,
        PS_CLICK_R3,

        //always have this flag in the end
        DEVICE_INPUT_SIZE
    };

    enum BUTTON_STATE {
        PRESS,
        RELEASE
    };

    enum MOUSE {
        MOUSE_MOVED_TO,
        MOUSE_SCROLL,

        //always have this flag in the end
        MOUSE_SIZE
    };
}

#endif // YINPUT_H
