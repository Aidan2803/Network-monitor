#include "state.hpp"

#include "info-displayer.hpp"

void State::PrintInfoVector() const {
  for (int i = 0; i < info_options_vector_.size(); i++) {
    std::cout << info_options_vector_[i];
  }
}

StateID State::GetStateID() const { return state_id_; }

size_t State::OptionsAmount() const { return info_options_vector_.size(); }

StateMainMenu::StateMainMenu() : State(StateID::kMainMenuState) {
  info_options_vector_.push_back("1 - Monitoring\n");
  info_options_vector_.push_back("2 - Data Base menu\n");
  info_options_vector_.push_back("3 - Exit\n");
}
StateMonitoringMenu::StateMonitoringMenu() : State(StateID::kMonitoringMenuState) {
  info_options_vector_.push_back("1 - Default monitoring\n");
  info_options_vector_.push_back("2 - Back\n");
  info_options_vector_.push_back("3 - Exit\n");
}
StateDataBaseMenu::StateDataBaseMenu() : State(StateID::kDataBaseMenuState) {
  info_options_vector_.push_back("1 - Upload to DB\n");
  info_options_vector_.push_back("2 - Upload from DB\n");
  info_options_vector_.push_back("3 - Back\n");
  info_options_vector_.push_back("4 - Exit\n");
}

void StateMainMenu::PrintUserInfo() const {
  // system("clear");
  std::cout << "--- Main menu ---\n";
  PrintInfoVector();
  std::cout << "Choose your option and press enter please\n";
}

void StateMonitoringMenu::PrintUserInfo() const {
  system("clear");
  std::cout << "--- Monitoring menu ---\n";
  PrintInfoVector();
  std::cout << "Choose your option and press enter please\n";
}

void StateDataBaseMenu::PrintUserInfo() const {
  system("clear");
  std::cout << "--- Data base menu ---\n";
  PrintInfoVector();
  std::cout << "Choose your option and press enter please\n";
}

void StateMainMenu::HandleUserInputForState(char input) {
  std::cout << input << "\n";
  switch (input) {
    case '1':
      info_disp_->TransitionToState(new StateMonitoringMenu);
      break;
    case '2':
      info_disp_->TransitionToState(new StateDataBaseMenu);
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
      info_disp_->TransitionToState(new StateDataBaseMenu);
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
