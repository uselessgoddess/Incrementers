cmake_minimum_required(VERSION 3.16)
include("LinksPlatform.cmake")
project(Platform.Incrementers)
initial_linksplatform_engine(Platform.Incrementers)

set(CMAKE_CXX_STANDARD ${LINKS_PLATFORM_CXX_STANDARD})
add_subdirectory(Platform.Incrementers)

include_extension_if_support(Tests)
