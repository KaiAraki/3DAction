//================================================================================
//
//    スコア描画クラス
//    Author : Araki Kai                                作成日 : 2018/06/20
//
//================================================================================



//======================================================================
//
// インクルード文
//
//======================================================================

#include "ScoreDraw.h"

#include <Renderer\RendererDirectX9\RendererDirectX9.h>



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

void ScoreDraw::Init()
{
	// ステートの変更
	SetState(DrawComponent::State::FIXED_2D);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 終了処理関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ScoreDraw::Uninit()
{
	
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 描画関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ScoreDraw::Draw(unsigned mesh_index)
{
	mesh_index = mesh_index;
}