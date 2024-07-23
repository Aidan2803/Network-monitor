#pragma once

#include <iostream>

class UserMenu;
class State;
class StateDataBaseMenu;
class StateMonitoringMenu;
class StateMainMenu;

class State {
public:
    void SetUserMenu(UserMenu* menu) {
        um_ = menu;
    }
    virtual void PrintUserMenuOptions() = 0;

protected:
    UserMenu* um_;
};

class UserMenu {
public:
    static UserMenu* GetUserMenu() {
        if (!user_menu_) {
            user_menu_ = new UserMenu();
        }
        return user_menu_;
    }

    ~UserMenu() {
        if (state_) {
            delete state_;
        }
    }

    void TransitionToState(State* state) {
        if (state_) {
            delete state_;
        }
        state_ = state;
        state_->SetUserMenu(this);
    }

    void PrintUserMenu() {
        state_->PrintUserMenuOptions();
    }

private:
    UserMenu() : state_(nullptr) {}

    static UserMenu* user_menu_;
    State* state_;
};

class StateDataBaseMenu : public State {
public:
    void PrintUserMenuOptions() override;
};

class StateMonitoringMenu : public State {
public:
    void PrintUserMenuOptions() override;
};

class StateMainMenu : public State {
public:
    void PrintUserMenuOptions() override;
};
