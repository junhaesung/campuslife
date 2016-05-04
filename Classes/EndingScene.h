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

	void returnToMenuScene(Ref *sender);
	void scheduleCallBackMenuScene(float delta);

	void replaceToAchievementScene(Ref *sender);
	void scheduleCallBackAchievementScene(float delta);

	void pushEndingDetailScene(Ref *sender);
	void scheduleCallBackEndingDetailScene(float delta);
};

#endif // __ENDING_SCENE_H__
