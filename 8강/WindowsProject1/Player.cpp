#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::Init()
{
	m_ptPos1 = { WINSIZEX / 2, WINSIZEY - 30 };
	m_fMoveSpeed = 20;
	m_rtSize = 50;
}

void Player::Update()
{
	// 키입력 처리
	if (g_pKeyManager->isStayDown(VK_LEFT) || g_pKeyManager->isStayKeyDown('A')) // 0x0001
		m_ptPos1.x -= (m_rtBox1.left >= m_fMoveSpeed) ? m_fMoveSpeed : 0;
	else if (g_pKeyManager->isStayDown(VK_RIGHT) || g_pKeyManager->isStayKeyDown('D'))
		m_ptPos1.x += (m_rtBox1.right <= WINSIZEX - m_fMoveSpeed) ? m_fMoveSpeed : 0;

	// 포지션 위치에 따른 렉트 정보 업데이트
	m_rtBox1 = RECT_MAKE(m_ptPos1.x, m_ptPos1.y, m_rtSize);
}

void Player::Render()
{
	RECT_DRAW(m_rtBox1);
}
