#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QSlider>
#include <QLabel>

/*! \class MainWindow class
   \brief MainWindow creates the GUI
*/
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;
    QListWidget* listWidget;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QPushButton *pbReadTrack;
    QPushButton *pbStartSampling;
    QPushButton *pbStopSampling;
    QSlider *thresSlider;
    QLabel *thresLabel;

    void setDisplayText(const QString s);

private slots:
    void on_pbReadTrack_clicked();
    void on_pbStartSampling_clicked();
    void on_pbStopSampling_clicked();
    void on_thresSlider_released();
};

#endif // MAINWINDOW_H
