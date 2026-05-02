#ifndef GRID_H
#define GRID_H

#include <QPainter>
#include <iostream>

class Grid{
    private:
        int g_nbl;
        int g_nbc;
        int** g_grid;

    public:
        Grid(int nbl=22, int nbc=10, std::array<std::array<int, 10>, 22> grid_={}); //rq : std::array<std::array<int, 4>, 4> grid_={} initialise grid_ avec des 0 par default
        Grid(const Grid& g);
        ~Grid();
        Grid& operator=(const Grid& g);

        int get_nbl() const;
        int get_nbc() const;
        int get_grid(int row, int col) const;
        int* operator[](int row);
        int check_full_line();
        void add_grid(std::array<std::array<int, 4>, 4> tetro, int x_pos, int y_pos);
        void display(QPainter * p, int height, int width) const;
};

#endif // GRID_H
