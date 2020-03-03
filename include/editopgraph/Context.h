#pragma once

#include "dag/Context.h"

#include <ee0/typedef.h>

#include <SM_Vector.h>

namespace pt0 { class Camera; }
namespace pt3 { class Viewport; }

namespace editopgraph
{

class Context : public dag::Context
{
public:
    Context(const std::shared_ptr<pt0::Camera>& cam,
        const pt3::Viewport& vp, const ee0::SubjectMgrPtr& publisher)
        : m_camera(cam)
        , m_vp(vp)
        , m_publisher(publisher)
    {
    }

    void SetMousePos(int x, int y) { m_mouse_pos.Set(x, y); }

    auto GetCamera() const { return m_camera; }
    auto& GetViewport() const { return m_vp; }

private:
    std::shared_ptr<pt0::Camera> m_camera = nullptr;
    const pt3::Viewport&         m_vp;
    ee0::SubjectMgrPtr           m_publisher = nullptr;

    sm::ivec2 m_mouse_pos;

}; // Context

}