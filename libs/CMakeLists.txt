include_directories (${CMAKE_CURRENT_LIST_DIR})

file (GLOB_RECURSE vector ${CMAKE_CURRENT_LIST_DIR}/data_structures/vector/*.[ch])
file (GLOB_RECURSE vectorVoid ${CMAKE_CURRENT_LIST_DIR}/data_structures/vectorVoid/*.[ch])
file (GLOB_RECURSE array ${CMAKE_CURRENT_LIST_DIR}/data_structures/array/*.[ch])
file (GLOB_RECURSE matrix ${CMAKE_CURRENT_LIST_DIR}/data_structures/matrix/*.[ch])
file (GLOB_RECURSE tests ${CMAKE_CURRENT_LIST_DIR}/data_structures/tests/*.[ch])



set (libraries
        ${vector}
        ${vectorVoid}
        ${array}
        ${matrix}
        ${tests}



)