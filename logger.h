#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#ifndef ELPP_NO_DEFAULT_LOG_FILE
#    define ELPP_NO_DEFAULT_LOG_FILE
#endif

#ifndef ELPP_STL_LOGGING
#    define ELPP_STL_LOGGING
#endif

#include <iostream>
#include "easylogging++.h"

/**
 * Loggerclass which wraps easylogging++ framework into a singleton.
 * Please make sure you define 'INITIALIZE_EASYLOGGINGPP' above your main,
 * right below the includes. This ensures the framework is initialized only once.
 */
class Logger {
 private:
    Logger() {
        el::Configurations conf("C:/Users/Matthijs/Desktop/Embedded-Vision-Project/logging.conf");
        el::Loggers::reconfigureAllLoggers(conf);
    }

    Logger(Logger const& copy);

    Logger& operator=(Logger const& copy);

    el::Logger* logger = el::Loggers::getLogger("default");

    /**
     * Ensure only one single instance of Logger is created. (Singleton Pattern)
     */
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }


 public:
    /**
     * @return Returns logger instance of easylogging framework.
     */
    static el::Logger*& log() {
        return getInstance().logger;
    }

};

#endif /* LOGGER_HPP_ */
