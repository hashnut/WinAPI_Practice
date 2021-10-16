#include "stdafx.h"
#include "Item.h"

Item::Item()
{
}

Item::~Item()
{
}

void Item::Init()
{
	m_nShieldDelay = 500;
}

void Item::Update()
{
	if (m_nShieldDelay >= 500) {
		shield newShield;

		newShield.rt = ELLIPSE_MAKE(rand() % (WINSIZEX - 15), (WINSIZEY - 30), newShield.shieldRadius);


	}
	else m_nShieldDelay++;

}

void Item::Render()
{
}
