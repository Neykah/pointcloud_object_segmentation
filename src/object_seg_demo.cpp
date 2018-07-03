#include "ros/ros.h"
#include "object_seg/crop.h"
#include "object_seg/segmentation.h"
#include "visualization_msgs/Marker.h"
#include "sensor_msgs/PointCloud2.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "object_seg_demo");
    ros::NodeHandle nh;

    // Crop the background
    ros::Publisher crop_pub = nh.advertise<sensor_msgs::PointCloud2>("cropped_cloud", 1, true);
    object_seg::Cropper cropper(crop_pub);
    ros::Subscriber crop_sub = nh.subscribe("cloud_in", 1, &object_seg::Cropper::Callback, &cropper);

    // Segment the planes
    ros::Publisher marker_pub = nh.advertise<visualization_msgs::Marker>("visualisation_marker", 1, true);
    object_seg::Segmenter segmenter(marker_pub);
    ros::Subscriber sub = nh.subscribe("cropped_cloud", 1, &object_seg::Segmenter::Callback, &segmenter);

    ros::spin();
    return 0;
}