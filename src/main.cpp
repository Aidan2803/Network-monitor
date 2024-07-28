#include <iostream>

#include "info-displayer-handler.hpp"

int main() {
  InfoDisplayerHandler* info_disp_handler = InfoDisplayerHandler::GetInfoDisplayerHandler();
  info_disp_handler->InfoDisplayerLoop();
}