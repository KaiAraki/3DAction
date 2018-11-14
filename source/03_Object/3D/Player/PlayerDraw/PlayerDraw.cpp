//================================================================================
//
//    プレイヤー描画クラス
//    Author : Araki Kai                                作成日 : 2018/03/27
//
//================================================================================



//======================================================================
//
// インクルード文
//
//======================================================================

#include "PlayerDraw.h"

#include <Renderer\RendererDirectX9\RendererDirectX9.h>
//#include <ComponentManager/DrawManager/Shader/TestShaderObject/TestShaderObject.h>



//======================================================================
//
// 定数定義
//
//======================================================================

const std::string PlayerDraw::MODEL_NAME   = "knight_low/knight_low.X";//"kyouryuu/kyouryuu.x";//"BlockSphere/BlockSphere.x";
const std::string PlayerDraw::TEXTURE_PATH = "resource/ModelX/";
const std::string PlayerDraw::NORMAL_TEXTURE_NAME01 = "knight_low/knight_01.png";
const std::string PlayerDraw::NORMAL_TEXTURE_NAME02 = "knight_low/sword_01.png";



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

void PlayerDraw::Init()
{
	// オーダーリスト設定
	GetDrawOrderList()->SetDrawType(DrawOrderList::DrawType::OPACITY);
	GetDrawOrderList()->GetRenderTargetFlag()->Set(DrawOrderList::RENDER_TARGET_BACK_BUFFER);
	GetDrawOrderList()->SetVertexShaderType(ShaderManager::VertexShaderType::VERTEX_FIXED);
	GetDrawOrderList()->SetPixelShaderType(ShaderManager::PixelShaderType::PIXEL_FIXED);

	// Xモデル登録
	player_model_ = ModelXManager::AddUniqueData(&MODEL_NAME);

	// 頂点宣言用メッシュ更新
	//TestShaderObject::UpdateMeshDeclaration(player_model_);

	// 法線マップのロード
	normal_texture_[0] = TextureManager::AddUniqueData(&NORMAL_TEXTURE_NAME01, &TEXTURE_PATH);
	normal_texture_[1] = TextureManager::AddUniqueData(&NORMAL_TEXTURE_NAME02, &TEXTURE_PATH);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 終了処理関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void PlayerDraw::Uninit()
{
	
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 描画関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void PlayerDraw::Draw(unsigned object_index, unsigned mesh_index)
{
	// 現在のメッシュの描画
	player_model_->GetMesh()->DrawSubset(mesh_index);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ 行列取得関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

const MATRIX* PlayerDraw::GetMatrix(unsigned object_index)
{
	object_index = object_index;

	// メッシュ数の取得
	return GetGameObject()->GetTransform()->GetWorldMatrix();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ メッシュ数取得関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

unsigned PlayerDraw::GetMeshNum(unsigned object_index)
{
	object_index = object_index;

	return player_model_->GetMeshNum();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ マテリアルの取得関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

D3DMATERIAL9* PlayerDraw::GetMaterial(unsigned object_index, unsigned mesh_index)
{
	object_index = object_index;

	return player_model_->GetMaterial(mesh_index);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ デカールテクスチャ情報を取得関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

LPDIRECT3DTEXTURE9 PlayerDraw::GetDecaleTexture(unsigned object_index, unsigned mesh_index)
{
	object_index = object_index;

	return player_model_->GetDecaleTextureName(mesh_index)->GetHandler();
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// [ ノーマルテクスチャ情報を取得関数 ]
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

LPDIRECT3DTEXTURE9 PlayerDraw::GetNormalTexture(unsigned object_index, unsigned mesh_index)
{
	object_index = object_index;

	return normal_texture_[mesh_index]->GetHandler();
}