#pragma once

#include "editopgraph/Component.h"

#include <SM_Vector.h>

namespace editopgraph
{
namespace comp
{

class RayPlaneIntersect : public Component
{
public:
    RayPlaneIntersect()
    {
        m_imports = {
            {{ ParamType::Ray,   "Ray",   "R" }},
            {{ ParamType::Plane, "Plane", "P" }},
        };
        m_exports = {
            {{ ParamType::Float3, "Pos", "P" }},
        };
    }

    virtual void Execute(const std::shared_ptr<dag::Context>& ctx = nullptr) override;

    RTTR_ENABLE(Component)

#define PARM_FILEPATH "editopgraph/component/RayPlaneIntersect.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // RayPlaneIntersect

}
}