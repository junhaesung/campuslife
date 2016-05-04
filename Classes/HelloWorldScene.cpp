#include "HelloWorldScene.h"
#include "RoomScene.h"
#include "OptionScene.h"
#include "AchievementScene.h"
#include "OpeningScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
	/*
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
	*/

	// 배경그리기
	auto spr_bg = Sprite::create("background_opening_2x.png");
	spr_bg->setPosition(Point(0, 0));
	spr_bg->setAnchorPoint(Point(0, 0));
	this->addChild(spr_bg);

	// 메뉴 라벨
	auto label_01 = Label::createWithSystemFont("RoomScene", "consolas", 30.0);
	label_01->setTextColor(Color4B::BLACK);
	auto label_02 = Label::createWithSystemFont("OptionScene", "consolas", 30.0);
	label_02->setTextColor(Color4B::BLACK);
	auto label_03 = Label::createWithSystemFont("AchievementScene", "consolas", 30.0);
	label_03->setTextColor(Color4B::BLACK);
	auto label_04 = Label::createWithSystemFont("Exit", "consolas", 30.0);
	label_04->setTextColor(Color4B::BLACK);
	auto label_05 = Label::createWithSystemFont("OpeningScene", "consolas", 30.0);
	label_05->setTextColor(Color4B::BLACK);
	
	// 메뉴 아이템
	auto item_01 = MenuItemLabel::create(label_01, CC_CALLBACK_1(HelloWorld::loadRoomScene, this));
	auto item_02 = MenuItemLabel::create(label_02, CC_CALLBACK_1(HelloWorld::loadOptionScene, this));
	auto item_03 = MenuItemLabel::create(label_03, CC_CALLBACK_1(HelloWorld::loadAchievementScene, this));
	auto item_04 = MenuItemLabel::create(label_04, CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	auto item_05 = MenuItemLabel::create(label_05, CC_CALLBACK_1(HelloWorld::loadOpeningScene, this));

	// 메뉴
	auto menu = Menu::create(item_01,item_02, item_03, item_04, item_05, NULL);
	menu->alignItemsVertically();
	this->addChild(menu);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void HelloWorld::loadRoomScene(Ref *sender)
{
	this->scheduleOnce(schedule_selector(HelloWorld::scheduleCallBackRoomScene), 0);
}
void HelloWorld::scheduleCallBackRoomScene(float delta)
{
	//Director::getInstance()->pushScene(OptionScene::createScene());
	Director::getInstance()->replaceScene(RoomScene::createScene());
}

void HelloWorld::loadOptionScene(Ref *sender)
{
	this->scheduleOnce(schedule_selector(HelloWorld::scheduleCallBackOptionScene), 0);
}
void HelloWorld::scheduleCallBackOptionScene(float delta)
{
	Director::getInstance()->pushScene(OptionScene::createScene());
	//Director::getInstance()->replaceScene(OptionScene::createScene());
}

void HelloWorld::loadAchievementScene(Ref *sender)
{
	this->scheduleOnce(schedule_selector(HelloWorld::scheduleCallBackAchievementScene), 0);
}
void HelloWorld::scheduleCallBackAchievementScene(float delta)
{
	Director::getInstance()->pushScene(AchievementScene::createScene());
}

void HelloWorld::loadOpeningScene(Ref *sender)
{
	this->scheduleOnce(schedule_selector(HelloWorld::scheduleCallBackOpeningScene), 0);
}
void HelloWorld::scheduleCallBackOpeningScene(float delta)
{
	//Director::getInstance()->pushScene(OptionScene::createScene());
	Director::getInstance()->replaceScene(OpeningScene::createScene());
}
