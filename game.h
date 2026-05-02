#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "tetromino.h"
#include "I_tetro.h"
#include "J_tetro.h"
#include "L_tetro.h"
#include "O_tetro.h"
#include "S_tetro.h"
#include "T_tetro.h"
#include "Z_tetro.h"

#include <iostream>
#include <random>
#include <fstream>

class Game{
    private:
        std::mt19937 gen;
        std::uniform_int_distribution<> dis;

        Tetromino* curr_tetro=nullptr;
        Tetromino* next_tetro=nullptr;
        Tetromino* hold_tetro=nullptr;
        Grid* grid=nullptr;
        int state=1;
        int score=0;
        int level=0;
        int full_row=0;
        bool holded=false;
        bool end=false;
        int nbl;
        int nbc;

    public:
        Game(int nb_l, int nb_c, int state_=1, int full_row_=0, int score_=0, bool holded_=false, int curr_tetro_=0, int next_tetro_=0, int hold_tetro_=0, std::array<std::array<int, 10>, 22> grid_={});
        Game(const Game& g);
        Game& operator=(const Game& g);
        ~Game();

        int get_level() const;
        void get_rd_tetro();
        Tetromino* get_tetro(int tetro_id);
        bool get_end() const;
        int get_state() const;
        bool check_collision(std::array<std::array<int, 4>, 4> tetro, int x_pos, int y_pos) const;
        void update_score(int full_row_nbr);
        void rotate_tetro_right();
        void rotate_tetro_left();
        void move_tetro_right();
        void move_tetro_left();
        void move_tetro_down();
        void check_end();
        void hard_drop();
        void set_hold();
        void display_score(QPainter * p, int height, int width) const;
        void display_projection(std::array<std::array<int, 4>, 4> tetro, int x_pos, int y_pos, QPainter *p, int nbl, int nbc, int height, int width) const;
        void softdrop_scoring();
        void display(QPainter * p, int height, int width) const;
        void reset();
        void save(std::string path, int time);
};

#endif // GAME_H
