cmake_minimum_required(VERSION 4.2)

project(OpenMPTutorial)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)

find_package(OpenMP REQUIRED)

target_link_libraries(app
    PRIVATE
        OpenMP::OpenMP_CXX
)