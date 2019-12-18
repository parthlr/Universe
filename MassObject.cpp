//
// Created by Parth on 11/13/2019.
//

#include "MassObject.h"
#include <cmath>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"

MassObject::MassObject(float object_mass, float object_radius, float object_elasticity, float (&object_position)[2], float (&object_velocity)[2], float (&object_acceleration)[2], Shader object_shader) : position(object_position), velocity(object_velocity), acceleration(object_acceleration), shader(object_shader) {
    mass = object_mass;
    radius = object_radius;
    elasticity = object_elasticity;
}

float MassObject::get_mass() {
    return mass;
}

float MassObject::get_radius() {
    return radius;
}

float MassObject::get_elasticity() {
    return elasticity;
}

float* MassObject::get_position() {
    return position;
}

void MassObject::set_position(const float *new_position) {
    position[0] = new_position[0];
    position[1] = new_position[1];
}

float* MassObject::get_velocity() {
    return velocity;
}

void MassObject::set_velocity(const float *new_velocity) {
    velocity[0] = new_velocity[0];
    velocity[1] = new_velocity[1];
}

float* MassObject::get_acceleration() {
    return acceleration;
}

void MassObject::set_acceleration(const float *new_acceleration) {
    acceleration[0] = new_acceleration[0];
    acceleration[1] = new_acceleration[1];
}

void MassObject::set_vertices(float x, float y, int triangles, float radius) {
    int numVertices = triangles + 2;
    float vertices[numVertices * 3];
    float angle = 0.0;
    vertices[0] = x;
    vertices[1] = y;
    vertices[2] = 0.0;
    int vertIndex = 3;
    for (int i = 1; i < numVertices; i++) {
        vertices[vertIndex] = radius * cos(angle) / 1920;
        vertices[vertIndex + 1] = radius * sin(angle) / 1080;
        vertices[vertIndex + 2] = 0.0;

        vertIndex += 3;
        angle += (2 * M_PI) / triangles;
    }
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void MassObject::initialize_polygon() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    set_vertices(position[0], position[1], 120, radius);
    glBindVertexArray(VAO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void MassObject::set_graphical_position(float x, float y) {
    float new_position[2] = {x, y};
    set_position(new_position);
    shader.use();
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(x, y, 0.0f));
    shader.setMat4("transform", transform);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 150);
}