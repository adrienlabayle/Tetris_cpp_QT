#include "grid.h"

Grid::Grid(int nbl, int nbc, std::array<std::array<int, 10>, 22> grid_){
    g_nbl = nbl;
    g_nbc = nbc;
    g_grid = new int*[g_nbl];
    for(int i=0; i<g_nbl; i++){
        g_grid[i] = new int[g_nbc];
        for(int j=0; j<g_nbc; j++){
            g_grid[i][j] = grid_[i][j];
        }
    }
}

Grid::Grid(const Grid& g){
    g_nbl = g.g_nbl;
    g_nbc = g.g_nbc;
    g_grid = new int*[g_nbl];
    for(int i=0; i<g_nbl; i++){
        g_grid[i] = new int[g_nbc];
        for(int j=0; j<g_nbc; j++){
            g_grid[i][j] = g.g_grid[i][j];
        }
    }
}

Grid::~Grid(){
    for(int i=0; i<g_nbl; i++){
        delete g_grid[i];
    }
    delete g_grid;
}

Grid& Grid::operator=(const Grid& g){
    for(int i=0; i<g_nbl; i++){
        delete g_grid[i];
    }
    delete g_grid;

    g_nbl = g.g_nbl;
    g_nbc = g.g_nbc;
    g_grid = new int*[g_nbl];
    for(int i=0; i<g_nbl; i++){
        g_grid[i] = new int[g_nbc];
        for(int j=0; j<g_nbc; j++){
            g_grid[i][j] = g.g_grid[i][j];
        }
    }

    return *this;
}

int Grid::get_nbl() const{
    return g_nbl;
}

int Grid::get_nbc() const{
    return g_nbc;
}

int Grid::get_grid(int row, int col) const{ //permet de retourner une case de la grille sans pouvoir la modifier
    return g_grid[row][col];
}

int* Grid::operator[](int row){
    return g_grid[row];
}

int Grid::check_full_line(){
    int full_row_nbr=0;
    for(int i = g_nbl - 1; i >= 0; i--){
        bool full = true;

        for(int j = 0; j < g_nbc; j++){
            if(g_grid[i][j] == 0){
                full = false;
                break;
            }
        }

        if(full){  // descendre toutes les lignes au-dessus
            for(int k = i; k > 0; k--){
                for(int j = 0; j < g_nbc; j++){
                    g_grid[k][j] = g_grid[k-1][j];
                }
            }
            for(int j = 0; j < g_nbc; j++){  // vider la première ligne
                g_grid[0][j] = 0;
            }

            full_row_nbr++;
            i++;  // on re-teste la même ligne après décalage
        }
    }
    return full_row_nbr;
}

void Grid::add_grid(std::array<std::array<int, 4>, 4> tetro, int x_pos, int y_pos){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(tetro[i][j]!=0){
                g_grid[y_pos+i][x_pos+j] = tetro[i][j];
            }
        }
    }
}

void Grid::display(QPainter * p, int height, int width) const{
    int x = (2*width/5)/g_nbc;
    int y = height/g_nbl;

    QColor gridColor1(20, 30, 45);   // bleu nuit
    QColor gridColor2(30, 45, 65);   // bleu acier

    for(int i=0; i<g_nbl; i++){
        for(int j=0; j<g_nbc; j++){
            switch (g_grid[i][j]){
                case 0:
                    if(j%2==0){
                        p->setPen(QPen(gridColor1, 1));
                        p->drawRect((3*width/5) + (j*x) + 1, 0 + (i*y), x-1, y);
                        p->fillRect((3*width/5) + (j*x) + 1, 0 + (i*y), x-1, y, QBrush(gridColor1));
                    }
                    else{
                        p->setPen(QPen(gridColor2, 1));
                        p->drawRect((3*width/5) + (j*x) + 1, 0 + (i*y), x-1, y);
                        p->fillRect((3*width/5) + (j*x) + 1, 0 + (i*y), x-1, y, QBrush(gridColor2));
                    }
                    break;
                case 1:
                    p->setPen(QPen(Qt::white, 2));
                    p->drawRect((3*width/5) + (j*x), 0 + (i*y), x, y);
                    p->fillRect(((3*width/5) + (j*x))+1, (0 + (i*y))+1, x-2, y-2, QBrush(Qt::darkRed));
                    break;
                case 2:
                    p->setPen(QPen(Qt::white, 2));
                    p->drawRect((3*width/5) + (j*x), 0 + (i*y), x, y);
                    p->fillRect(((3*width/5) + (j*x))+1, (0 + (i*y))+1, x-2, y-2, QBrush(Qt::red));
                    break;
                case 3:
                    p->setPen(QPen(Qt::white, 2));
                    p->drawRect((3*width/5) + (j*x), 0 + (i*y), x, y);
                    p->fillRect(((3*width/5) + (j*x))+1, (0 + (i*y))+1, x-2, y-2, QBrush(Qt::green));
                    break;
                case 4:
                    p->setPen(QPen(Qt::white, 2));
                    p->drawRect((3*width/5) + (j*x), 0 + (i*y), x, y);
                    p->fillRect(((3*width/5) + (j*x))+1, (0 + (i*y))+1, x-2, y-2, QBrush(Qt::blue));
                    break;
                case 5:
                    p->setPen(QPen(Qt::white, 2));
                    p->drawRect((3*width/5) + (j*x), 0 + (i*y), x, y);
                    p->fillRect(((3*width/5) + (j*x))+1, (0 + (i*y))+1, x-2, y-2, QBrush(Qt::cyan));
                    break;
                case 6:
                    p->setPen(QPen(Qt::white, 2));
                    p->drawRect((3*width/5) + (j*x), 0 + (i*y), x, y);
                    p->fillRect(((3*width/5) + (j*x))+1, (0 + (i*y))+1, x-2, y-2, QBrush(Qt::magenta));
                    break;
                case 7:
                    p->setPen(QPen(Qt::white, 2));
                    p->drawRect((3*width/5) + (j*x), 0 + (i*y), x, y);
                    p->fillRect(((3*width/5) + (j*x))+1, (0 + (i*y))+1, x-2, y-2, QBrush(Qt::yellow));
                    break;
                default:
                    break;
            }
        }
    }
}
