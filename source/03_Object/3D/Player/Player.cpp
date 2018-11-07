//================================================================================
//
//    プレイヤークラス
//    Author : Araki Kai                                作成日 : 2018/04/01
//
//================================================================================



//======================================================================
//
// インクルード文
//
//======================================================================

#include "Player.h"



//======================================================================
//
// 非静的メンバ関数定義
//
//======================================================================

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 初期化関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player::Init(UpdateComponent*        update_component, 
				  DrawComponent*          draw_component,
				  CollisionComponent*     collision_component,
				  GameScene* game_scene)
{
	// 各種代入
	game_scene_ = game_scene;

	// 基底クラスの初期化
	Init_SuperClass(update_component, draw_component, collision_component);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 終了処理関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player::Uninit()
{
	// 基底クラスの終了処理
	Uninit_SuperClass();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ Reset処理関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player::Reset()
{

}