#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Shader.h"
#include "MassObject.h"
#include "Physics.h"

std::vector<MassObject> massObjects;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Objects", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 1920, 1080);

    // Test objects for collision test
    float position[2] = {0.0, 0.0};
    float velocity[2] = {-10.0, -10.0};
    float acceleration[2] = {0.0, 0.0};
    Shader shader1("E:/C++/Universe/shaders/test_vertex_shader.vs", "E:/C++/Universe/shaders/test_fragment_shader.fragment");
    MassObject massObject1(10, 50, 1, position, velocity, acceleration, shader1);
    massObject1.initialize_polygon();
    massObjects.push_back(massObject1);

    float position2[2] = {0.0, 0.0};
    float velocity2[2] = {10.0, 10.0};
    float acceleration2[2] = {0.0, 0.0};
    Shader shader2("E:/C++/Universe/shaders/test_vertex_shader.vs", "E:/C++/Universe/shaders/test_fragment_shader.fragment");
    MassObject massObject2(10, 50, 1, position2, velocity2, acceleration2, shader2);
    massObject2.initialize_polygon();
    massObjects.push_back(massObject2);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    massObject1.set_graphical_position(0.5, 0.5);
    massObject2.set_graphical_position(-0.5, -0.5);
    glfwSwapBuffers(window);
    glfwPollEvents();

    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        for (MassObject massObject : massObjects) {
            Physics::set_motion(massObject);
            massObject.set_graphical_position(massObject.get_position()[0], massObject.get_position()[1]);
        }
        if (Physics::collision(massObject1, massObject2)) {
            Physics::on_collide(massObject1, massObject2);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    for (MassObject massObject : massObjects) {
        unsigned int &VAO = massObject.VAO;
        unsigned int &VBO = massObject.VBO;
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}