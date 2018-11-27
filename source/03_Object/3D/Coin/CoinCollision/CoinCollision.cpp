//================================================================================
//
//    コイン衝突クラス
//    Author : Araki Kai                                作成日 : 2018/07/24
//
//================================================================================



//**********************************************************************
//
// インクルード文
//
//**********************************************************************

#include "CoinCollision.h"

#include <Renderer\RendererDirectX9\RendererDirectX9.h>



//**********************************************************************
//
// 定数定義
//
//**********************************************************************

const float CoinCollision::BOUNDING_OBB_RIGHT   = 1.0f;
const float CoinCollision::BOUNDING_OBB_UP      = 1.0f;
const float CoinCollision::BOUNDING_OBB_FORWARD = 1.0f;

const float CoinCollision::SUBSTANCE_RIGHT   = 1.0f;
const float CoinCollision::SUBSTANCE_UP	  = 1.0f;
const float CoinCollision::SUBSTANCE_FORWARD = 1.0f;



//**********************************************************************
//
// 非静的メンバ関数定義
//
//**********************************************************************
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 初期化関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void CoinCollision::Init()
{
	// ステート
	CollisionBase::setState(CollisionBase::State::COIN);

	// 複数衝突オブジェクト
	collision_objects_ = new CollisionObjects();
	collision_objects_->setCollisionBase(this);
	collision_objects_->getOctreeAABB()
		->Init(*GetGameObject()->GetTransform()->GetPosition(), 
			   Vec3(1.0f, 1.0f, 1.0f));
	CollisionBase::AddCollisionObjectsToArray(collision_objects_);

	// バウンディングOBBの作成
	OBB* temp_obb_ = new OBB(BOUNDING_OBB_RIGHT,
							 BOUNDING_OBB_UP, 
							 BOUNDING_OBB_FORWARD,
							 *GetGameObject()->GetTransform()->GetPosition());
	
	bounding_obb_ = new CollisionObject(temp_obb_, ObjectTag::BOUNDING_OBB);

	// バウンディングOBBの登録
	collision_objects_->AddCollisionObjectToArray(bounding_obb_);


	// 本体OBBの作成
	temp_obb_ = new OBB(SUBSTANCE_RIGHT,
						SUBSTANCE_UP, 
						SUBSTANCE_FORWARD,
						*GetGameObject()->GetTransform()->GetPosition());

	substance_ = new CollisionObject(temp_obb_, ObjectTag::SUBSTANCE);

	// 本体OBBの登録
	collision_objects_->AddCollisionObjectToArray(substance_);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 終了処理関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void CoinCollision::Uninit()
{
	// スーパークラスの終了処理
	CollisionNull::Uninit();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 更新関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void CoinCollision::Update()
{
	// 複数衝突オブジェクトの更新
	collision_objects_->getOctreeAABB()
		->setPosition(*GetGameObject()->GetTransform()->GetPosition());
	collision_objects_->getOctreeAABB()->Update();

	// バウンディングOBBの更新
	OBB* temp_obb = (OBB*)bounding_obb_->getCollisionShape();

	temp_obb->position_		  = *GetGameObject()->GetTransform()->GetPosition();
	temp_obb->axis_			  = *GetGameObject()->GetTransform()->GetAxisVector();
	temp_obb->lenght_right_	  = GetGameObject()->GetTransform()->GetScale()->x * BOUNDING_OBB_RIGHT;
	temp_obb->lenght_up_	  = GetGameObject()->GetTransform()->GetScale()->y * BOUNDING_OBB_UP;
	temp_obb->lenght_forward_ = GetGameObject()->GetTransform()->GetScale()->z * BOUNDING_OBB_FORWARD;


	// 本体スフィアOBBの更新
	temp_obb = (OBB*)substance_->getCollisionShape();

	temp_obb->position_		  = *GetGameObject()->GetTransform()->GetPosition();
	temp_obb->axis_			  = *GetGameObject()->GetTransform()->GetAxisVector();
	temp_obb->lenght_right_	  = GetGameObject()->GetTransform()->GetScale()->x * SUBSTANCE_RIGHT;
	temp_obb->lenght_up_	  = GetGameObject()->GetTransform()->GetScale()->y * SUBSTANCE_UP;
	temp_obb->lenght_forward_ = GetGameObject()->GetTransform()->GetScale()->z * SUBSTANCE_FORWARD;
}