#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

static const std::string OPENCV_WINDOW = "Image window";
static const std::string SKYVIEW = "SKYVIEW";
using namespace cv;
class ImageConverter
{
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
  image_transport::Publisher image_pub_;

public:
  ImageConverter()
    : it_(nh_)
  {
    // Subscrive to input video feed and publish output video feed
    image_sub_ = it_.subscribe("/image_raw_flipped", 1,
      &ImageConverter::imageCb, this);
    image_pub_ = it_.advertise("/image_converter/output_video", 1);

    cv::namedWindow(OPENCV_WINDOW);
    cv::namedWindow(SKYVIEW);

    readImage();
  }

  ~ImageConverter()
  {
    cv::destroyWindow(OPENCV_WINDOW);
  }

  void imageCb(const sensor_msgs::ImageConstPtr& msg)
  {
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }

    // Draw an example circle on the video stream
    if (cv_ptr->image.rows > 600 && cv_ptr->image.cols > 600)
      cv::circle(cv_ptr->image, cv::Point(2048/2, 2448/2), 500, CV_RGB(255,0,0),8);

    // grey image
    cv::Mat img_out;
    cv::cvtColor(cv_ptr->image, img_out, CV_RGB2GRAY);  //转换成灰度图象
    // std::cout<<"image size rows ->" <<cv_ptr->image.rows<<"  image size cols->"<<cv_ptr->image.cols<<std::endl;

    // Update GUI Window
    cv::resize(cv_ptr->image, cv_ptr->image, cv::Size(cv_ptr->image.cols/2, cv_ptr->image.rows/2)); // to half size or even smaller
    cv::flip(cv_ptr->image, cv_ptr->image, -1);
    cv::imshow(OPENCV_WINDOW, cv_ptr->image);
    cv::waitKey(3);

    // Output modified video stream
    image_pub_.publish(cv_ptr->toImageMsg());
  }

  void readImage()
  {
    std::cout<<"read a image from a .png file"<<std::endl;
    cv::Mat image_ = cv::imread("src/ivactuator/data/skyview",cv::IMREAD_COLOR);
    std::cout<<"image size rows ->" <<image_.rows<<"  image size cols->"<<image_.cols<<std::endl;
    if( image_.empty() )                      // Check for invalid input
    {
        std::cout <<  "Could not open or find the image" << std::endl ;
    }
    cv::namedWindow( SKYVIEW, cv::WINDOW_AUTOSIZE ); // Create a window for display.

    // start image processing here
    cv::Mat img_out;
    cv::cvtColor(image_, img_out, CV_RGB2GRAY);  //转换成灰度图象

    cv::imshow(SKYVIEW, img_out);
    cv::waitKey(0); 
  }
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "skyview");
  ImageConverter ic;
  ros::spin();
  return 0;
}