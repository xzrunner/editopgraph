#pragma once

#include "editopgraph/Param.h"

#include <ee0/typedef.h>

#include <SM_Vector.h>
#include <SM_Ray.h>
#include <SM_Plane.h>

#include <memory>

namespace pt0 { class Camera; }
namespace pt3 { class Viewport; }

namespace editopgraph
{

class CameraParam : public Param
{
public:
    explicit CameraParam(const std::shared_ptr<pt0::Camera>& cam)
        : m_cam(cam) {}

    virtual ParamType Type() const override {
        return ParamType::Camera;
    }

    auto& GetCamera() const { return m_cam; }

private:
    std::shared_ptr<pt0::Camera> m_cam = nullptr;

}; // CameraParam

class ViewportParam : public Param
{
public:
    explicit ViewportParam(const pt3::Viewport& vp)
        : m_vp(vp) {}

    virtual ParamType Type() const override {
        return ParamType::Viewport;
    }

    auto& GetViewport() const { return m_vp; }

private:
    const pt3::Viewport& m_vp;

}; // ViewportParam

class PublisherParam : public Param
{
public:
    explicit PublisherParam(const ee0::SubjectMgrPtr& publisher)
        : m_publisher(publisher) {}

    virtual ParamType Type() const override {
        return ParamType::Publisher;
    }

    auto& GetPublisher() const { return m_publisher; }

private:
    ee0::SubjectMgrPtr m_publisher;

}; // PublisherParam

class ScreenPosParam : public Param
{
public:
    explicit ScreenPosParam(const sm::ivec2& pos)
        : m_pos(pos) {}

    virtual ParamType Type() const override {
        return ParamType::ScreenPos;
    }

    auto& GetPos() const { return m_pos; }

private:
    sm::ivec2 m_pos;

}; // ScreenPosParam

class Float3Param : public Param
{
public:
    explicit Float3Param(const sm::vec3& val)
        : m_val(val) {}

    virtual ParamType Type() const override {
        return ParamType::Float3;
    }

    auto& GetValue() const { return m_val; }

private:
    sm::vec3 m_val;

}; // Float3Param

class RayParam : public Param
{
public:
    explicit RayParam(const sm::Ray& ray)
        : m_ray(ray) {}

    virtual ParamType Type() const override {
        return ParamType::Ray;
    }

    auto& GetRay() const { return m_ray; }

private:
    sm::Ray m_ray;

}; // RayParam

class PlaneParam : public Param
{
public:
    explicit PlaneParam(const sm::Plane& plane)
        : m_plane(plane) {}

    virtual ParamType Type() const override {
        return ParamType::Plane;
    }

    auto& GetPlane() const { return m_plane; }

private:
    sm::Plane m_plane;

}; // PlaneParam

}