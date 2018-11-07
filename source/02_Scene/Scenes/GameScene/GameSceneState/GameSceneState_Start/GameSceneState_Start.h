//================================================================================
//
//    ゲームシーンステートクラス(スタート)
//    Author : Araki Kai                                作成日 : 2018/11/06
//
//================================================================================

#ifndef	_GAME_SCENE_STATE_START_H_
#define _GAME_SCENE_STATE_START_H_



//****************************************
// インクルード文
//****************************************
#include <SceneBace/SceneBace.h>



//****************************************
// クラス宣言
//****************************************
class GameScene;



/*********************************************************//**
* @brief
* ゲームシーンステートクラス(スタート)
*
* ゲームシーンのステートクラス
* 最初の状態を表す
*************************************************************/
class GameSceneState_Start : public SceneBace::StateAbstract
{
//==============================
// 非静的メンバ変数
//==============================
protected:
	GameScene* game_scene_ = nullptr;	//!< ゲームシーン



//==============================
// 非静的メンバ関数
//==============================
public:
	/**
	* @brief
	* 初期化関数
	*/
	void Init() override;

	/**
	* @brief
	* 終了関数
	*/
	void Uninit() override;

	/**
	* @brief
	* 更新関数
	*/
	void Update() override;

	/**
	* @brief
	* リセット関数
	*/
	void Reset() override;
};



#endif