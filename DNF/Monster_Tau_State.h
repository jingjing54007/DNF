#pragma once
#include "Monster_State.h"

/**
 * @class CMonster_Tau_StandingState
 * @brief ţͷվ��״̬
 * 
 *
 */
class CMonster_Tau_StandingState
	:public CMonster_State
{
public:
	CMonster_Tau_StandingState(CMonster* monster) : CMonster_State(monster) {};
	~CMonster_Tau_StandingState() {};
	void InitState();
	void Update();

};

/**
 * @class CMonster_Tau_RunningState
 * @brief ţͷ����״̬
 * 
 *
 */
class CMonster_Tau_RunningState
	:public CMonster_State
{
public:
	CMonster_Tau_RunningState(CMonster* monster) : CMonster_State(monster) {};
	~CMonster_Tau_RunningState() {};
	void InitState();
	void Update();

};

/**
 * @class CMonster_Tau_AttackingState
 * @brief ţͷ����״̬
 * 
 *
 */
class CMonster_Tau_AttackingState
	:public CMonster_State
{
public:
	CMonster_Tau_AttackingState(CMonster* monster) : CMonster_State(monster) {};
	~CMonster_Tau_AttackingState() {};
	void InitState();
	void Update();
};


/**
 * @class CMonster_Tau_BeAttackedState
 * @brief ţͷ������״̬
 *
 *����д����Update������ֻ�趨���������ֵ
 */
class CMonster_Tau_BeAttackedState
	:public CMonster_BeAttackedState
{
public:
	CMonster_Tau_BeAttackedState(CMonster* monster);
	~CMonster_Tau_BeAttackedState() {};

	
	/**
	 * @brief �л�Ϊվ��״̬
	 * 
	 * 
	 * @return  void  
	 */
	 void SwitchStanding();

};


/**
 * @class CMonster_Tau_HittingState
 * @brief ţͷ"��ײ"״̬
 * 
 *
 */
class CMonster_Tau_HittingState
	:public CMonster_State
{
public:
	CMonster_Tau_HittingState(CMonster* monster) : CMonster_State(monster) {};
	~CMonster_Tau_HittingState() {}

	void InitState();
	void Update();
private:
	bool m_HitFlag; /**<  ����Ƿ�ײ��*/
};

/**
 * @class CMonster_Tau_Roar
 * @brief ţͷ"���"״̬
 * 
 *
 */
class CMonster_Tau_Roar
	:public CMonster_State
{
public:
	CMonster_Tau_Roar(CMonster* monster) : CMonster_State(monster) {};
	~CMonster_Tau_Roar() {}

	void InitState();
	void Update();
};