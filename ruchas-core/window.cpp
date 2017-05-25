//
// Created by david on 25/05/17.
//

#include "window.h"
#include <iostream>

void Window::clear() const
{

    glClearColor(bgcolor.red,bgcolor.green,bgcolor.blue,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(window);
}

void Window::update() const
{
    glfwPollEvents();
}

int Window::shouldClose() const
{
    return glfwWindowShouldClose(window);
}

int main()
{

    if(!glfwInit())
        return -1;
    Window::rgbcolor color(1.0f,0.1f,0.1f);
    Window w(1080,1920,"Hello World",color);
    glfwMakeContextCurrent(w.getGlwindow());
    GLenum error = glewInit();
    if(error != GLEW_OK) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(error));
        std::cout << "Error initializing GLEW" << std::endl;
        return -1;
    }
    while(!w.shouldClose())
    {
        w.update();
        w.clear();
    }
    glfwTerminate();
    return 0;
}