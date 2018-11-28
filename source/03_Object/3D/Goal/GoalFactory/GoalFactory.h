//================================================================================
//
//    ゴールファクトリークラス
//    Author : Araki Kai                                作成日 : 2018/11/28
//
//================================================================================

#ifndef	_GOAL_FACTORY_H_
#define _GOAL_FACTORY_H_



//****************************************
// インクルード文
//****************************************
#include "../Goal.h"
#include "../GoalDraw/GoalDraw.h"
#include "../GoalCollision/GoalCollision.h"



/*********************************************************//**
* @brief
* ゴールファクトリークラス
*
* ゴールのファクトリークラス
*************************************************************/
class GoalFactory
{
//==============================
// 非静的メンバ関数
//==============================
public:
	/**
	* @brief
	* 作成関数
	*/
	Goal* Create()
	{
		Goal* temp = new Goal();

		// 初期化
		temp->Init(new GoalDraw(),
				   new GoalCollision());

		return temp;
	}
};



#endif