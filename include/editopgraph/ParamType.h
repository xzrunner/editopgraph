#pragma once

namespace editopgraph
{

enum class ParamType
{
    Port,

    Any,

    Camera,
    Viewport,
    Publisher,  // Subscriber

    ScreenPos,
    Float3,

    Ray,
    Plane,

    Renderer,
};

}