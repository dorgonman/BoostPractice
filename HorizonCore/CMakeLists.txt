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



IF (WIN32)
	file(GLOB PLATFORM_WIN32_IMPLEMENT_SRCS
		"cpp/Platform/windows/implement/*.h"
		"cpp/Platform/windows/implement/*.cpp"
	)
	source_group_by_dir(PLATFORM_WIN32_IMPLEMENT_SRCS)
	set(PLATFORM_IMPLEMENT_SRCS ${PLATFORM_WIN32_IMPLEMENT_SRCS})
ELSE()
  # set stuff for other systems
ENDIF()



#add_executable(HorizonCore ${PLATFORM_SRCS})
#add_library(HorizonCoreShared SHARED ${PROJ_SRCS})
add_library(HorizonCoreStatic STATIC ${PROJ_SRCS} ${PLATFORM_IMPLEMENT_SRCS})

#generate_export_header(LibHorizonCore EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/xxxx.h)

#include(../cmake/LibLink.cmake)