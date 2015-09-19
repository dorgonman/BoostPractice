#!/bin/sh
set -e
pwd
#NOTE: please install msysgit inorder to execute linux shell under windows
#rm -rf ../proj.win32
BOOST_ROOT="$(pwd)/../../thirdparty/boost_1_59_0/"
mkdir ../../proj.win32 || true
cd ../../proj.win32
cmake ../ -G "Visual Studio 12 2013" \
	  -DBOOST_ROOT="${BOOST_ROOT}"
	  #-DBOOST_INCLUDE_DIRS="${boost_root}/boost" -DBoost_LIBRARY_DIRS="${boost_root}/stage/lib"

