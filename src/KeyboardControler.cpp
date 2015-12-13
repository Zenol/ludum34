#include "mlc.h"

#include "KeyboardControler.hpp"
#include "View.hpp"

void KeyboardControler::key_pressed(std::string key)
{
    if (mlc_keycode(key.c_str()) == KEY_ESC
        || key == "q" || key == "Q")
        View::get_instance()->exit();

    View *view = View::get_instance();
    if (mlc_keycode(key.c_str()) == KEY_LEFT)
    {
        view->get_player().move_left();
    }
    if (mlc_keycode(key.c_str()) == KEY_RIGHT)
    {
        view->get_player().move_right();
    }
}
