#include <string>
#include <iostream>
#include <cmath>

#include "mlc.h"

#include "View.hpp"

View::View()
    :run(true), player(39)
{
    mlc_cur_hide();
}

View *View::get_instance()
{
    static View* instance;

    if (!instance)
        instance = new View;
    return instance;
}

void View::animate_particles()
{
}

void View::draw_particles()
{
}

void View::clean_particles(Particles &particles)
{
    for (Particles::iterator it = particles.begin();
         it != particles.end(); it++)
        if (it-> x < 0 || it->y < 0 ||
            it->x > 79 || it->y > 29)
            it = particles.erase(it);
}

bool View::refresh()
{
    int w = mlc_width();
    int h = mlc_height();

    if (w < 80 || h < 30)
    {
        mlc_clear();
        std::string msg = "Smallest size : 80x60";

        int x = x/2 - msg.length()/2;
        if (x < 0)
            x = 0;
        int y = h/2;
        mlc_setpos(10, y);
        mlc_putcolor(CLR__BLACK);
        mlc_putcolor(CLR_RED);
        mlc_putstr(msg.c_str());

        mlc_show();

        return false;
    }

    mlc_clear();

    time++;

    animate_particles();
    draw_particles();
    player.draw();

    mlc_show();

    return run;
}

void View::resize(int w, int h)
{
}

void View::exit()
{
    run = false;
}

void Player::move_left()
{
    x -= 2;
    if (x < 0)
        x = 0;
}

void Player::move_right()
{
    x += 2;
    if (x >= 80)
        x = 79;
}

int Player::get_position()
{
    return x;
}

float sign(float v)
{
    if (v < 0)
        return -1;
    return 1;
}

void Player::draw()
{
    mlc_setpos(x, 15);
    mlc_putcolor(CLR__BLACK);
    mlc_putcolor(CLR_RED);
    mlc_putchar('O');

    for (Particles::iterator it = particles.begin();
         it != particles.end(); it++)
    {
        it->x += it->vx;
        it->y += it->vy;
        it->vx += (x - it->x) / 6.0f;
        it->vy += (15 - it->y) / 6.0f;
        if (std::abs(it->x - x) > size)
            it->vx -= 0.3 * it->vx;
        if (std::abs(it->y - 15) > size)
            it->vy -= 0.3 * it->vy;
        mlc_setpos((int)it->x, (int)it->y);
        mlc_putcolor(CLR_BLUE);
        mlc_putchar(it->c);
    }


    size += 0.001 * 1 / size;
}
