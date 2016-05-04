#ifndef __ACHIEVEMENTDETAIL_SCENE_H__
#define __ACHIEVEMENTDETAIL_SCENE_H__

#include "cocos2d.h"

class AchieveDetailScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
	CREATE_FUNC(AchieveDetailScene);

	void returnToAchievementScene(Ref *sender);
	void scheduleCallBackAchievementScene(float delta);
};

#endif // __ACHIEVEMENTDETAIL_SCENE_H__
