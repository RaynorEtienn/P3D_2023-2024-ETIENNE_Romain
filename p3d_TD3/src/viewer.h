#ifndef VIEWER_H
#define VIEWER_H

#include "opengl.h"
#include "shader.h"
#include "camera.h"
#include "mesh.h"
#include "sphere.h"

#include <iostream>

class Viewer{
public:
    //! Constructor
    Viewer();
    virtual ~Viewer();

    // gl stuff
    void init(int w, int h);
    void display();
    void updateScene();
    void reshape(int w, int h);
    void loadProgram();

    // events
    void mousePressed(GLFWwindow* window, int button, int action);
    void mouseMoved(int x, int y);
    void mouseScroll(double x, double y);
    void keyPressed(int key, int action, int mods);
    void charPressed(int key);

private:
    int _winWidth, _winHeight;

    Camera _cam;
    Shader _prg;
    std::vector<std::string> _prgNames;
    int _currentPrg;
    Mesh _mesh;

    int _textureHandle;

    // Mouse parameters
    Eigen::Vector2f _lastMousePos;
    int _button = -1;
};

#endif
