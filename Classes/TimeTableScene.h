#ifndef __TIMETABLE_SCENE_H__
#define __TIMETABLE_SCENE_H__

#include "cocos2d.h"

class TimeTableScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
	CREATE_FUNC(TimeTableScene);

	void toComputerScene(Ref *sender);
	void scheduleCallBackComputerScene(float delta);
};

#endif // __TIMETABLE_SCENE_H__
