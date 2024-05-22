#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "GameObject.h"

class StaticObject : public GameObject {
public:
    virtual void display() = 0;
};

#endif // STATICOBJECT_H
