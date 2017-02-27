cmake_minimum_required( VERSION 3.1 )

project ( projectGenerator )

file(
    GLOB_RECURSE
    projectGenerator_SRC
    ./src
    "*.h"
    "*.cpp"
)

add_executable( projectGenerator ${projectGenerator_SRC} )