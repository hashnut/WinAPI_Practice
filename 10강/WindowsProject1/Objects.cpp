#include "stdafx.h"
#include "Objects.h"


Objects::Objects()
{
}


Objects::~Objects()
{
}

void Objects::Init()
{
	m_nDelay = 1000;
}

void Objects::Update()
{
	if (m_nDelay >= 1000)
	{
		tagBox box;
		box.rt.left = rand() % (WINSIZEX - 15);
		box.rt.right = box.rt.left + 30;
		box.rt.top = -30;
		box.rt.bottom = 0;

		box.speed = (rand() % 11 + 5) / 10.0f;

		m_vecBox.push_back(box);
		m_nDelay = rand() % 1000;
	}
	else
		m_nDelay += m_nLevel;

	vector<tagBox>::iterator iter;

	for (iter = m_vecBox.begin(); iter != m_vecBox.end(); iter++)
	{
		iter->rt.top += iter->speed;
		iter->rt.bottom += iter->speed;

		if (iter->rt.top > WINSIZEY + 10)
		{
			m_vecBox.erase(iter);
			break;
		}
	}
}

void Objects::Render()
{
	for (int i = 0; i < m_vecBox.size(); i++)
	{
		RECT_DRAW(m_vecBox[i].rt);
	}
}
