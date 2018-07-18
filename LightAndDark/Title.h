#pragma once

class Title
	: public MyBaseApp::Scene
{
public:
	Title();
	~Title();

	void init() override;
	void update() override;
	void draw() const override;
};