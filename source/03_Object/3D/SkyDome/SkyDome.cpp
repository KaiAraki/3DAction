//================================================================================
//
//    スカイドームクラス
//    Author : Araki Kai                                作成日 : 2018/05/15
//
//================================================================================



//======================================================================
//
// インクルード文
//
//======================================================================

#include "SkyDome.h"



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

void SkyDome::Init(UpdateComponent* update_component,
				   DrawComponent*   draw_component)
{
	// 基底クラスの初期化
	Init_SuperClass(update_component, draw_component, nullptr);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 終了処理関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void SkyDome::Uninit()
{
	// 基底クラスの終了処理
	Uninit_SuperClass();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ Reset処理関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void SkyDome::Reset()
{

}