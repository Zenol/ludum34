#ifndef VIEW_HPP_
#define VIEW_HPP_

#include <list>

class Particle {
public:
    Particle()
        :x(0), y(0), vx(0), vy(0), c('#')
    {};

    Particle(float _x, float _y, float _vx, float _vy, char _c)
        :x(_x), y(_y), vx(_vx), vy(_vy), c(_c)
    {};

    float x;
    float y;
    float vx;
    float vy;
    char  c;
};

typedef  std::list<Particle> Particles;

class Player {
public:
    Player(int ix) : x(ix), size(4) {};

    void move_left();
    void move_right();

    void draw();

    int x;
    float size;

    Particles particles;
};

class View {
public:
    static View *get_instance();

    // Exit when equal to false
    bool refresh();

    //Called when screen resized
    void resize(int w, int h);

    //Stop the game
    void exit();

    Player &get_player() {return player;}

private:
    View();

    void animate_particles();

    void draw_particles(char* color, Particles &particles);
    void clean_particles(Particles &particles);
    void reattach_particles(Particles &particles);
    void move_particles(Particles &particles);
    void update_particle_list(Particles &particles);

    Player player;
    Particles purple;
    Particles yellow;
    Particles red;
    Particles orange;
    Particles green;
    int time;
    bool run;
};

#endif /* !VIEW_HPP_ */
