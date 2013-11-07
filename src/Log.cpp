#include "Log.hpp"

#include <string>
#include <iostream>

Log *Log::logger;

Log::Log() {}
Log::~Log() {}

void Log::format(int level, std::string prefix, std::string msg) {
    if (level > this->filter_to) {
	std::cout << "[" << prefix << "] " << msg << std::endl;
    }
}

Log *Log::Get() {
    if (!logger) {
	logger = new Log();
    }

    return logger;
}

void Log::Debug(std::string msg) {
    format(LV_DEBUG, MSG_DEBUG, msg);
}

void Log::Info(std::string msg) {
    format(LV_INFO, MSG_INFO, msg);
}

void Log::Warn(std::string msg) {
    format(LV_WARN, MSG_WARN, msg);
}

void Log::Error(std::string msg) {
    format(LV_ERROR, MSG_ERROR, msg);
}

void Log::Fatal(std::string msg) {
    format(LV_FATAL, MSG_FATAL, msg);
}

void Log::WTF(std::string msg) {
    format(LV_WTF, MSG_WTF, msg);
}

void Log::Filter(int level) {
    this->filter_to = level;
}
