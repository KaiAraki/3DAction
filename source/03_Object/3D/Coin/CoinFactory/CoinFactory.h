//================================================================================
//
//    コインファクトリークラス
//    Author : Araki Kai                                作成日 : 2018/07/24
//
//================================================================================

#ifndef	_COIN_FACTORY_H_
#define _COIN_FACTORY_H_



//======================================================================
//
// インクルード文
//
//======================================================================

#include "../Coin.h"
#include "../CoinDraw/CoinDraw.h"
#include "../CoinCollision/CoinCollision.h"


//======================================================================
//
// クラス定義
//
//======================================================================

class CoinFactory
{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public :
	// メンバ関数
	Coin* Create()
	{
		Coin* temp = new Coin();

		// 初期化
		temp->Init(new CoinDraw(),
				   new CoinCollision());

		return temp;
	}
};



#endif