#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "camera_base_tf_publish");
  ros::NodeHandle node;

  tf::TransformBroadcaster br;
  tf::Transform transform;

  ros::Rate rate(10.0);
  while (node.ok()){
   //transform.setOrigin( tf::Vector3(0.0, 0.0, 0.68) );
    //q.setRPY(0, 3.14/4, 0);
    transform.setOrigin( tf::Vector3(0.55, -0.70, 0.80) );
    tf::Quaternion q;
    q.setRPY(0, 3.14/8, 3.14/2);
    transform.setRotation(q);
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "base_link", "camera_link"));
    rate.sleep();
  }
  return 0;
};
