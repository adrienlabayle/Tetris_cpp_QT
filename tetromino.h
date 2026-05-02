#ifndef TETROMINO_H
#define TETROMINO_H

#include <QPainter>

#include <QDebug>

class Tetromino{
    protected:
        int t_type;
        std::array<std::array<std::array<int, 4>, 4>, 4> t_shape;
        std::array<int, 2> top_left;
        int curr_rotation=0;

    public:
        Tetromino(int type, int x_pos);
        virtual ~Tetromino();

        int get_type() const;
        int get_x() const;
        int get_y() const;
        int get_rotation() const;
        void set_rotation(int rotation=0);
        void set_coord(int x, int y);
        std::array<std::array<int, 4>, 4> get_shape(int rotation) const;
        void right_move();
        void left_move();
        void down_move();
        void rotate_left();
        void rotate_right();

        virtual void display(QPainter * p, int nbl, int nbc, int height, int width) const;
        virtual void next_display(QPainter * p, int nbl, int nbc, int height, int width) const;
        virtual void hold_display(QPainter * p, int nbl, int nbc, int height, int width) const;
};

#endif // TETROMINO_H
