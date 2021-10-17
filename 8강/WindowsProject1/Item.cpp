#include "stdafx.h"
#include "Item.h"
#include "player.h"

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
	// Create Shield
	if (m_nShieldDelay >= 500) {
		// shield newShield;

		// It doesn't work, even though it should work the same way as the following 4 lines of code... WHY?
		//newShield.rt = ELLIPSE_MAKE(rand() % (WINSIZEX - 15), (WINSIZEY - 30), newShield.shieldRadius);

		//newShield.rt.left = rand() % (WINSIZEX - 20);
		//newShield.rt.right = newShield.rt.left + newShield.shieldRadius * 2;
		//newShield.rt.top = (WINSIZEY - 30) - newShield.shieldRadius;
		//newShield.rt.bottom = (WINSIZEY - 30) + newShield.shieldRadius;


		m_Shield.rt.left = rand() % (WINSIZEX - 20);
		m_Shield.rt.right = m_Shield.rt.left + m_Shield.shieldRadius * 2;
		m_Shield.rt.top = (WINSIZEY - 30) - m_Shield.shieldRadius;
		m_Shield.rt.bottom = (WINSIZEY - 30) + m_Shield.shieldRadius;

		//m_vecShield.push_back(newShield);
		m_nShieldDelay = rand() % 200;
		m_Shield.shieldHP = 10;

	}
	else m_nShieldDelay++;

	if (m_Shield.shieldTimer > 0)
		m_Shield.shieldTimer--;
	else m_Shield.shieldTimer = 200;

	// Destroy Shield
	//vector<shield>::iterator iter;
	//for (iter = m_vecShield.begin(); iter != m_vecShield.end(); iter++) {
	//	iter->shieldTimer--;

	//	if (iter->shieldTimer <= 0 || iter->shieldHP <= 0) {
	//		m_vecShield.erase(iter);
	//		break;
	//	}
	//}

}

void Item::Render()
{
	//for (int i = 0; i < m_vecShield.size(); i++) {
	//	ELLIPSE_DRAW(m_vecShield[i].rt);
	//}

	if (m_Shield.shieldHP > 0 && m_Shield.shieldTimer > 0)
		ELLIPSE_DRAW(m_Shield.rt);
}
