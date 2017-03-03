cmake_minimum_required( VERSION 3.1 )

project ( offshoot )

set (CMAKE_CXX_STANDARD 11)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/ )

include(ExternalProject)

include( thirdparty/thirdparty.cmake )

include( src/internal.cmake )
include( tests/tests.cmake )