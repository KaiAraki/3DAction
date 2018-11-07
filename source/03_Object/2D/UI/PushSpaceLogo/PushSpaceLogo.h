//================================================================================
//
//    プッシュスペースロゴクラス
//    Author : Araki Kai                                作成日 : 2018/09/02
//
//================================================================================

#ifndef	_PUSH_SPACE_LOGO_H_
#define _PUSH_SPACE_LOGO_H_



//======================================================================
//
// インクルード文
//
//======================================================================

#include <GameObjectOrigin\GameObjectOrigin.h>

#include <Polygon\PlanePolygon\PlanePolygon.h>



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

class PushSpaceLogo : public GameObjectOrigin
{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// メンバ関数
	void Init(UpdateComponent* update_component,
		      DrawComponent*   draw_component);
	void Uninit() override;
	void Reset()  override;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// 公開メンバ変数
	PlanePolygon*    plane_polygon_;
};



#endif