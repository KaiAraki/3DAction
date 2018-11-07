//================================================================================
//
//    プレイヤー更新クラス
//    Author : Araki Kai                                作成日 : 2018/03/27
//
//================================================================================

#ifndef	_PLAYER_UPDATE_H_
#define _PLAYER_UPDATE_H_



//======================================================================
//
// インクルード文
//
//======================================================================

#include "../Player.h"

#include <Component\UpdateComponent\UpdateComponent.h>



//======================================================================
//
// クラス定義
//
//======================================================================

class PlayerUpdate : public UpdateComponent
{
//------------------------------------------------------------
private :
	// 定数
	static const float SPEED;


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
	Player* player_;

};



#endif