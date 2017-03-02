file(
    GLOB
    TEST_GOOGLETEST_SRC

    ${CMAKE_CURRENT_LIST_DIR}/googletest/src/*.cc
)
set(TEST_GOOGLETEST_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/googletest/include )

source_group( tests\\thirdparty\\googletest\\src FILES ${TEST_GOOGLETEST_SRC} )
source_group( tests\\thirdparty\\googletest\\ REGULAR_EXPRESSION ${TEST_GOOGLETEST_INCLUDE} )


file(
    GLOB
    TEST_GOOGLEMOCK_SRC

    ${CMAKE_CURRENT_LIST_DIR}/googlemock/src/*.cc
)
set(TEST_GOOGLEMOCK_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/googlemock/include )

source_group( tests\\thirdparty\\googlemock\\src FILES ${TEST_GOOGLEMOCK_SRC} )
source_group( tests\\thirdparty\\googlemock\\ REGULAR_EXPRESSION ${TEST_GOOGLEMOCK_INCLUDE} )

# Google used a few weird includes, so we need to tell the library to look there.
target_include_directories( test_offshoot PUBLIC ${TEST_GOOGLETEST_INCLUDE} ${TEST_GOOGLEMOCK_INCLUDE} ${CMAKE_CURRENT_LIST_DIR}/googletest/ )
target_sources( test_offshoot PUBLIC ${TEST_GOOGLETEST_SRC} ${TEST_GOOGLETEST_INCLUDE} ${TEST_GOOGLEMOCK_SRC} ${TEST_GOOGLEMOCK_INCLUDE} )
