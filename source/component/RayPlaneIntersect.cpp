#include "editopgraph/component/RayPlaneIntersect.h"
#include "editopgraph/ParamImpl.h"
#include "editopgraph/CompHelper.h"

#include <SM_Plane.h>
#include <SM_RayIntersect.h>

namespace editopgraph
{
namespace comp
{

void RayPlaneIntersect::Execute(const std::shared_ptr<dag::Context>& ctx)
{
    m_vals.resize(1, nullptr);

    auto p_ray   = CompHelper::CheckInputParam<RayParam>(*this, 0);
    auto p_plane = CompHelper::CheckInputParam<PlaneParam>(*this, 1);
    if (p_ray && p_plane)
    {
        sm::vec3 cross;
        if (sm::ray_plane_intersect(p_ray->GetRay(), p_plane->GetPlane(), &cross)) {
            m_vals[0] = std::make_shared<Float3Param>(cross);
        }
    }
}

}
}