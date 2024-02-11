add_executable(test_complex test_complex.cpp)
add_executable(test_rational test_rational.cpp)
add_executable(test_dynarr test_dynarr.cpp)
add_executable(test_StackArr test_StackArr.cpp)

target_link_libraries(test_complex complex)
target_link_libraries(test_rational rational)
target_link_libraries(test_dynarr dynarr)
target_link_libraries(test_StackArr StackArr)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_StackArr)


