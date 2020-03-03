#pragma once

#include "editopgraph/Component.h"

#include <SM_Vector.h>

namespace editopgraph
{
namespace comp
{

class Plane : public Component
{
public:
    Plane()
    {
        m_exports = {
            {{ ParamType::Plane, "Plane", "P" }},
        };
    }

    virtual void Execute(const std::shared_ptr<dag::Context>& ctx = nullptr) override;

    RTTR_ENABLE(Component)

#define PARM_FILEPATH "editopgraph/component/Plane.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // Plane

}
}