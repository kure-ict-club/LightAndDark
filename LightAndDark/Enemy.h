#pragma once
class Enemy
	: public Task
{
public:
	Enemy() = default;

	Enemy(const Vec2& pos);

	~Enemy();

	s3d::Polygon getPolygon() const;

private:
	void update();
	void draw();

	Vec2 m_pos;
	Image m_image;
	Texture m_texture;
	s3d::Polygon m_core;

	TaskCall m_update;
	TaskCall m_draw;

	TaskLink m_send;
};
