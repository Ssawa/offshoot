cmake_minimum_required( VERSION 3.0 )

project ( projectGenerator )

include( deps.cmake )

include( internal.cmake )

add_executable( projectGenerator ${INTERNAL} ${DEPS})
