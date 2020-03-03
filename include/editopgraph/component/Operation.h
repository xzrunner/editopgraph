#pragma once

#include "editopgraph/Component.h"

namespace editopgraph
{
namespace comp
{

class Operation : public Component
{
public:
    Operation()
    {
        m_imports = {
            {{ ParamType::Port, "mouse_left_down" }},
            {{ ParamType::Port, "mouse_left_up" }},
            {{ ParamType::Port, "mouse_drag" }},
            {{ ParamType::Port, "draw" }},
        };
    }

    virtual void Execute(const std::shared_ptr<dag::Context>& ctx = nullptr) override;

    RTTR_ENABLE(Component)

#define PARM_FILEPATH "editopgraph/component/Operation.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // Component

}
}