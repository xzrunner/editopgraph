#pragma once

namespace editopgraph
{

template <typename T>
std::shared_ptr<T> CompHelper::CheckInputParam(const Component& comp, size_t idx)
{
    auto param = GetInputParam(comp, idx);
    return std::dynamic_pointer_cast<T>(param);
}

}