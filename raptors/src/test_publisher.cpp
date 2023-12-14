#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "test_publisher");
    ros::NodeHandle node_handle;
    ros::Publisher pub = node_handle.advertise<std_msgs::String>("RaptorIN", 1000);
    ros::Rate loop_rate(1); 

    while (ros::ok()) {
        std_msgs::String msg;
        msg.data = "Test message for RaptorIN";
        pub.publish(msg);
        ROS_INFO("Published: %s", msg.data.c_str());
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
