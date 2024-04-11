cmake_minimum_required(VERSION 3.27)
project(BasicsOfProgrammingCourse C)

set(CMAKE_C_STANDARD 11)

include ("libs/CMakeLists.txt")

set (files
        ${libraries}
        olds_main/lab14.c
        olds_main/lab16.c
        olds_main/lab15.c
        libs/tests/string.c
        libs/tests/string.h
        olds_main/lab17.c
        main.c



)

add_executable (BasicsOfProgrammingCourse ${files}
       )

target_sources (BasicsOfProgrammingCourse PRIVATE ${files})
source_group (TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${files})
