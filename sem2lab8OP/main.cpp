#include "cube.h"

int main(int argc, char **argv) {
    if (!glfwInit()) {
        cout << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(800, 800, "Rubik's Cube Example", NULL, NULL);
    if (!window) {
        cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);
    cube.shuffle(100);
    if (glewInit() != GLEW_OK) {
        cout << "Failed to initialize GLEW\n";
        glfwTerminate();
        return -1;
    }
    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
