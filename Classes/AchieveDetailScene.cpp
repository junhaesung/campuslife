#include "AchieveDetailScene.h"

USING_NS_CC;

Scene* AchieveDetailScene::createScene()
{
    auto scene = Scene::create();
	auto layer = AchieveDetailScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool AchieveDetailScene::init()
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

	auto label = Label::createWithTTF("AchieveDetailScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	// 메뉴 라벨 만들기
	auto label_01 = Label::createWithSystemFont("ToAchivementScene", "consolas", 30.0);
	label_01->setTextColor(Color4B::WHITE);

	// 메뉴 아이템 만들기
	auto item_01 = MenuItemLabel::create(label_01, CC_CALLBACK_1(AchieveDetailScene::returnToAchievementScene, this));

	// 메뉴 만들기
	auto menu = Menu::create(item_01, NULL);
	menu->alignItemsVertically();
	this->addChild(menu);

    return true;
}
void AchieveDetailScene::returnToAchievementScene(Ref *sender)
{
	// 액션 실행
	// 1.5초 후에 콜백함수 호출
	this->scheduleOnce(schedule_selector(AchieveDetailScene::scheduleCallBackAchievementScene), 0);
}

void AchieveDetailScene::scheduleCallBackAchievementScene(float delta)
{
	// pop하고 AchievementScene으로 돌아감
	Director::getInstance()->popScene();
}