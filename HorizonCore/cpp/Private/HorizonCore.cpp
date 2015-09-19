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

//BOOST_LOG_ATTRIBUTE_KEYWORD(module, "Module", std::string)

namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;


namespace horizon{

    HorizonCore::HorizonCore(){
        typedef  boost::log::sinks::synchronous_sink<LogBackend> HorizonLogSink;
        boost::shared_ptr<HorizonLogSink> sink = boost::make_shared<HorizonLogSink>();
        //boost::log::add_common_attributes();
        sink->set_formatter
            (
            expr::format("%1%: [%2%] [%3%]: %4%")
            % expr::attr< unsigned int >("RecordID")
            % expr::attr< boost::log::trivial::severity_level >("Severity")
            % expr::attr< boost::posix_time::ptime >("TimeStamp")
            % expr::smessage
            );
        logging::core::get()->add_global_attribute("RecordID", attrs::counter< unsigned int >());
        logging::core::get()->add_global_attribute("TimeStamp", attrs::local_clock());

       
        boost::log::core::get()->add_sink(sink);
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

    HorizonCore::~HorizonCore(){
        boost::log::core::get()->remove_all_sinks();
    }


    HorizonCore* HorizonCore::GetInstance(){
        static HorizonCore s_instance;
        return &s_instance;
    }



    void HorizonCore::init(){
        HORIZON_TRACE << "starting...";

    }



}//namespace horizon