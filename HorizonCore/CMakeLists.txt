cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT (HorizonCore CXX)

include(../cmake/UtilMacro.cmake)
include(../cmake/CommonSetting.cmake)
include(../cmake/LibSetting.cmake)




file(GLOB PROJ_SRCS
	"cpp/Public/*.hpp"
 	"cpp/Public/*.h"
    "cpp/Public/*.cpp"
   	"cpp/Private/*.hpp"
   	"cpp/Private/*.h"
    "cpp/Private/*.cpp"
)

source_group_by_dir(PROJ_SRCS)


file(GLOB PLATFORM_SRCS
 	"cpp/Platform/standard/*.h"
    "cpp/Platform/standard/*.cpp"
)

source_group_by_dir(PLATFORM_SRCS)

#add_executable(HorizonCore ${PLATFORM_SRCS})
#add_library(HorizonCoreShared SHARED ${PROJ_SRCS})
add_library(HorizonCoreStatic STATIC ${PROJ_SRCS})

#generate_export_header(LibHorizonCore EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/xxxx.h)

#include(../cmake/LibLink.cmake)