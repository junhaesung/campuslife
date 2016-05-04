#include "RoomScene.h"
#include "ComputerScene.h"
#include "ClosetScene.h"
#include "DailyWorkScene.h"

USING_NS_CC;

Scene* RoomScene::createScene()
{
    auto scene = Scene::create();
	auto layer = RoomScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool RoomScene::init()
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

    // create menu, it's an autorelease object

    /////////////////////////////
    // 3. add your codes below...
	auto label = Label::createWithTTF("RoomScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	// 메뉴 라벨
	auto label_01 = Label::createWithSystemFont("toComputerScene", "consolas", 30.0);
	label_01->setTextColor(Color4B::WHITE);
	auto label_02 = Label::createWithSystemFont("toClosetScene", "consolas", 30.0);
	label_02->setTextColor(Color4B::WHITE);
	auto label_03 = Label::createWithSystemFont("toDailyWorkScene", "consolas", 30.0);
	label_03->setTextColor(Color4B::WHITE);

	// 메뉴 아이템
	auto item_01 = MenuItemLabel::create(label_01, CC_CALLBACK_1(RoomScene::toComputerScene, this));
	auto item_02 = MenuItemLabel::create(label_02, CC_CALLBACK_1(RoomScene::toClosetScene, this));
	auto item_03 = MenuItemLabel::create(label_03, CC_CALLBACK_1(RoomScene::toDailyWorkScene, this));

	// 메뉴
	auto menu = Menu::create(item_01, item_02, item_03, NULL);
	menu->alignItemsVertically();
	this->addChild(menu);

    return true;
}

void RoomScene::toComputerScene(Ref *sender)
{
	this->scheduleOnce(schedule_selector(RoomScene::scheduleCallBackComputerScene), 0);
}
void RoomScene::scheduleCallBackComputerScene(float delta)
{
	Director::getInstance()->pushScene(ComputerScene::createScene());
}

void RoomScene::toClosetScene(Ref *sender)
{
	this->scheduleOnce(schedule_selector(RoomScene::scheduleCallBackClosetScene), 0);
}
void RoomScene::scheduleCallBackClosetScene(float delta)
{
	Director::getInstance()->pushScene(ClosetScene::createScene());
}

void RoomScene::toDailyWorkScene(Ref *sender)
{
	this->scheduleOnce(schedule_selector(RoomScene::scheduleCallBackDailyWorkScene), 0);
}
void RoomScene::scheduleCallBackDailyWorkScene(float delta)
{
	Director::getInstance()->pushScene(DailyWorkScene::createScene());
}