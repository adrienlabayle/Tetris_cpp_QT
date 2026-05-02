#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QPixmap>
#include <QResizeEvent>

#include <fstream>

#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        void showGame();
        void showMenu();
        void showPause();
        void showEnd();
        void showSave();
        void showDifficulty();
        void showSettings();
        void music_play(QMediaPlayer* music, QAudioOutput* audio, QUrl path, float volume);
        void save_text_display(QPainter* p, int height, int width) const;
        void game_time_display(QPainter* p, int height, int width) const;
        void game_time_update();
        void paintEvent(QPaintEvent* e);
        void keyPressEvent(QKeyEvent * event);
        void mousePressEvent(QMouseEvent* event);
        void timerEvent();
        void settings_display(QPainter* p, int height, int width) const;


    private slots:
        void on_play_button_clicked();
        void on_quit_button_clicked();
        void on_pause_button_clicked();
        void on_get_back_button_clicked();
        void on_back_to_menu_button_clicked();
        void on_restart_button_clicked();
        void on_back_to_menu_end_button_clicked();
        void on_no_button_clicked();
        void on_yes_button_clicked();
        void on_continue_button_clicked();
        void on_easy_button_clicked();
        void on_medium_button_clicked();
        void on_hard_button_clicked();
        void on_settings_button_clicked();
        void on_menu_button_clicked();

    private:
        Ui::MainWindow *ui;
        Game* w_game=nullptr;
        QTimer* w_timer;
        QTimer* w_game_timer;
        int game_timer=0;
        int nb_min=0;
        std::string w_path=std::string("D:/IMDS/C++/PERSO/Tetris/Save/save.txt");
        QUrl w_s_path = QUrl(QString::fromStdString(std::string("D:/IMDS/C++/PERSO/Tetris/Sound/Tetris_theme.m4a")));
        QUrl w_s_m_path = QUrl(QString::fromStdString(std::string("D:/IMDS/C++/PERSO/Tetris/Sound/Menu_theme.mp3")));
        QMediaPlayer* menu_music;
        QAudioOutput* menu_music_audio;
        QMediaPlayer* game_music;
        QAudioOutput* game_music_audio;
        QPixmap menu_background;
        QPixmap game_background;
        QPixmap lose_background;
        int w_game_data[8]={}; //={} permet de tt remplir de 0
        std::array<std::array<int, 10>, 22> w_grid_data={};
};

#endif // MAINWINDOW_H
