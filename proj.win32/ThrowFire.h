#ifndef _H_THROW_FIRE_
#define _H_THROW_FIRE_

#include "Skill.h"
class ThrowFire : public Skill{
public:
    ThrowFire();
    ~ThrowFire();
    virtual bool init();
    CREATE_FUNC(ThrowFire);

    void createFire(int base_hurt);
    void EndSkill();
};

#endif