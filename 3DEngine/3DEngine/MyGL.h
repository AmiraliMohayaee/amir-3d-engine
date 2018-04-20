#ifndef MYGL_H
#define MYGL_H

#ifdef WIN32
#include <Windows.h>
//#include <gl/glew.h>
#include "GLEW\Include\glew.h"
#include <gl/GL.h>
#include <gl/glut.h>
#endif

#ifdef MAC
#include <OpenGL/gl.h> 
#endif

#endif