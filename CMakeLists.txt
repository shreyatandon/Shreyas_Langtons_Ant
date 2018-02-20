cmake_minimum_required(VERSION 3.0)
find_package(OpenCV REQUIRED)
add_executable(MAIN main.cpp)
target_link_libraries(MAIN ${OpenCV_LIBS})