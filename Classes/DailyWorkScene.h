#ifndef __DAILYWORK_SCENE_H__
#define __DAILYWORK_SCENE_H__

#include "cocos2d.h"

class DailyWorkScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
	CREATE_FUNC(DailyWorkScene);

	void toRoomScene(Ref *sender);
	void scheduleCallBackRoomScene(float delta);
};

#endif // __DAILYWORK_SCENE_H__
