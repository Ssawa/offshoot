# I realize that CMake has a very nice "add_subdirectory" command that I'm ignoring
# and we may very well convert to using it as some point, but for now I kind of want
# my variables to be global without having to litter PARENT_SCOPEs all over the place

include( ${CMAKE_CURRENT_LIST_DIR}/OF/OF.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/offshoot/offshoot.cmake )

source_group( src FILES ${CMAKE_CURRENT_LIST_DIR}/main.cpp )

set( INTERNAL_NO_MAIN ${OFFSHOOT_FILES} )
set ( INTERNAL ${INTERNAL_NO_MAIN} ${CMAKE_CURRENT_LIST_DIR}/main.cpp )

add_executable( offshoot ${INTERNAL} ${THIRDPARTY} )

add_dependencies( offshoot POCO_PROJECT )

LinkPocoLib(offshoot PocoFoundation)
LinkPocoLib(offshoot PocoJSON)
LinkPocoLib(offshoot PocoNet)
LinkPocoLib(offshoot PocoUtil)
LinkPocoLib(offshoot PocoXML)
