#pragma once
#include "GameNode.h"
#include "Player.h"
#include "Objects.h"


class MainGame : public GameNode
{
private:
	int				m_nScore;
	int				m_nLevel;

	Player*			m_pPlayer;
	Objects*		m_pObjects;

public:
	MainGame();
	~MainGame();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
};

