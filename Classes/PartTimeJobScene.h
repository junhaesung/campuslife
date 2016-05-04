#ifndef __PARTTIMEJOB_SCENE_H__
#define __PARTTIMEJOB_SCENE_H__

#include "cocos2d.h"

class PartTimeJobScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
	CREATE_FUNC(PartTimeJobScene);

	void toComputerScene(Ref *sender);
	void scheduleCallBackComputerScene(float delta);
};

#endif // __PARTTIMEJOB_SCENE_H__
