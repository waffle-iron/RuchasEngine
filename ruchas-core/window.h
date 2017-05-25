//
// Created by david on 25/05/17.
//

#ifndef RUCHASENGINE_WINDOW_H
#define RUCHASENGINE_WINDOW_H


#include <cstddef>
#include <cstdint>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
public:
    struct rgbcolor
    {
        GLfloat red;
        GLfloat green;
        GLfloat blue;

        rgbcolor(GLfloat red,GLfloat green,GLfloat blue):red(red),green(green),blue(blue){};
    };
private:
    int width;
    int height;
    const char* title;
    rgbcolor bgcolor;
    GLFWwindow *window;
public:
    Window(int width,int height,const char* title,rgbcolor bgcolor):width(width),height(height),title(title),bgcolor(bgcolor)
    {
#pragma warning
        window = glfwCreateWindow(width,height,title,NULL,NULL);
    };
    ~Window()
    {
        glfwDestroyWindow(window);
    }
    GLFWwindow* getGlwindow() { return window;};
    void clear() const;
    void update() const;
    int shouldClose() const;
};


#endif //RUCHASENGINE_WINDOW_H
