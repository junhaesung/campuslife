#include "EndingScene.h"
#include "AchievementScene.h"
#include "EndingDetailScene.h"

USING_NS_CC;

Scene* EndingScene::createScene()
{
    auto scene = Scene::create();
	auto layer = EndingScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool EndingScene::init()
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
	auto label = Label::createWithTTF("EndingScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	// �޴� �� �����
	auto label_01 = Label::createWithSystemFont("ToMenu", "consolas", 30.0);
	label_01->setTextColor(Color4B::WHITE);
	auto label_02 = Label::createWithSystemFont("ToAchievementScene", "consolas", 30.0);
	label_02->setTextColor(Color4B::WHITE);
	auto label_03 = Label::createWithSystemFont("ToEndingDetailScene", "consolas", 30.0);
	label_03->setTextColor(Color4B::WHITE);

	// �޴� ������ �����
	auto item_01 = MenuItemLabel::create(label_01, CC_CALLBACK_1(EndingScene::returnToMenuScene, this));
	auto item_02 = MenuItemLabel::create(label_02, CC_CALLBACK_1(EndingScene::replaceToAchievementScene, this));
	auto item_03 = MenuItemLabel::create(label_03, CC_CALLBACK_1(EndingScene::pushEndingDetailScene, this));

	// �޴� �����
	auto menu = Menu::create(item_01, item_02, item_03, NULL);
	menu->alignItemsVertically();
	this->addChild(menu);

    return true;
}
void EndingScene::returnToMenuScene(Ref *sender)
{
	// �׼� ����
	// 1.5�� �Ŀ� �ݹ��Լ� ȣ��
	this->scheduleOnce(schedule_selector(EndingScene::scheduleCallBackMenuScene), 0);
}

void EndingScene::scheduleCallBackMenuScene(float delta)
{
	// pop�ϰ� �޴�ȭ������ ���ư�
	Director::getInstance()->popScene();
}

void EndingScene::replaceToAchievementScene(Ref *sender)
{
	// �׼� ����
	// 1.5�� �Ŀ� �ݹ��Լ� ȣ��
	this->scheduleOnce(schedule_selector(EndingScene::scheduleCallBackAchievementScene), 0);
}

void EndingScene::scheduleCallBackAchievementScene(float delta)
{
	// Achievement scene ���� replace
	Director::getInstance()->replaceScene(AchievementScene::createScene());
}

void EndingScene::pushEndingDetailScene(Ref *sender)
{
	// �׼� ����
	// 1.5�� �Ŀ� �ݹ��Լ� ȣ��
	this->scheduleOnce(schedule_selector(EndingScene::scheduleCallBackEndingDetailScene), 0);
}

void EndingScene::scheduleCallBackEndingDetailScene(float delta)
{
	// push EndingDetail scene ����
	Director::getInstance()->pushScene(EndingDetailScene::createScene());
}