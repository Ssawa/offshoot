ExternalProject_Add(
    POCO_PROJECT
    DOWNLOAD_COMMAND ""
    PREFIX ${CMAKE_CURRENT_LIST_DIR}/poco_build
    SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/poco
    CMAKE_ARGS -DPOCO_STATIC=ON -DENABLE_MONGODB=OFF -DENABLE_PDF=OFF -DENABLE_NETSSL=OFF -DENABLE_NETSSL_WIN=OFF -DENABLE_CRYPTO=OFF -DENABLE_DATA=OFF -DENABLE_DATA_SQLITE=OFF -DENABLE_DATA_MYSQL=OFF -DENABLE_DATA_ODBC=OFF -DENABLE_SEVENZIP=OFF -DENABLE_ZIP=OFF -DENABLE_APACHECONNECTOR=OFF -DENABLE_CPPPARSER=OFF -DENABLE_POCODOC=OFF -DENABLE_PAGECOMPILER=OFF -DENABLE_PAGECOMPILER_FILE2PAGE=OFF
)

set( POCO_LIB_DEBUG_PATH ${CMAKE_CURRENT_LIST_DIR}/poco_build/src/POCO_PROJECT-build/lib/Debug/ )
set( POCO_LIB_RELEASE_PATH ${CMAKE_CURRENT_LIST_DIR}/poco_build/src/POCO_PROJECT-build/lib/Release/ )

macro ( LinkPocoLib target libName )
    target_link_libraries( ${target}
        debug ${POCO_LIB_DEBUG_PATH}${CMAKE_STATIC_LIBRARY_PREFIX}${libName}d${CMAKE_STATIC_LIBRARY_SUFFIX}
        optimized ${POCO_LIB_RELEASE_PATH}${CMAKE_STATIC_LIBRARY_PREFIX}${libName}${CMAKE_STATIC_LIBRARY_SUFFIX}
    )
endmacro()

set( POCO_FOUNDATION_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/poco/Foundation/include )
set( POCO_JSON_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/poco/JSON/include )
set( POCO_NET_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/poco/Net/include )
set( POCO_UTIL_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/poco/Util/include )
set( POCO_XML_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/poco/XML/include )

source_group( thirdparty\\poco\\foundation\\ REGULAR_EXPRESSION ${POCO_FOUNDATION_INCLUDE} )
source_group( thirdparty\\poco\\json\\ REGULAR_EXPRESSION ${POCO_JSON_INCLUDE} )
source_group( thirdparty\\poco\\net\\ REGULAR_EXPRESSION ${POCO_NET_INCLUDE} )
source_group( thirdparty\\poco\\util\\ REGULAR_EXPRESSION ${POCO_UTIL_INCLUDE} )
source_group( thirdparty\\poco\\xml\\ REGULAR_EXPRESSION ${POCO_XML_INCLUDE} )

set( POCO ${POCO_FOUNDATION_INCLUDE} ${POCO_JSON_INCLUDE} ${POCO_NET_INCLUDE} ${POCO_UTIL_INCLUDE} ${POCO_XML_INCLUDE} )

include_directories( ${POCO} )