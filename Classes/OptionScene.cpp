#include "OptionScene.h"

USING_NS_CC;

Scene* OptionScene::createScene()
{
    auto scene = Scene::create();
	auto layer = OptionScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool OptionScene::init()
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
	auto label = Label::createWithTTF("OptionScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	// 메뉴 아이템 만들기
	auto label_menu = Label::createWithSystemFont("ToMenu", "consolas", 30.0);
	label_menu->setTextColor(Color4B::WHITE);
	auto item_01 = MenuItemLabel::create(label_menu, CC_CALLBACK_1(OptionScene::returnToMenuScene, this));

	// 메뉴 만들기
	auto menu = Menu::create(item_01, NULL);
	menu->alignItemsVertically();
	this->addChild(menu);

    return true;
}

void OptionScene::returnToMenuScene(Ref *sender)
{
	// 액션 실행

	// 1.5초 후에 콜백함수 호출
	this->scheduleOnce(schedule_selector(OptionScene::scheduleCallBackMenuScene), 0);
}

void OptionScene::scheduleCallBackMenuScene(float delta)
{
	// pop하고 메뉴화면으로 돌아감
	Director::getInstance()->popScene();
}
