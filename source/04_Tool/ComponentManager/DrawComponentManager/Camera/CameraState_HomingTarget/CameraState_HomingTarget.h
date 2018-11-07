//================================================================================
//
//    �^�[�Q�b�g�ǐՃJ�����X�e�[�g�N���X
//    Author : Araki Kai                                �쐬�� : 2018/03/21
//
//================================================================================

#ifndef	_CAMERA_STATE_HOMING_TARGET_H_
#define _CAMERA_STATE_HOMING_TARGET_H_



//======================================================================
//
// �C���N���[�h��
//
//======================================================================

#include "../Camera.h"



//======================================================================
//
// �N���X�錾
//
//======================================================================

class GameObjectOrigin;



//======================================================================
//
// �N���X��`
//
//======================================================================

class CameraState_HomingTarget : public Camera::State
{
//------------------------------------------------------------
private :
	// �萔
	static const float HOMING_CAMERA_POSITION_Y;
	static const float HOMING_CAMERA_POSITION_Z;
	static const float HOMING_CAMERA_LOOK_AT_POINT_Y;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// �����o�֐�
	void Init  (Camera* camera) override;
	void Uninit(Camera* camera) override {camera = camera;}
	void Update(Camera* camera) override;

	void SetTarget(GameObjectOrigin* target) {target_ = target;}


//------------------------------------------------------------
private :
	// �����o�ϐ�
	GameObjectOrigin* target_;
};



#endif