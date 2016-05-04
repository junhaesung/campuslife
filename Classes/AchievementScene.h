#ifndef __ACHIEVEMENT_SCENE_H__
#define __ACHIEVEMENT_SCENE_H__

#include "cocos2d.h"

class AchievementScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(AchievementScene);

	void returnToMenuScene(Ref *sender);
	void scheduleCallBackMenuScene(float delta);

	void replaceToEndingScene(Ref *sender);
	void scheduleCallBackEndingScene(float delta);

	void pushAchieveDetailScene(Ref *sender);
	void scheduleCallBackAchieveDetailScene(float delta);
};

#endif // __HELLOWORLD_SCENE_H__
