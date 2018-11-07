//================================================================================
//
//    �N���A���S�`��N���X
//    Author : Araki Kai                                �쐬�� : 2018/06/19
//
//================================================================================



//======================================================================
//
// �C���N���[�h��
//
//======================================================================

#include "ClearLogoDraw.h"

#include <Renderer\RendererDirectX9\RendererDirectX9.h>
#include <Polygon\PlanePolygon\PlanePolygon.h>



//======================================================================
//
// �萔��`
//
//======================================================================

const std::string ClearLogoDraw::TEXTURE_NAME = "UI/Clear.png";
const float ClearLogoDraw::SCALE = 1.25f;



//======================================================================
//
// ��ÓI�����o�֐���`
//
//======================================================================

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ �������֐� ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ClearLogoDraw::Init()
{
	// �X�e�[�g�̕ύX
	SetState(DrawComponent::State::FIXED_2D);

	// ClearLogo�Ƀ_�E���L���X�g
	clear_logo_ = (ClearLogo*)GetGameObjectOrigin();

	// �e�N�X�`���̓o�^
	decale_texture_ = TextureManager::AddUniqueData(&TEXTURE_NAME);

	// �g�k
	clear_logo_->GetTransform()->GetScale()->x = decale_texture_->GetWidth() * SCALE;
	clear_logo_->GetTransform()->GetScale()->y = decale_texture_->GetHeight() * (SCALE + 0.2f);

	// �ړ�
	*clear_logo_->GetTransform()->GetPosition() = Vec3(0.0f, 0.0f, 0.0f);
	
	clear_logo_->GetTransform()->UpdateWorldMatrixSRT();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ �I�������֐� ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ClearLogoDraw::Uninit()
{
	
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ �`��֐� ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ClearLogoDraw::Draw(unsigned mesh_index)
{
	mesh_index = mesh_index;

	clear_logo_->plane_polygon_->Draw();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ ���b�V�����擾�֐� ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

unsigned ClearLogoDraw::GetMeshNum()
{
	return clear_logo_->plane_polygon_->GetMeshNum();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ �}�e���A���̎擾�֐� ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

D3DMATERIAL9* ClearLogoDraw::GetMaterial(unsigned mesh_index)
{
	mesh_index = mesh_index;

	return clear_logo_->plane_polygon_->GetMaterial();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ �f�J�[���e�N�X�`�������擾�֐� ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

LPDIRECT3DTEXTURE9 ClearLogoDraw::GetDecaleTexture(unsigned mesh_index)
{
	mesh_index = mesh_index;

	return decale_texture_->GetHandler();
}