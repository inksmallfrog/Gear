/*
    Role��
    ���н�ɫ�����Boss��NPC�Ļ��ࡣ
    ����״̬ö�ٶ���͹��������ԺͶ���������
*/
#ifndef _H_ROLE_
#define _H_ROLE_

#include <cocos2d.h>
USING_NS_CC;

//�������ģ�����ڽ��й������Ի��ȷ�Χ�ж�
struct BoundingBox {
    //����λ�õĺ���ģ��
    Rect actual;
    //���λ�õĺ���ģ��
    Rect origin;
};

//�����ɫ�����п���״̬
enum eRoleState{
    ROLE_STATE_STAND = 0,
    ROLE_STATE_WALK,
    ROLE_STATE_RUSH,
    ROLE_STATE_JUMP,
    ROLE_STATE_CROUCH,
    ROLE_STATE_ATTACK,
    ROLE_STATE_RUSHATTACK,
    ROLE_STATE_SKILL,
    ROLE_STATE_HURT,
    ROLE_STATE_DIE
};

//�����ɫ��������
enum eRoleDirection{
    ROLE_DIRECTION_LEFT, 
    ROLE_DIRECTION_RIGHT
};

enum eCollisionState{
    ROLE_COLLISION_NULL = 1 << 0,
    ROLE_COLLISION_FLOOR = 1 << 1,
    ROLE_COLLISION_WALL =  1 << 2,
    ROLE_COLLISION_BOUNCE = 1 << 3,
    ROLE_COLLISION_DROP = 1 << 4,
    ROLE_COLLISION_CORNER = ROLE_COLLISION_NULL | ROLE_COLLISION_WALL
};

class Role : public Sprite{
public:
    Role();
    virtual ~Role();

    //����CC_SYNTHESIZE���ݵ����ӽ�ɫ����
    CC_SYNTHESIZE(int, m_currentHp, CurrentHp);
    CC_SYNTHESIZE(int, m_maxHp, MaxHp);
    CC_SYNTHESIZE(int, m_currentMp, CurrentMp);
    CC_SYNTHESIZE(int, m_maxMp, MaxMp);
    CC_SYNTHESIZE(int, m_strenth, Strenth);
    CC_SYNTHESIZE(int, m_defence, Defence);
    CC_SYNTHESIZE(Vec2, m_velocity, Velocity);


    //Add other properties here

    CC_SYNTHESIZE(eRoleDirection, m_direction, Direction);
    CC_SYNTHESIZE(eRoleState, m_state, State);

    CC_SYNTHESIZE(bool, m_moveable, Moveable);
    CC_SYNTHESIZE(bool, m_dropping, Dropping);

    CC_SYNTHESIZE(BoundingBox, m_bodyBox, BodyBox);

    //״̬�������
    bool ChangeState(const eRoleState new_state);

    //���������������Ժ���Ӧ������������retain����ʹ�����ܳ��ڱ������ڴ���
    CC_SYNTHESIZE_RETAIN(Action*, m_pStandAction, StandAction);
    CC_SYNTHESIZE_RETAIN(Action*, m_pWalkAction, WalkAction);
    CC_SYNTHESIZE_RETAIN(Action*, m_pJumpAction, JumpAction);

    //Add other actions here

    //���Բ��Ŷ���
    virtual void runStandAction();
    virtual void runWalkAction();
    virtual void runJumpAction();

    //�������涯����֡����ͬ����Ŵ�0��ʼ��
    Animation* createNormalAction(const char* format_string, int frame_count, int fps);

    //CallFunc* createIdleCallbackFunc()

    BoundingBox createBoundingBox(Vec2 origin, Size size);
    virtual void updateBox(BoundingBox& box);

    //���½�ɫ
    void update();

    //����ͼ�ı�ʱ������֪ͨ
    void setMapSize(Size new_mapsize);
    Size getMapSize();

protected:
    Size m_mapSize;    //�洢��ͼ��С
    int m_lastCollisionState;
};

#endif