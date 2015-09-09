#MESSAGE( STATUS "SET_UP_COMMON_SETTING:         " ${PROJECT_NAME} )

#PROJECT_SOURCE_DIR

#include project root, public and private folder for current project
set (PROJECT_PRIVATE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cpp/Private)
include_directories("${PROJECT_PRIVATE_DIR}")

set (PROJECT_PUBLIC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cpp/Public)
include_directories("${PROJECT_PUBLIC_DIR}")

set (PROJECT_CPP_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cpp/)
include_directories("${PROJECT_CPP_SRC_DIR}")


#set CXX FLAGS for linux
IF(UNIX)
	set (CMAKE_CXX_FLAGS "-std=c++0x -stdlib=libc++ -O2 -g -Wall")
ENDIF()

