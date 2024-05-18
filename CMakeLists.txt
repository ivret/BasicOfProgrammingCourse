cmake_minimum_required(VERSION 3.27)
project(BasicsOfProgrammingCourse C)

set(CMAKE_C_STANDARD 11)

include ("libs/CMakeLists.txt")

set (files
        ${libraries}
        olds_main/lab14.c
        olds_main/lab16.c
        olds_main/lab15.c
        libs/data_structures/str/string.c
        libs/data_structures/str/string.h
        olds_main/lab17.c
        olds_main/lab18.c
        libs/data_structures/penultimate_labe/lab_19.c
        libs/data_structures/penultimate_labe/lab_19.h
        main.c
        olds_main/lab18.c
        libs/data_structures/polynom/polynominals.c
        libs/data_structures/polynom/polynominals.h
        libs/data_structures/data/data.c
        libs/data_structures/data/data.h


)

add_executable (BasicsOfProgrammingCourse ${files}
       )

target_sources (BasicsOfProgrammingCourse PRIVATE ${files})
source_group (TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${files})
