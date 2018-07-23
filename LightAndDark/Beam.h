# pragma once

# include "Marill.h"

class Beam
	: public Task
{
public:
	Beam() = default;
	Beam(const Vec2& pos);
	~Beam();

	void hitCheck(Marill& enemy);

private:
	void update();
	void draw();

	Vec2 m_pos;
	Line m_line;
	Stopwatch time;

	TaskCall m_draw;
	TaskCall m_update;

	TaskLink m_send;
};

