//================================================================================
//
//    物理クラス
//    Author : Araki Kai                                作成日 : 2018/08/19
//
//================================================================================



//======================================================================
//
// インクルード文
//
//======================================================================

#include "Physics.h"

#include <Vector\ConvertToFrame\MeterToFrame\MeterToFrame.h>
#include <GameObjectOrigin\GameObjectOrigin.h>



//======================================================================
//
// 定数定義
//
//======================================================================

const float Physics::VELOCITY_MIN = 0.0001f;



//======================================================================
//
// 非静的メンバ関数定義
//
//======================================================================

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ コンストラクタ ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Physics::Physics(GameObjectOrigin* game_object_origin)
	: game_object_origin_  (game_object_origin),
	  max_velocity_		   (100.0f),
	  mass_				   (1.0f),
	  friction_			   (0.0f),
	  my_friction_		   (1.0f),
	  bounciness_		   (0.0f),
	  my_bounciness_       (1.0f),
	  is_gravity_          (true),
	  gravity_acceleration_(MeterPerSecondSquared_To_MeterPerFrameSquared(9.8f)),
	  gravity_direction_   (0.0f, -1.0f, 0.0f),
	  is_on_tha_ground_    (false),
	  is_landing_          (false)
	  
{
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ デストラクタ ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Physics::~Physics()
{

}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 更新関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Physics::Update()
{
	// 加速度更新
	UpdateAcceleration();
	
	// 速度更新
	UpdateVelocity();
	
	// 座標更新
	UpdatePosition();

	// 対象のパラメータをリセット
	Reset();
}



//--------------------------------------------------------------------------------
//
// [ リセット関数 ]
//
//--------------------------------------------------------------------------------

void Physics::Reset()
{
	// 地面判定
	is_on_tha_ground_ = false;

	// 摩擦力
	friction_ = 0.0f;

	// 反発力
	bounciness_ = 0.0f;

	// 加速度
	acceleration_.ResetVector();
}



//--------------------------------------------------------------------------------
//
// [ 加速度更新関数 ]
//
//--------------------------------------------------------------------------------

void Physics::UpdateAcceleration()
{
	// 重力の追加
	SetGravity();

	// 地面上の処理
	SetGround();
}



//--------------------------------------------------------------------------------
//
// [ 速度更新関数 ]
//
//--------------------------------------------------------------------------------

void Physics::UpdateVelocity()
{
	// 加速度を速度に追加
	velocity_ += acceleration_;

	// 摩擦力追加
	if (friction_ > 0.0f)
	{
		velocity_ *= friction_;
	}
	
	// 反発力を追加
	if (bounciness_ > 0.0f)
	{
		velocity_ *= -bounciness_;
	}
	
	// 速度の最小値・最大値チェック
	CheckVelocityMinMax();
}



//--------------------------------------------------------------------------------
//
// [ 座標更新関数 ]
//
//--------------------------------------------------------------------------------

void Physics::UpdatePosition()
{
	// 速度を座標に作用
	*game_object_origin_->GetTransform()->GetPosition() += velocity_;

	// 行列の更新(ビルボードにも対応)
	game_object_origin_->GetTransform()->UpdateWorldMatrixISRT();
}



//--------------------------------------------------------------------------------
//
// [ 重力追加関数 ]
//
//--------------------------------------------------------------------------------

void Physics::SetGravity()
{
	// 重力を作用させるかどうか
	if (!is_gravity_) return;

	// 重力の大きさ算出
	gravity_direction_.AnyLengthVector(mass_ * gravity_acceleration_);

	// オブジェクトの加速度に重力を追加
	acceleration_ += gravity_direction_;
}



//--------------------------------------------------------------------------------
//
// [ 地面の処理関数 ]
//
//--------------------------------------------------------------------------------

void Physics::SetGround()
{
	// 地面上にいるかどうか
	if (is_on_tha_ground_)
	{
		// 着地処理
		if (!is_landing_)
		{
			is_landing_ = true;

			velocity_.y = 0.0f;
		}

		// 垂直抗力の追加
		acceleration_ += -gravity_direction_;
	}
	else
	{
		// 着地フラグ解放
		if (!is_landing_) return;
		is_landing_ = false;
	}
}



//--------------------------------------------------------------------------------
//
// [ 速度の最小値・最大値チェック関数 ]
//
//--------------------------------------------------------------------------------

void Physics::CheckVelocityMinMax()
{
	// 最小値
	if (velocity_.GetLength() <= VELOCITY_MIN)
	{
		velocity_.ResetVector();
	}

	// 最大値
	if (velocity_.GetLength() >= max_velocity_)
	{
		velocity_.AnyLengthVector(max_velocity_);
	}
}