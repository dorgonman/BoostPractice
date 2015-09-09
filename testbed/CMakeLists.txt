cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT (testbed CXX)

include(../cmake/UtilMacro.cmake)
include(../cmake/CommonSetting.cmake)
include(../cmake/LibSetting.cmake)




#============add project testbedStatic library=============
file(GLOB PROJ_SRCS
 	"cpp/Public/*.h"
    "cpp/Public/*.cpp"
    "cpp/Private/*.h"
    "cpp/Private/*.cpp"
)

source_group_by_dir(PROJ_SRCS)
add_library(testbedStatic STATIC ${PROJ_SRCS})
#=============================================================
#============add project testbed executable=============
file(GLOB PLATFORM_SRCS
 	"cpp/Platform/standard/*.h"
    "cpp/Platform/standard/*.cpp"
)

source_group_by_dir(PLATFORM_SRCS)
add_executable(testbed ${PLATFORM_SRCS})


#=============================================================

#============add project testbedTestCase executable=============
file(GLOB TEST_SRC
 	"cpp/unit_test/*.hpp"
 	"cpp/unit_test/*.cpp"
)
source_group_by_dir(TEST_SRC)

#set_source_files_properties("cpp/unit_test/main.cpp" PROPERTIES HEADER_FILE_ONLY TRUE) 
add_executable(testbedTestCase ${TEST_SRC})
add_custom_command(TARGET testbedTestCase
				   POST_BUILD
				   COMMAND $(TargetPath) ARGS --result_code=no --report_level=no)
#=============================================================


include(../cmake/LibLink.cmake)

target_link_libraries(testbedTestCase testbedStatic)
target_link_libraries(testbed testbedStatic)
target_link_libraries(testbedTestCase HorizonCoreStatic)



