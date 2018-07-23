# include "stdafx.h"
# include "CallGroup.h"
# include "Enemy.h"

Enemy::Enemy(const Vec2 & pos)
	: Task()
	, m_pos(pos)
	, m_image(L"Asset/ƒ}ƒŠƒ‹.png")
	, m_texture(m_image)
	, m_core(Imaging::FindExternalContour(m_image, true))
	, m_update(this, &Enemy::update, CallGroup::Update)
	, m_draw(this, &Enemy::draw, CallGroup::Draw)
	, m_send(this)
{
	m_core.moveBy(m_pos);
}

Enemy::~Enemy()
{
}

s3d::Polygon Enemy::getPolygon() const
{
	return m_core;
}

void Enemy::update()
{

}

void Enemy::draw()
{
	m_texture.draw(m_pos);
}
