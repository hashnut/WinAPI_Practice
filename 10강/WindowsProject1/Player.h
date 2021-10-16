#pragma once
#include "GameNode.h"
class Player : public GameNode
{
private:
	POINT			m_ptPos1;
	RECT			m_rtBox1;
	float			m_fMoveSpeed;

public:
	Player();
	~Player();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	RECT& GetRect() { return m_rtBox1; }
};

