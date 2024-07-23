#pragma once

#include <iostream>

enum class StateID { kMainMenuState = 0, kMonitoringMenuState = 1, kDataBaseMenuState = 2 };

class UserMenu;
class State;
class StateDataBaseMenu;
class StateMonitoringMenu;
class StateMainMenu;

class State {
public:
  void SetUserMenu(UserMenu* menu) { um_ = menu; }
  virtual void PrintUserMenuOptions() = 0;
  StateID GetStateID() { return state_id_; }

protected:
State(StateID stateid):um_{nullptr}, state_id_{stateid}{}
  UserMenu* um_;
  StateID state_id_;
};

class UserMenu {
public:
  static UserMenu* GetUserMenu();

  ~UserMenu();

  void TransitionToState(State* state);

  void PrintUserMenu();

  StateID GetStateID();

private:
  UserMenu() : state_(nullptr) {}

  static UserMenu* user_menu_;
  State* state_;
};

class StateMainMenu : public State {
public:
  StateMainMenu();
  void PrintUserMenuOptions() override;
};

class StateMonitoringMenu : public State {
public:
  StateMonitoringMenu();
  void PrintUserMenuOptions() override;
};

class StateDataBaseMenu : public State {
public:
  StateDataBaseMenu();
  void PrintUserMenuOptions() override;
};
