cmake_minimum_required(VERSION 2.8.3)
project(test_motion_pepper)

# Tell CMake where to find "FindNAOqi.cmake"
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  sensor_msgs
  std_msgs
  tf
)


find_package(NAOqi QUIET COMPONENTS
    alcommon
    alvision
    alproxies
    alerror
    alvalue
    qi
    qitype
)


# Make sure Boost.Filesystem v3 is used.
add_definitions(-DBOOST_FILESYSTEM_VERSION=3)


catkin_package(
  
#  INCLUDE_DIRS
#  include
  
  LIBRARIES
  test_motion_pepper
  
  CATKIN_DEPENDS
  geometry_msgs
  roscpp
  sensor_msgs
  std_msgs
  tf

  DEPENDS 

)

include_directories(include)

include_directories(SYSTEM
  ${NAOqi_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

## Make sure Boost.Filesystem v3 is used.
add_definitions(-DBOOST_FILESYSTEM_VERSION=3)


# Declare a cpp library
add_library(test_motion_pepper
  include/test_motion_pepper.h
  src/test_motion_pepper.cpp
)


target_link_libraries(test_motion_pepper
  ${catkin_LIBRARIES}
  ${NAOqi_LIBRARIES}

)

## Declare a cpp executable
add_executable(test_motion_pepper_node src/main.cpp)

  target_link_libraries(test_motion_pepper_node
    ${resource_retriever_LIBRARIES}
    ${catkin_LIBRARIES}
    ${Boost_LIBRARIES}
    test_motion_pepper
    )


