#include "ComputerScene.h"
#include "PartTimeJobScene.h"
#include "TimeTableScene.h"
#include "TimeTableTutorialScene.h"

USING_NS_CC;

Scene* ComputerScene::createScene()
{
    auto scene = Scene::create();
	auto layer = ComputerScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool ComputerScene::init()
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
	auto label = Label::createWithTTF("ComputerScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	// 메뉴 라벨
	auto label_01 = Label::createWithSystemFont("toPartTimeJobScene", "consolas", 30.0);
	label_01->setTextColor(Color4B::WHITE);
	auto label_02 = Label::createWithSystemFont("toTimeTableScene", "consolas", 30.0);
	label_02->setTextColor(Color4B::WHITE);
	auto label_03 = Label::createWithSystemFont("toRoomScene", "consolas", 30.0);
	label_03->setTextColor(Color4B::WHITE);
	auto label_04 = Label::createWithSystemFont("toTimeTableTutorialScene", "consolas", 30.0);
	label_04->setTextColor(Color4B::WHITE);

	// 메뉴 아이템
	auto item_01 = MenuItemLabel::create(label_01, CC_CALLBACK_1(ComputerScene::toPartTimeJobScene, this));
	auto item_02 = MenuItemLabel::create(label_02, CC_CALLBACK_1(ComputerScene::toTimeTableScene, this));
	auto item_03 = MenuItemLabel::create(label_03, CC_CALLBACK_1(ComputerScene::toRoomScene, this));
	auto item_04 = MenuItemLabel::create(label_04, CC_CALLBACK_1(ComputerScene::toTimeTableTutorialScene, this));

	// 메뉴
	auto menu = Menu::create(item_01, item_02, item_03, item_04, NULL);
	menu->alignItemsVertically();
	this->addChild(menu);

    return true;
}

void ComputerScene::toPartTimeJobScene(Ref *sender)
{
	this->scheduleOnce(schedule_selector(ComputerScene::scheduleCallBackPartTimeJobScene), 0);
}
void ComputerScene::scheduleCallBackPartTimeJobScene(float delta)
{
	Director::getInstance()->pushScene(PartTimeJobScene::createScene());
}

void ComputerScene::toTimeTableScene(Ref *sender)
{
	this->scheduleOnce(schedule_selector(ComputerScene::scheduleCallBackTimeTableScene), 0);
}
void ComputerScene::scheduleCallBackTimeTableScene(float delta)
{
	Director::getInstance()->pushScene(TimeTableScene::createScene());
}

void ComputerScene::toRoomScene(Ref *sender)
{
	this->scheduleOnce(schedule_selector(ComputerScene::scheduleCallBackRoomScene), 0);
}
void ComputerScene::scheduleCallBackRoomScene(float delta)
{
	Director::getInstance()->popScene();
}

void ComputerScene::toTimeTableTutorialScene(Ref *sender)
{
	this->scheduleOnce(schedule_selector(ComputerScene::scheduleCallBackTimeTableTutorialScene), 0);
}
void ComputerScene::scheduleCallBackTimeTableTutorialScene(float delta)
{
	Director::getInstance()->pushScene(TimeTableTutorialScene::createScene());
}
