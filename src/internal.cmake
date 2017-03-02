include( ${CMAKE_CURRENT_LIST_DIR}/OF/OF.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/offshoot/offshoot.cmake )

source_group( src FILES ${CMAKE_CURRENT_LIST_DIR}/main.cpp )

set( INTERNAL ${OFFSHOOT_FILES} ${CMAKE_CURRENT_LIST_DIR}/main.cpp )
