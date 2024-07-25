#include "user-menu-handler.hpp"

UserMenuHandler* UserMenuHandler::user_menu_handler_ = nullptr;

UserMenuHandler* UserMenuHandler::GetUserMenuHandler() {
  if (!user_menu_handler_) {
    user_menu_handler_ = new UserMenuHandler();
  }
  return user_menu_handler_;
}

void UserMenuHandler::InitUserMenuHandler() {
  um_ = UserMenu::GetUserMenu();
  um_->TransitionToState(new StateMainMenu());
}

void UserMenuHandler::UserMenuLoop() {
  InitUserMenuHandler();

  while (1) {
    um_->PrintUserMenu();
    um_->RetreiveUserInput();
    um_->HandleUserInput();
  }
}
