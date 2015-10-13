#include "mainwindow.h"
#include "ui_mainwindow.h"

/** Constructor of MainWindow
 *  \brief Creates main window with object.
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /// Creates listwidget to print information. Left upper point on coordinates (25,25), size 250x250.
    listWidget = new QListWidget(this);
    listWidget->setGeometry(QRect(QPoint(25, 25), QSize(250, 250)));

    /// Creates pushbutton on coordiantes (25,300), size 100x25.
    pbReadTrack = new QPushButton("Determine track", this);
    pbReadTrack->setGeometry(QRect(QPoint(25, 300), QSize(100, 25)));
    pbReadTrack->setEnabled(true);

    pbStartSampling = new QPushButton("Start sampling", this);
    pbStartSampling->setGeometry(QRect(QPoint(25, 350), QSize(100, 25)));
    pbStartSampling->setEnabled(false);

    pbStopSampling = new QPushButton("Stop sampling", this);
    pbStopSampling->setGeometry(QRect(QPoint(175, 350), QSize(100, 25)));
    pbStopSampling->setEnabled(false);

    /// Creates threshold slider and label
    thresSlider = new QSlider(this);
    thresSlider->setGeometry(QRect(QPoint(300, 25), QSize(25, 250)));
    thresSlider->setMinimum(0);
    thresSlider->setMaximum(255);

    thresLabel = new QLabel(this);
    thresLabel->setText("Threshold");
    thresLabel->setGeometry(QRect(QPoint(275, 0), QSize(75, 25)));

    /// Connect the functionalty of a object to a member function from this class.
    connect(pbReadTrack, SIGNAL(clicked(bool)), this, SLOT(on_pbReadTrack_clicked()));
    connect(pbStartSampling, SIGNAL(clicked(bool)), this, SLOT(on_pbStartSampling_clicked()));
    connect(pbStopSampling, SIGNAL(clicked(bool)), this, SLOT(on_pbStopSampling_clicked()));
    connect(thresSlider, SIGNAL(valueChanged(int)), this, SLOT(on_thresSlider_released()));
}


/** Destructor of MainWindow
 *  \brief Destruct object of class MainWindow.
 */
MainWindow::~MainWindow()
{
    /// Deletes allocated memory
    delete pbReadTrack;
    delete pbStartSampling;
    delete pbStopSampling;
}

/** on_pbStartSampling_clicked()
 *  \brief This function is called when pushbutton Start sampling is clicked.
 */
void MainWindow::on_pbReadTrack_clicked()
{
    pbStartSampling->setEnabled(true);
    pbStopSampling->setEnabled(false);
    pbReadTrack->setEnabled(true);
    //logDebug("Determine track button pressed");
}

/** on_pbStartSampling_clicked()
 *  \brief This function is called when pushbutton Start sampling is clicked.
 */
void MainWindow::on_pbStartSampling_clicked()
{
    pbStopSampling->setEnabled(true);
    pbStartSampling->setEnabled(false);
    pbReadTrack->setEnabled(false);
    //logDebug("Start sampling button pressed");
}

/** on_pbStopSampling_clicked()
 *  \brief This function is called when pushbutton Stop sampling is clicked.
 */
void MainWindow::on_pbStopSampling_clicked()
{
    pbReadTrack->setEnabled(true);
    pbStartSampling->setEnabled(true);
    pbStopSampling->setEnabled(false);
    //logDebug("Stop sampling button pressed");
}

/** on_thresSlider_released()
 *  \brief This function is called when threshold slider is released.
 */
void MainWindow::on_thresSlider_released()
{
    QString s;
    s.push_back("Threshold value: ");
    s.push_back(QString::number(thresSlider->value()));
    setDisplayText(s);
}

/** logDebug(const QString s)
 *  \brief This function is called from object handler to get debug information to the listwidget.
 */
void MainWindow::setDisplayText(const QString s)
{
    listWidget->addItem(s);
    listWidget->scrollToBottom();
}
