#ifndef _LOG_H_
#define _LOG_H_

#include <string>
#include <map>

#define LV_ALL -1
#define LV_DEBUG 0
#define LV_INFO 1
#define LV_WARN 2
#define LV_ERROR 3
#define LV_FATAL 4
#define LV_WTF 5

#define LV_DEFAULT 1

#define MSG_DEBUG "DEBUG"
#define MSG_INFO "INFO"
#define MSG_WARN "WARN"
#define MSG_ERROR "ERROR"
#define MSG_FATAL "FATAL"
#define MSG_WTF "WTF"

/** \brief brief
 *
 * detailed
 */
class Log
{
public:
    Log();
    virtual ~Log();

    void Debug(std::string msg);
    void Info(std::string msg);
    void Warn(std::string msg);
    void Error(std::string msg);
    void Fatal(std::string msg);
    void WTF(std::string msg);

    void Filter(int level);

    static Log *Get();

private:
    void format(int level, std::string prefix, std::string msg);
    int filter_to;
    static Log *logger;
};

#endif /* _LOG_H_ */
