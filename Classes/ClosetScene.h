#ifndef __CLOSET_SCENE_H__
#define __CLOSET_SCENE_H__

#include "cocos2d.h"

class ClosetScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
	CREATE_FUNC(ClosetScene);
};

#endif // __CLOSET_SCENE_H__
