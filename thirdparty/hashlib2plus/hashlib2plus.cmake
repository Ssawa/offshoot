# You might be wondering why we're including this library when POCO has a perfectly
# good Crypto library. Unfortunatly, POCO's library is dependent on OpenSSL and,
# seeing as we're only potentially interested in the MD5 of a file, this is just
# easier.

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
