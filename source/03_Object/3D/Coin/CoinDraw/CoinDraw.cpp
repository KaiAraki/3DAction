//================================================================================
//
//    コイン描画クラス
//    Author : Araki Kai                                作成日 : 2018/07/24
//
//================================================================================



//****************************************
// インクルード文
//****************************************
#include "CoinDraw.h"

#include <ResourceManager/ResourceManager.h>



//****************************************
// 定数定義
//****************************************
const std::string CoinDraw::DECALE_TEXTURE = "Coin.png";



//****************************************
// 非静的メンバ関数定義
//****************************************
//--------------------------------------------------
// +初期化関数
//--------------------------------------------------
void CoinDraw::Init()
{
	// オーダーリスト設定
	GetDrawOrderList()->SetDrawType(DrawOrderList::DrawType::TRANSPARENCY);
	GetDrawOrderList()->GetRenderTargetFlag()->Set(DrawOrderList::RENDER_TARGET_BACK_BUFFER);
	GetDrawOrderList()->SetVertexShaderType(ShaderManager::VertexShaderType::VERTEX_FIXED);
	GetDrawOrderList()->SetPixelShaderType(ShaderManager::PixelShaderType::PIXEL_FIXED);
	GetDrawOrderList()->SetIsBillboard(true);

	// ダウンキャスト
	coin_ = (Coin*)GetGameObject();

	// デカールテクスチャの読み込み
	decale_texture_ = TextureManager::AddUniqueData(&DECALE_TEXTURE);
}



//--------------------------------------------------
// +終了関数
//--------------------------------------------------
void CoinDraw::Uninit()
{
}



//--------------------------------------------------
// +更新関数
//--------------------------------------------------
void CoinDraw::Update()
{
	if (coin_->getCount() > 0)
	{
		coin_->GetPolygon()->SetColor(XColor4(1.0f, 0.0f, 0.0f, 1.0f));

		coin_->setCount(coin_->getCount() - 1);
	}
	else
	{
		coin_->GetPolygon()->SetColor(XColor4(1.0f, 1.0f, 1.0f, 1.0f));
	}
}



//--------------------------------------------------
// +描画関数
//--------------------------------------------------
void CoinDraw::Draw(unsigned object_index, unsigned mesh_index)
{
	object_index = object_index;
	mesh_index = mesh_index;

	// ポリゴン描画
	coin_->GetPolygon()->Draw();
}



//--------------------------------------------------
// +描画前設定関数
//--------------------------------------------------
void CoinDraw::SettingBeforeDrawing(Camera* camera, unsigned object_index)
{
	camera = camera;
	object_index = object_index;
}



//--------------------------------------------------
// +行列取得関数
//--------------------------------------------------
const MATRIX* CoinDraw::GetMatrix(unsigned object_index)
{
	object_index = object_index;

	return coin_->GetTransform()->GetWorldMatrix();
}



//--------------------------------------------------
// +メッシュ数取得関数
//--------------------------------------------------
unsigned CoinDraw::GetMeshNum(unsigned object_index)
{
	object_index = object_index;

	return coin_->GetPolygon()->GetMeshNum();
}



//--------------------------------------------------
// +マテリアル取得関数
//--------------------------------------------------
D3DMATERIAL9* CoinDraw::GetMaterial(unsigned object_index, unsigned mesh_index)
{
	object_index = object_index;
	mesh_index = mesh_index;

	return coin_->GetPolygon()->GetMaterial();
}



//--------------------------------------------------
// +デカールテクスチャ取得関数
//--------------------------------------------------
LPDIRECT3DTEXTURE9 CoinDraw::GetDecaleTexture(unsigned object_index, 
											  unsigned mesh_index)
{
	object_index = object_index;
	mesh_index = mesh_index;

	return decale_texture_->GetHandler();
}