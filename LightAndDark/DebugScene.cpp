#include "stdafx.h"
#include "DebugScene.h"


DebugScene::DebugScene()
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
		changeScene(SceneName::Title);
	}
}

void DebugScene::draw() const
{
	FontAsset(L"normal_10")(L"Debug").draw();
}
