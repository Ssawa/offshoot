aux_source_directory( deps/poco/src/Util DEPS_POCO_UTIL_SRC )
aux_source_directory( deps/poco/src/XML DEPS_POCO_XML_SRC )

file(
    GLOB
    DEPS_POCO_DOM_HEADERS
    deps/poco/include/Poco/DOM

    "*.h"
)

file(
    GLOB
    DEPS_POCO_SAX_HEADERS
    deps/poco/include/Poco/SAX

    "*.h"
)

file(
    GLOB
    DEPS_POCO_XML_HEADERS
    deps/poco/include/Poco/XML

    "*.h"
)

file(
    GLOB
    DEPS_POCO_UTIL_HEADERS
    deps/poco/include/Poco/Util

    "*.h"
)

include_directories(deps/poco/include)
set( DEPS_POCO_HEADERS ${DEPS_POCO_DOM_HEADERS} ${DEPS_POCO_SAX_HEADERS} ${DEPS_POCO_XML_HEADERS} ${DEPS_POCO_UTIL_HEADERS} )

source_group( deps\\Poco\\src\\Util FILES ${DEPS_POCO_UTIL_SRC} )
source_group( deps\\Poco\\src\\XML FILES ${DEPS_POCO_XML_SRC} )
source_group( deps\\Poco\\Headers FILES ${DEPS_POCO_HEADERS} )

set( DEPS ${DEPS_POCO_UTIL_SRC} ${DEPS_POCO_XML_SRC} ${DEPS_POCO_HEADERS} )
