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
	};
}