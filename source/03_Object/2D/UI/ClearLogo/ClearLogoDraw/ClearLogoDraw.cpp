//================================================================================
//
//    クリアロゴ描画クラス
//    Author : Araki Kai                                作成日 : 2018/06/19
//
//================================================================================



//======================================================================
//
// インクルード文
//
//======================================================================

#include "ClearLogoDraw.h"

#include <Renderer\RendererDirectX9\RendererDirectX9.h>
#include <Polygon\PlanePolygon\PlanePolygon.h>



//======================================================================
//
// 定数定義
//
//======================================================================

const std::string ClearLogoDraw::TEXTURE_NAME = "UI/Clear.png";
const float ClearLogoDraw::SCALE = 1.25f;



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

void ClearLogoDraw::Init()
{
	// ステートの変更
	SetState(DrawComponent::State::FIXED_2D);

	// ClearLogoにダウンキャスト
	clear_logo_ = (ClearLogo*)GetGameObjectOrigin();

	// テクスチャの登録
	decale_texture_ = TextureManager::AddUniqueData(&TEXTURE_NAME);

	// 拡縮
	clear_logo_->GetTransform()->GetScale()->x = decale_texture_->GetWidth() * SCALE;
	clear_logo_->GetTransform()->GetScale()->y = decale_texture_->GetHeight() * (SCALE + 0.2f);

	// 移動
	*clear_logo_->GetTransform()->GetPosition() = Vec3(0.0f, 0.0f, 0.0f);
	
	clear_logo_->GetTransform()->UpdateWorldMatrixSRT();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 終了処理関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ClearLogoDraw::Uninit()
{
	
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 描画関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ClearLogoDraw::Draw(unsigned mesh_index)
{
	mesh_index = mesh_index;

	clear_logo_->plane_polygon_->Draw();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ メッシュ数取得関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

unsigned ClearLogoDraw::GetMeshNum()
{
	return clear_logo_->plane_polygon_->GetMeshNum();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ マテリアルの取得関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

D3DMATERIAL9* ClearLogoDraw::GetMaterial(unsigned mesh_index)
{
	mesh_index = mesh_index;

	return clear_logo_->plane_polygon_->GetMaterial();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ デカールテクスチャ情報を取得関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

LPDIRECT3DTEXTURE9 ClearLogoDraw::GetDecaleTexture(unsigned mesh_index)
{
	mesh_index = mesh_index;

	return decale_texture_->GetHandler();
}