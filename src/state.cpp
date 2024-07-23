#include "state.hpp"
#include "user-menu.hpp"

StateMainMenu::StateMainMenu() : State(StateID::kMainMenuState) {}
StateMonitoringMenu::StateMonitoringMenu() : State(StateID::kMonitoringMenuState) {}
StateDataBaseMenu::StateDataBaseMenu() : State(StateID::kDataBaseMenuState) {}

void StateMainMenu::PrintUserMenuOptions() {
    std::cout << "--- Main menu ---\n";
    std::cout << "1 - Monitoring\n";
    std::cout << "2 - Data Base menu\n";
    std::cout << "3 - Exit\n";
    std::cout << "Choose your option and press enter please\n";
    um_->TransitionToState(new StateMonitoringMenu());
}

void StateMonitoringMenu::PrintUserMenuOptions() {
    std::cout << "--- Monitoring menu ---\n";
    std::cout << "1 - Default monitoring\n";
    std::cout << "2 - Back\n";
    std::cout << "3 - Exit\n";
    std::cout << "Choose your option and press enter please\n";
    um_->TransitionToState(new StateDataBaseMenu());
}

void StateDataBaseMenu::PrintUserMenuOptions() {
    std::cout << "--- Data base menu ---\n";
    std::cout << "Choose your option and press enter please\n";
    um_->TransitionToState(new StateMonitoringMenu());
}
