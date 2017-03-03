# I should really make better macros and then use it throughout the entire
# project. But what better place to try out a new macro than the test folder?
macro(add_test_folder relPath)
    file(
        GLOB
        TEST_SRC

        ${CMAKE_CURRENT_LIST_DIR}/${relPath}/*.h
        ${CMAKE_CURRENT_LIST_DIR}/${relPath}/*.cpp

    )
    
    string(REPLACE "/" "\\" groupPath ${relPath})
    source_group( tests\\src\\${groupPath} FILES ${TEST_SRC} )
    LIST(APPEND TEST_INTERNAL ${TEST_SRC})
endmacro()

add_test_folder("/")
add_test_folder("mocks")
add_test_folder("offshoot/commands")
