
#MESSAGE( STATUS "BOOST_ROOT: ${BOOST_ROOT}" )

set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)
#set(Boost_DEBUG TRUE)

find_package(Boost COMPONENTS filesystem REQUIRED) 

if(Boost_FOUND)
	MESSAGE( STATUS "Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}" )
	MESSAGE( STATUS "Boost_INCLUDE_DIR: ${Boost_INCLUDE_DIR}" )
	MESSAGE( STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}" )
	link_directories(${Boost_LIBRARY_DIRS})
	include_directories( ${Boost_INCLUDE_DIR})
endif()
