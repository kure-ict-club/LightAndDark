# pragma once

namespace pika
{
	enum class CallPriority
	{
		Spark,
		Beam, 
		Pika,
	};
}

class Pikachu
	: public Task
{
public:
	Pikachu() = default;

	Pikachu(const Vec2& pos);

	~Pikachu();

private:
	void update();
	void draw();

	Vec2 m_pos;
	Texture m_texture;

	TaskCall m_update;
	TaskCall m_draw;

	TaskLink m_send;
};

