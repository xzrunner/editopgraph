#include "editopgraph/EditOpGraph.h"

namespace editopgraph
{

CU_SINGLETON_DEFINITION(EditOpGraph);

extern void regist_rttr();

EditOpGraph::EditOpGraph()
{
	regist_rttr();
}

}