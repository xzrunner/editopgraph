#pragma once

#include "editopgraph/typedef.h"
#include "editopgraph/ParamType.h"

#include <dag/Node.h>

namespace editopgraph
{

class Component : public dag::Node<ParamType>
{
public:
    Component() {}

    auto& GetAllValues() const { return m_vals; }

protected:
    std::vector<ParamPtr> m_vals;

    RTTR_ENABLE(dag::Node<ParamType>)

}; // Component

}