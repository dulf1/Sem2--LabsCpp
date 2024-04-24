#include "cube.h"

float angleX = 0.0;
float angleY = 0.0;
float angleZ = 0.0;
const float rotationSpeed = 15.0;
Cube cube;


Cube::Cube() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            colors[i][j] = i;
        }
    }
}

void Cube::rotateLower() {
    if (!isReplaying) {
        actions.push([this] { rotateLowerReverse(); });
        toCopy.push(4);
    }
    int down[3][3] = {
            {colors[4][0], colors[4][1], colors[4][2]},
            {colors[4][3], colors[4][4], colors[4][5]},
            {colors[4][6], colors[4][7], colors[4][8]}
    };

    colors[4][0] = down[0][2];
    colors[4][1] = down[1][2];
    colors[4][2] = down[2][2];
    colors[4][3] = down[0][1];
    colors[4][4] = down[1][1];
    colors[4][5] = down[2][1];
    colors[4][6] = down[0][0];
    colors[4][7] = down[1][0];
    colors[4][8] = down[2][0];
    int front[3] = {colors[0][0], colors[0][1], colors[0][2]};
    int right[3] = {colors[3][0], colors[3][1], colors[3][2]};
    int back[3] = {colors[1][0], colors[1][1], colors[1][2]};
    int left[3] = {colors[2][0], colors[2][1], colors[2][2]};

    colors[0][0] = right[0];
    colors[0][1] = right[1];
    colors[0][2] = right[2];

    colors[3][0] = back[0];
    colors[3][1] = back[1];
    colors[3][2] = back[2];

    colors[1][0] = left[0];
    colors[1][1] = left[1];
    colors[1][2] = left[2];

    colors[2][0] = front[0];
    colors[2][1] = front[1];
    colors[2][2] = front[2];
}

void Cube::rotateLowerReverse() {
    if (!isReplaying) {
        actions.push([this] { rotateLower(); });
        toCopy.push(1);
    }
    int down[3][3] = {
            {colors[4][0], colors[4][1], colors[4][2]},
            {colors[4][3], colors[4][4], colors[4][5]},
            {colors[4][6], colors[4][7], colors[4][8]}
    };

    colors[4][0] = down[2][0];
    colors[4][1] = down[1][0];
    colors[4][2] = down[0][0];
    colors[4][3] = down[2][1];
    colors[4][4] = down[1][1];
    colors[4][5] = down[0][1];
    colors[4][6] = down[2][2];
    colors[4][7] = down[1][2];
    colors[4][8] = down[0][2];
    int front[3] = {colors[0][0], colors[0][1], colors[0][2]};
    int right[3] = {colors[3][0], colors[3][1], colors[3][2]};
    int back[3] = {colors[1][0], colors[1][1], colors[1][2]};
    int left[3] = {colors[2][0], colors[2][1], colors[2][2]};

    colors[0][0] = left[0];
    colors[0][1] = left[1];
    colors[0][2] = left[2];

    colors[3][0] = front[0];
    colors[3][1] = front[1];
    colors[3][2] = front[2];

    colors[1][0] = right[0];
    colors[1][1] = right[1];
    colors[1][2] = right[2];

    colors[2][0] = back[0];
    colors[2][1] = back[1];
    colors[2][2] = back[2];

}

void Cube::rotateMiddle() {
    if (!isReplaying) {
        actions.push([this] { rotateMiddleReverse(); });
        toCopy.push(5);
    }
    int tempFront[3] = {colors[0][3], colors[0][4], colors[0][5]};
    int tempRight[3] = {colors[3][3], colors[3][4], colors[3][5]};
    int tempBack[3] = {colors[1][3], colors[1][4], colors[1][5]};
    int tempLeft[3] = {colors[2][3], colors[2][4], colors[2][5]};

    colors[0][3] = tempRight[0];
    colors[0][4] = tempRight[1];
    colors[0][5] = tempRight[2];

    colors[3][3] = tempBack[0];
    colors[3][4] = tempBack[1];
    colors[3][5] = tempBack[2];

    colors[1][3] = tempLeft[0];
    colors[1][4] = tempLeft[1];
    colors[1][5] = tempLeft[2];

    colors[2][3] = tempFront[0];
    colors[2][4] = tempFront[1];
    colors[2][5] = tempFront[2];
}

void Cube::rotateMiddleReverse() {
    if (!isReplaying) {
        actions.push([this] { rotateMiddle(); });
        toCopy.push(2);
    }
    int tempFront[3] = {colors[0][3], colors[0][4], colors[0][5]};
    int tempRight[3] = {colors[3][3], colors[3][4], colors[3][5]};
    int tempBack[3] = {colors[1][3], colors[1][4], colors[1][5]};
    int tempLeft[3] = {colors[2][3], colors[2][4], colors[2][5]};

    colors[0][3] = tempLeft[0];
    colors[0][4] = tempLeft[1];
    colors[0][5] = tempLeft[2];

    colors[3][3] = tempFront[0];
    colors[3][4] = tempFront[1];
    colors[3][5] = tempFront[2];

    colors[1][3] = tempRight[0];
    colors[1][4] = tempRight[1];
    colors[1][5] = tempRight[2];

    colors[2][3] = tempBack[0];
    colors[2][4] = tempBack[1];
    colors[2][5] = tempBack[2];
}

void Cube::rotateUpper() {
    if (!isReplaying) {
        actions.push([this] { rotateUpperReverse(); });
        toCopy.push(6);
    }
    int up[3][3] = {
            {colors[5][0], colors[5][1], colors[5][2]},
            {colors[5][3], colors[5][4], colors[5][5]},
            {colors[5][6], colors[5][7], colors[5][8]}
    };

    colors[5][0] = up[0][2];
    colors[5][1] = up[1][2];
    colors[5][2] = up[2][2];
    colors[5][3] = up[0][1];
    colors[5][4] = up[1][1];
    colors[5][5] = up[2][1];
    colors[5][6] = up[0][0];
    colors[5][7] = up[1][0];
    colors[5][8] = up[2][0];
    int front[3] = {colors[0][6], colors[0][7], colors[0][8]};
    int right[3] = {colors[3][6], colors[3][7], colors[3][8]};
    int back[3] = {colors[1][6], colors[1][7], colors[1][8]};
    int left[3] = {colors[2][6], colors[2][7], colors[2][8]};

    colors[0][6] = right[0];
    colors[0][7] = right[1];
    colors[0][8] = right[2];

    colors[3][6] = back[0];
    colors[3][7] = back[1];
    colors[3][8] = back[2];

    colors[1][6] = left[0];
    colors[1][7] = left[1];
    colors[1][8] = left[2];

    colors[2][6] = front[0];
    colors[2][7] = front[1];
    colors[2][8] = front[2];
}

void Cube::rotateUpperReverse() {
    if (!isReplaying) {
        actions.push([this] { rotateUpper(); });
        toCopy.push(3);
    }
    int up[3][3] = {
            {colors[5][0], colors[5][1], colors[5][2]},
            {colors[5][3], colors[5][4], colors[5][5]},
            {colors[5][6], colors[5][7], colors[5][8]}
    };

    colors[5][0] = up[2][0];
    colors[5][1] = up[1][0];
    colors[5][2] = up[0][0];
    colors[5][3] = up[2][1];
    colors[5][4] = up[1][1];
    colors[5][5] = up[0][1];
    colors[5][6] = up[2][2];
    colors[5][7] = up[1][2];
    colors[5][8] = up[0][2];

    int front[3] = {colors[0][6], colors[0][7], colors[0][8]};
    int right[3] = {colors[3][6], colors[3][7], colors[3][8]};
    int back[3] = {colors[1][6], colors[1][7], colors[1][8]};
    int left[3] = {colors[2][6], colors[2][7], colors[2][8]};

    colors[0][6] = left[0];
    colors[0][7] = left[1];
    colors[0][8] = left[2];

    colors[3][6] = front[0];
    colors[3][7] = front[1];
    colors[3][8] = front[2];

    colors[1][6] = right[0];
    colors[1][7] = right[1];
    colors[1][8] = right[2];

    colors[2][6] = back[0];
    colors[2][7] = back[1];
    colors[2][8] = back[2];
}

void Cube::rotateLowerUp() {
    if (!isReplaying) {
        actions.push([this] { rotateLowerDown(); });
        toCopy.push(10);
    }
    int down[3][3] = {
            {colors[2][0], colors[2][1], colors[2][2]},
            {colors[2][3], colors[2][4], colors[2][5]},
            {colors[2][6], colors[2][7], colors[2][8]}
    };

    colors[2][0] = down[0][2];
    colors[2][1] = down[1][2];
    colors[2][2] = down[2][2];
    colors[2][3] = down[0][1];
    colors[2][4] = down[1][1];
    colors[2][5] = down[2][1];
    colors[2][6] = down[0][0];
    colors[2][7] = down[1][0];
    colors[2][8] = down[2][0];
    int temp[3] = {colors[0][0], colors[0][3], colors[0][6]};
    // Вращение столбца вверх
    colors[0][0] = colors[4][0];
    colors[0][3] = colors[4][3];
    colors[0][6] = colors[4][6];

    colors[4][0] = colors[1][0];
    colors[4][3] = colors[1][3];
    colors[4][6] = colors[1][6];

    colors[1][0] = colors[5][0];
    colors[1][3] = colors[5][3];
    colors[1][6] = colors[5][6];

    colors[5][0] = temp[0];
    colors[5][3] = temp[1];
    colors[5][6] = temp[2];
}

void Cube::rotateLowerDown() {
    if (!isReplaying) {
        actions.push([this] { rotateLowerUp(); });
        toCopy.push(7);
    }
    int down[3][3] = {
            {colors[2][0], colors[2][1], colors[2][2]},
            {colors[2][3], colors[2][4], colors[2][5]},
            {colors[2][6], colors[2][7], colors[2][8]}
    };

    colors[2][0] = down[2][0];
    colors[2][1] = down[1][0];
    colors[2][2] = down[0][0];
    colors[2][3] = down[2][1];
    colors[2][4] = down[1][1];
    colors[2][5] = down[0][1];
    colors[2][6] = down[2][2];
    colors[2][7] = down[1][2];
    colors[2][8] = down[0][2];
    int temp[3] = {colors[0][0], colors[0][3], colors[0][6]};
    // Вращение столбца вниз
    colors[0][0] = colors[5][0];
    colors[0][3] = colors[5][3];
    colors[0][6] = colors[5][6];

    colors[5][0] = colors[1][0];
    colors[5][3] = colors[1][3];
    colors[5][6] = colors[1][6];

    colors[1][0] = colors[4][0];
    colors[1][3] = colors[4][3];
    colors[1][6] = colors[4][6];

    colors[4][0] = temp[0];
    colors[4][3] = temp[1];
    colors[4][6] = temp[2];
}

void Cube::rotateMiddleUp() {
    if (!isReplaying) {
        actions.push([this] { rotateMiddleDown(); });
        toCopy.push(11);
    }
    int temp[3] = {colors[0][1], colors[0][4], colors[0][7]};

    colors[0][1] = colors[4][1];
    colors[0][4] = colors[4][4];
    colors[0][7] = colors[4][7];

    colors[4][1] = colors[1][1];
    colors[4][4] = colors[1][4];
    colors[4][7] = colors[1][7];

    colors[1][1] = colors[5][1];
    colors[1][4] = colors[5][4];
    colors[1][7] = colors[5][7];

    colors[5][1] = temp[0];
    colors[5][4] = temp[1];
    colors[5][7] = temp[2];
}

void Cube::rotateMiddleDown() {
    if (!isReplaying) {
        actions.push([this] { rotateMiddleUp(); });
        toCopy.push(8);
    }

    int temp[3] = {colors[0][1], colors[0][4], colors[0][7]};

    colors[0][1] = colors[5][1];
    colors[0][4] = colors[5][4];
    colors[0][7] = colors[5][7];

    colors[5][1] = colors[1][1];
    colors[5][4] = colors[1][4];
    colors[5][7] = colors[1][7];

    colors[1][1] = colors[4][1];
    colors[1][4] = colors[4][4];
    colors[1][7] = colors[4][7];

    colors[4][1] = temp[0];
    colors[4][4] = temp[1];
    colors[4][7] = temp[2];
}

void Cube::rotateUpperUp() {
    if (!isReplaying) {
        actions.push([this] { rotateUpperDown(); });
        toCopy.push(12);
    }
    int up[3][3] = {
            {colors[3][0], colors[3][1], colors[3][2]},
            {colors[3][3], colors[3][4], colors[3][5]},
            {colors[3][6], colors[3][7], colors[3][8]}
    };

    colors[3][0] = up[0][2];
    colors[3][1] = up[1][2];
    colors[3][2] = up[2][2];
    colors[3][3] = up[0][1];
    colors[3][4] = up[1][1];
    colors[3][5] = up[2][1];
    colors[3][6] = up[0][0];
    colors[3][7] = up[1][0];
    colors[3][8] = up[2][0];
    int temp[3] = {colors[0][2], colors[0][5], colors[0][8]};
    // Вращение столбца вверх
    colors[0][2] = colors[4][2];
    colors[0][5] = colors[4][5];
    colors[0][8] = colors[4][8];

    colors[4][2] = colors[1][2];
    colors[4][5] = colors[1][5];
    colors[4][8] = colors[1][8];

    colors[1][2] = colors[5][2];
    colors[1][5] = colors[5][5];
    colors[1][8] = colors[5][8];

    colors[5][2] = temp[0];
    colors[5][5] = temp[1];
    colors[5][8] = temp[2];
}

void Cube::rotateUpperDown() {
    if (!isReplaying) {
        actions.push([this] { rotateUpperUp(); });
        toCopy.push(9);
    }
    int up[3][3] = {
            {colors[3][0], colors[3][1], colors[3][2]},
            {colors[3][3], colors[3][4], colors[3][5]},
            {colors[3][6], colors[3][7], colors[3][8]}
    };

    colors[3][0] = up[2][0];
    colors[3][1] = up[1][0];
    colors[3][2] = up[0][0];
    colors[3][3] = up[2][1];
    colors[3][4] = up[1][1];
    colors[3][5] = up[0][1];
    colors[3][6] = up[2][2];
    colors[3][7] = up[1][2];
    colors[3][8] = up[0][2];
    int temp[3] = {colors[0][2], colors[0][5], colors[0][8]};

    colors[0][2] = colors[5][2];
    colors[0][5] = colors[5][5];
    colors[0][8] = colors[5][8];

    colors[5][2] = colors[1][2];
    colors[5][5] = colors[1][5];
    colors[5][8] = colors[1][8];

    colors[1][2] = colors[4][2];
    colors[1][5] = colors[4][5];
    colors[1][8] = colors[4][8];

    colors[4][2] = temp[0];
    colors[4][5] = temp[1];
    colors[4][8] = temp[2];
}

void Cube::replayActionsInReverse() {
    isReplaying = true;
    double lastTime = glfwGetTime();
    double interval = 0.1;

    while (!actions.empty()) {
        double currentTime = glfwGetTime();
        if (currentTime - lastTime >= interval) {
            actions.top()();
            actions.pop();
            lastTime = currentTime;

            display();
            glfwSwapBuffers(glfwGetCurrentContext());
            glfwPollEvents();
        }
    }
    while (!toCopy.empty()) {
        toCopy.pop();
    }
    isReplaying = false;
}

void Cube::saveActions(const string &filename, const string &fileN) {
    ofstream file(filename, std::ios::out);
    ofstream file2(fileN, std::ios::out);
    if (!file.is_open()) {
        cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    if (!file2.is_open()) {
        cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            file << colors[i][j] << (j < 8 ? " " : "\n");
        }
    }
    while (!toCopy.empty()) {
        file2 << toCopy.top() << " ";
        toCopy.pop();
    }
    file.close();
    file2.close();
}

void Cube::loadActions(const string &filename, const string &fileN) {
    ifstream file(filename, ios::in);
    ifstream file2(fileN, ios::in);
    if (!file.is_open()) {
        cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }
    if (!file2.is_open()) {
        cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            file >> colors[i][j];
        }
    }
    file.close();
    vector<int> temp;
    int line;
    while (file2 >> line) {
        temp.push_back(line);
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        toCopy.push(temp[i]);
        if (temp[i] == 1) {
            actions.push([this] { rotateLower(); });
        } else if (temp[i] == 2) {
            actions.push([this] { rotateMiddle(); });
        } else if (temp[i] == 3) {
            actions.push([this] { rotateUpper(); });
        } else if (temp[i] == 4) {
            actions.push([this] { rotateLowerReverse(); });
        } else if (temp[i] == 5) {
            actions.push([this] { rotateMiddleReverse(); });
        } else if (temp[i] == 6) {
            actions.push([this] { rotateUpperReverse(); });
        } else if (temp[i] == 7) {
            actions.push([this] { rotateLowerUp(); });
        } else if (temp[i] == 8) {
            actions.push([this] { rotateMiddleUp(); });
        } else if (temp[i] == 9) {
            actions.push([this] { rotateUpperUp(); });
        } else if (temp[i] == 10) {
            actions.push([this] { rotateLowerDown(); });
        } else if (temp[i] == 11) {
            actions.push([this] { rotateMiddleDown(); });
        } else if (temp[i] == 12) {
            actions.push([this] { rotateUpperDown(); });
        }
    }
    file2.close();
}

void Cube::currStatus() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cout << colors[i][j] << (j < 8 ? " " : "\n");
        }
    }
    cout << "\n";
}


void drawCube() {
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            switch (cube.colors[i][j]) {
                case 0:
                    glColor3f(1.0, 0.0, 0.0);
                    break; // Red
                case 1:
                    glColor3f(0.0, 1.0, 0.0);
                    break; // Green
                case 2:
                    glColor3f(0.0, 0.0, 1.0);
                    break; // Blue
                case 3:
                    glColor3f(1.0, 1.0, 0.0);
                    break; // Yellow
                case 4:
                    glColor3f(1.0, 0.0, 1.0);
                    break; // Magenta
                case 5:
                    glColor3f(0.0, 1.0, 1.0);
                    break; // Cyan
            }
            int row = j / 3;
            int col = j % 3;
            float x = col * 0.3333 - 0.5;
            float y = row * 0.3333 - 0.5;
            float z = 0.5;
            if (i == 0) {
                glVertex3f(x, y, -z);
                glVertex3f(x + 0.3333, y, -z);
                glVertex3f(x + 0.3333, y + 0.3333, -z);
                glVertex3f(x, y + 0.3333, -z);
            } else if (i == 1) {
                glVertex3f(x, y, z);
                glVertex3f(x + 0.3333, y, z);
                glVertex3f(x + 0.3333, y + 0.3333, z);
                glVertex3f(x, y + 0.3333, z);
            } else if (i == 2) {
                glVertex3f(-z, y, x);
                glVertex3f(-z, y, x + 0.3333);
                glVertex3f(-z, y + 0.3333, x + 0.3333);
                glVertex3f(-z, y + 0.3333, x);
            } else if (i == 3) {
                glVertex3f(z, y, x);
                glVertex3f(z, y, x + 0.3333);
                glVertex3f(z, y + 0.3333, x + 0.3333);
                glVertex3f(z, y + 0.3333, x);
            } else if (i == 4) {
                glVertex3f(x, -z, y);
                glVertex3f(x + 0.3333, -z, y);
                glVertex3f(x + 0.3333, -z, y + 0.3333);
                glVertex3f(x, -z, y + 0.3333);
            } else if (i == 5) {
                glVertex3f(x, z, y);
                glVertex3f(x + 0.3333, z, y);
                glVertex3f(x + 0.3333, z, y + 0.3333);
                glVertex3f(x, z, y + 0.3333);
            }
        }
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    glRotatef(angleZ, 0.0, 0.0, 1.0);
    drawCube();
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS or action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_UP:
                angleX += rotationSpeed;
                break;
            case GLFW_KEY_DOWN:
                angleX -= rotationSpeed;
                break;
            case GLFW_KEY_LEFT:
                angleY -= rotationSpeed;
                break;
            case GLFW_KEY_RIGHT:
                angleY += rotationSpeed;
                break;
            case GLFW_KEY_1:
                cube.rotateLower();
                break;
            case GLFW_KEY_2:
                cube.rotateMiddle();
                break;
            case GLFW_KEY_3:
                cube.rotateUpper();
                break;
            case GLFW_KEY_4:
                cube.rotateLowerUp();
                break;
            case GLFW_KEY_5:
                cube.rotateMiddleUp();
                break;
            case GLFW_KEY_6:
                cube.rotateUpperUp();
                break;
            case GLFW_KEY_7:
                cube.rotateLowerDown();
                break;
            case GLFW_KEY_8:
                cube.rotateMiddleDown();
                break;
            case GLFW_KEY_9:
                cube.rotateUpperDown();
                break;
            case GLFW_KEY_Q:
                cube.rotateLowerReverse();
                break;
            case GLFW_KEY_W:
                cube.rotateMiddleReverse();
                break;
            case GLFW_KEY_E:
                cube.rotateUpperReverse();
                break;
            case GLFW_KEY_ENTER:
                cube.replayActionsInReverse();
                break;
            case GLFW_KEY_S:
                cube.saveActions("cube_state.txt", "status.txt");
                break;
            case GLFW_KEY_L:
                cube.loadActions("cube_state.txt", "status.txt");
                break;
            case GLFW_KEY_X:
                cube.currStatus();
                break;
        }
    }
}

void Cube::shuffle(int num_moves) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 12);

    for (int i = 0; i < num_moves; ++i) {
        int move = dis(gen);
        switch (move) {
            case 1:
                rotateLower();
                break;
            case 2:
                rotateMiddle();
                break;
            case 3:
                rotateUpper();
                break;
            case 4:
                rotateLowerReverse();
                break;
            case 5:
                rotateMiddleReverse();
                break;
            case 6:
                rotateUpperReverse();
                break;
            case 7:
                rotateLowerUp();
                break;
            case 8:
                rotateMiddleUp();
                break;
            case 9:
                rotateUpperUp();
                break;
            case 10:
                rotateLowerDown();
                break;
            case 11:
                rotateMiddleDown();
                break;
            case 12:
                rotateUpperDown();
                break;
            default:
                break;
        }
    }
}
