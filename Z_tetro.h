#ifndef Z_TETRO_H
#define Z_TETRO_H

#include "tetromino.h"

class Ztetro : public Tetromino{
    public:
        Ztetro(int x_pos);

        void display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void next_display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void hold_display(QPainter * p, int nbl, int nbc, int height, int width) const;
};

#endif // Z_TETRO_H
