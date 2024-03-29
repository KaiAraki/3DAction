//================================================================================
//
//    プッシュスペースロゴ更新クラス
//    Author : Araki Kai                                作成日 : 2018/09/02
//
//================================================================================

#ifndef	_PUSH_SPACE_LOGO_UPDATE_H_
#define _PUSH_SPACE_LOGO_UPDATE_H_



//======================================================================
//
// インクルード文
//
//======================================================================

#include "../PushSpaceLogo.h"

#include <Component\UpdateComponent\UpdateComponent.h>



//======================================================================
//
// クラス定義
//
//======================================================================

class PushSpaceLogoUpdate : public UpdateComponent
{
//------------------------------------------------------------
private :
	// 定数
	static const int CHANGE_NUM;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// メンバ関数
	void Init()		  override;
	void Uninit()	  override;
	void Update()	  override;
	void LateUpdate() override;
	void Debug()      override;


//------------------------------------------------------------
private :
	PushSpaceLogo* push_space_logo_;
	int change_count_;
	XColor4 color_;

};



#endif