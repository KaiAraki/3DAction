//================================================================================
//
//    タイトルロゴクラス
//    Author : Araki Kai                                作成日 : 2018/07/03
//
//================================================================================

#ifndef	_TITLE_LOGO_H_
#define _TITLE_LOGO_H_



//======================================================================
//
// インクルード文
//
//======================================================================

#include <GameObjectOrigin\GameObjectOrigin.h>



//======================================================================
//
// クラス宣言
//
//======================================================================

class PlanePolygon;



//======================================================================
//
// クラス定義
//
//======================================================================

class TitleLogo : public GameObjectOrigin
{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// メンバ関数
	void Init(DrawComponent* draw_component);
	void Uninit() override;
	void Reset()  override;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// 公開メンバ変数
	PlanePolygon*    plane_polygon_;
};



#endif