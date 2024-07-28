#pragma once

#include <iostream>
#include <vector>

class InfoDisplayer;

enum class StateID { kMainMenuState = 0, kMonitoringMenuState = 1, kDataBaseMenuState = 2 };

class State {
public:
  void SetInfoDisplayer(InfoDisplayer* menu) { info_disp_ = menu; }
  virtual void PrintUserInfo() const = 0;
  void PrintInfoVector() const;
  virtual void HandleUserInputForState(char input) = 0;

  StateID GetStateID() const;
  size_t OptionsAmount() const;

protected:
  State(StateID stateid) : info_disp_(nullptr), state_id_(stateid) {}
  InfoDisplayer* info_disp_;
  StateID state_id_;
  std::vector<std::string> info_options_vector_;
};

class StateMainMenu : public State {
public:
  StateMainMenu();
  void PrintUserInfo() const override;
  void HandleUserInputForState(char input) override;
};

class StateMonitoringMenu : public State {
public:
  StateMonitoringMenu();
  void PrintUserInfo() const override;
  void HandleUserInputForState(char input) override;
};

class StateDataBaseMenu : public State {
public:
  StateDataBaseMenu();
  void PrintUserInfo() const override;
  void HandleUserInputForState(char input) override;
};
