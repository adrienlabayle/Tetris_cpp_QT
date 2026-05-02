#ifndef T_TETRO_H
#define T_TETRO_H

#include "tetromino.h"

class Ttetro : public Tetromino{
    public:
        Ttetro(int x_pos);

        void display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void next_display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void hold_display(QPainter * p, int nbl, int nbc, int height, int width) const;
};

#endif // T_TETRO_H
