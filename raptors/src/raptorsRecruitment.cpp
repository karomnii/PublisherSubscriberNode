#include "ros/ros.h"
#include "std_msgs/String.h"

#define NAME_AND_SURNAME "Piotr Ledwoch"
ros::Publisher pub;

void messageCallback(const std_msgs::String::ConstPtr& msg) {
    std::string received_message = msg->data;
    std::string new_message = received_message + " " + NAME_AND_SURNAME + " / " + std::to_string(ros::Time::now().toSec());
    std_msgs::String output_msg;
    output_msg.data = new_message;
    //for testing
    //ROS_INFO("%s", output_msg.data.c_str());
    pub.publish(output_msg);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "raptorsRecruitment");
    ros::NodeHandle node_handle;
    pub = node_handle.advertise<std_msgs::String>("RaptorOUT", 1000);
    ros::Subscriber sub = node_handle.subscribe("RaptorIN", 1000, messageCallback);

    ros::spin();


    return 0;
}
