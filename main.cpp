#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include "Shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void draw_triangle_fan(float x, float y, float z, int width, int height, int triangles, float radius, unsigned int VBO);

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "LearnOpenGL", NULL, NULL);
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

    Shader circle1Shader("E:/C++/Universe/shaders/test_vertex_shader.vs", "E:/C++/Universe/shaders/test_fragment_shader.fragment");
    Shader circle2Shader("E:/C++/Universe/shaders/test_vertex_shader.vs", "E:/C++/Universe/shaders/test_fragment_shader.fragment");

    int width, height;
    glfwGetWindowSize(window, &width, &height);

    unsigned int VBO, circle1VAO;
    glGenVertexArrays(1, &circle1VAO);
    glGenBuffers(1, &VBO);
    draw_triangle_fan(0.0, 0.0, 0.0, width, height, 120, 50, VBO);
    glBindVertexArray(circle1VAO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    unsigned int circle2VAO;
    glGenVertexArrays(1, &circle2VAO);
    glBindVertexArray(circle2VAO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    float xPos = 0.0f;
    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        circle1Shader.use();
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(xPos, 0.0f, 0.0f));
        circle1Shader.setMat4("transform", transform);

        glBindVertexArray(circle1VAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 150);

        circle2Shader.use();
        glm::mat4 transform2 = glm::mat4(1.0f);
        transform2 = glm::translate(transform2, glm::vec3(-xPos, 0.0f, 0.0f));
        circle2Shader.setMat4("transform", transform2);

        glBindVertexArray(circle2VAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 150);

        glfwSwapBuffers(window);
        glfwPollEvents();
        xPos += 0.001f;
    }
    glDeleteVertexArrays(1, &circle1VAO);
    glDeleteVertexArrays(1, &circle2VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}

void draw_triangle_fan(float x, float y, float z, int width, int height, int triangles, float radius, unsigned int VBO) {
    int numVertices = triangles + 2;
    float vertices[numVertices * 3];
    float angle = 0.0;
    vertices[0] = x;
    vertices[1] = y;
    vertices[2] = z;
    int vertIndex = 3;
    for (int i = 1; i < numVertices; i++) {
        vertices[vertIndex] = radius * cos(angle) / width;
        vertices[vertIndex + 1] = radius * sin(angle) / height;
        vertices[vertIndex + 2] = 0.0;

        vertIndex += 3;
        angle += (2 * M_PI) / triangles;
    }
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}