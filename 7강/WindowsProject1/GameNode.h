#pragma once
class GameNode
{
public:
	GameNode();
	~GameNode();

	virtual void Init()		= 0;	// ���� ���� �Լ�
	virtual void Update()	= 0;
	virtual void Render()	= 0;
};

