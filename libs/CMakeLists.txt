include_directories (${CMAKE_CURRENT_LIST_DIR})

file (GLOB_RECURSE vector ${CMAKE_CURRENT_LIST_DIR}/data_structures/vector/*.[ch])
file (GLOB_RECURSE vectorVoid ${CMAKE_CURRENT_LIST_DIR}/data_structures/vectorVoid/*.[ch])

set (libraries
        ${vector}
        ${vectorVoid}
)