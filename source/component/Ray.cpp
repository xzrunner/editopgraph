#include "editopgraph/component/Ray.h"
#include "editopgraph/CompHelper.h"
#include "editopgraph/ParamImpl.h"
#include "editopgraph/Context.h"

#include <painting3/PerspCam.h>
#include <painting3/Viewport.h>

namespace editopgraph
{
namespace comp
{

void Ray::Execute(const std::shared_ptr<dag::Context>& ctx)
{
    m_vals.resize(1, nullptr);

    auto start_pos = m_start_pos;
    auto end_pos = m_end_pos;

    auto p_start = CompHelper::GetInputParam(*this, 0);
    auto p_end   = CompHelper::GetInputParam(*this, 1);

    if (p_start)
    {
        switch (p_start->Type())
        {
        case ParamType::Camera:
        {
            auto cam = std::static_pointer_cast<CameraParam>(p_start)->GetCamera();
            auto cam_type = cam->TypeID();
            if (cam_type == pt0::GetCamTypeID<pt3::PerspCam>()) {
                start_pos = std::dynamic_pointer_cast<pt3::PerspCam>(cam)->GetPos();
            }
        }
            break;
        case ParamType::Float3:
            start_pos = std::static_pointer_cast<Float3Param>(p_start)->GetValue();
            break;
        }
    }
    if (p_end)
    {
        switch (p_end->Type())
        {
        case ParamType::ScreenPos:
        {
            if (ctx)
            {
                auto _ctx = std::static_pointer_cast<Context>(ctx);

                auto cam = _ctx->GetCamera();
                auto cam_type = cam->TypeID();
                if (cam_type == pt0::GetCamTypeID<pt3::PerspCam>())
                {
                    auto p_cam = std::dynamic_pointer_cast<pt3::PerspCam>(cam);

                    auto pos = std::static_pointer_cast<ScreenPosParam>(p_end)->GetPos();
                    sm::vec3 ray_dir = _ctx->GetViewport().TransPos3ScreenToDir(
                        sm::vec2(static_cast<float>(pos.x), static_cast<float>(pos.y)), *p_cam);
                    end_pos = start_pos + ray_dir;
                }
            }
        }
            break;
        case ParamType::Float3:
            end_pos = std::static_pointer_cast<Float3Param>(p_end)->GetValue();
            break;
        }
    }

    sm::Ray ray(start_pos, end_pos - start_pos);
    m_vals[0] = std::make_shared<RayParam>(ray);
}

}
}