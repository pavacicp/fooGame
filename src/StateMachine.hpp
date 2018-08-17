#pragma once

#include <memory>
#include <stack>
#include "Window.hpp"

class State;

class StateMachine
{
public:
	void run(std::unique_ptr<State> state);
	void update();
	void draw();
	void handleEvents();
	void handleInput();

	template <typename T>
	static std::unique_ptr<T> build(Win &window, StateMachine &machine);

private:
	std::stack<std::unique_ptr<State>> states;

};

template <typename T>
std::unique_ptr<T> StateMachine::build(Win &window, StateMachine &machine)
{
	return std::unique_ptr<T> (new T (window, machine));
}