#pragma once

enum class BaseSceneName
{
	Title,
	Game,
	Debug,
};

using MyBaseApp = SceneManager<SceneName>;