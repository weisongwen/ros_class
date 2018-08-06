# Template for writing ROS node package, using C++

This ros node firstly subscribe the topic (/imu), then publish the content with new topic name (/imu2).

[imu](https://baike.baidu.com/item/%E6%83%AF%E6%80%A7%E6%B5%8B%E9%87%8F%E5%8D%95%E5%85%83/7942440?fr=aladdin) is a sensor to measure the acceleration of objects,

subscriber: 

```
/imu
```
publisher: 

```
/imu2
```
## How to Build

```
$ cd $HOME
$ mkdir template_ros/src
$ cd template_ros/src
$ git clone https://github.com/weisongwen/ros_class.git
$ cd ..
$ catkin_make
```

## How to Start (open roscore first)
### Method 1:
```
$ cd $HOME/template_ros
$ source dev/setup.bash
$ roslaunch ivactuator starup.launch
$ cd $HOME/cat_ws/src/ivactuator/data
$ rosbag play imu.bag
```

### Method 2:
```
$ cd $HOME/template_ros
$ source dev/setup.bash
$ rosrun ivactuator ivactuator
$ cd $HOME/cat_ws/src/ivactuator/data
$ rosbag play imu.bag
```


## Claim

If there is any thing inappropriate, please contact me through 17902061r@connect.polyu.hk (Weisong WEN).

## LICENSE
### BSD License – PolyU

Copyright (c) 2018 [Weisong WEN](https://github.com/weisongwen)

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

* Neither the name of the <organization> nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
