#ifndef I_TETRO_H
#define I_TETRO_H

#include "tetromino.h"

class Itetro : public Tetromino{
    public:
        Itetro(int x_pos);

        void display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void next_display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void hold_display(QPainter * p, int nbl, int nbc, int height, int width) const;
};

#endif // I_TETRO_H
