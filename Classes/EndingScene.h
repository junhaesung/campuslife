#ifndef __ENDING_SCENE_H__
#define __ENDING_SCENE_H__

#include "cocos2d.h"

class EndingScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
	CREATE_FUNC(EndingScene);
};

#endif // __ENDING_SCENE_H__
