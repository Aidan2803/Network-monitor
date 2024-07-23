#include <iostream>
#include "user-menu.hpp"
#include "state.hpp"

int main(){
    UserMenu* um = UserMenu::GetUserMenu();
    um->TransitionToState(new StateMainMenu());
    um->PrintUserMenu();
    um->PrintUserMenu();
}