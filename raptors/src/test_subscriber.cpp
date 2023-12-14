#include "ros/ros.h"
#include "std_msgs/String.h"

void messageCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("Received: %s", msg->data.c_str());
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "test_subscriber");
    ros::NodeHandle node_handle;
    ros::Subscriber sub = node_handle.subscribe("RaptorOUT", 1000, messageCallback);

    ros::spin();

    return 0;
}
