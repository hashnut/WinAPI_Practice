#pragma once
#include "SingletonBase.h"
#include <bitset>

using namespace std;

/*
bitset : bool 타입을 담고 있는 자료구조(컨테이너)

set() : bit 모두 1로 설정
reset() : bit 모두 0으로 설정
set(i, value) : i번째 값을 value로 설정
[] : 배열 형태의 접근이 가능 ex) bit[10] = false;
flip() : bit 값 전환 0 -> 1, 1 -> 0

all() : 모든 비트가 1일 때 트루 반환
none() : 모든 비트가 0일 때 트루 반환
any() : 1개라도 1이면 트루 반환
count() : 값이 1로 셋팅 된 비트의 갯수 반환
*/

#define g_pKeyManager KeyManager::GetInstance()

#define KEYMAX 256

class KeyManager : public SingletonBase<KeyManager>
{
private:
	bitset<KEYMAX> m_bitKeyUp;
	bitset<KEYMAX> m_bitKeyDown;
	bitset<KEYMAX> m_bitKeyToggle;

public:
	void Setup();			// 키 매니져 초기화

	bool isOnceKeyDown(int key);	// 키가 한번 눌림
	bool isOnceKeyUp(int key);		// 키를 눌렀다 땜
	bool isStayKeyDown(int key);	// 키를 누르고 있음
	bool isToggleKey(int key);		// 토글키(키를 키고 끔)
};

