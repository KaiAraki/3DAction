//================================================================================
//
//    チュートリアルロゴ01描画クラス
//    Author : Araki Kai                                作成日 : 2018/09/02
//
//================================================================================

#ifndef	_TUTORIAL_LOGO_01_DRAW_H_
#define _TUTORIAL_LOGO_01_DRAW_H_



//======================================================================
//
// インクルード文
//
//======================================================================

#include <string>

#include "../TutorialLogo01.h"

#include <Component\DrawComponent\DrawComponent.h>
#include <ResourceManager\ResourceManager.h>



//======================================================================
//
// クラス定義
//
//======================================================================

class TutorialLogo01Draw : public DrawComponent
{
//------------------------------------------------------------
private :
	// 定数
	static const std::string TEXTURE_NAME;
	static const float       SCALE;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// メンバ関数
	void Init()   override;
	void Uninit() override;
	void Draw(unsigned mesh_index) override;

	unsigned		   GetMeshNum()							 override;
	D3DMATERIAL9*	   GetMaterial(unsigned mesh_index)		 override;
	LPDIRECT3DTEXTURE9 GetDecaleTexture(unsigned mesh_index) override;


//------------------------------------------------------------
private :
	// メンバ変数
	TutorialLogo01* title_logo_;
	TextureObject* decale_texture_;


};



#endif