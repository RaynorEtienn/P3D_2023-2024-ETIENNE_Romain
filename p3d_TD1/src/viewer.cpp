#include "viewer.h"


#define POSITION_ATTRIB 0
#define COLOR_ATTRIB 1

Viewer::Viewer()
{
}

Viewer::~Viewer()
{
    glDeleteVertexArrays(1,&_vao);
    glDeleteBuffers(2,_vbo);
    glDeleteProgram(_prog);
}

////////////////////////////////////////////////////////////////////////////////
// GL stuff

// initialize OpenGL context
void Viewer::init(int w, int h){
    _winWidth = w;
    _winHeight = h;

    // Couleur d'arrière plan
    glClearColor(0.0, 0.0, 0.0, 0.0);

    loadPrograms();
    createVAO();

    glViewport(0, 0, w, h);
}

void Viewer::reshape(int w, int h){
    _winWidth = w;
    _winHeight = h;
   //TD 1.1

    glViewport(0, 0, w, h);
    //rieng
    //glViewport(w/2, 0, w, h);
    //glViewport(w/2, h/2, w, h);

}


/*!
   callback to draw graphic primitives
 */
void Viewer::display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(_prog);
    glBindVertexArray(_vao);

   //TD 1.2

    //glViewport(0, 0, _winWidth/2, _winHeight);
    glDrawArrays(GL_TRIANGLES, 0, 6);


    //glViewport(_winWidth/2, 0, _winWidth/2, _winHeight);
    //glDrawArrays(GL_TRIANGLES, 0, 3);

   //TD 1.2

   //TD 5.1

   //POINTS
    //glDisable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(25.0);
    //glDrawArrays(GL_POINTS, 0, 3);

   //CONTOURS
    //glDrawArrays(GL_LINE_LOOP, 0, 3);

    glBindVertexArray(0);
    glUseProgram(0);


}


void Viewer::updateScene() 
{
    display();
}

void Viewer::loadPrograms()
{
    GLuint vert;
    GLuint frag;

    const char* vert_shader =
      "\
    #version 330 core\n\
    \n\
    in vec3 vtx_position;\n\
    in vec3 vtx_color;\n\
    out vec3 v_color;\n\
    \n\
    void main(void) { \n\
        v_color = vtx_color;\n\
        gl_Position = vec4(vtx_position, 1.0);\n\
    }\n\
    ";

    const char* frag_shader =
      "\
    #version 330 core\n\
    \n\
    in vec3 v_color;\n\
    out vec4 out_color;\n\
    \n\
    void main(void) { \n\
        out_color = vec4(v_color,1.0);\n\
    }\n\
    ";

    // Création du vertex shader
    vert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert, 1, &vert_shader, 0);
    glCompileShader(vert);

    // Création du fragment shader
    frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag, 1, &frag_shader, 0);
    glCompileShader(frag);

    // Création du programme
    _prog = glCreateProgram();
    glAttachShader(_prog, vert);
    glAttachShader(_prog, frag);

    // Spécification des points d'entrée
    glBindAttribLocation(_prog, POSITION_ATTRIB, "vtx_position");
    glBindAttribLocation(_prog, COLOR_ATTRIB, "vtx_color");

    glLinkProgram(_prog);

    checkError();
}

void Viewer::createVAO(void)
{
    // Question 5.3 => Non.

    GLfloat vert_data[] = {
        -1.0, -1.0, 0.0,
        1.0, -1.0, 0.0,
        1.0, 1.0, 0.0,
        -1.0, -1.0, 0.0,
        1.0, 1.0, 0.0,
        -1.0, 1.0, 0.0

    };

    GLfloat col_data[] = {
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 0.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 1.0, 0.0,
    };


    // Création du VAO et des VBO
    glGenVertexArrays(1, &_vao);
    glGenBuffers(2, _vbo);

    // On "bind" le VAO
    glBindVertexArray(_vao);

    // On active les points d'entrée
    glEnableVertexAttribArray(POSITION_ATTRIB);
    glEnableVertexAttribArray(COLOR_ATTRIB);

    // On active le buffer des sommets
    glBindBuffer(GL_ARRAY_BUFFER, _vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, 6*3*sizeof(GLfloat), vert_data, GL_STATIC_DRAW);
    // On envoie les données
    glVertexAttribPointer(POSITION_ATTRIB, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // On active le buffer des couleurs
    glBindBuffer(GL_ARRAY_BUFFER, _vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, 6*3*sizeof(GLfloat), col_data, GL_STATIC_DRAW);
    glVertexAttribPointer(COLOR_ATTRIB, 3, GL_FLOAT, GL_FALSE, 0, 0);

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
   //TD 1.3
    //R
    if (key == GLFW_KEY_1 && action == GLFW_PRESS) {
        glClearColor(1.0, 0.0, 0.0, 0.0); // Fourth value => Alpha value
    }
    //G
     if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
        glClearColor(0.0, 1.0, 0.0, 0.0);
    }
    //B
    if (key == GLFW_KEY_3 && action == GLFW_PRESS) {
      glClearColor(0.0, 0.0, 1.0, 0.0);
    }
    //Black
    if (key == GLFW_KEY_0 && action == GLFW_PRESS) {
      glClearColor(0.0, 0.0, 0.0, 0.0);
    }

}

void Viewer::charPressed(int key)
{
}
