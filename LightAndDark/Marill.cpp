# include "stdafx.h"
# include "CallGroup.h"
# include "Marill.h"

Marill::Marill(const Vec2 & pos)
	: Task()
	, m_pos(pos)
	, m_image(L"Asset/ƒ}ƒŠƒ‹.png")
	, m_texture(m_image)
	, m_core(Imaging::FindExternalContour(m_image, true))
	, m_update(this, &Marill::update, CallGroup::Update)
	, m_draw(this, &Marill::draw, CallGroup::Draw)
	, m_send(this)
{
	m_core.moveBy(m_pos);
}

Marill::~Marill()
{
}

s3d::Polygon Marill::getPolygon() const
{
	return m_core;
}

void Marill::update()
{

}

void Marill::draw()
{
	m_texture.draw(m_pos);
}
