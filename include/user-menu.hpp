#pragma once

#include <vector>

#include "state.hpp"
#include "constnts.hpp"

class UserMenu {
public:
  static UserMenu* GetUserMenu();
  ~UserMenu();
  void TransitionToState(State* state);
  void PrintUserMenu() const;

  void RetreiveUserInput();
  void HandleUserInput();

  size_t GetMenuOptionsAmount() const;
  StateID GetStateID() const;

private:
  UserMenu() : state_(nullptr) {}
  static UserMenu* user_menu_;
  State* state_;
  char user_input_;
};
