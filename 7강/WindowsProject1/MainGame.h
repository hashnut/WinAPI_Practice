#pragma once
#include "GameNode.h"
class MainGame : public GameNode
{
private:
	struct tagBox
	{
		RECT	rt;
		float	speed;
	};

private:
	POINT			m_ptPos1;
	RECT			m_rtBox1;
	float			m_fMoveSpeed;
	int				m_nScore;
	int				m_nLevel;

	vector<tagBox>	m_vecBox;
	int				m_nDelay;

public:
	MainGame();
	~MainGame();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
};

