#include "stdafx.h"
#include "Title.h"


Title::Title()
{
}


Title::~Title()
{
}

void Title::init()
{
}

void Title::update()
{
	if (Input::MouseL.clicked)
	{
		changeScene(SceneName::Game);
	}
}

void Title::draw() const
{
	FontAsset(L"normal_10")(L"Title").draw();
}
