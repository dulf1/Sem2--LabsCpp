#ifndef RUBIK_CUBE_CUBE_H
#define RUBIK_CUBE_CUBE_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stack>
#include <functional>
#include <fstream>
#include <random>

using namespace std;

class Cube {
public:
    int colors[6][9];
    stack<function<void()>> actions;
    stack<int> toCopy;
    bool isReplaying = false;

    Cube();

    void rotateLower();

    void rotateLowerReverse();

    void rotateMiddle();

    void rotateMiddleReverse();

    void rotateUpper();

    void rotateUpperReverse();

    void rotateLowerUp();

    void rotateLowerDown();

    void rotateMiddleUp();

    void rotateMiddleDown();

    void rotateUpperUp();

    void rotateUpperDown();

    void replayActionsInReverse();

    void saveActions(const string &filename, const string &fileN);

    void loadActions(const string &filename, const string &fileN);

    void currStatus();

    void shuffle(int num_moves);

};

extern float angleX, angleY, angleZ;
extern Cube cube;

void drawCube();

void display();

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mod);

#endif //RUBIK_CUBE_CUBE_H