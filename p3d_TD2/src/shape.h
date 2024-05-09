#ifndef SHAPE_H
#define SHAPE_H

#include "shader.h"
#include <Eigen/Geometry>

class Shape {
public:
    Shape() : _ready(false) {}
    virtual ~Shape() {}

    virtual void init() = 0;
    virtual void display(Shader *shader) = 0;

    const Eigen::AlignedBox3f& boundingBox() const { return _bbox; }

protected:
    bool _ready;
    Eigen::AlignedBox3f _bbox;
};

#endif // SHAPE_H
