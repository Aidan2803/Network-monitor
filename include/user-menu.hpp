#include "state.hpp"

class Menu {
public:
  Menu* CreateMenu() {
    if(menu_){
        return menu_;
    } 

    menu_ = Menu();
    
  }

  ~Menu() {
    if (state_) {
      delete state_;
    }
  }

  void TransitionToState(State* state) {
    if (this->state_) {
      delete state_;
    }
    state_ = state;
    state_->SetMenu(this);
  }

private:
    Menu* menu_;
  Menu() {}
  State* state_;
};