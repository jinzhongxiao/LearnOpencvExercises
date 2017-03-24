cmake_minimum_required(VERSION 2.8)
project(controlVideo)

find_package(OpenCV 2.4.8 REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
