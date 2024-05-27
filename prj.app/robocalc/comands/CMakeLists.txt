add_library(comands comands.cpp comands.hpp)
set_property(TARGET comands PROPERTY CXX_STANDARD 20)
target_include_directories(comands PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS comands)