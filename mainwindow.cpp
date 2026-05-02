#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    ui->pause_button->setFocusPolicy(Qt::NoFocus);
    ui->quit_button->setFocusPolicy(Qt::NoFocus);
    ui->restart_button->setFocusPolicy(Qt::NoFocus);
    ui->back_to_menu_button->setFocusPolicy(Qt::NoFocus);

    w_timer = new QTimer(this);

    connect(w_timer, &QTimer::timeout, this, &MainWindow::timerEvent);

    w_game_timer = new QTimer(this);

    connect(w_game_timer, &QTimer::timeout, this, &MainWindow::game_time_update);
    game_timer = 0;
    nb_min=0;

    game_music = new QMediaPlayer;
    game_music_audio = new QAudioOutput;
    menu_music = new QMediaPlayer;
    menu_music_audio = new QAudioOutput;

    music_play(menu_music, menu_music_audio, w_s_m_path, 0.9);

    menu_background.load("D:/IMDS/C++/PERSO/Tetris/Image/Menu_background.png");
    game_background.load("D:/IMDS/C++/PERSO/Tetris/Image/play_background.jpg");
    lose_background.load("D:/IMDS/C++/PERSO/Tetris/Image/Lose_background.jpg");

}

MainWindow::~MainWindow(){
    delete ui;
    if(w_game){
        delete w_game;
    }
    delete w_timer;
    delete w_game_timer;
    delete game_music;
    delete game_music_audio;
    delete menu_music;
    delete menu_music_audio;
}

//_______________________________________________________________________________________________

void MainWindow::showGame(){
    ui->stackedWidget->setCurrentIndex(1);
    w_timer->start(1000);
    w_game_timer->start(1000);
    this->repaint();
}

void MainWindow::showMenu(){
    ui->stackedWidget->setCurrentIndex(0);
    music_play(menu_music, menu_music_audio, w_s_m_path, 0.9);
    w_timer->stop();
    w_game_timer->stop();
    this->repaint();
}

void MainWindow::showPause(){
    ui->stackedWidget->setCurrentIndex(2);
    game_music->pause();
    w_timer->stop();
    w_game_timer->stop();
    this->repaint();
}

void MainWindow::showEnd(){
    ui->stackedWidget->setCurrentIndex(3);
    game_music->stop();
    w_timer->stop();
    w_game_timer->stop();
    this->repaint();
}

void MainWindow::showSave(){
    ui->stackedWidget->setCurrentIndex(4);
    game_music->stop();
    w_timer->stop();
    w_game_timer->stop();
    this->repaint();
}

void MainWindow::showDifficulty(){
    ui->stackedWidget->setCurrentIndex(5);
    this->repaint();
}

void MainWindow::showSettings(){
    ui->stackedWidget->setCurrentIndex(6);
    menu_music->stop();
    this->repaint();
}

//_______________________________________________________________________________________________

void MainWindow::on_play_button_clicked(){
    showDifficulty();
}

void MainWindow::on_quit_button_clicked(){
    showSave();
}

void MainWindow::on_pause_button_clicked(){
    showPause();
}

void MainWindow::on_get_back_button_clicked(){
    game_music->play();
    showGame();
}

void MainWindow::on_back_to_menu_button_clicked(){
    showSave();
}

void MainWindow::on_restart_button_clicked(){
    delete w_game;
    w_game = new Game(22, 10);
    music_play(game_music, game_music_audio, w_s_path, 0.3);
    game_timer=0;
    nb_min=0;
    showGame();
}

void MainWindow::on_back_to_menu_end_button_clicked(){
    showMenu();
    delete w_game;
    w_game = nullptr;
    game_timer=0;
    nb_min=0;
}

void MainWindow::on_no_button_clicked(){
    showMenu();
    delete w_game;
    w_game = nullptr;
    game_timer=0;
    nb_min=0;
}

void MainWindow::on_yes_button_clicked(){
    showMenu();
    w_game->save(w_path, game_timer);
    delete w_game;
    w_game = nullptr;
    game_timer=0;
    nb_min=0;
}

void MainWindow::on_continue_button_clicked(){
    std::ifstream f(w_path);

    if(!f.is_open()){
        std::cerr << "Erreur : impossible d'ouvrir le fichier save\n";
    }
    else{
        std::string temp;
        int i=0;

        while((f.eof() == false) && (i<8)){
            f >> temp;
            w_game_data[i] = stoi(temp);
            i++;
        }

        for(int j=0; j<22 && !f.eof(); j++){
            for(int k=0; k<10 && !f.eof(); k++){
                f >> temp;
                w_grid_data[j][k] = stoi(temp);
            }
        }

        f.close();
    }
    game_timer = w_game_data[0];
    nb_min = game_timer/60;
    w_game = new Game(22, 10, w_game_data[1], w_game_data[2], w_game_data[3], w_game_data[4], w_game_data[5], w_game_data[6], w_game_data[7], w_grid_data);
    menu_music->stop();
    music_play(game_music, game_music_audio, w_s_path, 0.3);
    showGame();
}

void MainWindow::on_easy_button_clicked()
{
    w_game = new Game(22, 10, 1, 0, 0, 0, 0, 0, 0);
    menu_music->stop();
    music_play(game_music, game_music_audio, w_s_path, 0.3);
    showGame();
}

void MainWindow::on_medium_button_clicked()
{
    w_game = new Game(22, 10, 2, 0, 0, 0, 0, 0, 0);
    menu_music->stop();
    music_play(game_music, game_music_audio, w_s_path, 0.3);
    showGame();
}

void MainWindow::on_hard_button_clicked()
{
    w_game = new Game(22, 10, 3, 0, 0, 0, 0, 0, 0);
    menu_music->stop();
    music_play(game_music, game_music_audio, w_s_path, 0.3);
    showGame();
}

void MainWindow::on_settings_button_clicked()
{
    showSettings();
}

void MainWindow::on_menu_button_clicked()
{
    showMenu();
}

//_______________________________________________________________________________________________

void MainWindow::music_play(QMediaPlayer* music, QAudioOutput* audio, QUrl path, float volume){
    music->setAudioOutput(audio);
    music->setSource(path);
    music->setLoops(QMediaPlayer::Infinite);
    audio->setVolume(volume);

    music->play();
}

void MainWindow::save_text_display(QPainter* p, int height, int width) const{
    int nbl = 22;
    int nbc = 10;
    int x = (2*width/5)/nbc;
    int y = height/nbl;

    QColor textColor(230, 220, 200);
    p->setPen(QPen(textColor, 1) );
    p->setFont(QFont("Arial",12));

    QRect saveTextRect((width/2) - 2*x, 0 + 4*y, 8*x, 2*y); // x, y, largeur, hauteur
    p->drawText(saveTextRect, Qt::AlignCenter | Qt::AlignCenter, "VOULEZ VOUS SAUVEGARDER ?");
}

void MainWindow::game_time_display(QPainter* p, int height, int width) const{
    int nbl = 22;
    int nbc = 10;
    int x = (2*width/5)/nbc;
    int y = height/nbl;

    QColor textColor(230, 220, 200);
    p->setPen(QPen(textColor, 1) );
    p->setFont(QFont("Arial",10));

    //gestion des minutes
    QRect timeMinValueRect((width/5) + (5*x), 0 + (((nbl/2)+2-6)*y), 4*x, 2*y);
    p->drawText(timeMinValueRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(nb_min));

    QRect timeMinTextRect((width/5) + (5*x) +5, 0 + (((nbl/2)+2-6)*y), 4*x, 2*y);
    p->drawText(timeMinTextRect, Qt::AlignLeft | Qt::AlignVCenter, " min ");

    QRect timeSecValueRect((width/5) + (6*x) , 0 + (((nbl/2)+2-6)*y), 4*x, 2*y);
    p->drawText(timeSecValueRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(game_timer - nb_min*60));

    QRect timeSecTextRect((width/5) + (6*x) +10, 0 + (((nbl/2)+2-6)*y), 4*x, 2*y);
    p->drawText(timeSecTextRect, Qt::AlignLeft | Qt::AlignVCenter, " s ");

    QRect timeTextRect((width/5) + (1*x), 0 + (((nbl/2)+2-6)*y), 4*x, 2*y);
    p->drawText(timeTextRect, Qt::AlignRight | Qt::AlignVCenter, "TIME : ");
}

void MainWindow::game_time_update(){
    game_timer++;
    nb_min = game_timer/60;

    this->repaint();
}

void MainWindow::paintEvent(QPaintEvent* e){   //affiche a l'ecran tt les choses a afficher
    QWidget::paintEvent(e);
    QPainter painter(this);

    QColor backgroundColor(30, 22, 14);


    if(ui->stackedWidget->currentIndex()==0){
        painter.setOpacity(0.8);
        painter.drawPixmap(rect(), menu_background);
    }
    else if(ui->stackedWidget->currentIndex()==1){
        painter.drawPixmap(rect(), game_background);
        w_game->display(&painter, height(), width());
        game_time_display(&painter, height(), width());
    }
    else if(ui->stackedWidget->currentIndex()==2){
        w_game->display(&painter, height(), width());
        game_time_display(&painter, height(), width());
        painter.drawPixmap(rect(), game_background);
    }
    else if(ui->stackedWidget->currentIndex()==3){
        w_game->display(&painter, height(), width());
        game_time_display(&painter, height(), width());
        painter.drawPixmap(rect(), lose_background);
    }
    else if(ui->stackedWidget->currentIndex()==4){
        painter.drawPixmap(rect(), game_background);
        w_game->display(&painter, height(), width());
        game_time_display(&painter, height(), width());
        save_text_display(&painter, height(), width());
    }
    else if(ui->stackedWidget->currentIndex()==5){
        painter.setOpacity(0.4);
        painter.drawPixmap(rect(), menu_background);
    }
    else if(ui->stackedWidget->currentIndex()==6){
        painter.drawPixmap(rect(), game_background);
        settings_display(&painter, height(), width());
    }
}

void MainWindow::keyPressEvent(QKeyEvent * event){   //event loop, cest un peu la boucle du jeu, on detecte les touche utiliser par le joueur afin deffectuer les action quil souhaite realiser
    if(w_game && !w_game->get_end())
    {
        if(ui->stackedWidget->currentIndex()==1){
            switch (event->key()){
                case Qt::Key_Up : w_game->rotate_tetro_right();
                    break;
                case Qt::Key_Down : w_game->move_tetro_down();
                    if(w_game->get_end()){
                        showEnd();
                    }
                    else{
                        w_game->softdrop_scoring();
                    }
                    break;
                case Qt::Key_Left : w_game->move_tetro_left();
                    break;
                case Qt::Key_Right : w_game->move_tetro_right();
                    break;
                case Qt::Key_Space : w_game->hard_drop();
                    if(w_game->get_end()){
                        showEnd();
                    }
                    break;
                case Qt::Key_Return : w_game->set_hold();
                    break;
                default:
                    break;
            }
        }
        this->repaint();
    }
}

void MainWindow::mousePressEvent(QMouseEvent* event){
    if(ui->stackedWidget->currentIndex()==1){
        if (event->button() == Qt::LeftButton){
            w_game->rotate_tetro_left();
        }
        else if(event->button() == Qt::RightButton){
            w_game->rotate_tetro_right();
        }
    }
    this->repaint();
}

void MainWindow::timerEvent(){
    if(w_game && !w_game->get_end())
    {
        int level = w_game->get_level();
        if(level<10){
            if(w_game->get_state()==3){
                if(level<5){
                    w_timer->start(500 - level*100);
                }
            }
            else{
                w_timer->start(1000 - level*100);
            }
        }
        w_game->move_tetro_down();
        if(w_game->get_end()){
            showEnd();
        }
        this->repaint();
    }
}

void MainWindow::settings_display(QPainter* p, int height, int width) const{
    QColor textColor(230, 220, 200);
    p->setPen(QPen(textColor, 1) );
    p->setFont(QFont("Terminal",30));

    QRect timeTextRect(width/7, 0, width/2, height/4);
    p->drawText(timeTextRect, Qt::AlignRight | Qt::AlignVCenter, "Regles du jeu : ");

    p->setFont(QFont("Arial",11));
    QRect describTextRect(width/4, height/7, (4*width)/5, (3*height)/4);
    p->drawText(describTextRect, Qt::AlignLeft | Qt::AlignTop,  "\n"
                                                                "Le jeu est compose de 7 pieces (tetrominos) ayant chacune une forme,\n"
                                                                "couleur et rotation unique.\n"
                                                                "Vous pouvez déplacer les pieces à l'aide des fleches directionnelles de\n"
                                                                "votre clavier :\n"
                                                                "fleche de droite : correspond au deplacement vers la droite\n"
                                                                "fleche de gauche : correspond au deplacement vers la gauche\n"
                                                                "fleche du bas : correspond au soft drop, la pièce descend plus vite\n"
                                                                "fleche du haut : correspond à la rotation de la piece.\n "
                                                                "Egalement, vous pouvez utiliser la touche espace de votre clavier pour\n"
                                                                "lacher la piece (hard drop).\n"
                                                                "\n"
                                                                "Concernant le score, selon le nombre de ligne complete simultanement le\n"
                                                                "nombre de point attribue n'est pas le meme.\n"
                                                                "1 ligne ----> 40,  2 lignes ---> 100,  3 lignes ---> 300,  4 lignes ---> 1200\n"
                                                                "Et ces points augmenteront proportionnellement au niveau.\n"
                                                                "Chaque pallier de niveau se débloque lorsque vous completez 10 lignes.\n"
                                                                "\n"
                                                                "Depuis le menu, en appuyant sur le bouton play, vous pourrez selectionner\n"
                                                                "la difficulte du jeu :\n"
                                                                "Easy : Visualisation de l'ombre du tetromino courant + possibilite de\n"
                                                                "garder (hold) le tetromino\n"
                                                                "Medium : Pas de vision de l'ombre + possibilite de garder (hold) le tetromino\n"
                                                                "Hard : Jeu plus rapide + impossibilite de garder une piece et de voir l'ombre\n"
                                                                "\n"
                                                                "Il est egalement possible de sauvegarder la partie en cours, pour cela il faudra\n"
                                                                "quitter la partie et alors il vous sera possible de sauvegarder.\n"
                                                                "Et depuis le menu vous pourrez reprendre votre sauvegarde.\n"
                                                                "\n"
                                                                "Bon jeu !!!");
}


