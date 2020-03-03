#pragma once

#include "editopgraph/Component.h"

namespace editopgraph
{
namespace comp
{

class Context : public Component
{
public:
    enum class OutputID
    {
        ID_CAM,
        ID_VP,
        ID_SUB,
        ID_POS,
    };

public:
    Context()
    {
        m_exports = {
            {{ ParamType::Camera,    "Camera",    "C" }},
            {{ ParamType::Viewport,  "Viewport",  "V" }},
            {{ ParamType::Publisher, "Publisher", "M" }},
        };
    }

    virtual void Execute(const std::shared_ptr<dag::Context>& ctx = nullptr) override;

    RTTR_ENABLE(Component)

#define PARM_FILEPATH "editopgraph/component/Context.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // Context

}
}