include( ${CMAKE_CURRENT_LIST_DIR}/src/test_internal.cmake )

add_executable( test_offshoot ${TEST_INTERNAL} ${INTERNAL_NO_MAIN} ${THIRDPARTY} )

add_dependencies( test_offshoot POCO_PROJECT )

LinkPocoLib(test_offshoot PocoFoundation)
LinkPocoLib(test_offshoot PocoJSON)
LinkPocoLib(test_offshoot PocoNet)
LinkPocoLib(test_offshoot PocoUtil)
LinkPocoLib(test_offshoot PocoXML)

target_include_directories( test_offshoot PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src/ )
target_include_directories( test_offshoot PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../src )

# We do something a little different here, compared to the offshoot exe.
# We declare our executable first and then include our testing third parties.
# These third parties are expected to use "target_sources" to add their sources
# to the target and use "target_include_directories" to set the include for this
# target *only* (not "include_directories", which would set it for our main offshoot
# executable as well)
include( ${CMAKE_CURRENT_LIST_DIR}/thirdparty/test_thirdparty.cmake )
