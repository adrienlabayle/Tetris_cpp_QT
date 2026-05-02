#include "I_tetro.h"

Itetro::Itetro(int xpos) : Tetromino(1, xpos){
    t_shape = {{
        // rotation 0
        {{{0,t_type,0,0},
          {0,t_type,0,0},
          {0,t_type,0,0},
          {0,t_type,0,0}}},

        // rotation 1
        {{{t_type,t_type,t_type,t_type},
          {0,0,0,0},
          {0,0,0,0},
          {0,0,0,0}}},

        // rotation 2
        {{{0,t_type,0,0},
          {0,t_type,0,0},
          {0,t_type,0,0},
          {0,t_type,0,0}}},

        // rotation 3
        {{{t_type,t_type,t_type,t_type},
          {0,0,0,0},
          {0,0,0,0},
          {0,0,0,0}}},
    }};
}

void Itetro::display(QPainter * p, int nbl, int nbc, int height, int width) const{
    int x = (2*width/5)/nbc;
    int y = height/nbl;

    std::array<std::array<int, 4>, 4> curr_shape = get_shape(get_rotation());

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(curr_shape[i][j]!=0){
                p->setPen(QPen(Qt::white, 2));
                p->drawRect((3*width/5) + ((j+top_left[0])*x), 0 + ((i+top_left[1])*y), x, y);
                p->fillRect(((3*width/5) + ((j+top_left[0])*x))+1, (0 + ((i+top_left[1])*y))+1, x-2, y-2, QBrush(Qt::darkRed));
            }
        }
    }
}

void Itetro::next_display(QPainter * p, int nbl, int nbc, int height, int width) const{
    int x = (2*width/5)/nbc;
    int y = height/nbl;

    std::array<std::array<int, 4>, 4> curr_shape = get_shape(get_rotation());

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(curr_shape[i][j]!=0){
                p->setPen(QPen(Qt::white, 2));
                p->drawRect((width/5) + ((j+top_left[0])*x), 0 + ((i+(nbl/2)-2-6)*y), x, y);
                p->fillRect(((width/5) + ((j+top_left[0])*x))+1, (0 + ((i+(nbl/2)-8)*y))+1, x-2, y-2, QBrush(Qt::darkRed)); /* on fait -2-4 le -2 vient du vrai recentrage*/
            }
        }
    }
}

void Itetro::hold_display(QPainter * p, int nbl, int nbc, int height, int width) const{
    int x = (2*width/5)/nbc;
    int y = height/nbl;

    std::array<std::array<int, 4>, 4> curr_shape = get_shape(get_rotation());

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(curr_shape[i][j]!=0){
                p->setPen(QPen(Qt::white, 2));
                p->drawRect((width/5) + ((j+3)*x), 0 + ((i+(nbl/2)+6)*y), x, y);
                p->fillRect(((width/5) + ((j+3)*x))+1, (0 + ((i+(nbl/2)+6)*y))+1, x-2, y-2, QBrush(Qt::darkRed)); /* on fait -2-4 le -2 vient du vrai recentrage*/
            }
        }
    }
}
