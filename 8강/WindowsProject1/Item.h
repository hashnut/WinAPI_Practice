#pragma once
#include "GameNode.h"

struct shield
{
	RECT rt;
	int shieldRadius = 30;	// Player�� �浹 ������ �������� 30, �浹 �Ŀ��� �������� �簢�� ������ + 15�� ����.
	int shieldHP = 10;		// ���� ������ object�� �浹�ϸ� �����
	int shieldTimer = 500;	// ���� �ð��� ������ �����
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

