#ifndef __CLOSING_SCENE_H__
#define __CLOSING_SCENE_H__

#include "cocos2d.h"

class ClosingScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
	CREATE_FUNC(ClosingScene);
};

#endif // __CLOSING_SCENE_H__
