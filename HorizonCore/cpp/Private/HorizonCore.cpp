#include "HorizonCore.h"
#include "HorizonLog.h"
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <fstream>

#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/attributes/timer.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/record_ordering.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/locale.hpp>
//BOOST_LOG_ATTRIBUTE_KEYWORD(module, "Module", std::string)

namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;


namespace horizon{

    HorizonCore::HorizonCore(){}

    HorizonCore::~HorizonCore(){
       // boost::log::core::get()->remove_all_sinks();
    }


    HorizonCore* HorizonCore::GetInstance(){
        static HorizonCore s_instance;
        return &s_instance;
    }



    void HorizonCore::init(){
        initLog();
        HORIZON_TRACE << "HorizonCore starting...";

    }

    void HorizonCore::initLog(){
        typedef  boost::log::sinks::synchronous_sink<LogBackend> HorizonLogSink;
        boost::shared_ptr<HorizonLogSink> sink = boost::make_shared<HorizonLogSink>();
        //boost::log::add_common_attributes();
        auto logFormat = expr::format("%1%: [%2%] [%3%]: %4%")
            % expr::attr< unsigned int >("RecordID")
            % expr::attr< boost::log::trivial::severity_level >("Severity")
            % expr::attr< boost::posix_time::ptime >("TimeStamp")
            % expr::smessage;
        sink->set_formatter(logFormat);
        logging::core::get()->add_global_attribute("RecordID", attrs::counter< unsigned int >());
        logging::core::get()->add_global_attribute("TimeStamp", attrs::local_clock());



        std::locale loc = boost::locale::generator()("en_US.UTF-8");
        sink->imbue(loc);
        boost::log::core::get()->add_sink(sink);



        logging::add_file_log(
            keywords::file_name = "HorizonCore.log",
            keywords::filter = expr::attr< boost::log::trivial::severity_level >("Severity") >= boost::log::trivial::trace,
            keywords::format = (logFormat)
            );

        //logging::add_file_log
        //    (
        //    keywords::file_name = "sample_%N.log",                                        /*< file name pattern >*/
        //    keywords::rotation_size = 10 * 1024 * 1024,                                   /*< rotate files every 10 MiB... >*/
        //    keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
        //    keywords::format = "[%TimeStamp%]: %Message%"                                 /*< log record format >*/
        //    );

        //boost::log::core::get()->add_sink(fileSync);


        //logging::core::get()->set_filter
        // (
        // logging::trivial::severity >= logging::trivial::info
        // );
        //sinks::syslog::custom_severity_mapping< boost::log::trivial::severity_levels > mapping("Severity");
        // mapping[normal] = sinks::syslog::info;
        // mapping[warning] = sinks::syslog::warning;
        // mapping[error] = sinks::syslog::critical;
        //  boost::shared_ptr< std::ostream > strm(new std::ofstream("HorizonCore.log"));
        //if (!strm->good())
        //throw std::runtime_error("Failed to open a text log file");
        // Add it to the core
        //sink->locked_backend()->(strm);

        //boost::log::::add_file_log("HorizonCore.log");
    }

    void HorizonCore::flushAllLog(){
        boost::log::core::get()->flush();
    }



}//namespace horizon