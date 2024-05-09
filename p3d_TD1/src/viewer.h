#ifndef VIEWER_H
#define VIEWER_H

#include "opengl.h"

#include <iostream>

class Viewer
{
 public:
   //! Constructor
   Viewer();
   virtual ~Viewer();
   
   // gl stuff
   void init(int w, int h);
   void display();
   void updateScene();
   void reshape(int w, int h);
   void createVAO();
   void loadPrograms();
   
   // events
   void mousePressed(GLFWwindow* window, int button, int action);
   void mouseMoved(int x, int y);
   void mouseScroll(double x, double y);
   void keyPressed(int key, int action, int mods);
   void charPressed(int key);
   
 private:
   int _winWidth, _winHeight;

   GLuint _vao;
   GLuint _vbo[2];
   GLuint _prog;
};

#endif
