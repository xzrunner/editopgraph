#define XSTR(s) STR(s)
#define STR(s) #s

#ifndef PARM_COMP_TYPE
#error "You must define PARM_COMP_TYPE macro before include this file"
#endif

#ifndef PARM_FILEPATH_H
#define PARM_FILEPATH_H editopgraph/component/##PARM_COMP_TYPE##.h
#endif

#include XSTR(PARM_FILEPATH_H)

#undef PARM_COMP_NAME
#undef PARM_COMP_TYPE
#undef PARM_FILEPATH_H
