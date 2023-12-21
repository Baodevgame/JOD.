#include "GameScene.h"
#include"MainMenu.h"
#include"ui/CocosGUI.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool GameScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto background = Sprite::create("bg1.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background->setScale(1);
	this->addChild(background, -1);
	
	auto button = ui::Button::create("14.png");
	button->setTitleText("Back");
	button->setTitleFontName("fonts/victoria.ttf");
	button->setTitleFontSize(100);
	button->setTitleColor(Color3B::BLACK);
	button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
		{
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				CCLOG("Button 1 clicked!");
				Director::getInstance()->replaceScene(TransitionFade::create(2, MainMenu::createScene()));
				break;
			case ui::Widget::TouchEventType::CANCELED:
				break;
			default:
				break;
			}
		});
	button->setPosition(Vec2(visibleSize.width / 2-550, visibleSize.height /2+350));
	button->setScale(0.5);
	this->addChild(button);

    return true;
}


void GameScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}

