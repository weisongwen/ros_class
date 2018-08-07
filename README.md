# Template for writing ROS node package, using C++

This ros node firstly subscribe the topic (/imu), then publish the content with new topic name (/imu2).
calculate the translation based on the axis acc. the translation is published as topic (/translation).

[imu](https://baike.baidu.com/item/%E6%83%AF%E6%80%A7%E6%B5%8B%E9%87%8F%E5%8D%95%E5%85%83/7942440?fr=aladdin) is a sensor to measure the acceleration of objects,

subscriber: 

```
/imu
```
publisher: 

```
/imu2
/translation
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
$ source devel/setup.bash
$ roslaunch ivactuator starup.launch
$ cd $HOME/template_ros/src/ivactuator/data
$ rosbag play imu.bag
```

### Method 2:
```
$ cd $HOME/template_ros
$ source devel/setup.bash
$ roslaunch ivactuator starup.launch
$ cd $HOME/template_ros/src/ivactuator/data
$ rosbag play imu.bag
```

### how to show what is in the /imu topic?
```
$ rostopic echo /imu
```
```
header: 
  seq: 7706
  stamp: 
    secs: 1488703480
    nsecs: 392411775
  frame_id: imu_link
orientation: 
  x: 0.0397092215717
  y: 0.00633058696985
  z: 0.172644585371
  w: 0.984162986279
orientation_covariance: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
angular_velocity: 
  x: 0.00770223420113
  y: 0.0133386412635
  z: 0.298744618893
angular_velocity_covariance: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
linear_acceleration: 
  x: -0.462217539549
  y: 0.82411634922
  z: 10.5903949738
linear_acceleration_covariance: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
---
header: 
  seq: 7707
  stamp: 
    secs: 1488703480
    nsecs: 400926097
  frame_id: imu_link
orientation: 
  x: 0.0397337637842
  y: 0.00631054723635
  z: 0.17284142971
  w: 0.984127640724
orientation_covariance: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
angular_velocity: 
  x: 0.00446937792003
  y: 0.0157519895583
  z: 0.297159343958
angular_velocity_covariance: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
linear_acceleration: 
  x: -0.761591672897
  y: 0.844375252724
  z: 10.3588495255
linear_acceleration_covariance: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
---
header: 
  seq: 7708
  stamp: 
    secs: 1488703480
    nsecs: 412612312
  frame_id: imu_link
orientation: 
  x: 0.0397733263671
  y: 0.00629096990451
  z: 0.173106268048
  w: 0.984079658985
orientation_covariance: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
angular_velocity: 
  x: 0.00744306994602
  y: 0.014955855906
  z: 0.299250811338
angular_velocity_covariance: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
linear_acceleration: 
  x: -1.03676986694
  y: 0.68077814579
  z: 10.4217367172
linear_acceleration_covariance: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
---

```
## Claim

If there is any thing inappropriate, please contact me through weisong.wen@berkeley.edu (Weisong WEN).

## LICENSE
### BSD License – PolyU

Copyright (c) 2018 [Weisong WEN](https://github.com/weisongwen)

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

* Neither the name of the <organization> nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
