#include "user-menu.hpp"

UserMenu* UserMenu::user_menu_ = nullptr;

UserMenu* UserMenu::GetUserMenu() {
  if (!user_menu_) {
    user_menu_ = new UserMenu();
  }
  return user_menu_;
}

UserMenu::~UserMenu() {
  if (state_) {
    delete state_;
  }
}

void UserMenu::TransitionToState(State* state) {
  if (state_) {
    delete state_;
  }
  state_ = state;
  state_->SetUserMenu(this);
}

void UserMenu::PrintUserMenu() { state_->PrintUserMenuOptions(); }

StateID UserMenu::GetStateID() { return state_->GetStateID(); }

StateMainMenu::StateMainMenu() : State(StateID::kMainMenuState) {}
StateMonitoringMenu::StateMonitoringMenu() : State(StateID::kMonitoringMenuState) {}
StateDataBaseMenu::StateDataBaseMenu() : State(StateID::kDataBaseMenuState) {}

void StateMainMenu::PrintUserMenuOptions() {
  std::cout << "--- Main menu ---\n";
  std::cout << "1 - Monitoring";
  std::cout << "2 - Data Base menu";
  std::cout << "3 - Exit";
  std::cout << "Choose your option and press enter please\n";
  um_->TransitionToState(new StateMonitoringMenu());
}

void StateMonitoringMenu::PrintUserMenuOptions() {
  std::cout << "--- Monitoring menu ---\n";
  std::cout << "1 - Default monitoring";
  std::cout << "2 - Back";
  std::cout << "3 - Exit";
  std::cout << "Choose your option and press enter please\n";
  um_->TransitionToState(new StateDataBaseMenu());
}

void StateDataBaseMenu::PrintUserMenuOptions() {
  std::cout << "--- Data base menu ---\n";
  std::cout << "Choose your option and press enter please\n";
  um_->TransitionToState(new StateMonitoringMenu());
}
