#pragma once


class EngineState;

/// <summary>
/// Engineクラス
/// </summary>
class Engine {

public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Engine();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Engine();

	void up();
	void down();

	void changeState(EngineState* newState);
	void showNowState();


private:

	EngineState* state_;

};



/// <summary>
/// EngineStateクラス
/// </summary>
class EngineState {

public:
	// 純粋仮想関数　※派生クラスに実装を強制する
	virtual void up(Engine* pEngine) = 0;
	virtual void down(Engine* pEnegine) = 0;
	virtual void showState() = 0;
};



/// <summary>
/// EngineIdleクラス
/// </summary>
class EngineIdle : public EngineState {

public:
	void up(Engine* pEngine) override;
	void down(Engine* pEngine) override;
	void showState() override;
};



/// <summary>
/// EngineLowクラス
/// </summary>
class EngineLow : public EngineState {

public:
	void up(Engine* pEngine) override;
	void down(Engine* pEngine) override;
	void showState() override;
};



/// <summary>
/// EngineHighクラス
/// </summary>
class EngineHigh : public EngineState {

public:
	void up(Engine* pEngine) override;
	void down(Engine* pEngine) override;
	void showState() override;
};