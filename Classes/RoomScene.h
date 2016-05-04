#ifndef __ROOM_SCENE_H__
#define __ROOM_SCENE_H__

#include "cocos2d.h"

class RoomScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
	CREATE_FUNC(RoomScene);

	void toComputerScene(Ref *sender);
	void scheduleCallBackComputerScene(float delta);

	void toClosetScene(Ref *sender);
	void scheduleCallBackClosetScene(float delta);

	void toDailyWorkScene(Ref *sender);
	void scheduleCallBackDailyWorkScene(float delta);
};

#endif // __ROOM_SCENE_H__
