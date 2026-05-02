#include "tetromino.h"

Tetromino::Tetromino(int type, int x_pos){
    t_type = type;

    top_left[0] = x_pos;
    top_left[1] = 0;
}

Tetromino::~Tetromino(){

}

int Tetromino::get_type() const{
    return t_type;
}

int Tetromino::get_x() const{
    return top_left[0];
}

int Tetromino::get_y() const{
    return top_left[1];
}

int Tetromino::get_rotation() const{
    return curr_rotation;
}

void Tetromino::set_rotation(int rotation){
    curr_rotation = rotation;
}

void Tetromino::set_coord(int x, int y){
    top_left[0] = x;
    top_left[1] = y;
}

std::array<std::array<int, 4>, 4> Tetromino::get_shape(int rotation) const{
    return t_shape[rotation];
}

void Tetromino::right_move(){
    top_left[0]++;
}

void Tetromino::left_move(){
    top_left[0]--;
}

void Tetromino::down_move(){
    top_left[1]++;
}

void Tetromino::rotate_right(){
    curr_rotation = (curr_rotation+1)%4;
}

void Tetromino::rotate_left(){
    curr_rotation = (curr_rotation+3)%4;
}

void Tetromino::display(QPainter * p, int nbl, int nbc, int height, int width) const{

}

void Tetromino::next_display(QPainter * p, int nbl, int nbc, int height, int width) const{

}

void Tetromino::hold_display(QPainter * p, int nbl, int nbc, int height, int width) const{

}
