cmake_minimum_required( VERSION 3.0 )

project ( projectGenerator )

include( thirdparty/thirdparty.cmake )
include( internal.cmake )

add_executable( projectGenerator ${INTERNAL} ${THIRDPARTY})
