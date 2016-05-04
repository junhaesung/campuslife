#ifndef __TIMETABLETUTORIAL_SCENE_H__
#define __TIMETABLETUTORIAL_SCENE_H__

#include "cocos2d.h"

class TimeTableTutorialScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
	CREATE_FUNC(TimeTableTutorialScene);

	void toTimeTableScene(Ref *sender);
	void scheduleCallBackTimeTableScene(float delta);
};

#endif // __TIMETABLETUTORIAL_SCENE_H__
