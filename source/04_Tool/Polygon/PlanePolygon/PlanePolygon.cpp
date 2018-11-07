//================================================================================
//
//    ���ʃ|���S���N���X
//    Author : Araki Kai                                �쐬�� : 2017/12/06
//
//================================================================================




//======================================================================
//
// �C���N���[�h��
//
//======================================================================

#include "PlanePolygon.h"

#include <main.h>
#include <SafeRelease/SafeRelease.h>

#include <Texture\TextureObject\TextureObject.h>



//======================================================================
//
// �萔��`
//
//======================================================================

const int PlanePolygon::PRIMITIVE_NUM = 2;



//======================================================================
//
// ��ÓI�����o�֐���`
//
//======================================================================

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ �f�t�H���g�R���X�g���N�^ ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

PlanePolygon::PlanePolygon(XColor4 color, Vec2 plane_size)
	: vertex_buffer_(nullptr),
	index_buffer_(nullptr),
	device_(nullptr)
{
	CreateVertex((Color4)color, plane_size);
	CreateIndex();

	CreateMaterial();

	Renderer::GetInstance()->GetDevice(&device_);
	if (device_ == nullptr)
	{
		MessageBox(nullptr, "NotGetDevice!(PlanePolygon.cpp)", "Error", MB_OK);
		return;
	}

	AccessVRAM();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ �f�X�g���N�^ ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

PlanePolygon::~PlanePolygon()
{
	// ���_�o�b�t�@�̉��
	SafeRelease::PlusRelease(&vertex_buffer_);

	// �C���f�b�N�X�o�b�t�@�̉��
	SafeRelease::PlusRelease(&index_buffer_);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ �J���[�Z�b�g�֐� ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void PlanePolygon::SetColor(XColor4 color)
{
	for (std::vector<RendererDirectX9::VERTEX_3D>::size_type i = 0; i < vertex_.size(); i++)
	{
		vertex_[i].color_ = (Color4)color;
	}

	RegistrationVertex();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ UV�ݒ�֐� ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void PlanePolygon::SetUV(const TextureObject* texture, const int pattern_num)
{
	vertex_[0].texcoord_ = Vec2(texture->GetUV(pattern_num).u0, texture->GetUV(pattern_num).v0);
	vertex_[1].texcoord_ = Vec2(texture->GetUV(pattern_num).u1, texture->GetUV(pattern_num).v0);
	vertex_[2].texcoord_ = Vec2(texture->GetUV(pattern_num).u0, texture->GetUV(pattern_num).v1);
	vertex_[3].texcoord_ = Vec2(texture->GetUV(pattern_num).u1, texture->GetUV(pattern_num).v1);

	RegistrationVertex();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ �`��֐� ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void PlanePolygon::Draw()
{
	// FVF�̐ݒ�(�f�o�C�X�̕��ɒ��_�̑�����������)
	device_->SetFVF(RendererDirectX9::FVF_VERTEX_3D);

	// ���_�o�b�t�@���g��GPU�ƃo�[�e�b�N�X�o�b�t�@�̃p�C�v���C��
	// �g�������Ȃ�������NULL�������
	device_->SetStreamSource(0,										// �p�C�v���C���ԍ�
							vertex_buffer_,							// �o�[�e�b�N�X�o�b�t�@�ϐ���
							0,										// �ǂ����痬�����ނ�
							sizeof(RendererDirectX9::VERTEX_3D));	// �X�g���C�h�l(�ׂ̒��_�܂ł̒�����1���_�̑傫��)

	// �C���f�b�N�X���Z�b�g����
	device_->SetIndices(index_buffer_);

	// ���C�e�B���O��ON�ɂ���(���C�g�S�Ă�ON�AOFF����)
	device_->SetRenderState(D3DRS_LIGHTING, FALSE);

	device_->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP,
								 0,						// �Z�b�g�X�g���[������ǂꂭ�炢����Ă��邩
								 0,						// �C���f�b�N�X�ň�ԏ������l
								 (UINT)vertex_.size(),	// ���_��
								 0,						// �X�^�[�g�C���f�b�N�X�ԍ�
								 PRIMITIVE_NUM);		// �v���~�e�B�u��


	// ���C�e�B���O��ON�ɂ���(���C�g�S�Ă�ON�AOFF����)
	device_->SetRenderState(D3DRS_LIGHTING, TRUE);
}



//--------------------------------------------------------------------------------
//
// [ ���_�쐬�֐� ]
//
//--------------------------------------------------------------------------------

void PlanePolygon::CreateVertex(Color4 color, Vec2 plane_size)
{
	// ���_���̓���
	float temp_x = plane_size.x / 2;
	float temp_y = plane_size.y / 2;

	float u0 = 0.0f;
	float v0 = 0.0f;
	float u1 = 1.0f;
	float v1 = 1.0f;

	vertex_.push_back({Vec3(-temp_x,  temp_y, 0.0f), Vec3(0.0f, 0.0f, -1.0f), color, Vec2(u0, v0)});
	vertex_.push_back({Vec3(temp_x,  temp_y, 0.0f), Vec3(0.0f, 0.0f, -1.0f), color, Vec2(u1, v0)});
	vertex_.push_back({Vec3(-temp_x, -temp_y, 0.0f), Vec3(0.0f, 0.0f, -1.0f), color, Vec2(u0, v1)});
	vertex_.push_back({Vec3(temp_x, -temp_y, 0.0f), Vec3(0.0f, 0.0f, -1.0f), color, Vec2(u1, v1)});
}



//--------------------------------------------------------------------------------
//
// [ �C���f�b�N�X�쐬�֐� ]
//
//--------------------------------------------------------------------------------

void PlanePolygon::CreateIndex()
{
	index_.push_back(2);
	index_.push_back(0);
	index_.push_back(3);
	index_.push_back(1);
}



//--------------------------------------------------------------------------------
//
// [ �}�e���A���쐬�֐� ]
//
//--------------------------------------------------------------------------------

void PlanePolygon::CreateMaterial()
{
	// �}�e���A���̐ݒ�
	ZeroMemory(&material_, sizeof(material_));	// �������̃A�h���X����sizeof()����0�Ŗ��߂�(�N���X�ɂ͎g��Ȃ�)

	// �}�e���A���J���[�𔒂ɂ���
	material_.Diffuse.r = 1.0f;
	material_.Diffuse.g = 1.0f;
	material_.Diffuse.b = 1.0f;
	material_.Diffuse.a = 1.0f;

	// �A���r�G���g�}�e���A���̐ݒ�
	material_.Ambient.r = 1.0f;
	material_.Ambient.g = 1.0f;
	material_.Ambient.b = 1.0f;
	material_.Ambient.a = 1.0f;
}



//--------------------------------------------------------------------------------
//
// [ VRAM�ւ̃A�N�Z�X����֐� ]
//
//--------------------------------------------------------------------------------

void PlanePolygon::AccessVRAM()
{
	// VRAM�̃��������m��(GPU�Ɉ˗�)(���_�o�b�t�@�̍쐬)
	HRESULT  hr = device_->CreateVertexBuffer(sizeof(RendererDirectX9::VERTEX_3D) * (int)vertex_.size(),	// �؂肽��baf�̗�(�o�C�g)�A�܂�1���_�̗e�ʁ~�K�v���_��
											  D3DUSAGE_WRITEONLY,											// �g�p�p�r(����͏������݂̂݁AGPU�������������������񂾃f�[�^��ǂ�ł̓_��(�l���s��))
											  RendererDirectX9::FVF_VERTEX_3D,								// ���_����
											  D3DPOOL_MANAGED,												// ���_�o�b�t�@�̊Ǘ����@( MANAGED�͊Ǘ���Direct3D�ɂ��C���Ƃ����Ӗ� )
											  &vertex_buffer_,												// �Ǘ��҂̋��ꏊ�̃�����(�|�C���^�̃|�C���^)(�S�Ă͂���̒l��m�邽�߂̍��)
											  NULL);

	if (FAILED(hr))
	{
		MessageBox(NULL, "Vertex buffer was not created.", "Error", MB_OK);
	}


	// VRAM�̃��������m��(GPU�Ɉ˗�)(�C���f�b�N�X�o�b�t�@�̍쐬)
	hr = device_->CreateIndexBuffer(sizeof(WORD) * (int)index_.size(),		// �؂肽��baf�̗�(�o�C�g)�A�܂�1���_�̗e�ʁ~�K�v���_��
									D3DUSAGE_WRITEONLY,		// �g�p�p�r(����͏������݂̂݁AGPU�������������������񂾃f�[�^��ǂ�ł̓_��(�l���s��))
									D3DFMT_INDEX16,			// ���_�t�H�[�}�b�g(WORD�^������16�ADWORD�^�Ȃ�32)
									D3DPOOL_MANAGED,			// ���_�o�b�t�@�̊Ǘ����@( MANAGED�͊Ǘ���Direct3D�ɂ��C���Ƃ����Ӗ� )
									&index_buffer_,			// �Ǘ��҂̋��ꏊ�̃�����(�|�C���^�̃|�C���^)(�S�Ă͂���̒l��m�邽�߂̍��)
									NULL);					// �Ȃ��H

	if (FAILED(hr))
	{
		MessageBox(NULL, "Index buffer was not created.", "Error", MB_OK);
	}

	RegistrationVertex();

	RegistrationIndex();
}



//--------------------------------------------------------------------------------
//
// [ ���_�̓o�^�֐� ]
//
//--------------------------------------------------------------------------------

void PlanePolygon::RegistrationVertex()
{
	// ���_�̓o�^
	// ���z�A�h���X�����炤���_�|�C���^
	RendererDirectX9::VERTEX_3D* temp_vertex;

	// ���b�N����
	vertex_buffer_->Lock(0,						// �ǂ����烍�b�N��������
						 0,						// �ǂ̂��炢�؂肽����(0��VertexBuffer�S��)
						 (void**)&temp_vertex,	// ���b�N�����VRAM�̉��z�A�h���X�����炦��(���ۂɏ�������ł���킯�ł͂Ȃ�)
						 D3DLOCK_DISCARD);		// 0�ł��悢

	for (std::vector<RendererDirectX9::VERTEX_3D>::size_type i = 0; i < vertex_.size(); i++)
	{
		temp_vertex[i] = vertex_[i];
	}


	// �A�����b�N
	vertex_buffer_->Unlock();
}



//--------------------------------------------------------------------------------
//
// [ �C���f�b�N�X�̓o�^�֐� ]
//
//--------------------------------------------------------------------------------

void PlanePolygon::RegistrationIndex()
{
	// �C���f�b�N�X�̓o�^
	// ���z�A�h���X�����炤���_�|�C���^ 
	LPWORD temp_index;


	// ���b�N����
	index_buffer_->Lock(0,						// �ǂ����烍�b�N��������
						0,						// �ǂ̂��炢�؂肽����(0��VertexBuffer�S��)
						(void**)&temp_index,	// ���b�N�����VRAM�̉��z�A�h���X�����炦��(���ۂɏ�������ł���킯�ł͂Ȃ�)
						D3DLOCK_DISCARD);		// 0�ł��悢

	for (std::vector< WORD >::size_type i = 0; i < index_.size(); i++)
	{
		temp_index[i] = index_[i];

	}

	// �A�����b�N
	index_buffer_->Unlock();
}