# include "stdafx.h"
# include "Beam.h"

Hina::Beam::~Beam()
{
}

void Hina::Beam::update()
{
	m_length += 0.1;	//no problem
	//m_pos				//can't use
}

void Hina::Beam::draw()
{
}
