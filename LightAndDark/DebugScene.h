#pragma once
class DebugScene
	: public MyBaseApp::Scene
{
public:
	DebugScene();
	~DebugScene();

	void init() override;
	void update() override;
	void draw() const override;
};

