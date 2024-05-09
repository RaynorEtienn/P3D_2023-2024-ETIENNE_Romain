#ifndef VIEWER_H
#define VIEWER_H

#include "opengl.h"
#include "shader.h"
#include "camera.h"
#include "sphere.h"
#include "cube.h"

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
    void addSphere(const Eigen::Vector3f& position = Eigen::Vector3f(0, 0, 0),
                   const Eigen::Vector3f& color = Eigen::Vector3f(0.0f, 0.0f, 0.0f),
                   float radius = 1.0f); /** Basic Molecule */

    // molecules
    void Benzene();
    void CarbonDioxyde();
    void Methane();
    void Dippers();

private:
    int _winWidth, _winHeight;

    Camera _cam;
    Shader _prg;
    std::vector<std::string> _prgNames;
    int _currentPrg;
    Sphere _sphere;
    Cube _cube;

    // Mine
    std::vector<float> _SphereRadius;
    std::vector<Eigen::Vector3f> _Colors;
    std::vector<Eigen::Vector3f> _Positions;
    int _Selector;

    int _textureHandle;

    // Mouse parameters
    Eigen::Vector2f _lastMousePos;
    int _button = -1;
};

#endif
