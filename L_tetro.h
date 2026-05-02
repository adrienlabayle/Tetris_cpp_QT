#ifndef L_TETRO_H
#define L_TETRO_H

#include "tetromino.h"

class Ltetro : public Tetromino{
    public:
        Ltetro(int x_pos);

        void display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void next_display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void hold_display(QPainter * p, int nbl, int nbc, int height, int width) const;
};

#endif // L_TETRO_H
