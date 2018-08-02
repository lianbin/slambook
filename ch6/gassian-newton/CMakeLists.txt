cmake_minimum_required( VERSION 2.8 )
project( gsnt )

set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

# 添加cmake模块以使用ceres库
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules )

# 寻找G2O
#find_package( G2O REQUIRED )
include_directories( 
    "/usr/include/eigen3"
)

# OpenCV
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_DIRS} )

add_executable( gsnt gsnt.cpp )
# 与G2O和OpenCV链接
target_link_libraries( gsnt 
    ${OpenCV_LIBS}
)
