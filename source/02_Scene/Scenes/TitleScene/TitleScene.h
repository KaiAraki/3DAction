//================================================================================
//
//    タイトルシーンクラス
//    Author : Araki Kai                                作成日 : 2018/07/03
//
//================================================================================

#ifndef	_TITLE_SCENE_H_
#define _TITLE_SCENE_H_



//****************************************
// インクルード文
//****************************************
#include <SceneBace/SceneBace.h>



/*********************************************************//**
* @brief
* タイトルシーンクラス
*
* タイトルシーンのクラス
*************************************************************/
class TitleScene : public SceneBace
{
//==============================
// 非静的メンバ関数
//==============================
public:
	/**
	* @brief
	* コンストラクタ
	* @param
	* state : 最初のステート
	*/
	TitleScene(StateAbstract* state) : SceneBace(state) {}
};



#endif