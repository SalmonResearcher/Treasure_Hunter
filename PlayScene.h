#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"



//テストシーンを管理するクラス
class PlayScene : public GameObject
{
	int hBGM_;

	int hScoreSound_;
	int soundtimer;
	Text* pText;

	// 定数の定義
	const int INITAL_BULLET_POSITION = 500;

	const int INITIAL_UI = 1;

	const int JEWEL_POSITION_X = 45;
	const int JEWEL_POSITION_Y = 650;

	const int SCORE_POSITION_X = 950;
	const int SCORE_POSITION_Y = 45;

	const int TIMER_POSITION_X = 850;
	const int TIMER_POSITION_Y = 45;

	const int SCORE_INDEX = 0;
	const int TIMER_INDEX = 0;
	const int JEWEL_INDEX = 0;

	const int TIMER_LIMIT_SECONDS = 60;
	const int ENEMY_SPAWN_INTERVAL = 30;

	const float SPAWN_RANDOM_X_MIN = -80.0f;
	const float SPAWN_RANDOM_X_MAX = 60.0f;

	const int SOUND_PRIORITY = 5;
	const float PITCH_INCREMENT = 0.01f;
	const float INITIAL_PITCH = 1.0f;
	const float COUNT_VOLUME = 0.2f;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//サウンドを〇Fごとに再生する
	void SoundPlay(int handle, int interval);

	//ゲーム終了時
	void HandleEndOfGame();

};