#pragma once

#include "editopgraph/Component.h"

#include <SM_Vector.h>

namespace editopgraph
{
namespace comp
{

class Ray : public Component
{
public:
    Ray()
    {
        m_imports = {
            {{ ParamType::Any, "Start Pos", "S"}},
            {{ ParamType::Any, "End Pos",   "E"}},
        };
        m_exports = {
            {{ ParamType::Ray, "Ray", "R" }},
        };
    }

    virtual void Execute(const std::shared_ptr<dag::Context>& ctx = nullptr) override;

private:


    RTTR_ENABLE(Component)

#define PARM_FILEPATH "editopgraph/component/Ray.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // Component

}
}