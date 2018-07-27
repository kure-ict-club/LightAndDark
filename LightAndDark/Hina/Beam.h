# pragma once

namespace Hina
{
	class Beam
		: public Task
	{
	public:
		Beam() = default;
		~Beam();
	private:
		void update();
		void draw();

		TaskCall m_update;
		TaskCall m_draw;
		TaskLink m_send;

		Vec2 m_pos;
		double m_length;
		double m_speed;
	};
}