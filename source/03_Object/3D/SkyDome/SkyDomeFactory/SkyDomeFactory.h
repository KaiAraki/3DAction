//================================================================================
//
//    �X�J�C�h�[���t�@�N�g���[�N���X
//    Author : Araki Kai                                �쐬�� : 2018/07/22
//
//================================================================================

#ifndef	_SKY_DOME_FACTORY_H_
#define _SKY_DOME_FACTORY_H_



//======================================================================
//
// �C���N���[�h��
//
//======================================================================

#include "../SkyDome.h"
#include "../SkyDomeUpdate/SkyDomeUpdate.h"
#include "../SkyDomeDraw/SkyDomeDraw.h"



//======================================================================
//
// �N���X��`
//
//======================================================================

class SkyDomeFactory
{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// �����o�֐�
	SkyDome* Create()
	{
		SkyDome* temp = new SkyDome();

		// ������
		temp->Init(new SkyDomeUpdate(),
				   new SkyDomeDraw());

		return temp;
	}
};



#endif