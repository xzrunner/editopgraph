#pragma once

#include "editopgraph/typedef.h"

namespace editopgraph
{

class CompHelper
{
public:
    static CompPtr  GetInputComp(const Component& comp, size_t idx);
    static ParamPtr GetInputParam(const Component& comp, size_t idx);

    template <typename T>
    static std::shared_ptr<T> CheckInputParam(const Component& comp, size_t idx);

}; // CompHelper

}

#include "editopgraph/CompHelper.inl"