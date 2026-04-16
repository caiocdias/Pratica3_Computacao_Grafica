cmake_minimum_required(VERSION 4.1)
project(Pratica3_Computacao_Grafica)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(Pratica3_Computacao_Grafica main.cpp)

target_link_libraries(Pratica3_Computacao_Grafica PRIVATE
        OpenGL::GL
        OpenGL::GLU
        GLUT::GLUT
)