#pragma once
#include "GameNode.h"

struct tagBox
{
	RECT	rt;
	float	speed;
};

class Objects : public GameNode
{
private:
	vector<tagBox>	m_vecBox;
	int				m_nDelay;

	int				m_nLevel;

public:
	Objects();
	~Objects();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetLevel(int n) { m_nLevel = n; }
	vector<tagBox>& GetBox() { return m_vecBox; }
};