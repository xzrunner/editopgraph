#ifndef EXE_FILEPATH
#error "You must define EXE_FILEPATH macro before include this file"
#endif

// io

#define PARM_COMP_TYPE Context
#define PARM_COMP_NAME context
#include EXE_FILEPATH

#define PARM_COMP_TYPE Operation
#define PARM_COMP_NAME operation
#include EXE_FILEPATH

// math

#define PARM_COMP_TYPE Plane
#define PARM_COMP_NAME plane
#include EXE_FILEPATH

#define PARM_COMP_TYPE Ray
#define PARM_COMP_NAME ray
#include EXE_FILEPATH

#define PARM_COMP_TYPE RayPlaneIntersect
#define PARM_COMP_NAME ray_plane_intersect
#include EXE_FILEPATH
