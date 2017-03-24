cmake_minimum_required(VERSION 2.8)
project(showImage)

find_package(OpenCV 2.4.8 REQUIRED)
message(STATUS "opencv include files : "  ${OpenCV_INCLUDE_DIRS})

add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
