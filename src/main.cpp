#include <iostream>

#include "user-menu.hpp"

int main() {
  UserMenu* um = UserMenu::GetUserMenu();
  um->TransitionToState(new StateMainMenu());
  um->PrintUserMenu();
  um->PrintUserMenu();
}