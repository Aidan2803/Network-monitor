#include "info-displayer-handler.hpp"

InfoDisplayerHandler* InfoDisplayerHandler::user_menu_handler_ = nullptr;

InfoDisplayerHandler* InfoDisplayerHandler::GetInfoDisplayerHandler() {
  if (!user_menu_handler_) {
    user_menu_handler_ = new InfoDisplayerHandler();
  }
  return user_menu_handler_;
}

void InfoDisplayerHandler::InitInfoDisplayerHandler() {
  info_disp_ = InfoDisplayer::GetInfoDisplayer();
  info_disp_->TransitionToState(new StateMainMenu());
}

void InfoDisplayerHandler::InfoDisplayerLoop() {
  InitInfoDisplayerHandler();

  while (1) {
    info_disp_->PrintInfo();
    info_disp_->RetreiveUserInput();
    info_disp_->HandleUserInput();
  }
}
