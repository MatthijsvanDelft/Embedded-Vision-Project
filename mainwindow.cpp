#include "mainwindow.h"
#include "ui_mainwindow.h"

/** Constructor of MainWindow
 *  Creates main window with object
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ///Creates listwidget to print information. Left upper point on coordinates (25,25), size 250x250.
    listWidget = new QListWidget(this);
    listWidget->setGeometry(QRect(QPoint(25, 25),QSize(250, 250)));


    ///Creates pushbutton on coordiantes (25,300), size 100x25.
    pbStartSampling = new QPushButton("Start sampling", this);
    pbStartSampling->setGeometry(QRect(QPoint(25, 300),QSize(100, 25)));

    pbStopSampling = new QPushButton("Stop sampling", this);
    pbStopSampling->setGeometry(QRect(QPoint(175, 300),QSize(100, 25)));

    /** Connect signal and slot
     *  Connect the functionalty of a pushbutton to a member function from this class.
     *  So if pbStartSampling is clicked, call from this class member function on_pbStartSampling_clicked();
     */
    connect(pbStartSampling, SIGNAL(clicked(bool)), this, SLOT(on_pbStartSampling_clicked()));
    connect(pbStopSampling, SIGNAL(clicked(bool)), this, SLOT(on_pbStopSampling_clicked()));
}


/** Destructor of MainWindow
 *
 */
MainWindow::~MainWindow()
{

}

/** on_pbStartSampling_clicked()
 *  This function is called when pushbutton Start sampling is clicked
 *  Makes pushbutton Start sampling unclickable and Stop sampling clickable
 */
void MainWindow::on_pbStartSampling_clicked()
{
    pbStartSampling->setEnabled(false);
    pbStopSampling->setEnabled(true);
    //logDebug("Start sampling button pressed");
}

/** on_pbStopSampling_clicked()
 *  This function is called when pushbutton Stop sampling is clicked
 *  Makes pushbutton Start sampling clickable and Stop sampling unclickable
 */
void MainWindow::on_pbStopSampling_clicked()
{
    pbStartSampling->setEnabled(true);
    pbStopSampling->setEnabled(false);
    //logDebug("Stop sampling button pressed");
}

/** logDebug(const QString s)
 *  This function is called from object handler to get debug information to the listwidget
 *  Add information to listwidget and scroll down
 */
void MainWindow::setDisplayText(const QString s)
{
    listWidget->addItem(s);
    listWidget->scrollToBottom();
}
