//================================================================================
//
//    プッシュスペースロゴクラス
//    Author : Araki Kai                                作成日 : 2018/09/02
//
//================================================================================



//======================================================================
//
// インクルード文
//
//======================================================================

#include "PushSpaceLogo.h"



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

void PushSpaceLogo::Init(UpdateComponent* update_component,
						 DrawComponent*   draw_component)
{
	// プレーンポリゴン作成
	plane_polygon_ = new PlanePolygon();

	// 基底クラスの初期化
	Init_SuperClass(update_component, draw_component, nullptr);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 終了処理関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void PushSpaceLogo::Uninit()
{
	// 基底クラスの終了処理
	Uninit_SuperClass();

	// 各種開放
	SafeRelease::Normal(&plane_polygon_);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ Reset処理関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void PushSpaceLogo::Reset()
{

}