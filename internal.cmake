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

    "src/addons/*.h"
    "src/addons/*.cpp"
)

file(
    GLOB
    SRC_PROJECTS

    "src/projects/*.h"
    "src/projects/*.cpp"
)

file(
    GLOB
    SRC_UTILS

    "src/utils/*.h"
    "src/utils/*.cpp"
)

source_group( src\\addons FILES ${SRC_ADDONS} )
source_group( src\\projects FILES ${SRC_PROJECTS} )
source_group( src\\utils FILES ${SRC_UTILS} )
source_group( src FILES src/main.cpp )

set( INTERNAL ${SRC_ADDONS} ${SRC_PROJECTS} ${SRC_UTILS} src/main.cpp )
