/// <summary>
/// test/TaskSystem
/// </summary>

# include <Siv3D.hpp>
# include "CallGroup.h"
# include "DebugScene.h"
# include "Title.h"
# include "Game.h"

void Main()
{
	Window::SetTitle(L"ひかりとやみ-pointN");
	Window::SetStyle(WindowStyle::Sizeable);

	SceneManager<BaseSceneName> sceneManager;
	sceneManager.add<DebugScene>(BaseSceneName::Debug);
	sceneManager.add<Title>(BaseSceneName::Title);
	sceneManager.add<Game>(BaseSceneName::Game);


	while (System::Update())
	{
		sceneManager.updateAndDraw();

		TaskCall::All::Update(CallGroup::Update);
		TaskCall::All::Update(CallGroup::Draw);

		Task::All::Update();
	}

	Task::All::Clear();
}
