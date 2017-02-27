cmake_minimum_required( VERSION 3.0 )

project ( offshoot )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/ )

include( thirdparty/thirdparty.cmake )
include( src/internal.cmake )

add_executable( offshoot ${INTERNAL} ${THIRDPARTY})
