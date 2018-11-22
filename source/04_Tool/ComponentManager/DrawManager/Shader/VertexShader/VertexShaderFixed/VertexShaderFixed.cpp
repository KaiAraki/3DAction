//================================================================================
//
//    �Œ�@�\���_�V�F�[�_�[�N���X
//    Author : Araki Kai                                �쐬�� : 2018/03/26
//
//================================================================================



//****************************************
// �C���N���[�h��
//****************************************
#include "VertexShaderFixed.h"
#include "../../../Camera/Camera.h"

#include <Component/Base/DrawBase/DrawBase.h>
#include <Renderer/Renderer.h>
#include <GameObjectManager/GameObjectManager.h>


//****************************************
// ��ÓI�����o�֐���`
//****************************************
//--------------------------------------------------
// +�������֐�
//--------------------------------------------------
void VertexShaderFixed::Init()
{
	// �f�o�C�X������
	ShaderBase::InitDevice();

	// �����_�[�X�e�[�g�̐ݒ�( �œK���̏ꍇ�͂��܂�Ă΂Ȃ��悤�ɐ݌v���� )
	((RendererDirectX9*)Renderer::GetInstance()->GetRenderer())->UseAlphaBlending(true);
	((RendererDirectX9*)Renderer::GetInstance()->GetRenderer())->SetAlphaBlending_Linear();

	// �e�N�X�`���[�X�e�[�W�X�e�[�g�̐ݒ�
	// �������e�N�X�`���X�e�[�W�ԍ�
	// ���������l�̉��Z����͏�Z(RG1*RG2�܂�ATEXTURE��DIFFUSE)
	ShaderBase::GetDevice()->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	ShaderBase::GetDevice()->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	ShaderBase::GetDevice()->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	// �T���v���[�X�e�[�g�̐ݒ�
	((RendererDirectX9*)Renderer::GetInstance()->GetRenderer())->SetDefaultSamplerState();
}



//--------------------------------------------------
// +�I���֐�
//--------------------------------------------------
void VertexShaderFixed::Uninit()
{

}



//--------------------------------------------------
// +���ʐݒ�֐�
//--------------------------------------------------
void VertexShaderFixed::CommonSetting(DrawBase* draw, Camera* camera, unsigned object_index)
{
	// �@�������1�ɐ��K��
	ShaderBase::GetDevice()->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);

	// �s��̃Z�b�g
	ShaderBase::GetDevice()->SetTransform(D3DTS_VIEW, camera->GetViewMatrix());
	ShaderBase::GetDevice()->SetTransform(D3DTS_PROJECTION, camera->GetProjectionMatrix());
	ShaderBase::GetDevice()->SetTransform(D3DTS_WORLD, draw->GetMatrix(object_index));
	
	// ���C�g�Z�b�g
	ShaderBase::GetDevice()->SetRenderState(D3DRS_LIGHTING, draw->GetDrawOrderList()->GetIsLighting());

	// ���C�g�̍X�V
	UpdateDirectionalLignt();
}



//--------------------------------------------------
// +�ŗL�ݒ�֐�
//--------------------------------------------------
void VertexShaderFixed::SpecificSetting(DrawBase* draw, Camera* camera,
										unsigned object_index, unsigned mesh_index)
{
	SetTexture(draw, object_index, mesh_index);
	SetMaterial(draw, object_index, mesh_index);
}



//--------------------------------------------------
// -�e�N�X�`���ݒ�֐�
//--------------------------------------------------
void VertexShaderFixed::SetTexture(DrawBase* draw, unsigned object_index,
								   unsigned mesh_index)
{
	LPDIRECT3DTEXTURE9 temp = draw->GetDecaleTexture(object_index, mesh_index);

	ShaderBase::GetDevice()->SetTexture(0, temp);
}



//--------------------------------------------------
// -�}�e���A���ݒ�֐� 
//--------------------------------------------------
void VertexShaderFixed::SetMaterial(DrawBase* draw, unsigned object_index,
									unsigned mesh_index)
{
	D3DMATERIAL9* temp = draw->GetMaterial(object_index, mesh_index);

	if (temp == nullptr) return;

	ShaderBase::GetDevice()->SetMaterial(temp);
}



//--------------------------------------------------
// -�}�e���A���ݒ�֐� 
//--------------------------------------------------
void VertexShaderFixed::UpdateDirectionalLignt()
{
	// ���C�g�̐ݒ�
	ZeroMemory(&directional_light_, sizeof(directional_light_));

	directional_light_.Type = D3DLIGHT_DIRECTIONAL;

	// ���C�g������P�ʃx�N�g���ő��
	Vec3 directional_light_vector = *GameObjectManager::GetDrawManager()->GetDirectionalLightVector();
	D3DXVec3Normalize((D3DXVECTOR3*)&directional_light_.Direction, &directional_light_vector);

	// ���C�g�J���[
	directional_light_.Diffuse.r = 1.0f;
	directional_light_.Diffuse.g = 1.0f;
	directional_light_.Diffuse.b = 1.0f;
	directional_light_.Diffuse.a = 1.0f;

	// �A���r�G���g���C�g
	directional_light_.Ambient.r = 0.1f;
	directional_light_.Ambient.g = 0.1f;
	directional_light_.Ambient.b = 0.1f;
	directional_light_.Ambient.a = 1.0f;

	// �O���[�o���A���r�G���g�̐ݒ�
	ShaderBase::GetDevice()->SetRenderState(D3DRS_AMBIENT, D3DXCOLOR(0.1f, 0.1f, 0.1f, 1.0f));

	// ���C�g���f�o�C�X�ɃZ�b�g(��������0�`4�̃��C�g�ԍ�)
	ShaderBase::GetDevice()->SetLight(0, &directional_light_);

	// 0�ԃ��C�g���g����悤�ɂ���
	ShaderBase::GetDevice()->LightEnable(0, TRUE);
}