#include <ros/ros.h>

#include <sensor_msgs/JointState.h>
#include <sensor_msgs/SetCameraInfo.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <std_msgs/Int8.h>

#include <qi/applicationsession.hpp>
#include <qi/anyobject.hpp>


class test_motion_pepper
{
public:

  test_motion_pepper(ros::NodeHandle &nh);
  ~test_motion_pepper();
  void spin();
  qi::AnyValue fromStringVectorToAnyValue(const std::vector<std::string> &vector);
  qi::AnyValue fromDoubleVectorToAnyValue(const std::vector<double> &vector);


protected:

  // Robot
  std::string m_ip;


  // ROS
  ros::NodeHandle n;

  int freq;




// New Proxy
  qi::SessionPtr m_session; //!< Session to connect to Pepper
  qi::AnyObject m_qiProxy;


};
