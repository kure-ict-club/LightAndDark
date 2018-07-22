# include "stdafx.h"
# include "CallGroup.h"
# include "Pikachu.h"
# include "Beam.h"
# include "Enemy.h"

Pikachu::Pikachu(const Vec2 & pos)
	: Task()
	, m_pos(pos)
	, m_texture(L"Asset/Pikachu1.png")
	, m_update(this, &Pikachu::update, CallGroup::Update)
	, m_draw(this, &Pikachu::draw, CallGroup::Draw, pika::CallPriority::Pika)
	, m_send(this)
{
}

Pikachu::~Pikachu()
{
}

void Pikachu::update()
{
	if (Input::KeySpace.clicked)
	{
		Create<Beam>(m_pos);
	}

	if (Input::KeyRight.pressed)
	{
		m_pos.x += 3.0;
	}
	if (Input::KeyLeft.pressed)
	{
		m_pos.x -= 3.0;
	}
	if (Input::KeyDown.pressed)
	{
		m_pos.y += 3.0;
	}
	if (Input::KeyUp.pressed)
	{
		m_pos.y -= 3.0;
	}
}

void Pikachu::draw()
{
	m_texture.draw(m_pos);
}
