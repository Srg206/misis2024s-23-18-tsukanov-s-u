add_executable(test_complex test_complex.cpp)
add_executable(test_rational test_rational.cpp)
add_executable(test_dynarr test_dynarr.cpp)
add_executable(test_stackarr test_stackarr.cpp)
add_executable(test_stacklist test_stacklist.cpp)
add_executable(test_queuelist test_queuelist.cpp)



target_link_libraries(test_complex complex)
target_link_libraries(test_rational rational)
target_link_libraries(test_dynarr dynarr)
target_link_libraries(test_stackarr stackarr)
target_link_libraries(test_stacklist stacklist)
target_link_libraries(test_queuelist queuelist)


set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_queuelist)


