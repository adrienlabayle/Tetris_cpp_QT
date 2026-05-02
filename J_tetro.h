#ifndef J_TETRO_H
#define J_TETRO_H

#include "tetromino.h"

class Jtetro : public Tetromino{
    public:
        Jtetro(int x_pos);

        void display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void next_display(QPainter * p, int nbl, int nbc, int height, int width) const;
        void hold_display(QPainter * p, int nbl, int nbc, int height, int width) const;
};

#endif // J_TETRO_H
