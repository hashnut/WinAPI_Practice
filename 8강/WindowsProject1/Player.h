#pragma once
#include "GameNode.h"
class Player : public GameNode
{
private:
	POINT			m_ptPos1;
	RECT			m_rtBox1;
	int				m_rtSize;
	float			m_fMoveSpeed;

public:
	Player();
	~Player();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	RECT& GetRect() { return m_rtBox1; }
	int GetRectSize() { return m_rtSize; }
};

