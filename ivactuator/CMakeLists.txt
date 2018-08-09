cmake_minimum_required(VERSION 2.8.3)
project(ivactuator)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg serial cv_bridge
  image_transport)

#***********************
#******   OpenCV
#***********************
find_package( OpenCV 2.4.8 REQUIRED )
if (NOT OpenCV_FOUND)
  message(FATAL_ERROR "*****!!!!! opencv NOT found.")
endif (NOT OpenCV_FOUND)    

## Declare ROS messages and services
add_message_files(FILES ivactuator.msg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)


## Declare a catkin package
catkin_package(   
   CATKIN_DEPENDS roscpp rospy std_msgs
   message_runtime
   serial)

## Build actuator
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(
    ivactuator
    src/ivactuator.cpp
    src/actuator.cpp
  )
target_link_libraries(ivactuator ${catkin_LIBRARIES})
add_dependencies(ivactuator ivactuator_generate_messages_cpp)

add_executable(skyview src/skyview.cpp)   
target_link_libraries(skyview ${catkin_LIBRARIES})  
add_dependencies(skyview robot_vision_generate_messages_cpp)  

