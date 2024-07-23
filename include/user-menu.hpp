#pragma once

#include "state.hpp"

class UserMenu {
public:
    static UserMenu* GetUserMenu();
    ~UserMenu();
    void TransitionToState(State* state);
    StateID GetStateID();
    void PrintUserMenu();

private:
    UserMenu() : state_(nullptr) {}
    static UserMenu* user_menu_;
    State* state_;
};
