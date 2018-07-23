# include "stdafx.h"
# include "CallGroup.h"
# include "Spark.h"
# include "Pikachu.h"

Spark::Spark(const Vec2 & pos, const Color & color)
	: Task()
	, m_pos(pos)
	, m_vec(RandomVec2())
	, m_speed(Random(5.0, 20.0))
	, m_color(color)
	, m_update(this, &Spark::update, CallGroup::Update)
	, m_draw(this, &Spark::draw, CallGroup::Draw, pika::CallPriority::Spark)
	, m_send(this)
{
}


Spark::~Spark()
{
}

void Spark::hitCheck(Enemy & enemy)
{
	if (Circle(m_pos, 2.0).intersects(enemy.getPolygon()))
	{
		enemy.Destroy();
	}
}

void Spark::update()
{
	if (--m_speed <= 0.0)
	{
		this->Destroy();
	}

	m_pos += m_vec * m_speed;	

	TaskLink::All::Call<Enemy>(this, &Spark::hitCheck);
}

void Spark::draw()
{
	Circle(m_pos, 2.0).draw(m_color);
}
