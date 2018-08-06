/*
 * Copyright (c) 2015-2020 Weisong WEN (weisong.wen@berkeley.edu)
 * Distributed under the IVPT Software License
 * Author: weisong wen
 * This is the template for writing a node, using C++ class
 * * *************************************************************************
 * */


#ifndef actuator_H
#define ACTUALOR_H

#include <iostream>
#include <math.h>
#include <ros/ros.h>
#include <string.h>
#include <boost/asio.hpp> 
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include "pthread.h"
#include <sensor_msgs/Imu.h>
using namespace std;
using namespace boost::asio; 
using namespace boost;

class actuator{
  public:
    actuator(ros::NodeHandle handle);
    ~actuator(){}  
    void run();
    void function1();
    void callback_sendthread();
    void imu_callback(const sensor_msgs::ImuConstPtr& imu_msg);
  private:  	
    ros::NodeHandle m_handle;
    ros::Publisher  imu_pub;
    ros::Subscriber imu_sub;
    float count;
};

#endif /*ACTUALOR_H*/
