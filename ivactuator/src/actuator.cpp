/*
 * Copyright (c) 2015-2020 Weisong WEN (weisong.wen@berkeley.edu)
 * Distributed under the IVPT Software License
 * Author: weisong wen
 * This is the template for writing a node, using C++ class
 * * *************************************************************************
 * */

#include "actuator.h"

/**
 *run()
 *constructor function, usually used for initialize some variables.
 */
actuator::actuator(ros::NodeHandle handle)
{
    m_handle = handle;
    count = 0;
    std::cout<<"this is the constructor function, this function will only run when the a class is created."<<std::endl;
}

/**
 *run()
 */
void actuator::run()
{
    imu_pub = m_handle.advertise<sensor_msgs::Imu>("/imu2",1000);
    imu_sub = m_handle.subscribe("/imu", 500, &actuator::imu_callback, this); // callback for /imu topic
    boost::thread thread(boost::bind(&actuator::callback_sendthread, this) );  
    thread.detach();
    int run_rate = 20; //50ms
    ros::Rate rate(run_rate);
    while(ros::ok()){
        ros::spinOnce();
        rate.sleep();
    }
}

/**
 *callback_sendthread()
 */
void actuator::callback_sendthread()
{
    while(1){
        function1();//
        usleep(5000*1000); // wait 500ms
    }
}

/**
 *function1()
 *simple function
 */
void actuator::function1()
{
    count++;
    std::cout<<"this is the function1 function......       Count = "<<count<<std::endl;
}

/**
 *imu_callback()
 */
void actuator::imu_callback(const sensor_msgs::ImuConstPtr& imu_msg)
{
    /*
    look at the structure of sensor_msgs/Imu using: rosmsg show sensor_msgs/Imu
    std_msgs/Header header
      uint32 seq
      time stamp
      string frame_id
    geometry_msgs/Quaternion orientation
      float64 x
      float64 y
      float64 z
      float64 w
    float64[9] orientation_covariance
    geometry_msgs/Vector3 angular_velocity
      float64 x
      float64 y
      float64 z
    float64[9] angular_velocity_covariance
    geometry_msgs/Vector3 linear_acceleration
      float64 x
      float64 y
      float64 z
    float64[9] linear_acceleration_covariance
    */
    // std::cout<<"this is the imu_callback function......"<<std::endl;
    sensor_msgs::Imu received_imu;
    received_imu = *imu_msg;
    std::cout<<"x axis acceleration-> "<<received_imu.angular_velocity.x<<std::endl;;
    imu_pub.publish(received_imu); // publish the new imu message using a new topic.
}
