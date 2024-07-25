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

void UserMenu::PrintUserMenu() const { state_->PrintUserMenuOptions(); }

StateID UserMenu::GetStateID() const { return state_->GetStateID(); }

size_t UserMenu::GetMenuOptionsAmount() const { return state_->OptionsAmount(); }

// TODO: make system to handle values bigger then 9
void UserMenu::RetreiveUserInput() {
  char input = '0';
  std::cin >> input;
  if (user_input_ >= user_menu_constants::ZERO_ASCII_VALUE && user_input_ <= user_menu_constants::ZERO_ASCII_VALUE + GetMenuOptionsAmount()) {
    user_input_ = input;
  }
}

void UserMenu::HandleUserInput(){
    state_->HandleUserInputForState(user_input_);
}