#ifndef LOGGER_H
#define LOGGER_H

#include "mainwindow.h"
#include <QString>

class Logger
{
private:
    MainWindow mainwindow;

public:
    Logger();
    void setLogProgram(const QString s);
    void setLogFile(const QString s);

protected:
};

#endif // LOGGER_H
