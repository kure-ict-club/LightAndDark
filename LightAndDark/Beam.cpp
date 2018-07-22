#include "stdafx.h"
# include "CallGroup.h"
# include "Beam.h"
# include "Spark.h"
# include "Pikachu.h"


Beam::Beam(const Vec2 & pos)
	: Task(TaskDestroyMode::Time, 1.0)
	, m_pos(pos)
	, m_line(pos, pos)
	, time(true)
	, m_update(this, &Beam::update, CallGroup::Update)
	, m_draw(this, &Beam::draw, CallGroup::Draw, pika::CallPriority::Beam)
	, m_send(this)
{
}


Beam::~Beam()
{
	Creates<Spark>(100, m_line.end, RandomColor());
}

void Beam::hitCheck(Enemy & enemy)
{
	if (m_line.intersects(enemy.getPolygon()))
	{
		enemy.Destroy();
	}
}

void Beam::update()
{
	m_line.end = m_pos + Vec2::Right * 6 * time.ms() / 15;
	TaskLink::All::Call<Enemy>(this, &Beam::hitCheck);
}

void Beam::draw()
{
	m_line.draw(Palette::Yellow);
}
