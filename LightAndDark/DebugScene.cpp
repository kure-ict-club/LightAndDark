#include "stdafx.h"
#include "DebugScene.h"


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


}

void DebugScene::draw() const
{
	FontAsset(L"normal_10")(L"Debug").draw();
}
