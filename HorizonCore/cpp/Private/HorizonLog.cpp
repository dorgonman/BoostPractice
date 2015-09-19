#include "HorizonLog.h"
#include<Windows.h> 
#include <tchar.h> 
#define MAX_LEN 256
//BOOST_LOG_ATTRIBUTE_KEYWORD(module, "Module", std::string)
/*typedef enum android_LogPriority {
    ANDROID_LOG_UNKNOWN = 0,
    ANDROID_LOG_DEFAULT,
    ANDROID_LOG_VERBOSE, //HORIZON_TRACE
    ANDROID_LOG_DEBUG,  //HORIZON_DEBUG
    ANDROID_LOG_INFO,   //HORIZON_INFO
    ANDROID_LOG_WARN,   //HORIZON_WARNING
    ANDROID_LOG_ERROR,  //HORIZON_ERROR
    ANDROID_LOG_FATAL,  //HORIZON_FATAL
    ANDROID_LOG_SILENT,
} android_LogPriority;*/
/*#define HORIZON_TRACE     BOOST_LOG_TRIVIAL(trace) << HORIZON_LOG_FUNCTION
#define HORIZON_DEBUG     BOOST_LOG_TRIVIAL(debug) << HORIZON_LOG_FUNCTION
#define HORIZON_INFO      BOOST_LOG_TRIVIAL(info) << HORIZON_LOG_FUNCTION
#define HORIZON_WARNING   BOOST_LOG_TRIVIAL(warning) << HORIZON_LOG_FUNCTION
#define HORIZON_ERROR     BOOST_LOG_TRIVIAL(error) << HORIZON_LOG_FUNCTION
#define HORIZON_FATAL     BOOST_LOG_TRIVIAL(fatal) << HORIZON_LOG_FUNCTION*/
namespace horizon{
#if defined(_WIN32) || defined(WIN32)     /* _Win32 is usually defined by compilers targeting 32 or   64 bit Windows systems */
    void LogBackend::consumeImplement(const std::string& msg){
  

        WCHAR wszBuf[MAX_LEN] = { 0 };
        MultiByteToWideChar(CP_UTF8, 0, msg.c_str(), -1, wszBuf, sizeof(wszBuf));
        OutputDebugStringW(wszBuf);
        OutputDebugStringA("\n");
    
    }
#endif

    void LogBackend::consume(const boost::log::record_view& rec, string_type const& logMessage){

        std::string msg = logMessage;
        auto values = rec.attribute_values();
        //rec.attribute_values().
        for (auto value : values){
            value.first;
            value.second;
        }
        //basic_formatted_sink_backend::consume(rec, command_line);
       // const char* log_msg = rec[boost::log::expressions::smessage].get().c_str();
        consumeImplement(msg);
       // std::cout << command_line << std::endl;
        //android_LogPriority log_sev = rec[severity].get();
        //const char* log_msg = rec[expr::smessage].get().c_str();
        //const char* log_module = "unknown";
        // forward to actual logging function
        // fake__android_log_print(log_sev, log_module, log_msg);
    }


}//namespace horizon