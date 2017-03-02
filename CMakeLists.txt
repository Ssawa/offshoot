cmake_minimum_required( VERSION 3.0 )

project ( offshoot )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/ )

include(ExternalProject)

include( thirdparty/thirdparty.cmake )
include( src/internal.cmake )

add_executable( offshoot ${INTERNAL} ${THIRDPARTY})

add_dependencies(offshoot POCO_PROJECT)

LinkPocoLib(offshoot PocoFoundation)
LinkPocoLib(offshoot PocoJSON)
LinkPocoLib(offshoot PocoNet)
LinkPocoLib(offshoot PocoUtil)
LinkPocoLib(offshoot PocoXML)
