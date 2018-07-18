#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::init()
{
}

void Game::update()
{
	if (Input::MouseL.clicked)
	{
		changeScene(BaseSceneName::Title);
	}
}

void Game::draw() const
{
	FontAsset(L"normal_10")(L"Game").draw();
}
