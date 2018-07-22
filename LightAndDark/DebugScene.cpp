# include "stdafx.h"
# include "DebugScene.h"
# include "Pikachu.h"

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

}

void DebugScene::draw() const
{
	FontAsset(L"normal_10")(L"Debug").draw();
}
