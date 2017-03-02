file(
    GLOB
    SRC_ADDONS

    ${CMAKE_CURRENT_LIST_DIR}/addons/*.h
    ${CMAKE_CURRENT_LIST_DIR}/addons/*.cpp
)

file(
    GLOB
    SRC_PROJECTS

    ${CMAKE_CURRENT_LIST_DIR}/projects/*.h
    ${CMAKE_CURRENT_LIST_DIR}/projects/*.cpp
)

file(
    GLOB
    SRC_UTILS

    ${CMAKE_CURRENT_LIST_DIR}/utils/*.h
    ${CMAKE_CURRENT_LIST_DIR}/utils/*.cpp
)

source_group( src\\OF\\addons FILES ${SRC_ADDONS} )
source_group( src\\OF\\projects FILES ${SRC_PROJECTS} )
source_group( src\\OF\\utils FILES ${SRC_UTILS} )

set( OF_FILES, ${SRC_ADDONS} ${SRC_PROJECTS} ${SRC_UTILS} )