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
    void LogBackend::logMessage(const boost::log::record_view& rec, const std::string& msg){
        //std::cout << msg;
        if (msg.size() > HORIZON_LOG_MAX_LEN){
            logMessageImplement(msg.substr(0, HORIZON_LOG_MAX_LEN-1));
            logMessage(rec, msg.substr(HORIZON_LOG_MAX_LEN - 1, msg.size()));
           
        }
        else{
            logMessageImplement(msg);
            logMessageImplement("\n");
        }
    }
    void LogBackend::consume(const boost::log::record_view& rec, string_type const& msg){

        const std::string msgStr = msg;
        logMessage(rec, msgStr);


        //boost::log::core::get()->flush();
        //auto values = rec.attribute_values();
        //rec.attribute_values().
        //for (auto value : values){
            //std::cout << value.first;
            //value.second.extract();
            //auto aaa = value.second;
            //std::cout << value.second.extract_or_default();     
        //}
       // using boost::log::trivial::severity_level;
       // auto severity = rec.attribute_values()[boost::log::aux::default_attribute_names::severity()].extract<severity_level>();
       // boost::log::v2s_mt_nt5::trivial::severity_level lv = severity.get();
       // const char* str = boost::log::trivial::to_string(lv);
        //if (!severity || severity.get() <= severity_level::info) {
       //  std::cout << "currentLogLevel: " << str << std::endl;
        //basic_formatted_sink_backend::consume(rec, command_line);
       // const char* log_msg = rec[boost::log::expressions::smessage].get().c_str();   
       // std::cout << command_line << std::endl;
        //android_LogPriority log_sev = rec[severity].get();
        //const char* log_msg = rec[expr::smessage].get().c_str();
        //const char* log_module = "unknown";
        // forward to actual logging function
        // fake__android_log_print(log_sev, log_module, log_msg);
    }


}//namespace horizon