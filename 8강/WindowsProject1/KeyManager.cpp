#include "stdafx.h"
#include "KeyManager.h"

void KeyManager::Setup()
{
    m_bitKeyUp.reset();
    m_bitKeyDown.reset();
}

bool KeyManager::isOnceKeyDown(int key)
{
    if (GetAsyncKeyState(key) & 0x8000) {
        
        // Ű�� ������ ������ ���� ����
        if (!m_bitKeyDown[key]) {
            // ���� ���·� ��ȯ
            m_bitKeyDown.set(key, true);
            return true;
        }
     }
    else {
        m_bitKeyDown.set(key, false);
    }

    return false;
}

bool KeyManager::isOnceKeyUp(int key)
{
    if (GetAsyncKeyState(key) & 0x8000) {

        m_bitKeyUp.set(key, true);
    }
    else {
        // Ű�� �����ٰ� ���� ��
        if (m_bitKeyUp[key]) {

            // �� ���·� ��ȯ
            m_bitKeyUp.set(key, false);
            return true;
        }
    }



    return false;
}

bool KeyManager::isStayKeyDown(int key)
{
    if (GetAsyncKeyState(key) & 0x8000) return true;
    return false;
}

bool KeyManager::isToggleKey(int key)
{
    if (GetAsyncKeyState(key) & 0x0001) return true;
    return false;
}

