cmake_minimum_required (VERSION 3.1)
project (mian)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)




include_directories($(CMAKE_CURRENT_SOURCE_DIR)/include)
add_executable(main ${SRC})