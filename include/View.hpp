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

    int get_position();

    void draw();
private:
    int x;
    Particles particles;
    float size;
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
    void draw_particles();

    void clean_particles(Particles &particles);

    Player player;
    Particles purple;
    int time;
    bool run;
};

#endif /* !VIEW_HPP_ */
