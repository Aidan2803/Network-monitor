#pragma once

#include <vector>

#include "constnts.hpp"
#include "state.hpp"

class InfoDisplayer {
public:
  static InfoDisplayer* GetInfoDisplayer();
  ~InfoDisplayer();
  void TransitionToState(State* state);
  void PrintInfo() const;

  void RetreiveUserInput();
  void HandleUserInput();

  size_t GetMenuOptionsAmount() const;
  StateID GetStateID() const;

private:
  InfoDisplayer() : state_(nullptr) {}

private:
  static InfoDisplayer* user_menu_;
  State* state_;
  char user_input_;
};
