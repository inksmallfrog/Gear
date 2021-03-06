/*
    Keyboard类，继承自Layer类
    用于键盘事件的处理
*/
#ifndef _H_KEYBOARD_
#define _H_KEYBOARD_

#include <cocos2d.h>
USING_NS_CC;

enum eKeyState{
    KEY_STATE_LEFT_ARROW = 0,
    KEY_STATE_RIGHT_ARROW,
    KEY_STATE_UP_ARROW,
    KEY_STATE_DOWN_ARROW,
    KEY_STATE_LEFT_CTRL,
    KEY_STATE_SPACE,
    KEY_STATE_Z,
    MAX_CHECK_KEY_NUMBER
};

enum eAccelerateKey{
    KEY_X = 0,
    KEY_C,
    KEY_V,
    MAX_KEY_ACCELERATE
};

class Keyboard : public Layer{
public:
    Keyboard();
    ~Keyboard();
    virtual bool init();
    CREATE_FUNC(Keyboard);

    //按键事件
    void onKeyPress(EventKeyboard::KeyCode keycode, Event* event);
    //释放按键事件
    void onKeyRelease(EventKeyboard::KeyCode keycode, Event* event);

    static bool getKeyState(eKeyState key);
    static bool m_bKeyState[MAX_CHECK_KEY_NUMBER];
    //static eToolsId m_AccelerateKey[MAX_KEY_ACCELERATE];
};

#endif