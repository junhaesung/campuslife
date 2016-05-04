#ifndef __ENDINGDETAIL_SCENE_H__
#define __ENDINGDETAIL_SCENE_H__

#include "cocos2d.h"

class EndingDetailScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
	CREATE_FUNC(EndingDetailScene);
};

#endif // __ENDINGDETAIL_SCENE_H__
