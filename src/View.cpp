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
    /* Script */
    if (time == 10)
    {
        purple.push_back(Particle(37, 0, 0, 1, 'z'));
        purple.push_back(Particle(39, 0, 0, 1, 'v'));
        purple.push_back(Particle(41, 0, 0, 1, 'w'));
    }

    if (time == 40)
    {
        orange.push_back(Particle(0, 0, 1, 1, '&'));
        orange.push_back(Particle(4, 0, 1, 1, '^'));
        orange.push_back(Particle(8, 0, 1, 1, '@'));
    }

    if (time == 63)
    {
        red.push_back(Particle(40, 0, -0.49, 1, '&'));
        red.push_back(Particle(40, 0, +0.49, 1, '&'));

    }

    if (time == 80)
    {
        green.push_back(Particle(79, 0, -1, 1, '&'));
        green.push_back(Particle(76, 0, -1, 1, '^'));
        green.push_back(Particle(72, 0, -1, 1, '@'));
    }

    Particles::iterator it;
    if (time > 100 && time < 400)
    {
        if (time % 10 == 0)
            yellow.push_back(Particle(40, 0, 0, 1.5, '$'));
    }
    if (time < 430)
        for (it = yellow.begin(); it != yellow.end(); it++)
        {
            float dx, dy;
            if(time > 250)
            {
                dx = (7 - it->x);
                dy = (40 - it->y);
            }
            else
            {
                dx = (80-7 - it->x);
                dy = (40 - it->y);
            }

            it->vx = 0.03*dx;
            it->vy = 0.03*dy;
        }

    if (time > 440 && time < 800)
    {
        if (time % 40 == 0)
        {
            orange.push_back(Particle(1,  0, 0, 0.3, '['));
            orange.push_back(Particle(5,  0, 0, 0.3, '{'));
            orange.push_back(Particle(10, 0, 0, 0.3, '('));

            orange.push_back(Particle(79, 0, 0, 0.3, ']'));
            orange.push_back(Particle(74, 0, 0, 0.3, '}'));
            orange.push_back(Particle(70, 0, 0, 0.3, ')'));
        }

    }
    if (time < 860)
        for (it = orange.begin(); it != orange.end(); it++)
            it->vx += 0.002*(40 - it->x);

    if (time == 890)
    {
        red   .push_back(Particle( 1,  1, 0, 0, 'e'));
        purple.push_back(Particle(70,  1, 0, 0, 'i'));
        red   .push_back(Particle(20,  1, 0, 0, 'i'));
        orange.push_back(Particle(10,  2, 0, 0, 'a'));
        red   .push_back(Particle(79,  0, 0, 0.3, 'k'));
        orange.push_back(Particle( 1,  3, 0, 0.3, 's'));
        purple.push_back(Particle( 3,  2, 0, 0.3, 's'));
        green .push_back(Particle(70,  4, 0, 0.3, 'l'));
        purple.push_back(Particle( 7,  1, 0, 0, 'q'));
        red   .push_back(Particle( 6,  2, 0, 0, 'r'));
        green .push_back(Particle(50,  1, 0, 0, 'h'));
        purple.push_back(Particle(40,  0, 0, 0, 'g'));
        green .push_back(Particle(43,  6, 0, 0, 'u'));

    }
    if (time >= 890 && time < 950)
    {
        for (it = orange.begin(); it != orange.end(); it++)
        {
            it->vx -= 0.002*(40 - it->x);
            it->vy -= 0.004*(-3 - it->y);
        }
        for (it = red.begin(); it != red.end(); it++)
        {
            it->vx -= 0.002*(40 - it->x);
            it->vy -= 0.004*(-3 - it->y);
        }
        for (it = green.begin(); it != green.end(); it++)
        {
            it->vx -= 0.002*(40 - it->x);
            it->vy -= 0.004*(-3 - it->y);
        }
        for (it = purple.begin(); it != purple.end(); it++)
        {
            it->vx -= 0.002*(40 - it->x);
            it->vy -= 0.004*(-3 - it->y);
        }
    }


    if (time > 950)
    {
        if (time % 10 == 0)
        {
            purple.push_back(Particle(time % 14 + 20, 0, 0, 1, '['));
            orange.push_back(Particle(time % 13, 3, 0, 1, '}'));
            green.push_back(Particle(time % 14 + 45, 9, 0, 1, ')'));
            yellow.push_back(Particle(time % 4 + 75, 0, 0, 1, ';'));
        }
    }

    /* Animation */
    update_particle_list(purple);
    update_particle_list(yellow);
    update_particle_list(red);
    update_particle_list(orange);
    update_particle_list(green);
}

void View::draw_particles(char *color, Particles &particles)
{
    for (Particles::iterator it = particles.begin();
         it != particles.end(); it++)
    {
        mlc_setpos(it->x, it->y);
        mlc_putcolor(color);
        mlc_putchar(it->c);
    }

}

void View::update_particle_list(Particles &particles)
{
    move_particles(particles);
    clean_particles(particles);
    reattach_particles(particles);
}

void View::move_particles(Particles &particles)
{
    for (Particles::iterator it = particles.begin();
         it != particles.end(); it++)
    {
        it->x += it->vx;
        it->y += it->vy;
    }
}

void View::clean_particles(Particles &particles)
{
    Particles::iterator it = particles.begin();
    while(it != particles.end())
    {
        if (it-> x < 0 || it->y < 0 ||
            it->x > 79 || it->y > 29)
            it = particles.erase(it);
        else
            it++;
    }
}

void View::reattach_particles(Particles &particles)
{
    Particles::iterator it = particles.begin();
    while (it != particles.end())
    {
        if (std::abs(it->x - player.x) < player.size
            && std::abs(it->y - 23) < player.size)
        {
            player.particles.push_back(*it);
            it = particles.erase(it);
        }
        else
            it++;
    }
}

bool View::refresh()
{
    int w = mlc_width();
    int h = mlc_height();

    if (w < 80 || h < 30)
    {
        mlc_clear();
        std::string msg = "Smallest size : 80x30";

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
    draw_particles(CLR_VIOLET, purple);
    draw_particles(CLR_YELLOW, yellow);
    draw_particles(CLR_RED, red);
    draw_particles(CLR_ORANGE, orange);
    draw_particles(CLR_GREEN, green);
    player.draw();

    mlc_show();

    if (player.particles.size() >= 100)
    {
        mlc_clear();
        std::cout << "Congratulation, you finished the game, with "
                  << player.particles.size() << " letters, after "
                  << time << " processor tics. Why not take a bit of sun?"
                  << std::endl;
        return false;
    }

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

float sign(float v)
{
    if (v < 0)
        return -1;
    return 1;
}

void Player::draw()
{
    mlc_setpos(x, 23);
    mlc_putcolor(CLR__BLACK);
    mlc_putcolor(CLR_RED);
    mlc_putchar('O');

    for (Particles::iterator it = particles.begin();
         it != particles.end(); it++)
    {
        it->x += it->vx;
        it->y += it->vy;
        it->vx += (x - it->x) / 6.0f;
        it->vy += (23 - it->y) / 6.0f;
        if (std::abs(it->x - x) > size)
            it->vx -= 0.3 * it->vx;
        if (std::abs(it->y - 23) > size)
            it->vy -= 0.3 * it->vy;
        if (it->x >0 && it->y > 0 && it->x <80 && it->y < 30)
        {
            mlc_setpos((int)it->x, (int)it->y);
            mlc_putcolor(CLR_BLUE);
            mlc_putchar(it->c);
        }
    }


    size = 4 + particles.size()/10.0f;
}
