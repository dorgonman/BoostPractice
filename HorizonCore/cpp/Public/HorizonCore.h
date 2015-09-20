

#ifndef _HORIZON_HORIZON_CORE_H_
#define _HORIZON_HORIZON_CORE_H_

#define SET_MODULE(logger,log_module)  logger.add_attribute(boost_android_logging::module.get_name(), boost::log::attributes::constant<std::string>(#log_module));

namespace horizon{
    class HorizonCore{
    private:
        HorizonCore();
        ~HorizonCore();
    public:
        static HorizonCore* GetInstance();

        void init();
        //flush log to file
        void flushAllLog();
    private:
        void initLog();
 
    };


}//namespace horizon


#endif //_HORIZON_HORIZON_CORE_H_