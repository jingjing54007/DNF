#include "Dungeon_RollandDeep.h"
#include "Dungeon_Home.h"
#include "Stage_RollandDeep.h"


CDungeon_RollandDeep::CDungeon_RollandDeep()
{
	m_Quit = false;
	m_NextDungeon = NULL;
}


CDungeon_RollandDeep::~CDungeon_RollandDeep()
{
}

void CDungeon_RollandDeep::DoInitDungeon()
{
	PlaySound(TEXT("./ImagePacks2/Music/forest01_new.wav"), NULL, SND_FILENAME | SND_ASYNC| SND_LOOP);
	//初始化副本场景
	CStage* p = new RollandDeepStage0();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_Score);
	m_Stages.push_back(p);

	p = new RollandDeepStage1();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_Score);
	m_Stages.push_back(p);

	p = new RollandDeepStage2();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_Score);
	m_Stages.push_back(p);

	p = new RollandDeepStage3();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_Score);
	m_Stages.push_back(p);

	p = new RollandDeepStage4();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_Score);
	m_Stages.push_back(p);

	p = new RollandDeepStage5();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_Score);
	m_Stages.push_back(p);

	p = new RollandDeepStage6();
	p->SetCharacter(m_Character);
	p->SetScorePointer(&m_Score);
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
	m_Stages[0]->SetNextStage(NEXT_STAGE(NULL, NULL, NULL, m_Stages[1]));
	m_Stages[1]->SetNextStage(NEXT_STAGE(m_Stages[3], NULL, m_Stages[0], NULL));
	m_Stages[2]->SetNextStage(NEXT_STAGE(NULL, NULL, NULL, m_Stages[3]));
	m_Stages[3]->SetNextStage(NEXT_STAGE(m_Stages[6], m_Stages[1], m_Stages[2], m_Stages[4]));
	m_Stages[4]->SetNextStage(NEXT_STAGE(NULL, NULL, m_Stages[3], 0));
	m_Stages[5]->SetNextStage(NEXT_STAGE(NULL, NULL, NULL, m_Stages[6]));
	m_Stages[6]->SetNextStage(NEXT_STAGE(NULL, m_Stages[3], m_Stages[5], NULL));

	m_Stages.at(0)->InitStage(); //设置初始场景
	m_CurStage = m_Stages.at(0);

	m_Character->SetViewSize(CStage::s_ViewWidth, CStage::s_ViewHeight, CStage::s_OffsetY);
	m_Character->SetX(180);
	m_Character->SetY(10);
	m_Character->SetZ(0);
	m_Clock_Start = clock();
}

void CDungeon_RollandDeep::DoRender(Mat& mat)
{
	if (clock() - m_Clock_Start < 3000)
	{
		s_Mat_DungeonLoading.copyTo(mat);
		return;
	}
	m_CurStage->Render(mat);

}
