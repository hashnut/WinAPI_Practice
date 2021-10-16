#pragma once
#include "GameNode.h"

struct shield
{
	RECT rt;
	int shieldRadius = 30;	// Player와 충돌 전에는 반지름이 30, 충돌 후에는 반지름이 사각형 사이즈 + 15로 잡자.
	int shieldHP = 10;		// 일정 갯수의 object와 충돌하면 사라짐
	int shieldTimer = 500;	// 일정 시간이 지나면 사라짐
};

class Item :
    public GameNode
{
private:
	vector<shield> m_vecShield;
	int m_nShieldDelay;

public:
	Item();
	~Item();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	vector<shield>& GetShield() { return m_vecShield; }
};

