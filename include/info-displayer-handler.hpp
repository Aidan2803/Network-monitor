#include "info-displayer.hpp"

class InfoDisplayerHandler {
public:
  static InfoDisplayerHandler* GetInfoDisplayerHandler();

  void InfoDisplayerLoop();

private:
  InfoDisplayerHandler(){};
  void InitInfoDisplayerHandler();

private:
  static InfoDisplayerHandler* user_menu_handler_;
  char user_input_;
  InfoDisplayer* info_disp_;
};