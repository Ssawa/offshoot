set(TCLAP_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/include)

include_directories( ${TCLAP_INCLUDE} )

source_group( thirdparty\\tclap\\ REGULAR_EXPRESSION ${TCLAP_INCLUDE} )

# Adding INCLUDE not because it's going to be compiled (they're all headers, obviously,
# but just so that they appear in the workspace that's generated)
set(TCLAP ${TCLAP_INCLUDE})