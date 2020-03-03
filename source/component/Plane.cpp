#include "editopgraph/component/Plane.h"
#include "editopgraph/ParamImpl.h"

#include <SM_Plane.h>

namespace editopgraph
{
namespace comp
{

void Plane::Execute(const std::shared_ptr<dag::Context>& ctx)
{
    m_vals.resize(1, nullptr);

    sm::Plane plane(m_normal, m_dist);
    m_vals[0] = std::make_shared<PlaneParam>(plane);
}

}
}