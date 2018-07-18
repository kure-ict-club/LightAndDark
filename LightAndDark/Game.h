#pragma once
class Game
	: public MyBaseApp::Scene
{
public:
	Game();
	~Game();

	void init() override;
	void update() override;
	void draw() const override;
};

