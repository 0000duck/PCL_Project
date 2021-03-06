/** \brief 文件的读写
 * 
 * 
 */
#pragma once
//linux io
#include <sys/types.h>  
#include <sys/stat.h>  
//opencv
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//pcl
#include <pcl/io/pcd_io.h>
#include <pcl/io/vtk_io.h>
//gp
#include "pcl_project/config.h"

namespace gp{
  
  /** \brief 导入图像文件
   * \param[in] argc 参数行数
   * \param[in] argv 具体参数
   * \param[out] png_data png图像数据数据的容器，间隔存储RGB和深度图像
   */ 
  void load_image(int argc,char **argv,std::vector<cv::Mat> &png_data);
  
  /** \brief 图像转点云
   * \param[in] png_data 图像数据容器
   * \param[out] cloud_data 点云数据容器
   */ 
  void image_to_pcd(std::vector<cv::Mat> &png_data,std::vector<pcl::PointCloud<PointT>::Ptr > &cloud_data);
  
  /** \brief 存储点云
   * \param[in] cloud_data 点云数据容器
   * \out pcd文件 执行目录下的pcd_data中
   */ 
  void save_pcd(std::vector<pcl::PointCloud<PointT>::Ptr > &cloud_data);
  
  /** \brief 导入点云文件
   * \param[in] argc 参数行数
   * \param[in] argv 具体参数
   * \param[out] cloud_data 取得的未经处理的点云对象指针的容器
   */ 
  void load_pcd(int argc,char **argv,std::vector<pcl::PointCloud<PointT>::Ptr > &cloud_data);
  
  /** @brief 加载JSON配置文件
   */ 
  void load_config_json();
}
