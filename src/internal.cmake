# I know that CMake doesn't like these globs for adding source files,
# understandably, because it makes it impossible for CMake to invalidate
# it's cache. However, I imagine for our context, the bigger fear is somebody
# adding a source code for their own specific project config (xcode, vis studio)
# and pushing their change without updating the CMake file. So this seems like
# the lesser of two evils; if you pull in a change, just remember you might need
# to rerun CMake manually.

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

file(
    GLOB
    SRC_COMMANDS

    ${CMAKE_CURRENT_LIST_DIR}/commands/*.h
    ${CMAKE_CURRENT_LIST_DIR}/commands/*.cpp
)

source_group( src\\addons FILES ${SRC_ADDONS} )
source_group( src\\projects FILES ${SRC_PROJECTS} )
source_group( src\\utils FILES ${SRC_UTILS} )
source_group( src\\commands FILES ${SRC_COMMANDS} )
source_group( src FILES ${CMAKE_CURRENT_LIST_DIR}/main.cpp )

set( INTERNAL ${SRC_COMMANDS} ${CMAKE_CURRENT_LIST_DIR}/main.cpp )
