//================================================================================
//
//    �Q�[���V�[���X�e�[�g�N���X(�X�^�[�g)
//    Author : Araki Kai                                �쐬�� : 2018/11/06
//
//================================================================================



//****************************************
// �C���N���[�h��
//****************************************
#include "GameSceneState_Start.h"
#include "../../GameScene.h"

#include <SceneManager/SceneManager.h>
#include <Scenes/ResultScene/ResultScene.h>
#include <Scenes/ResultScene/ResultSceneState/ResultSceneState_Start/ResultSceneState_Start.h>

#include <ResourceManager\ResourceManager.h>
#include <SafeRelease/SafeRelease.h>
#include <ConvertToFrame\MeterToFrame\MeterToFrame.h>
#include <Keyboard\Keyboard.h>

#include <3D\Coin\CoinFactory\CoinFactory.h>
#include <3D\Enemy\EnemyFactory\EnemyFactory.h>
#include <3D\Field\FieldFactory\FieldFactory.h>
#include <3D\SkyDome\SkyDomeFactory\SkyDomeFactory.h>
#include <3D\Player\PlayerFactory\PlayerFactory.h>
#include <2D\UI\Score\ScoreFactory\ScoreFactory.h>



//****************************************
// ��ÓI�����o�֐���`
//****************************************
//--------------------------------------------------
// +�������֐�
//--------------------------------------------------
void GameSceneState_Start::Init()
{
	// �Q�[���V�[���̎擾
	game_scene_ = (GameScene*)scene_;

	// �Q�[���V�[�����ʃf�[�^�[�̏�����
	game_scene_->SetIsClear(false);
	game_scene_->SetScore(0);

	// �f�t�H���g�J�����̍쐬
	DrawComponentManager::CreateDefaultCamera(new CameraState_CrawlUp());

	// �R�C���̍쐬
	CoinFactory coin_factory;
	Coin* temp = coin_factory.Create();
	*temp->GetTransform()->GetPosition() = Vec3(5.0f, 0.0f, 0.0f);
	temp->GetTransform()->UpdateWorldMatrixSRT();

	temp = coin_factory.Create();
	*temp->GetTransform()->GetPosition() = Vec3(5.0f, 0.0f, 5.0f);
	temp->GetTransform()->UpdateWorldMatrixSRT();

	temp = coin_factory.Create();
	*temp->GetTransform()->GetPosition() = Vec3(-5.0f, 0.0f, -5.0f);
	temp->GetTransform()->UpdateWorldMatrixSRT();

	// �X�J�C�h�[��
	SkyDomeFactory sky_dome_factory;
	sky_dome_factory.Create();


	// �t�B�[���h
	FieldFactory field_factory;
	field_factory.Create();


	// �v���C���[
	PlayerFactory player_factory;
	player_factory.Create(game_scene_);

	// �G
	EnemyFactory enemy_factory;
	Enemy* temp2 = enemy_factory.Create();
	*temp2->GetTransform()->GetPosition() = Vec3(-5.0f, 0.0f, 5.0f);
	temp2->GetTransform()->UpdateWorldMatrixSRT();



	// �X�R�A
	ScoreFactory score_factory;
	score_factory.Create(game_scene_);
}



//--------------------------------------------------
// +�I���֐�
//--------------------------------------------------
void GameSceneState_Start::Uninit()
{
}



//--------------------------------------------------
// +�X�V�֐�
//--------------------------------------------------
void GameSceneState_Start::Update()
{
	// �N���A
	if (game_scene_->GetScore() >= 90)
	{
		game_scene_->GetSceneManager()->GetCommonData()->SetIsClear(true);
		game_scene_->GetSceneManager()->SetNextScene(new ResultScene(new ResultSceneState_Start()));
	}

	// ���s
	if (game_scene_->GetScore() < 0)
	{
		game_scene_->GetSceneManager()->GetCommonData()->SetIsClear(false);
		game_scene_->GetSceneManager()->SetNextScene(new ResultScene(new ResultSceneState_Start()));
	}
}



//--------------------------------------------------
// +���Z�b�g�֐�
//--------------------------------------------------
void GameSceneState_Start::Reset()
{

}