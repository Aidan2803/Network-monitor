#include "user-menu.hpp"

class UserMenuHandler {
public:
  static UserMenuHandler* GetUserMenuHandler();

  void UserMenuLoop();

private:
  UserMenuHandler(){};
  void InitUserMenuHandler();

private:
  static UserMenuHandler* user_menu_handler_;
  char user_input_;
  UserMenu* um_;
};