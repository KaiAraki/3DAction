//================================================================================
//
//    ���U���g�V�[���N���X�w�b�_
//    Author : Araki Kai                                �쐬�� : 2018/06/19
//
//================================================================================

#ifndef	_RESULT_SCENE_H_
#define _RESULT_SCENE_H_



//****************************************
// �C���N���[�h��
//****************************************
#include <SceneBace/SceneBace.h>



/*********************************************************//**
* @brief
* ���U���g�V�[���N���X
*
* ���U���g�V�[���̃N���X
*************************************************************/
class ResultScene : public SceneBace
{
//==============================
// ��ÓI�����o�֐�
//==============================
public:
	/**
	* @brief
	* �R���X�g���N�^
	* @param
	* state : �ŏ��̃X�e�[�g
	*/
	ResultScene(StateAbstract* state) : SceneBace(state) {}
};



#endif