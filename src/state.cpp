#include "state.hpp"

#include "user-menu.hpp"

void State::PrintOptionsVector() const {
  for (int i = 0; i < menu_options_vector_.size(); i++) {
    std::cout << menu_options_vector_[i];
  }
}

StateID State::GetStateID() const{ return state_id_; }

size_t State::OptionsAmount() const { return menu_options_vector_.size(); }

StateMainMenu::StateMainMenu() : State(StateID::kMainMenuState) {
  menu_options_vector_.push_back("1 - Monitoring\n");
  menu_options_vector_.push_back("2 - Data Base menu\n");
  menu_options_vector_.push_back("3 - Exit\n");
}
StateMonitoringMenu::StateMonitoringMenu() : State(StateID::kMonitoringMenuState) {
  menu_options_vector_.push_back("1 - Default monitoring\n");
  menu_options_vector_.push_back("2 - Back\n");
  menu_options_vector_.push_back("3 - Exit\n");
}
StateDataBaseMenu::StateDataBaseMenu() : State(StateID::kDataBaseMenuState) {
  menu_options_vector_.push_back("1 - Upload to DB\n");
  menu_options_vector_.push_back("2 - Upload from DB\n");
  menu_options_vector_.push_back("3 - Back\n");
  menu_options_vector_.push_back("4 - Exit\n");
}

void StateMainMenu::PrintUserMenuOptions() const {
  system("clear");
  std::cout << "--- Main menu ---\n";
  PrintOptionsVector();
  std::cout << "Choose your option and press enter please\n";
}

void StateMonitoringMenu::PrintUserMenuOptions() const {
  system("clear");
  std::cout << "--- Monitoring menu ---\n";
  PrintOptionsVector();
  std::cout << "Choose your option and press enter please\n";
}

void StateDataBaseMenu::PrintUserMenuOptions() const {
  system("clear");
  std::cout << "--- Data base menu ---\n";
  PrintOptionsVector();
  std::cout << "Choose your option and press enter please\n";
}

void StateMainMenu::HandleUserInputForState(char input) {
  switch (input) {
    case '1':
      um_->TransitionToState(new StateMonitoringMenu);
      break;
    case '2':
      um_->TransitionToState(new StateDataBaseMenu);
      break;
    case '3':
      // TODO: exit here
      break;
    default:
      std::cout << "No valid input was provided\n";
      break;
  }
}

void StateMonitoringMenu::HandleUserInputForState(char input) {
  switch (input) {
    case '1':
      // TODO: transition to the Default Monitoring state 
      break;
    case '2':
      um_->TransitionToState(new StateDataMainMenu);
      break;
    case '3':
    // TODO: exit here
      break;
    default:
      std::cout << "No valid input was provided\n";
      break;
  }
}

void StateDataBaseMenu::HandleUserInputForState(char input) {
  switch (input) {
    case '1':
      // TODO: to implement Data Base Class first
      break;
    case '2':
      // TODO: to implement Data Base Class first
      break;
    case '3':
      // TODO: exit here
      break;
    default:
      std::cout << "No valid input was provided\n";
      break;
  }
}
