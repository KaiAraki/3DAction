//================================================================================
//
//    ���ʃN���X
//    Author : Araki Kai                                �쐬�� : 2017/11/28
//
//================================================================================

#ifndef	_PLANE_H_
#define _PLANE_H_



//======================================================================
//
// �C���N���[�h��
//
//======================================================================

#include "../CollisionShapeBase.h"

#include <Vector3D.h>



//======================================================================
//
// �N���X��`
//
//======================================================================

class Plane : public CollisionShapeBase
{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// �@����1�_�R���X�g���N�^( �f�t�H���g )
	Plane(Vec3 normal_vector = Vec3(0.0f, 0.0f, 0.0f), Vec3 point = Vec3(0.0f, 0.0f, 0.0f));

	// 3�_�����R���X�g���N�^
	Plane(Vec3 point0, Vec3 point1, Vec3 point2);


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// �f�X�g���N�^
	virtual ~Plane();


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// �����o�֐�	
	float Length_Point     (Vec3 point) const;
	bool  IsFrontSide_Point(Vec3 point) const;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// �����o�ϐ�
	Vector3D normal_vector_;
	float    adjustmet_d_;
};





//======================================================================
//
// ��ÓI�����o�֐���`( inline )
//
//======================================================================

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ �@����1�_�R���X�g���N�^( �f�t�H���g ) ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline Plane::Plane(Vec3 normal_vector, Vec3 point)
	: CollisionShapeBase(CollisionShapeBase::Type::PLANE),
	  normal_vector_(normal_vector)
{
	normal_vector_.CreateNormalize();

	adjustmet_d_ = -((normal_vector_.x * point.x) + (normal_vector_.y * point.y) + (normal_vector_.z * point.z));
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 3�_�����R���X�g���N�^ ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline Plane::Plane(Vec3 point0, Vec3 point1, Vec3 point2)
	: CollisionShapeBase(CollisionShapeBase::Type::PLANE)
{
	Vec3 temp_normal_vector = Point3_Cross(point0, point1, point2);

	*this = Plane(temp_normal_vector, point0);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ �f�X�g���N�^ ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline Plane::~Plane() 
{
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ ���ʂƍ��W�Ƃ̒����֐� ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline float Plane::Length_Point(Vec3 point)  const
{
	return (normal_vector_.x * point.x) + (normal_vector_.y * point.y) + (normal_vector_.z * point.z) + adjustmet_d_;
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ ���W�����ʂ̕\���ɂ��邩����֐� ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline bool Plane::IsFrontSide_Point(Vec3 point)  const
{
	if (Length_Point(point) < 0.0f) return false;

	return true;
}



#endif