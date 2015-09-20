#!/bin/sh
set -e


if [ "${BOOST_ROOT}" == "" ]
then
  BOOST_ROOT=$1
fi

if [ "${BOOST_ROOT}" == "" ]
then
  echo "Please define BOOST_ROOT path in system environment"
  exit 1
fi


echo {BOOST_ROOT}:  ${BOOST_ROOT}

#NOTE: please install msysgit inorder to execute linux shell under windows
#rm -rf ../proj.win32
#BOOST_ROOT="$(pwd)/../../thirdparty/boost_1_59_0/"
mkdir ../../proj.win32 || true
cd ../../proj.win32
cmake ../ -G "Visual Studio 12 2013" \
	  -DBOOST_ROOT="${BOOST_ROOT}"
	  #-DBOOST_INCLUDE_DIRS="${boost_root}/boost" -DBoost_LIBRARY_DIRS="${boost_root}/stage/lib"

