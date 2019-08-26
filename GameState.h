#pragma once
#include <vector>

//йкюяяш ме нопедекемш!!!
//нопедекхрэ!!!

using namespace std;

class GameState;
class GameEngine;

class GameState
{
protected:
	GameState() { }
public:
	virtual void Init() = 0;
	virtual void Clean() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	void ChangeState(GameEngine* game, GameState* state)
	{
		game->ChangeState(state);
	}
};

class GameEngine
{
public:
	void Init();
	void Cleanup();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return IsRunning; }
	void Quit() { IsRunning = false; }

private:
	
	vector<GameState*> states;

	bool IsRunning;
};
