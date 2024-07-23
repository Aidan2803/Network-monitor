#include <iostream>

#include "state.hpp"
#include "user-menu.hpp"

int main() {
  UserMenu* um = UserMenu::GetUserMenu();
  um->TransitionToState(new StateMainMenu());
  um->PrintUserMenu();
  um->PrintUserMenu();
}