cmake_minimum_required( VERSION 2.8 )
project( useSophusExt )

# 为使用 sophus，您需要使用find_package命令找到它
find_package( Sophus REQUIRED )
include_directories( ${Sophus_INCLUDE_DIRS} )

add_executable( useSophusExt useSophusExt.cpp )
target_link_libraries( useSophusExt ${Sophus_LIBRARIES} )