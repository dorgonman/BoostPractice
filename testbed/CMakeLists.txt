cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT (testbed CXX)

include(../cmake/UtilMacro.cmake)
include(../cmake/CommonSetting.cmake)
include(../cmake/LibSetting.cmake)





file(GLOB PROJ_SRCS
 	"cpp/Public/*.h"
    "cpp/Public/*.cpp"
    "cpp/Private/*.h"
    "cpp/Private/*.cpp"
)

source_group_by_dir(PROJ_SRCS)


file(GLOB PLATFORM_SRCS
 	"cpp/Platform/standard/*.h"
    "cpp/Platform/standard/*.cpp"
)

source_group_by_dir(PLATFORM_SRCS)

file(GLOB TEST_SRC
 	"cpp/unit_test/*.hpp"
 	"cpp/unit_test/*.cpp"
)

source_group_by_dir(TEST_SRC)

#set_source_files_properties("cpp/unit_test/main.cpp" PROPERTIES HEADER_FILE_ONLY TRUE) 

add_executable(testbed ${PLATFORM_SRCS} ${PROJ_SRCS})
add_executable(testbedTestCase ${TEST_SRC} ${PROJ_SRCS})


include(../cmake/LibLink.cmake)

