#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>

//!  MainWindow class.
/*!
  MainWindow creates the GUI
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

    QPushButton* pbStartSampling;
    QPushButton* pbStopSampling;

    void setDisplayText(const QString s);

private slots:
    void on_pbStartSampling_clicked();
    void on_pbStopSampling_clicked();
};

#endif // MAINWINDOW_H
