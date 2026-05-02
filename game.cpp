#include "game.h"

Game::Game(int nb_l, int nb_c, int state_, int full_row_, int score_, bool holded_, int curr_tetro_, int next_tetro_, int hold_tetro_, std::array<std::array<int, 10>, 22> grid_){
    std::random_device rd;
    gen = std::mt19937(rd());
    dis = std::uniform_int_distribution<>(0, 6);

    state = state_;
    score = score_;
    holded = holded_;
    full_row = full_row_;
    level = full_row_/10;

    if((curr_tetro_==0) && (next_tetro_==0)){
        get_rd_tetro();
        curr_tetro = next_tetro;
        get_rd_tetro();
    }
    else{
        curr_tetro = get_tetro(curr_tetro_);
        next_tetro = get_tetro(next_tetro_);
    }

    if(hold_tetro_!=0){
        hold_tetro = get_tetro(hold_tetro_);
    }

    nbl = nb_l;
    nbc = nb_c;

    grid = new Grid(nbl, nbc, grid_);
}

Game::Game(const Game& g){
    state = g.state;
    score = g.score;
    holded = g.holded;
    full_row = g.full_row;
    level = full_row/10;

    if((g.curr_tetro==nullptr) && (g.next_tetro==nullptr)){
        get_rd_tetro();
        curr_tetro = next_tetro;
        get_rd_tetro();
    }
    else{
        curr_tetro = g.curr_tetro;
        next_tetro = g.next_tetro;
    }

    if(g.hold_tetro!=nullptr){
        hold_tetro = g.hold_tetro;
    }

    nbl = g.nbl;
    nbc = g.nbc;

    if(g.grid!=nullptr){
        grid = g.grid;
    }
    else{
        grid = new Grid(nbl, nbc);
    }
}

Game& Game::operator=(const Game& g){
    delete grid;
    delete curr_tetro;
    delete next_tetro;
    delete hold_tetro;

    state = g.state;
    score = g.score;
    holded = g.holded;
    full_row = g.full_row;
    level = full_row/10;

    if((g.curr_tetro==nullptr) && (g.next_tetro==nullptr)){
        get_rd_tetro();
        curr_tetro = next_tetro;
        get_rd_tetro();
    }
    else{
        curr_tetro = g.curr_tetro;
        next_tetro = g.next_tetro;
    }

    if(g.hold_tetro!=nullptr){
        hold_tetro = g.hold_tetro;
    }

    nbl = g.nbl;
    nbc = g.nbc;

    if(g.grid!=nullptr){
        grid = g.grid;
    }
    else{
        grid = new Grid(nbl, nbc);
    }

    return *this;
}

Game::~Game(){
    delete grid;
    delete curr_tetro;
    delete next_tetro;
    delete hold_tetro;
}

int Game::get_level() const{
    return level;
}

void Game::get_rd_tetro(){
    int num = dis(gen);

    switch (num){
        case 0:
            next_tetro = new Itetro(3);
            break;
        case 1:
            next_tetro = new Jtetro(3);
            break;
        case 2:
            next_tetro = new Ltetro(3);
            break;
        case 3:
            next_tetro = new Otetro(3);
            break;
        case 4:
            next_tetro = new Stetro(3);
            break;
        case 5:
            next_tetro = new Ttetro(3);
            break;
        case 6:
            next_tetro = new Ztetro(3);
            break;
        default:
            break;
    }
}

Tetromino* Game::get_tetro(int tetro_id){
    switch (tetro_id){
    case 1:
        return new Itetro(3);
        break;
    case 2:
        return new Jtetro(3);
        break;
    case 3:
        return new Ltetro(3);
        break;
    case 4:
        return new Otetro(3);
        break;
    case 5:
        return new Stetro(3);
        break;
    case 6:
        return new Ttetro(3);
        break;
    case 7:
        return new Ztetro(3);
        break;
    default:
        break;
    }
}

bool Game::get_end() const{
    return end;
}

int Game::get_state() const{
    return state;
}

bool Game::check_collision(std::array<std::array<int, 4>, 4> tetro, int x_pos, int y_pos) const{ //revoie vrai si collision
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(tetro[i][j] != 0){
                if((x_pos+j >= 0) && (x_pos+j < nbc) && (y_pos+i < nbl)){ //on regarde si cette parti du tetro est dans la grille (puit)
                    if(grid->get_grid(y_pos+i, x_pos+j) != 0){
                        return true;
                    }
                }
                else{
                    return true;
                }
            }
        }
    }
    return false;
}

void Game::update_score(int full_row_nbr){
    int p;
    switch (full_row_nbr){
        case 0:
            p=0;
            break;
        case 1:
            p=40;
            break;
        case 2:
            p=100;
            break;
        case 3:
            p=300;
            break;
        default:
            p=1200;
            break;
    }

    score += p*(level+1);
    full_row += full_row_nbr;
    level = full_row/10;
}

void Game::softdrop_scoring(){
    score++;
}

void Game::rotate_tetro_right(){
    if(!check_collision(curr_tetro->get_shape((curr_tetro->get_rotation()+1)%4), curr_tetro->get_x(), curr_tetro->get_y())){
        curr_tetro->rotate_right();
    }
}

void Game::rotate_tetro_left(){
    if(!check_collision(curr_tetro->get_shape((curr_tetro->get_rotation()+3)%4), curr_tetro->get_x(), curr_tetro->get_y())){
        curr_tetro->rotate_left();
    }
}

void Game::move_tetro_right(){
    if(!check_collision(curr_tetro->get_shape(curr_tetro->get_rotation()), curr_tetro->get_x()+1, curr_tetro->get_y())){
        curr_tetro->right_move();
    }
}

void Game::move_tetro_left(){
    if(!check_collision(curr_tetro->get_shape(curr_tetro->get_rotation()), curr_tetro->get_x()-1, curr_tetro->get_y())){
        curr_tetro->left_move();
    }
}

void Game::move_tetro_down(){
    if(!check_collision(curr_tetro->get_shape(curr_tetro->get_rotation()), curr_tetro->get_x(), curr_tetro->get_y()+1)){
        curr_tetro->down_move();
    }
    else{
        grid->add_grid(curr_tetro->get_shape(curr_tetro->get_rotation()), curr_tetro->get_x(), curr_tetro->get_y());
        update_score(grid->check_full_line()); //on regarde les ligne pleine, on ajuste la grille en fonction, et on ajuste le scor en foonction
        check_end();
        if(!end){
            delete curr_tetro;
            curr_tetro = next_tetro;
            get_rd_tetro();
            holded=false;
        }
    }
}

void Game::check_end(){  //le y==0 cest pour la securite car dans lordre d appelle la fct sera tjr appelle au moment du spawn donc y==0
    if((curr_tetro->get_y() == 0) && check_collision(curr_tetro->get_shape(curr_tetro->get_rotation()), curr_tetro->get_x(), curr_tetro->get_y()+1)){
        end=true;
    }
}

void Game::hard_drop(){
    while(!check_collision(curr_tetro->get_shape(curr_tetro->get_rotation()), curr_tetro->get_x(), curr_tetro->get_y()+1)){
        curr_tetro->down_move();
        score += 2;
    }
    grid->add_grid(curr_tetro->get_shape(curr_tetro->get_rotation()), curr_tetro->get_x(), curr_tetro->get_y());
    update_score(grid->check_full_line()); //on regarde les ligne pleine, on ajuste la grille en fonction, et on ajuste le scor en foonction
    check_end();
    if(!end){
        delete curr_tetro;
        curr_tetro = next_tetro;
        get_rd_tetro();
        holded = false;
    }
}

void Game::set_hold(){
    if(state!=3 && !holded){
        if(hold_tetro!=nullptr){
            Tetromino * temp = hold_tetro;
            hold_tetro = curr_tetro;
            curr_tetro = temp;
            curr_tetro->set_coord(3,0);
        }
        else{
            hold_tetro = curr_tetro;
            curr_tetro = next_tetro;
            get_rd_tetro();
        }
        holded = true;

        hold_tetro->set_rotation();
    }
}

void Game::display_score(QPainter * p, int height, int width) const{
    int x = (2*width/5)/nbc;
    int y = height/nbl;

    QColor textColor(230, 220, 200);
    p->setPen(QPen(textColor, 1));

    QRect nextTextRect((width/5) + (1*x), 0 + (((nbl/2)-10)*y), 4*x, 2*y); // x, y, largeur, hauteur
    p->drawText(nextTextRect, Qt::AlignRight | Qt::AlignVCenter, "NEXT : ");

    QRect holdTextRect((width/5) + (1*x), 0 + (((nbl/2)+4)*y), 4*x, 2*y); // x, y, largeur, hauteur
    p->drawText(holdTextRect, Qt::AlignRight | Qt::AlignVCenter, "HOLD : ");

    QRect scoreaValueRect((width/5) + (5*x), 0 + (((nbl/2)+2-4)*y), 4*x, 2*y); // x, y, largeur, hauteur
    p->drawText(scoreaValueRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(score));
    QRect scoreTextRect((width/5) + (1*x), 0 + (((nbl/2)+2-4)*y), 4*x, 2*y); // x, y, largeur, hauteur
    p->drawText(scoreTextRect, Qt::AlignRight | Qt::AlignVCenter, "SCORE : ");

    QRect levelaValueRect((width/5) + (5*x), 0 + (((nbl/2)+3-4)*y), 4*x, 2*y); // x, y, largeur, hauteur
    p->drawText(levelaValueRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(level));
    QRect levelTextRect((width/5) + (1*x), 0 + (((nbl/2)+3-4)*y), 4*x, 2*y); // x, y, largeur, hauteur
    p->drawText(levelTextRect, Qt::AlignRight | Qt::AlignVCenter, "LEVEL : ");
}

void Game::display_projection(std::array<std::array<int, 4>, 4> tetro, int x_pos, int y_pos, QPainter *p, int nbl, int nbc, int height, int width) const{
    int x = (2 * width / 5) / nbc;
    int y = height / nbl;

    while (!check_collision(tetro, x_pos, y_pos + 1)) {
        y_pos++;
    }

    QColor ghostColor(180, 180, 180, 90);

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(tetro[i][j]!=0){
                p->setPen(QPen(Qt::white, 1));
                p->drawRect((3*width/5) + ((j+x_pos)*x), 0 + ((i+y_pos)*y), x, y);
                p->fillRect(((3*width/5) + ((j+x_pos)*x))+1, (0 + ((i+y_pos)*y))+1, x-2, y-2, QBrush(ghostColor));
            }
        }
    }
}

void Game::display(QPainter * p, int height, int width) const{
    grid->display(p, height, width);
    if(state==1){
        display_projection(curr_tetro->get_shape(curr_tetro->get_rotation()), curr_tetro->get_x(), curr_tetro->get_y(), p, nbl, nbc, height, width);
    }
    curr_tetro->display(p, nbl, nbc, height, width);
    next_tetro->next_display(p, nbl, nbc, height, width);

    if(hold_tetro!=nullptr){
        hold_tetro->hold_display(p, nbl, nbc, height, width);
    }

    display_score(p, height, width);
}

void Game::reset(){
    delete curr_tetro;
    delete next_tetro;
    delete grid;

    get_rd_tetro();
    curr_tetro = next_tetro;
    get_rd_tetro();
    grid = new Grid(nbl, nbc);
    score = 0;
    level = 0;
    end = false;
}

void Game::save(std::string path, int time){
    std::ofstream f(path);

    if(!f.is_open()){
        std::cerr << "Erreur : impossible d'ouvrir le fichier save\n";
    }
    else{
        std::string temp;
        std::array<int, 8> game_data;
        if(hold_tetro==nullptr){
            game_data = {time, state, full_row, score, int(holded), curr_tetro->get_type(), next_tetro->get_type(), 0};
        }
        else{
            game_data = {time, state, full_row, score, int(holded), curr_tetro->get_type(), next_tetro->get_type(), hold_tetro->get_type()};
        }

        int i=0;

        while((f.eof() == false) && (i<8)){
            temp = std::to_string(game_data[i]);
            f << temp << ' ';
            i++;
        }
        f << std::endl;

        for(int i=0; i<nbl && !f.eof(); i++){
            for(int j=0; j<nbc && !f.eof(); j++){
                f << std::to_string(grid->get_grid(i, j)) << ' ';
            }
            f << std::endl;
        }

        f.close();
    }
}
