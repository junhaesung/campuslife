#include "OpeningScene.h"
#include "RoomScene.h"

USING_NS_CC;

Scene* OpeningScene::createScene()
{
    auto scene = Scene::create();
	auto layer = OpeningScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool OpeningScene::init()
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
	auto label = Label::createWithTTF("OpeningScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	// 메뉴 라벨
	auto label_01 = Label::createWithSystemFont("ToRoomScene", "consolas", 30.0);
	label_01->setTextColor(Color4B::WHITE);

	// 메뉴 아이템
	auto item_01 = MenuItemLabel::create(label_01, CC_CALLBACK_1(OpeningScene::toRoomScene, this));

	// 메뉴
	auto menu = Menu::create(item_01, NULL);
	menu->alignItemsVertically();
	this->addChild(menu);

    return true;
}

void OpeningScene::toRoomScene(Ref *sender)
{
	this->scheduleOnce(schedule_selector(OpeningScene::scheduleCallBackRoomScene), 0);
}
void OpeningScene::scheduleCallBackRoomScene(float delta)
{
	//Director::getInstance()->pushScene(OptionScene::createScene());
	Director::getInstance()->replaceScene(RoomScene::createScene());
}