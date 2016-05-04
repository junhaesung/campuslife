#ifndef __OPENING_SCENE_H__
#define __OPENING_SCENE_H__

#include "cocos2d.h"

class OpeningScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
	CREATE_FUNC(OpeningScene);

	void toRoomScene(Ref *sender);
	void scheduleCallBackRoomScene(float delta);
};

#endif // __OPENING_SCENE_H__
