#include "viewer.h"
#include <Eigen/Eigen>
#include "cube.h"
#include "camera.h"


using namespace Eigen;

Viewer::Viewer()
:_scale(1.f)
{
    _currentPrg = 0;
    _prgNames.push_back("simple");
}

Viewer::~Viewer()
{
    glDeleteVertexArrays(1,&_vao);
    glDeleteBuffers(3,_vbo);
}

////////////////////////////////////////////////////////////////////////////////
// GL stuff

// initialize OpenGL context
void Viewer::init(int w, int h){
    _winWidth = w;
    _winHeight = h;

    // Use cube as member
    Cube m_cube;
    m_cube.init();

    // Couleur d'arrière plan
    glClearColor(0.0, 0.0, 0.0, 0.0);

    loadPrograms();
    createVAO();

    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, w, h);
}

void Viewer::reshape(int w, int h){
    _winWidth = w;
    _winHeight = h;
    glViewport(0, 0, w, h);
}


/*!
   callback to draw graphic primitives
 */
void Viewer::display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    _prg.activate();
    glBindVertexArray(_vao);

    //Affine3f M = Affine3f(Scaling(0.5f));   // => Affine3f M = Affine3f(Scaling(0.5f));
    Matrix4f Camera_Matrix = Camera::perspective(60.f, float(_winWidth)/float(_winHeight), 0.001f, 20.f);

    // Combinaison de transformations
    Affine3f M, A, R1, R2;
    Vector3f p(0.f, 0.f, -3.f);

    A = Affine3f(Scaling(_scale));
    R1 = AngleAxisf(0.25*M_PI, Vector3f::UnitZ());
    R2 = AngleAxisf(0.25*M_PI, Vector3f::UnitY());

    M = A;


    GLint loc = _prg.getUniformLocation("model_matrix");
    glUniformMatrix4fv(loc, 1, GL_FALSE, M.matrix().data()); 

    GLint loc_proj = _prg.getUniformLocation("projection_matrix");
    glUniformMatrix4fv(loc_proj, 1, GL_FALSE, Camera_Matrix.data());

    m_cube.display(&_prg);

    //glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    _prg.deactivate();
}


void Viewer::updateScene() 
{
    display();
}

void Viewer::loadPrograms()
{
    _prg.loadFromFiles(DATA_DIR"/shaders/" + _prgNames[_currentPrg] +".vert",
                       DATA_DIR"/shaders/" + _prgNames[_currentPrg] + ".frag");     // .vert => gl_Position = model_matrix * vec4(vtx_position, 2.0);
    checkError();
}

void Viewer::createVAO(void)
{
    GLfloat vert_data[] = {
        -1.0, -1.0, 0.0,
        1.0, -1.0, 0.0,
        1.0, 1.0, 0.0,
        -1.0, 1.0, 0.0,
    };

    GLuint indices[] = {
        1, 2, 0, 3
    };

    GLfloat col_data[] = {
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 1.0, 0.0,
    };

    // Création du VAO et des VBO
    glGenVertexArrays(1, &_vao);
    glGenBuffers(3, _vbo);

    // On "bind" le VAO
    glBindVertexArray(_vao);

    int positionAttribID = _prg.getAttribLocation("vtx_position");
    int colorAttribID = _prg.getAttribLocation("vtx_color");

    // On active les points d'entrée
    glEnableVertexAttribArray(positionAttribID);
    glEnableVertexAttribArray(colorAttribID);

    // On active le buffer des sommets
    glBindBuffer(GL_ARRAY_BUFFER, _vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, 4*3*sizeof(GLfloat), vert_data, GL_STATIC_DRAW);
    // On envoie les données
    glVertexAttribPointer(positionAttribID, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // On active le buffer des couleurs
    glBindBuffer(GL_ARRAY_BUFFER, _vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, 4*3*sizeof(GLfloat), col_data, GL_STATIC_DRAW);
    glVertexAttribPointer(colorAttribID, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _vbo[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4*sizeof(GLuint), indices,  GL_STATIC_DRAW);

    // On "unbind" le VAO, tout ceci est enregistré
    glBindVertexArray(0);

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
}

 
/*!
   callback to manage mouse : called when user move mouse with button pressed
   You can change in this function the way the user 
   interact with the system.
 */
void Viewer::mouseMoved(int x, int y)
{
}

void Viewer::mouseScroll(double x, double y)
{
}


/*!
   callback to manage keyboard interactions
   You can change in this function the way the user 
   interact with the system.
 */
void Viewer::keyPressed(int key, int action, int mods)
{
    switch(key){
    case GLFW_KEY_1:
    {
        glClearColor(1.0, 0.0, 0.0, 0.0);
        break;
    }
    case GLFW_KEY_2:
    {
        glClearColor(0.0, 1.0, 0.0, 0.0);
        break;
    }
    case GLFW_KEY_3:
    {
        glClearColor(0.0, 0.0, 1.0, 0.0);
        break;
    }
    case GLFW_KEY_0:
    {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        break;
    }
    case GLFW_KEY_A:
    {
        _scale*=0.75;
        break;
    }
    case GLFW_KEY_Z:
    {
        _scale/=0.75;
        break;
    }
    // Question 2.3
    case GLFW_KEY_R:{
        loadPrograms();
    }
    default:
        break;
    }
}

void Viewer::charPressed(int key)
{
}
