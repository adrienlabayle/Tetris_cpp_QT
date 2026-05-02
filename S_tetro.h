#ifndef S_TETRO_H
#define S_TETRO_H

#include "tetromino.h"

class Stetro : public Tetromino{
    public:
        Stetro(int x_pos);

        void display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void next_display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void hold_display(QPainter * p, int nbl, int nbc, int height, int width) const;
};

#endif // S_TETRO_H
