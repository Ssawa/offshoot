set(PUGIXML_SRC ${CMAKE_CURRENT_LIST_DIR}/src/pugixml.cpp)

set(PUGIXML_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/include)

include_directories( ${PUGIXML_INCLUDE} )

source_group( thirdparty\\pugixml\\src FILES ${PUGIXML_SRC} )
source_group( thirdparty\\pugixml\\ REGULAR_EXPRESSION ${PUGIXML_INCLUDE} )

set(PUGIXML ${PUGIXML_SRC} ${PUGIXML_INCLUDE})