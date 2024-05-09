#include "viewer.h"
#include "camera.h"

#include "SOIL2.h"

extern int WIDTH;
extern int HEIGHT;

using namespace Eigen;

Viewer::Viewer()
{
    _currentPrg = 0;
    _prgNames.push_back("simple");
}

Viewer::~Viewer()
{
}

////////////////////////////////////////////////////////////////////////////////
// GL stuff

// initialize OpenGL context
void Viewer::init(int w, int h){
    _winWidth = w;
    _winHeight = h;

    // Couleur d'arrière plan
    glClearColor(0.0, 0.0, 0.0, 0.0);

    loadProgram();
    _mesh.load(DATA_DIR"/models/lemming.off");
    _mesh.init();

    _cam.setSceneCenter(_mesh.boundingBox().center());
    _cam.setSceneRadius(_mesh.boundingBox().sizes().maxCoeff());
    _cam.setSceneDistance(_cam.sceneRadius() * 3.f);
    _cam.setMinNear(0.1f);
    _cam.setNearFarOffsets(-_cam.sceneRadius() * 100.f,
                            _cam.sceneRadius() * 100.f);
    _cam.setScreenViewport(AlignedBox2f(Vector2f(0.0,0.0), Vector2f(w,h)));

    glViewport(0, 0, w, h);
    glEnable(GL_DEPTH_TEST);
}

void Viewer::reshape(int w, int h){
    _winWidth = w;
    _winHeight = h;
    _cam.setScreenViewport(AlignedBox2f(Vector2f(0.0,0.0), Vector2f(w,h)));
    glViewport(0, 0, w, h);
}


/*!
   callback to draw graphic primitives
 */
void Viewer::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _prg.activate();

    glUniformMatrix4fv(_prg.getUniformLocation("projection_matrix"), 1, GL_FALSE, _cam.computeProjectionMatrix().data());
    glUniformMatrix4fv(_prg.getUniformLocation("view_matrix"), 1, GL_FALSE, _cam.computeViewMatrix().data());
    glUniformMatrix4fv(_prg.getUniformLocation("model_matrix"),1,GL_FALSE,_mesh.getTransformationMatrix().data());

    _mesh.display(&_prg);

    _prg.deactivate();
}


void Viewer::updateScene()
{
    display();
}

void Viewer::loadProgram()
{
    _prg.loadFromFiles(DATA_DIR"/shaders/" + _prgNames[_currentPrg] +".vert",
                       DATA_DIR"/shaders/" + _prgNames[_currentPrg] + ".frag");
    checkError();
}

////////////////////////////////////////////////////////////////////////////////
// Events

/*!
   callback to manage mouse : called when user press or release mouse button
   You can change in this function the way the user
   interact with the system.
 */
void Viewer::mousePressed(GLFWwindow *window, int button, int action)
{
    if(action == GLFW_PRESS) {
        if(button == GLFW_MOUSE_BUTTON_LEFT)
        {
            _cam.startRotation(_lastMousePos);
        }
        else if(button == GLFW_MOUSE_BUTTON_RIGHT)
        {
            _cam.startTranslation(_lastMousePos);
        }
        _button = button;
    }else if(action == GLFW_RELEASE) {
        if(_button == GLFW_MOUSE_BUTTON_LEFT)
        {
            _cam.endRotation();
        }
        else if(_button == GLFW_MOUSE_BUTTON_RIGHT)
        {
            _cam.endTranslation();
        }
        _button = -1;
    }
}


/*!
   callback to manage mouse : called when user move mouse with button pressed
   You can change in this function the way the user
   interact with the system.
 */
void Viewer::mouseMoved(int x, int y)
{
    if(_button == GLFW_MOUSE_BUTTON_LEFT)
    {
        _cam.dragRotate(Vector2f(x,y));
    }
    else if(_button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        _cam.dragTranslate(Vector2f(x,y));
    }
    _lastMousePos = Vector2f(x,y);
}

void Viewer::mouseScroll(double x, double y)
{
    _cam.zoom((y>0)? 1.1: 1./1.1);
}

/*!
   callback to manage keyboard interactions
   You can change in this function the way the user
   interact with the system.
 */
void Viewer::keyPressed(int key, int action, int mods)
{
    if(key == GLFW_KEY_R && action == GLFW_PRESS)
        loadProgram();
    else if (key == GLFW_KEY_UP && action == GLFW_PRESS){
        _currentPrg = (_currentPrg-1);
        if(_currentPrg<0)
            _currentPrg += _prgNames.size();
        loadProgram();
    } else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS){
        _currentPrg = (_currentPrg+1)%_prgNames.size();
        loadProgram();
    }
}

void Viewer::charPressed(int key)
{
}
