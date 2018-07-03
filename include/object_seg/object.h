#ifndef _OBJECT_SEG_OBJECT_H_
#define _OBJECT_SEG_OBJECT_H_

#include <string>

#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Vector3.h"
#include "pcl/point_cloud.h"
#include "pcl/point_types.h"

namespace object_seg {
struct Object
{
    int id;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud;
    geometry_msgs::Pose pose;
    geometry_msgs::Vector3 dimensions;
};
} // namespace object_seg

#endif // _OBJECT_SEG_OBJECT_H_