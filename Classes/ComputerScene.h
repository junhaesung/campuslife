#ifndef __COMPUTER_SCENE_H__
#define __COMPUTER_SCENE_H__

#include "cocos2d.h"

class ComputerScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
	CREATE_FUNC(ComputerScene);
};

#endif // __COMPUTER_SCENE_H__
