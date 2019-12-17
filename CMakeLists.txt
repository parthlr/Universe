cmake_minimum_required(VERSION 3.15)
project(Universe)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp glad.c Universe.cpp Universe.h Galaxy.cpp Galaxy.h System.cpp System.h MassObject.cpp MassObject.h Physics.cpp Physics.h Shader.cpp Shader.h)

add_executable(Universe ${SOURCE_FILES})
target_link_libraries(Universe -lglfw3 -lopengl32 -lgdi32)