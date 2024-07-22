#include "state.hpp"

class UserMenu {
public:
  UserMenu* GetUserMenu() {
    if(user_menu_){
        return user_menu_;
    } 

    user_menu_ = UserMenu();
    return user_menu_;
  }

  ~UserMenu() {
    if (state_) {
      delete state_;
    }
  }

  void TransitionToState(State* state) {
    if (this->state_) {
      delete state_;
    }
    state_ = state;
    state_->SetUserMenu(this);
  }

  void PrintMenu(){
    state_->PrintMenuOptions();
  }

private:
  UserMenu* user_menu_;
  UserMenu() {}
  State* state_;
};