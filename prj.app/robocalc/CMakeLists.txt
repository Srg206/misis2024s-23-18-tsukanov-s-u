add_subdirectory(comands)

add_library(robocalc robocalc.cpp robocalc.hpp)
add_executable(robocalc_app robocalc_app.cpp)

target_link_libraries(robocalc comands)
target_link_libraries(robocalc_app robocalc)