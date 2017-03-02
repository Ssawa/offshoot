file(
    GLOB
    TEST_SRC

    ${CMAKE_CURRENT_LIST_DIR}/*.h
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)

source_group( tests\\src\\ FILES ${TEST_SRC} )

set( TEST_INTERNAL ${TEST_SRC} )
