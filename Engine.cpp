#include "Engine.h"
#include <iostream>


// ----- Engineクラスの実装 ----- //
Engine::Engine() {
	state_ = new EngineIdle();
}


Engine::~Engine() {
	delete state_;
}


void Engine::up() {
	state_->up(this);
}


void Engine::down() {
	state_->down(this);
}


void Engine::changeState(EngineState* newState) {
	delete state_;
	state_ = newState;
}


void Engine::showNowState() {
	state_->showState();
}


// ----- EngineIdleクラスの実装 ----- //
void EngineIdle::up(Engine* pEngine) {
	std::cout << "Idle => Low" << std::endl;
	pEngine->changeState(new EngineLow());
}

void EngineIdle::down(Engine* pEngine) {
	std::cout << "(Idle)変更なし" << std::endl;
	pEngine->changeState(new EngineIdle());
}

void EngineIdle::showState() {
	std::cout << "state : Idle" << std::endl;
}


// ----- EngineLowクラスの実装 ----- //
void EngineLow::up(Engine* pEngine) {
	std::cout << "Low => High" << std::endl;
	pEngine->changeState(new EngineHigh());
}

void EngineLow::down(Engine* pEngine) {
	std::cout << "Low => Idle" << std::endl;
	pEngine->changeState(new EngineIdle());
}

void EngineLow::showState() {
	std::cout << "state : Low" << std::endl;
}


// ----- EngineHghクラスの実装 ----- //
void EngineHigh::up(Engine* pEngine) {
	std::cout << "(High) 変更なし" << std::endl;
	pEngine->changeState(new EngineHigh());
}

void EngineHigh::down(Engine* pEngine) {
	std::cout << "High => Low" << std::endl;
	pEngine->changeState(new EngineLow());
}

void EngineHigh::showState() {
	std::cout << "state : High" << std::endl;
}
