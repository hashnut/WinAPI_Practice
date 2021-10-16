#include "stdafx.h"
#include "MainGame.h"


MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::Init()
{
	m_ptPos1 = { WINSIZEX / 2, WINSIZEY - 30 };
	m_fMoveSpeed = 20;
	m_nScore = 500;
	m_nLevel = 1;
	m_nDelay = 50;
}

void MainGame::Update()
{
	InvalidateRect(g_hWnd, NULL, true);

	// 키입력 처리
	if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState('A') & 0x8000) // 0x0001
		m_ptPos1.x -= (m_rtBox1.left >= m_fMoveSpeed) ? m_fMoveSpeed : 0;
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState('D') & 0x8000)
		m_ptPos1.x += (m_rtBox1.right <= WINSIZEX - m_fMoveSpeed) ? m_fMoveSpeed : 0;

	m_nLevel = m_nScore / 100 + 1;

	// 포지션 위치에 따른 렉트 정보 업데이트
	m_rtBox1 = RECT_MAKE(m_ptPos1.x, m_ptPos1.y, 50);

	if (m_nDelay >= 50)
	{
		tagBox box;
		box.rt.left = rand() % (WINSIZEX - 15);
		box.rt.right = box.rt.left + 30;
		box.rt.top = -30;
		box.rt.bottom = 0;

		box.speed = rand() % 11 + 5;

		m_vecBox.push_back(box);
		m_nDelay = rand() % 50;
	}
	else
		m_nDelay += m_nLevel;

	vector<tagBox>::iterator iter;

	for (iter = m_vecBox.begin(); iter != m_vecBox.end(); iter++)
	{
		iter->rt.top += iter->speed;
		iter->rt.bottom += iter->speed;

		RECT rt;
		RECT rtIter = iter->rt;
		if (iter->rt.top > WINSIZEY)
		{
			m_nScore++;
			m_vecBox.erase(iter);
			break;
		}
		else if (IntersectRect(&rt, &m_rtBox1, &rtIter))
		{
			m_nScore -= 10;
			m_vecBox.erase(iter);
			break;
		}
		else if (PtInRect(&rtIter, g_ptMouse))
		{
			m_nScore += 5;
			m_vecBox.erase(iter);
			break;
		}
	}
}

void MainGame::Render()
{
	PAINTSTRUCT ps;

	HDC hdc = BeginPaint(g_hWnd, &ps);

	RECT_DRAW(m_rtBox1);

	for (int i = 0; i < m_vecBox.size(); i++)
	{
		RECT_DRAW(m_vecBox[i].rt);
	}

	char szBuf[32];

	_itoa_s(m_nLevel, szBuf, 10);
	string str = string(szBuf);
	TextOutA(hdc, 10, 10, str.c_str(), str.length());

	_itoa_s(m_nScore, szBuf, 10);
	str = string(szBuf);
	TextOutA(hdc, 10, 30, str.c_str(), str.length());

	EndPaint(g_hWnd, &ps);
}