#pragma once
#include "Dungeon.h"
#include "OtherObject.h"
#include "AnimationEffect.h"
#include "Hud.h"

#define FRAMES_PER_SECOND  500
#define FRAMES_TIME ( 1000 / FRAMES_PER_SECOND )
class CGame
{
private:
	bool m_IsRunning;
	void HandleInput(); //�������룺��Щ��������������ڽ����豸�����̣���꣬��Ϸ�������ȵȣ�������
	void Update();	//ϵͳ���£�update������������������Է��ģ��Ը�����ϵͳ���и��£��Ծ�����ǰ����Ϸ״̬
	void Render(); //��Ⱦ��render������������Ϸ����������Ⱦ��
	void __MergeMat(Mat& a, Mat& b, Mat& b_, int div);
	CCharacter* m_Character;
	CDungeon* m_CurDungeon;
	CHud* m_Hud;
	//Dungeon* dungeon_rolland;

	Mat m_Mat_ui;
	Mat m_Mat_ui_mask;
	Mat m_Mat_Game;
	
	std::vector<CAnimationEffect*> m_AnimationEffects;
public:
	CGame();
	~CGame();
	void Run();
	void InitRec();

	void onMouse(int Event, int x, int y, int flags, void* param);
};
