#include "user-menu.hpp"

UserMenu* UserMenu::user_menu_ = nullptr;

void StateDataBaseMenu::PrintUserMenuOptions() {
    std::cout << "--- Data base menu ---\n";
    std::cout << "Choose your option and press enter please\n";
    um_->TransitionToState(new StateMonitoringMenu());
}

void StateMonitoringMenu::PrintUserMenuOptions() {
    std::cout << "--- Monitoring menu ---\n";
    std::cout << "Choose your option and press enter please\n";
    um_->TransitionToState(new StateDataBaseMenu());
}

void StateMainMenu::PrintUserMenuOptions() {
    std::cout << "--- Main menu ---\n";
    std::cout << "Choose your option and press enter please\n";
    um_->TransitionToState(new StateMonitoringMenu());
}
