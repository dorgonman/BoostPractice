#NOTE: please install msysgit inorder to execute linux shell under windows
#set -e

#rm -rf ../proj.win32
boost_root="$(pwd)/../lib/boost_1_59_0/"
mkdir ../proj.win32
cd ../proj.win32
cmake ../ -G "Visual Studio 12 2013" \
	  -DBOOST_ROOT="${boost_root}"
	  #-DBOOST_INCLUDE_DIRS="${boost_root}/boost" -DBoost_LIBRARY_DIRS="${boost_root}/stage/lib"

