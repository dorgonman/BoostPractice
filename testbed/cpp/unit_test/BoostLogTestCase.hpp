#ifndef BOOST_TEST_MODULE
#define BOOST_TEST_MODULE BoostLogTestCase
#endif

#include <iostream>

#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>

#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include <boost/log/attributes/timer.hpp>
#include <boost/log/attributes/named_scope.hpp>

#include <boost/log/sources/logger.hpp>

#include <boost/log/support/date_time.hpp>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include <boost/ref.hpp>
#include <boost/bind.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/barrier.hpp>

#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/record_ordering.hpp>

namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;

// Here we define our application severity levels.
/*enum severity_level
{
    normal,
    notification,
    warning,
    error,
    critical
};*/

// The formatting logic for the severity level
/*template< typename CharT, typename TraitsT >
inline std::basic_ostream< CharT, TraitsT >& operator<< (
    std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl)
{
    static const char* const str[] =
    {
        "normal",
        "notification",
        "warning",
        "error",
        "critical"
    };
    if (static_cast< std::size_t >(lvl) < (sizeof(str) / sizeof(*str)))
        strm << str[lvl];
    else
        strm << static_cast< int >(lvl);
    return strm;
}*/
 

//#define BOOST_LOG_TRIVIAL(log) 
BOOST_AUTO_TEST_SUITE(BoostLogTestCaseSuit)



void test1(){
    src::severity_logger< boost::log::trivial::severity_level > slg2;
    BOOST_LOG_FUNCTION();
    BOOST_LOG_SEV(slg2, boost::log::trivial::severity_level::error) << "test1";
}

void start(){
   

    BOOST_LOG_FUNCTION();

    // Now our logs will be written both to the console and to the file.
    // Let's do a quick test and output something. We have to create a logger for this.
    //boost::log::sources::logger lg;
    boost::log::sources::logger_mt t;
    auto lg = boost::log::trivial::logger::get();
    lg.add_attribute("Uptime", attrs::timer());
 
    // And output...
    BOOST_LOG_TRIVIAL(info) << "Hello, World!"  << 1 << "test"; 
    BOOST_LOG_TRIVIAL(error) << "==hello2=="; 
    // Now, let's try logging with severity
    boost::log::sources::severity_logger< boost::log::trivial::severity_level > slg;

    // Let's pretend we also want to profile our code, so add a special timer attribute.
    slg.add_attribute("Uptime", attrs::timer());

    BOOST_LOG_SEV(slg, boost::log::trivial::severity_level::info) << "A normal severity message, will not pass to the file";
    BOOST_LOG_SEV(slg, boost::log::trivial::severity_level::warning) << "A warning severity message, will pass to the file";

    BOOST_LOG_SEV(slg, boost::log::trivial::severity_level::error) << "An error severity message, will pass to the file";
    test1();
}

void setupDefault(){
    // This is a simple tutorial/example of Boost.Log usage

    // The first thing we have to do to get using the library is
    // to set up the logging sinks - i.e. where the logs will be written to.
    logging::add_console_log(std::clog, keywords::format = "%TimeStamp%: %Message%");

    // One can also use lambda expressions to setup filters and formatters
    logging::add_file_log
        (
        "sample.log",
        keywords::filter = expr::attr< boost::log::trivial::severity_level >("Severity") >= boost::log::trivial::warning,
        keywords::format = expr::stream
        << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
        << " [" << expr::format_date_time< attrs::timer::value_type >("Uptime", "%O:%M:%S")
        << "] [" << expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
        << "] <" << expr::attr< boost::log::trivial::severity_level >("Severity")
        << "> " << expr::message
        );

    // Also let's add some commonly used attributes, like timestamp and record counter.
    //logging::add_common_attributes();
    logging::core::get()->add_thread_attribute("Scope", attrs::named_scope());
}




// The test checks construction and assignment
BOOST_AUTO_TEST_CASE(BasicUsage)
{
    setupDefault();
    //logging::core::get()->remove_all_sinks();  
    // Open a rotating text file
    boost::shared_ptr< std::ostream > strm(new std::ofstream("test.log"));
    if (!strm->good())
        throw std::runtime_error("Failed to open a text log file");

    // Create a text file sink
    typedef sinks::text_ostream_backend backend_t;
    typedef sinks::asynchronous_sink<
        backend_t,
        sinks::unbounded_ordering_queue<
        logging::attribute_value_ordering< unsigned int, std::less< unsigned int > >
        >
    > sink_t;
    boost::shared_ptr< sink_t > sink(new sink_t(
        boost::make_shared< backend_t >(),
        // We'll apply record ordering to ensure that records from different threads go sequentially in the file
        keywords::order = logging::make_attr_ordering("RecordID", std::less< unsigned int >())));

    sink->locked_backend()->add_stream(strm);

    sink->set_formatter
        (
        expr::format("%1%: [%2%] [%3%] - %4%")
        % expr::attr< unsigned int >("RecordID")
        % expr::attr< boost::posix_time::ptime >("TimeStamp")
        % expr::attr< boost::thread::id >("ThreadID")
        % expr::smessage
        );

    // Add it to the core
    logging::core::get()->add_sink(sink);

    // Add some attributes too
    logging::core::get()->add_global_attribute("TimeStamp", attrs::local_clock());
    logging::core::get()->add_global_attribute("RecordID", attrs::counter< unsigned int >());
    start();

    // Flush all buffered records
    sink->stop();
    sink->flush();
}




BOOST_AUTO_TEST_CASE(TrivialUsage)
{
    // Trivial logging: all log records are written into a file
    BOOST_LOG_TRIVIAL(trace) << "TrivialUsage A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "TrivialUsage A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "TrivialUsage An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

    // Filtering can also be applied
    using namespace boost::log;

    core::get()->set_filter
        (
        trivial::severity >= trivial::info
        );

    // Now the first two lines will not pass the filter
    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
}
BOOST_AUTO_TEST_SUITE_END()