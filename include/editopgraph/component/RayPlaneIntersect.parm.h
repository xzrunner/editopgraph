#ifndef PARAM_INFO
#error "You must define PARAM_INFO macro before include this file"
#endif

PARAM_INFO(Normal, sm::vec3, normal, m_normal, (0, 1, 0))
PARAM_INFO(Distance, float, dist, m_dist, (0))