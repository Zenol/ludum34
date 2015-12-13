#include "mlc.h"

#include "View.hpp"
#include "KeyboardControler.hpp"

KeyboardControler *kbd_controler;

void key(char *str, void *ptr)
{
    kbd_controler->key_pressed(str);
}

int display(void *ptr)
{
    return !View::get_instance()->refresh();
}

void resize(int w, int h, void *ptr)
{
    View::get_instance()->resize(w, h);
}

int main(int ac, char **av)
{
    mlc_init();

    kbd_controler = new KeyboardControler();

    // Bind hooks
    mlc_loop_hook((p_loop_hook)display, 0);
    mlc_key_hook((p_key_hook)key, 0);
    mlc_resize_hook((p_resize_hook)resize, 0);

    mlc_loop();
}
