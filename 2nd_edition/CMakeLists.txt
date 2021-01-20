cmake_minimum_required (VERSION 3.8)

project ("Computer-Graphics-Using-OpenGL")

include_directories(freeglut-install/include)
link_directories(freeglut-install/lib)

set(CMAKE_MSVCIDE_RUN_PATH freeglut-install/bin)

add_executable (example_2_2 "example_2_2.cpp")
target_link_libraries(example_2_2 freeglut)

add_executable (example_2_2_2 "example_2_2_2.cpp")
target_link_libraries(example_2_2_2 freeglut)
