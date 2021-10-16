#include "stdafx.h"
#include "MainGame.h"

// OOP (Object Oriented Programming : 객체 지향 프로그래밍)
// High Cohesion, Low Coupling (높은 응집도, 낮은 결합도)

MainGame::MainGame()
	: m_pPlayer(NULL)
	, m_pObjects(NULL)
{
	srand((unsigned int)time(NULL));

	// 플레이어, 오브젝트 클래스(객체) 생성
	m_pPlayer = new Player;
	m_pObjects = new Objects;
}


MainGame::~MainGame()
{
	g_pKeyManager->ReleaseInstance();
}

void MainGame::Init()
{
	m_nScore = 500;
	m_nLevel = 1;

	// 클래스 초기화
	if (m_pPlayer) m_pPlayer->Init();
	if (m_pObjects) m_pObjects->Init();
}

void MainGame::Update()
{
	InvalidateRect(g_hWnd, NULL, false);

	m_nLevel = m_nScore / 100 + 1;
	// 레벨 정보를 오브젝트에 넘겨줘야 한다.
	if (m_pObjects) m_pObjects->SetLevel(m_nLevel);

	// 클래스 업데이트
	if (m_pPlayer) m_pPlayer->Update();
	if (m_pObjects) m_pObjects->Update();

	vector<tagBox>::iterator iter;

	for (iter = m_pObjects->GetBox().begin(); iter != m_pObjects->GetBox().end(); iter++)
	{
		RECT rt;
		RECT rtIter = iter->rt;
		if (iter->rt.top > WINSIZEY)
		{
			m_nScore++;
		}
		else if (IntersectRect(&rt, &m_pPlayer->GetRect(), &rtIter))
		{
			m_nScore -= 10;
			m_pObjects->GetBox().erase(iter);
			break;
		}
		else if (PtInRect(&rtIter, g_ptMouse))
		{
			m_nScore += 5;
			m_pObjects->GetBox().erase(iter);
			break;
		}
	}
}

void MainGame::Render()
{
	PAINTSTRUCT ps;

	HDC hdc = BeginPaint(g_hWnd, &ps);

	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	// 클래스 렌더
	if (m_pPlayer) m_pPlayer->Render();
	if (m_pObjects) m_pObjects->Render();

	char szBuf[32];

	_itoa_s(m_nLevel, szBuf, 10);
	string str = string(szBuf);
	TextOutA(g_hDC, 10, 10, str.c_str(), str.length());

	_itoa_s(m_nScore, szBuf, 10);
	str = string(szBuf);
	TextOutA(g_hDC, 10, 30, str.c_str(), str.length());

	BitBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, g_hDC, 0, 0, SRCCOPY);

	EndPaint(g_hWnd, &ps);
}