#include <ros/ros.h>

#include "test_motion_pepper.h"

int main( int argc, char** argv )
{
  ros::init( argc, argv, "vs_grasping_pepper" );

  ros::NodeHandle n(std::string("~"));

  test_motion_pepper *node = new test_motion_pepper(n);

  node->spin();

  delete node;

  return 0;
}




