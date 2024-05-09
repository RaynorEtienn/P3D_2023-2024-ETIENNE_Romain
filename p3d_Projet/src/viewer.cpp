#include "viewer.h"
#include "camera.h"

#include "SOIL2.h"

extern int WIDTH;
extern int HEIGHT;

using namespace Eigen;

void Viewer::CarbonDioxyde() {
    _Colors.clear();
    _SphereRadius.clear();
    _Positions.clear();

    glClearColor(0.4, 0.4, 0.8, 1.0);

    addSphere(Eigen::Vector3f(0.0, 0.0, 0.0), Eigen::Vector3f(0.0f, 0.0f, 0.0f), 1.0f); // Carbon
    addSphere(Eigen::Vector3f(-1.5104, 0.0, 0.0), Eigen::Vector3f(1.0f, 0.0f, 0.0f), 0.9481f); // Left Oxygen
    addSphere(Eigen::Vector3f(1.5104, 0.0, 0.0), Eigen::Vector3f(1.0f, 0.0f, 0.0f), 0.9481f); // Right Oxygen
}

void Viewer::Methane() {
    _Colors.clear();
    _SphereRadius.clear();
    _Positions.clear();

    glClearColor(0.4, 0.4, 0.8, 1.0);

    addSphere(Eigen::Vector3f(0.0, 0.0, 0.0), Eigen::Vector3f(0.0f, 0.0f, 0.0f), 1.0f); // Carbon
    addSphere(Eigen::Vector3f(0.818, 0.818, 0.818), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.6883f); // Hydrogen 1
    addSphere(Eigen::Vector3f(0.818, -0.818, -0.818), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.6883f); // Hydrogen 2
    addSphere(Eigen::Vector3f(-0.818, 0.818, -0.818), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.6883f); // Hydrogen 3
    addSphere(Eigen::Vector3f(-0.818, -0.818, 0.818), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.6883f); // Hydrogen 4
}

void Viewer::Benzene() {
    _Colors.clear();
    _SphereRadius.clear();
    _Positions.clear();

    glClearColor(0.4, 0.4, 0.8, 1.0);

    addSphere(Eigen::Vector3f(1.4*cos(M_PI/6.f), 1.4*sin(M_PI/6.f), 0), Eigen::Vector3f(0.0f, 0.0f, 0.0f), 0.77f); // Carbon 1
    addSphere(Eigen::Vector3f(1.4*cos(3*M_PI/6.f), 1.4*sin(3*M_PI/6.f), 0), Eigen::Vector3f(0.0f, 0.0f, 0.0f), 0.77f); // Carbon 2
    addSphere(Eigen::Vector3f(1.4*cos(5*M_PI/6.f), 1.4*sin(5*M_PI/6.f), 0), Eigen::Vector3f(0.0f, 0.0f, 0.0f), 0.77f); // Carbon 3
    addSphere(Eigen::Vector3f(1.4*cos(7*M_PI/6.f), 1.4*sin(7*M_PI/6.f), 0), Eigen::Vector3f(0.0f, 0.0f, 0.0f), 0.77f); // Carbon 4
    addSphere(Eigen::Vector3f(1.4*cos(9*M_PI/6.f), 1.4*sin(9*M_PI/6.f), 0), Eigen::Vector3f(0.0f, 0.0f, 0.0f), 0.77f); // Carbon 5
    addSphere(Eigen::Vector3f(1.4*cos(11*M_PI/6.f), 1.4*sin(11*M_PI/6.f), 0), Eigen::Vector3f(0.0f, 0.0f, 0.0f), 0.77f); // Carbon 6

    addSphere(Eigen::Vector3f(2.49*cos(M_PI/6.f), 2.49*sin(M_PI/6.f), 0), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.53f); // Hydrogen 1
    addSphere(Eigen::Vector3f(2.49*cos(3*M_PI/6.f), 2.49*sin(3*M_PI/6.f), 0), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.53f); // Hydrogen 2
    addSphere(Eigen::Vector3f(2.49*cos(5*M_PI/6.f), 2.49*sin(5*M_PI/6.f), 0), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.53f); // Hydrogen 3
    addSphere(Eigen::Vector3f(2.49*cos(7*M_PI/6.f), 2.49*sin(7*M_PI/6.f), 0), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.53f); // Hydrogen 4
    addSphere(Eigen::Vector3f(2.49*cos(9*M_PI/6.f), 2.49*sin(9*M_PI/6.f), 0), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.53f); // Hydrogen 5
    addSphere(Eigen::Vector3f(2.49*cos(11*M_PI/6.f), 2.49*sin(11*M_PI/6.f), 0), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.53f); // Hydrogen 6
}

void Viewer::Dippers() {
    _Colors.clear();
    _SphereRadius.clear();
    _Positions.clear();

    glClearColor(0.157, 0.11, 0.235, 1.0);

    // Drawing the Petite Ourse (Small Dipper)
    addSphere(Eigen::Vector3f(-3.0f, 15.0f, 0.0f), Eigen::Vector3f(1.0f, 0.0f, 0.0f), 0.3f); // Polaris
    addSphere(Eigen::Vector3f(-6.0f, 13.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // ?
    addSphere(Eigen::Vector3f(-8.0f, 9.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // Epsilon
    addSphere(Eigen::Vector3f(-7.0f, 6.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // Zeta
    addSphere(Eigen::Vector3f(-9.0f, 5.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // Eta
    addSphere(Eigen::Vector3f(-7.0f, 1.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // ?
    addSphere(Eigen::Vector3f(-5.0f, 2.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // ?

    // Drawing the Grande Ourse (Big Dipper)
    addSphere(Eigen::Vector3f(7.0f, 3.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // Duhbe
    addSphere(Eigen::Vector3f(11.0f, -1.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // Merak
    addSphere(Eigen::Vector3f(7.0f, -6.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // Pheeda
    addSphere(Eigen::Vector3f(3.0f, -4.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // ?
    addSphere(Eigen::Vector3f(-1.0f, -7.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // ?
    addSphere(Eigen::Vector3f(-4.0f, -8.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // ?
    addSphere(Eigen::Vector3f(-7.0f, -12.0f, 0.0f), Eigen::Vector3f(1.0f, 1.0f, 1.0f), 0.3f); // Alkaid
}

Viewer::Viewer():_sphere(1.f, 40, 40)
{
    _currentPrg = 0;
    _prgNames.push_back("simple");
    _prgNames.push_back("complicated");
}

Viewer::~Viewer()
{
}

////////////////////////////////////////////////////////////////////////////////
// GL stuff

// initialize OpenGL context
void Viewer::init(int w, int h)
{
    _winWidth = w;
    _winHeight = h;

    // Couleur d'arrière plan
    glClearColor(0.4, 0.4, 0.8, 1.0); // Copied from subject

    loadProgram();
    _sphere.init();
    _cube.init();
    _Selector = 0;

    _cam.setSceneCenter(_sphere.boundingBox().center());
    _cam.setSceneRadius(_sphere.boundingBox().sizes().maxCoeff());
    _cam.setSceneDistance(_cam.sceneRadius() * 5.f);
    _cam.setMinNear(0.1f);
    _cam.setNearFarOffsets(-_cam.sceneRadius() * 100.f,
                            _cam.sceneRadius() * 100.f);
    _cam.setScreenViewport(AlignedBox2f(Vector2f(0.0, 0.0), Vector2f(w, h)));

    glViewport(0, 0, w, h);
    glEnable(GL_DEPTH_TEST);
}

void Viewer::reshape(int w, int h){
    _winWidth = w;
    _winHeight = h;
    _cam.setScreenViewport(AlignedBox2f(Vector2f(0.0, 0.0), Vector2f(w, h)));
    glViewport(0, 0, w, h);
}


/*!
   callback to draw graphic primitives
 */
void Viewer::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _prg.activate();

    if(_Selector <= 0)
    {
        CarbonDioxyde();
    }
    else if (_Selector == 1)
    {
        Methane();
    }
    else if (_Selector == 2)
    {
        Benzene();
    }
    else if (_Selector >= 3)
    {
        Dippers();
    }

    for (size_t i = 0; i < _Positions.size(); i++)
    {
        Eigen::Vector3f& C = _Colors[i];
        Eigen::Vector3f& P = _Positions[i];
        float& R = _SphereRadius[i];

        glUniform3f(_prg.getUniformLocation("color_vector"), C(0), C(1), C(2)); // Vecteur couleur
        glUniformMatrix4fv(_prg.getUniformLocation("projection_matrix"), 1, GL_FALSE, _cam.computeProjectionMatrix().data()); // Matrice projection
        glUniformMatrix4fv(_prg.getUniformLocation("view_matrix"), 1, GL_FALSE, _cam.computeViewMatrix().data()); // Matrice vue

        Matrix3f NM = (_cam.computeViewMatrix().matrix() * _cube.getTransformationMatrix().matrix()).topLeftCorner<3,3>();
        (NM.inverse()).transpose();

        glUniformMatrix3fv(_prg.getUniformLocation("normal_matrix"), 1, GL_FALSE, NM.data()); // Matrice normale
        glUniform1f(_prg.getUniformLocation("radius"), R); // Rayon sphere
        glUniform3fv(_prg.getUniformLocation("sphere_center"), 1, P.data()); // Vecteur centre sphere

        Matrix4f MM = Affine3f(Translation3f(Vector3f(P(0), P(1), P(2)))).matrix() * _cube.getTransformationMatrix().matrix() * Affine3f(Scaling(R)).matrix();
        glUniformMatrix4fv(_prg.getUniformLocation("model_matrix"), 1, GL_FALSE, MM.data()); // Matrice model

        _cube.display(&_prg);
    }

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

void Viewer::addSphere(const Eigen::Vector3f& position, const Eigen::Vector3f& color, float radius)
{
    _Positions.push_back(position);
    _Colors.push_back(color);
    _SphereRadius.push_back(radius);
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
    } else if (key == GLFW_KEY_E && action == GLFW_PRESS){
        _Selector < 3 ? _Selector += 1: 0;
    } else if (key == GLFW_KEY_D && action == GLFW_PRESS){
        _Selector > 0 ? _Selector -= 1 : 0;
    }
}

void Viewer::charPressed(int key)
{
}
