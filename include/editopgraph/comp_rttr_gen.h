#define XSTR(s) STR(s)
#define STR(s) #s

#ifndef PARM_COMP_TYPE
#error "You must define PARM_COMP_TYPE macro before include this file"
#endif

#ifndef PARM_COMP_NAME
#error "You must define PARM_COMP_NAME macro before include this file"
#endif

#ifndef PARM_FILEPATH_PARM
#define PARM_FILEPATH_PARM editopgraph/component/##PARM_COMP_TYPE##.parm.h
#endif

#define RTTR_NAME editopgraph::##PARM_COMP_NAME

 rttr::registration::class_<editopgraph::comp::PARM_COMP_TYPE>(XSTR(RTTR_NAME))
.constructor<>()
#define PARM_FILEPATH XSTR(PARM_FILEPATH_PARM)
#define PARM_NODE_CLASS editopgraph::comp::##PARM_COMP_TYPE
#include <dag/rttr_prop_gen.h>
#undef PARM_FILEPATH
#undef PARM_NODE_CLASS
;

#undef PARM_COMP_NAME
#undef PARM_COMP_TYPE
#undef PARM_FILEPATH_PARM
