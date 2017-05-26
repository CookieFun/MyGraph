cmake_minimum_required(VERSION 3.7)
project(MyGraph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp base.cpp base.h drawline.h drawline.cpp scanline.h scanline.cpp)
add_executable(MyGraph ${SOURCE_FILES})

set(OPENGL_FILE C:/freeglut)
INCLUDE_DIRECTORIES(${OPENGL_FILE}/include)
link_directories(${OPENGL_FILE}/lib/x64 "C:/Program Files/mingw-w64/x86_64-5.1.0-win32-seh-rt_v4-rev0/mingw64/lib")
target_link_libraries(MyGraph freeglut glu32 opengl32)
