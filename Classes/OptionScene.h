#ifndef __OPTION_SCENE_H__
#define __OPTION_SCENE_H__

#include "cocos2d.h"

class OptionScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(OptionScene);

	void returnToMenuScene(Ref *sender);
	void scheduleCallBackMenuScene(float delta);
};

#endif // __OPTION_SCENE_H__
