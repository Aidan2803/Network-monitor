#include "info-displayer.hpp"

InfoDisplayer* InfoDisplayer::user_menu_ = nullptr;

InfoDisplayer* InfoDisplayer::GetInfoDisplayer() {
  if (!user_menu_) {
    user_menu_ = new InfoDisplayer();
  }
  return user_menu_;
}

InfoDisplayer::~InfoDisplayer() {
  if (state_) {
    delete state_;
  }
}

void InfoDisplayer::TransitionToState(State* state) {
  if (state_) {
    delete state_;
  }
  state_ = state;
  state_->SetInfoDisplayer(this);
}

void InfoDisplayer::PrintInfo() const { state_->PrintUserInfo(); }

StateID InfoDisplayer::GetStateID() const { return state_->GetStateID(); }

size_t InfoDisplayer::GetMenuOptionsAmount() const { return state_->OptionsAmount(); }

// TODO: make system to handle values bigger then 9
void InfoDisplayer::RetreiveUserInput() {
  char input = '0';
  std::cin >> input;
  if (input >= user_menu_constants::ZERO_ASCII_VALUE &&
      input <= user_menu_constants::ZERO_ASCII_VALUE + GetMenuOptionsAmount()) {
    user_input_ = input;
  }
  std::cout << user_input_ <<  " " << input << "\n";
}

void InfoDisplayer::HandleUserInput() { state_->HandleUserInputForState(user_input_); }