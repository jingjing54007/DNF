#include "Dungeon_RollandDeep.h"
#include "Dungeon_Home.h"
#include "RollandDeepStage.h"


CDungeon_RollandDeep::CDungeon_RollandDeep()
{
	m_Quit = false;
	m_NextDungeon = NULL;
}


CDungeon_RollandDeep::~CDungeon_RollandDeep()
{
}

void CDungeon_RollandDeep::Update()	
{
	m_CurStage->Update(this);
	m_Character->UpdateState();
	if (m_CurStage->IsBossRoom() && m_CurStage->IsClearance() && m_IsClearance == false)
	{
		m_IsClearance = true;
		int ms = clock() - m_clock_statr;
		int score = m_score - ms;
		int min = (ms / 60000);
		ms -= min * 60000;
		int sec = ms / 1000;
		ms -= sec * 1000;
		int lsec = ms * 60 / 1000;
		m_Character->GetAnimationEffects()->push_back(
			new CResultAnimation(score >= 0 ? score : 0, 0, 236783462, min, sec, lsec, min, sec, lsec, this));
	}
}

void CDungeon_RollandDeep::DoInitDungeon()
{
	//初始化副本场景
	CStage* p = new RollandDeepStage0();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_score);
	m_Stages.push_back(p);

	p = new RollandDeepStage1();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_score);
	m_Stages.push_back(p);

	p = new RollandDeepStage2();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_score);
	m_Stages.push_back(p);

	p = new RollandDeepStage3();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_score);
	m_Stages.push_back(p);

	p = new RollandDeepStage4();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_score);
	m_Stages.push_back(p);

	p = new RollandDeepStage5();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_score);
	m_Stages.push_back(p);

	p = new RollandDeepStage6();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_score);
	m_Stages.push_back(p);


//	---------------
//|          |           |
//|    5    |     6    |
//|          |           |
//|----------------------
//|          |           |        |
//|    2    |     3    |    4  |
//|          |           |        |
//|----------------------
//|          |           |
//|    0    |     1    |
//|          |           |
//----------------

	//设置场景的连接
	m_Stages[0]->SetNextStage(CStage::NEXT_STAGE(NULL, NULL, NULL, m_Stages[1]));
	m_Stages[1]->SetNextStage(CStage::NEXT_STAGE(m_Stages[3], NULL, m_Stages[0], NULL));
	m_Stages[2]->SetNextStage(CStage::NEXT_STAGE(NULL, NULL, NULL, m_Stages[3]));
	m_Stages[3]->SetNextStage(CStage::NEXT_STAGE(m_Stages[6], m_Stages[1], m_Stages[2], m_Stages[4]));
	m_Stages[4]->SetNextStage(CStage::NEXT_STAGE(NULL, NULL, m_Stages[3], 0));
	m_Stages[5]->SetNextStage(CStage::NEXT_STAGE(NULL, NULL, NULL, m_Stages[6]));
	m_Stages[6]->SetNextStage(CStage::NEXT_STAGE(NULL, m_Stages[3], m_Stages[5], NULL));

	m_Stages.at(0)->InitStage(); //设置初始场景
	m_CurStage = m_Stages.at(0);

	m_Character->SetViewSize(CStage::s_ViewWidth, CStage::s_ViewHeight, CStage::s_OffsetY);
	m_Character->SetX(180);
	m_Character->SetY(10);
	m_Character->SetZ(0);
}
