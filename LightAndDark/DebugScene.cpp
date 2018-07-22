# include "stdafx.h"
# include "DebugScene.h"
# include "Pikachu.h"
# include "Enemy.h"

DebugScene::DebugScene()
	: image()
{
}


DebugScene::~DebugScene()
{
}

void DebugScene::init()
{
}

void DebugScene::update()
{
	if (Input::MouseL.clicked)
	{
		changeScene(BaseSceneName::Title);
	}

	if (Input::KeyP.clicked)
	{
		Vec2 vec(0, 0);
		Create<Pikachu>(std::move(vec));
	}
	if (Input::KeyE.clicked)
	{
		Vec2 vec(Random(Window::Width()), Random(Window::Height()));
		Create<Enemy>(std::move(vec));
	}

}

void DebugScene::draw() const
{
	FontAsset(L"normal_10")(L"Debug").draw();
}
