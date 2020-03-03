#define EXE_FILEPATH "editopgraph/comp_include_gen.h"
#include "editopgraph/comp_regist_cfg.h"
#undef EXE_FILEPATH

#include <rttr/registration>

RTTR_REGISTRATION
{

// base

rttr::registration::class_<dag::Node<editopgraph::ParamType>::Port>("editopgraph::Component::Port")
	.property("var", &dag::Node<editopgraph::ParamType>::Port::var)
;

rttr::registration::class_<editopgraph::Component>("editopgraph::Component")
	.method("GetImports", &editopgraph::Component::GetImports)
	.method("GetExports", &editopgraph::Component::GetExports)
;

#define EXE_FILEPATH "editopgraph/comp_rttr_gen.h"
#include "editopgraph/comp_regist_cfg.h"
#undef EXE_FILEPATH

}

namespace editopgraph
{

void regist_rttr()
{
}

}