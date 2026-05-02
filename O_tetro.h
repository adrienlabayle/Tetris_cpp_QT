#ifndef O_TETRO_H
#define O_TETRO_H

#include "tetromino.h"

class Otetro : public Tetromino{
    public:
        Otetro(int x_pos);

        void display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void next_display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void hold_display(QPainter * p, int nbl, int nbc, int height, int width) const;
};

#endif // O_TETRO_H
