#pragma once
#include "StateBase.h"
#include <string>
#include <map>

class GameObject;

class StateManager
{
private:
	//状態を文字列で管理
	std::map<std::string, StateBase*>statesMap_;
	StateBase* currentState_;
	GameObject* pParent_;

public:
	StateManager(GameObject* parent);
	~StateManager();

	void Update();
	void ChangeState(const std::string& stateName);
	StateBase* AddState(const std::string& stateName, StateBase* state);
	GameObject* GetGameObject() { return pParent_; }
};

