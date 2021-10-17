#pragma once
#include "GameNode.h"

struct shield
{
	RECT rt;
	int shieldRadius = 10;	// Player�� �浹 ������ �������� 30, �浹 �Ŀ��� �������� �簢�� ������ + 15�� ����.
	int shieldHP = 10;		// ���� ������ object�� �浹�ϸ� �����
	int shieldTimer = 200;	// ���� �ð��� ������ �����
};

class Item :
    public GameNode
{
private:
	//vector<shield> m_vecShield;
	shield m_Shield;
	int m_nShieldDelay;

public:
	Item();
	~Item();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	RECT& GetShield() { return m_Shield.rt; }
	void MinusShieldHP() { m_Shield.shieldHP--; }
};

