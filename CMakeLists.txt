cmake_minimum_required(VERSION 3.27)
project(pSim)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(pSim
        main.cpp
        src/Particle.cpp
        src/Particle.h)

install(TARGETS pSim DESTINATION bin)


target_link_libraries(pSim ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_link_libraries(pSim glut)
