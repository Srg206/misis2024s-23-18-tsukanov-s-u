add_library(stacklstt INTERFACE stacklstt.hpp)
##target_include_directories(stacklstt PUBLIC
##  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
##  $<INSTALL_INTERFACE:include>
##)
target_compile_features(stacklstt INTERFACE cxx_std_20)
