#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
#include "InputManager.h"


class PlayerCamera;
class StateManager;

class Player :public GameObject
{
private:
    int hModel_;    //モデル番号
    int hSound_;    //サウンド番号


    int hStage_;    //ステージモデル番号
    int hEnemy_;    //敵のモデル番号

    bool isJumping_; //ジャンプ中かどうか

    float moveY_;   //Y軸の加速度

    float jewelCount_;  //持っている宝石の数
    float weight_;      //宝石の重さ
    int killCount_;     //敵を倒した数
    int jewelDeliver_;  //運んだ宝石の数重力最大量

    StateManager* pStateManager_;//状態を切り替える
    PlayerCamera* pCamera_;

    bool attackEnd;

    RayCastData downRay;
    RayCastData play;

public:
    Player(GameObject* parent);     //コンストラクタ
    ~Player();                      //デストラクタ

    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;

    //動き

    void Walk();        //歩く
    void Jump();        //ジャンプ
    void Run();         //走り
    void Attacking();   //攻撃
    void Knockback();   //はじかれ

    bool IsJumping();   //接地しているか

    void AddGravity();  //重力をプレイヤーに加算

    void AddMovement(XMVECTOR moveVector, float run);   //プレイヤーの移動ベクトルを計算

    XMVECTOR CalcMovementInput();

    XMFLOAT3 GetPlayerPosition() { return transform_.position_; };

    void OnCollision(GameObject* pTarget)override;  //何かとぶつかったら

    // ゲッターとセッター
    int GetModelHandle() { return hModel_; }

    int SendJewel() { return jewelDeliver_; };        //宝石箱に納品した宝石の数を送ります
    int GetJewelCount();    //今手に持っている宝石の数を返します

    void KillCountUp();     //プレイヤーが直接敵を倒した数を1増やします
    int GetKillCount();     //プレイヤーが直接倒した敵の数を返します。

    void SetVelocityY(float vY) { moveY_ = vY; };
    float GetVelocityY() { return moveY_; };

    void SetJumping(bool flag) { isJumping_ = flag; }

    void SetMoveY(float moveY) { transform_.position_.y += moveY; }

    XMVECTOR GetKnockbackDirection();

    int GetStageHandle() { return hStage_; }

    void RotatePlayer(XMVECTOR moveVector);
    void RotatePlayer();

    //プレイヤーの重量を返します
    float GetWeight();

    //プレイヤーの速度を返します。
    float GetSpeed();

    //プレイヤーの攻撃が終わったらtrue
    bool IsAttackEnd();
};