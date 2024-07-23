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

void UserMenu::PrintUserMenu() {
    state_->PrintUserMenuOptions();
}

StateID UserMenu::GetStateID() {
    return state_->GetStateID();
}
