#include <boost/log/trivial.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/setup.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/expressions/keyword.hpp>

#ifndef _HORIZON_HORIZON_LOG_H_
#define _HORIZON_HORIZON_LOG_H_
namespace horizon{

#define HORIZON_LOG_FUNCTION "  [" <<  __FILE__ << "(" << __LINE__ << ")" << ": " <<  __FUNCTION__ << "]  "

#define HORIZON_TRACE     BOOST_LOG_TRIVIAL(trace) << HORIZON_LOG_FUNCTION
#define HORIZON_DEBUG     BOOST_LOG_TRIVIAL(debug) << HORIZON_LOG_FUNCTION
#define HORIZON_INFO      BOOST_LOG_TRIVIAL(info) << HORIZON_LOG_FUNCTION
#define HORIZON_WARNING   BOOST_LOG_TRIVIAL(warning) << HORIZON_LOG_FUNCTION
#define HORIZON_ERROR     BOOST_LOG_TRIVIAL(error) << HORIZON_LOG_FUNCTION
#define HORIZON_FATAL     BOOST_LOG_TRIVIAL(fatal) << HORIZON_LOG_FUNCTION


//#define HORIZON_TRACE_ASYNC     BOOST_LOG_TRIVIAL(trace) << HORIZON_LOG_FUNCTION
//#define HORIZON_DEBUG_ASYNC     BOOST_LOG_TRIVIAL(debug) << HORIZON_LOG_FUNCTION
//#define HORIZON_INFO_ASYNC      BOOST_LOG_TRIVIAL(info) << HORIZON_LOG_FUNCTION
//#define HORIZON_WARNING_ASYNC   BOOST_LOG_TRIVIAL(warning) << HORIZON_LOG_FUNCTION
//#define HORIZON_ERROR_ASYNC     BOOST_LOG_TRIVIAL(error) << HORIZON_LOG_FUNCTION
//#define HORIZON_FATAL_ASYNC     BOOST_LOG_TRIVIAL(fatal) << HORIZON_LOG_FUNCTION



    class LogBackend : public boost::log::sinks::basic_formatted_sink_backend < char > {
    public:
        virtual void consume(const boost::log::record_view& rec, string_type const& logMessage);
    private:
        void consumeImplement(const std::string& msg);

    };
   
  
    

} //namespace horizon



#endif //_HORIZON_HORIZON_LOG_H_