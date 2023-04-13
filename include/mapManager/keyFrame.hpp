#ifndef __KEY_FRAME_HH__
#define __KEY_FRAME_HH__
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

using PointType = pcl::PointXYZI;

class KeyFrame {
public:
    KeyFrame() {
        rawCloud.reset(new pcl::PointCloud<PointType>());
        cornerCloudDS.reset(new pcl::PointCloud<PointType>());
        surfCloudDS.reset(new pcl::PointCloud<PointType>());
    }
public:
    pcl::PointCloud<PointType>::Ptr rawCloud;
    pcl::PointCloud<PointType>::Ptr cornerCloudDS;
    pcl::PointCloud<PointType>::Ptr surfCloudDS;

    // 后续是否需要改为指针
    float x;
    float y;
    float z;
    float roll;
    float pitch;
    float yaw;
    float time;

    float imuRollInit;
    float imuPitchInit;
    float imuYawInit;

    bool odomAvailable{false};
    bool imuAvailable{true};
};
#endif

