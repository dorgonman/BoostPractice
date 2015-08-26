cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT (testbed CXX)

include(../cmake/UtilMacro.cmake)
include(../cmake/CommonSetting.cmake)
include(../cmake/LibSetting.cmake)





file(GLOB PROJ_SRCS
 	"cpp/Public/*.h"
    "cpp/Public/*.cpp"
)

source_group_by_dir(PROJ_SRCS)


file(GLOB PLATFORM_SRCS
 	"cpp/Platform/standard/*.h"
    "cpp/Platform/standard/*.cpp"
)

source_group_by_dir(PLATFORM_SRCS)



add_executable(testbed ${PLATFORM_SRCS} ${PROJ_SRCS})


include(../cmake/LibLink.cmake)

