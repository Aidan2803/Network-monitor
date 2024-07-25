#pragma once

#include <iostream>
#include <vector>

class UserMenu;

enum class StateID { kMainMenuState = 0, kMonitoringMenuState = 1, kDataBaseMenuState = 2 };

class State {
public:
  void SetUserMenu(UserMenu* menu) { um_ = menu; }
  virtual void PrintUserMenuOptions() const = 0;
  void PrintOptionsVector() const;
  virtual void HandleUserInputForState(char input) = 0;

  StateID GetStateID() const;
  size_t OptionsAmount() const;

protected:
  State(StateID stateid) : um_(nullptr), state_id_(stateid) {}
  UserMenu* um_;
  StateID state_id_;
  std::vector<std::string> menu_options_vector_;
};

class StateMainMenu : public State {
public:
  StateMainMenu();
  void PrintUserMenuOptions() const override;
  void HandleUserInputForState(char input) override;
};

class StateMonitoringMenu : public State {
public:
  StateMonitoringMenu();
  void PrintUserMenuOptions() const override;
  void HandleUserInputForState(char input) override;
};

class StateDataBaseMenu : public State {
public:
  StateDataBaseMenu();
  void PrintUserMenuOptions() const override;
  void HandleUserInputForState(char input) override;
};
