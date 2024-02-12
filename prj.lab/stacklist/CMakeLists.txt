add_library(stacklist stacklist.cpp stacklist.hpp)
set_property(TARGET stacklist PROPERTY CXX_STANDARD 20)
target_include_directories(complex PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
target_link_libraries(stacklist complex)
