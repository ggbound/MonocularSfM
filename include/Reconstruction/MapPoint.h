#ifndef __MAP_POINT_H__
#define __MAP_POINT_H__

#include <vector>

#include <opencv2/opencv.hpp>

#include "Common/Types.h"

namespace MonocularSfM
{


struct MapPointElement
{
    MapPointElement(){}
    MapPointElement(image_t image_id, point2D_t point2D_idx)
                  : image_id(image_id), point2D_idx(point2D_idx) {}

    image_t image_id;
    point2D_t point2D_idx;
};

class MapPoint
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // 存取整个track的3D点的ID
    ////////////////////////////////////////////////////////////////////////////////
    const point3D_t& Point3DIdx() const;
    point3D_t& Point3DIdx();
    void SetPoint3DIdx(const point3D_t&  point3D_idx);

    ////////////////////////////////////////////////////////////////////////////////
    // 存取整个track的3D点
    ////////////////////////////////////////////////////////////////////////////////
    const cv::Point3f& Point3D() const;
    cv::Point3f& Point3D();
    void SetPoint3D(const cv::Point3f& point3D);

    ////////////////////////////////////////////////////////////////////////////////
    // 获得track的长度
    ////////////////////////////////////////////////////////////////////////////////
    size_t Length() const;

    ////////////////////////////////////////////////////////////////////////////////
    // 获取整个track
    ////////////////////////////////////////////////////////////////////////////////
    const std::vector<MapPointElement>& Elements() const;
    std::vector<MapPointElement>& Elements();


    ////////////////////////////////////////////////////////////////////////////////
    // 获取track中的元素
    ////////////////////////////////////////////////////////////////////////////////
    const MapPointElement& Element(const size_t idx) const;
    MapPointElement& Element(const size_t idx);

    ////////////////////////////////////////////////////////////////////////////////
    // 向track中添加元素
    ////////////////////////////////////////////////////////////////////////////////
    void AddElement(const MapPointElement& element);
    void AddElement(const image_t image_id, const point2D_t point2D_idx);
    void AddElements(const std::vector<MapPointElement>& elements);

    ////////////////////////////////////////////////////////////////////////////////
    // 从track中删除元素
    ////////////////////////////////////////////////////////////////////////////////
    void DeleteElement(const size_t idx);
    void DeleteElement(const MapPointElement& element);
    void DeleteElement(const image_t image_id, const point2D_t point2D_idx);

private:
    point3D_t point3D_idx_;
    cv::Point3f point3D_;
    std::vector<MapPointElement> elements_;

};



} // namespace MonocularSfM

#endif //__MAP_POINT_H__
