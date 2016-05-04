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

	void toPartTimeJobScene(Ref *sender);
	void scheduleCallBackPartTimeJobScene(float delta);

	void toTimeTableScene(Ref *sender);
	void scheduleCallBackTimeTableScene(float delta);

	void toRoomScene(Ref *sender);
	void scheduleCallBackRoomScene(float delta);

	void toTimeTableTutorialScene(Ref *sender);
	void scheduleCallBackTimeTableTutorialScene(float delta);
};

#endif // __COMPUTER_SCENE_H__
