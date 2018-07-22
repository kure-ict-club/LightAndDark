# pragma once

class Spark
	: public Task
{
public:
	Spark() = default;
	Spark(const Vec2& pos, const Color& color);
	~Spark();

private:
	void update();
	void draw();

	Vec2 m_pos;
	Vec2 m_vec;
	double m_speed;
	Color m_color;

	TaskCall m_draw;
	TaskCall m_update;

	TaskLink m_send;
};

