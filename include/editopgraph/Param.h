#pragma once

#include "editopgraph/ParamType.h"

namespace editopgraph
{

class Param
{
public:
    virtual ParamType Type() const = 0;

}; // Param

}