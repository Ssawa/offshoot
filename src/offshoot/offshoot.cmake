# I know that CMake doesn't like these globs for adding source files,
# understandably, because it makes it impossible for CMake to invalidate
# it's cache. However, I imagine for our context, the bigger fear is somebody
# adding a source code for their own specific project config (xcode, vis studio)
# and pushing their change without updating the CMake file. So this seems like
# the lesser of two evils; if you pull in a change, just remember you might need
# to rerun CMake manually.

file(
    GLOB
    SRC_COMMANDS

    ${CMAKE_CURRENT_LIST_DIR}/commands/*.h
    ${CMAKE_CURRENT_LIST_DIR}/commands/*.cpp
)

source_group( src\\offshoot\\commands FILES ${SRC_COMMANDS} )

set( OFFSHOOT_FILES ${SRC_COMMANDS} )
