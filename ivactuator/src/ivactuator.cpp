/*
 * Copyright (c) 2015-2020 Weisong WEN (weisong.wen@berkeley.edu)
 * Distributed under the IVPT Software License
 * Author: weisong wen
 * This is the template for writing a node, using C++ class
 * * *************************************************************************
 * */


#include "actuator.h"

int main(int argc, char** argv)
{
   ros::init(argc,argv,"ivactuator");
   ros::NodeHandle nh;
   actuator* ivnode = new actuator(nh);
   ivnode->run();
   ros::spin();
 }
