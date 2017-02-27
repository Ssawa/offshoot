file(
    GLOB
    HASHLIB2PLUS_SRC

    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)

set(HASHLIB2PLUS_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/include)

include_directories( ${HASHLIB2PLUS_INCLUDE} )

source_group( thirdparty\\hashlib2plus\\src FILES ${HASHLIB2PLUS_SRC} )
source_group( thirdparty\\hashlib2plus\\ REGULAR_EXPRESSION ${HASHLIB2PLUS_INCLUDE} )

set(HASHLIB2PLUS ${HASHLIB2PLUS_SRC} ${HASHLIB2PLUS_INCLUDE})
