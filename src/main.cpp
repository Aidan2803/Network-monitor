#include <iostream>

#include "user-menu-handler.hpp"

int main() {
  UserMenuHandler* umh = UserMenuHandler::GetUserMenuHandler();
  umh->UserMenuLoop();
}