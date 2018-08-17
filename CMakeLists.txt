
cmake_minimum_required (VERSION 3.12)
project(fooGame)

include_directories("${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")

file(GLOB SRCS
  "${PROJECT_SOURCE_DIR}/src/*.?pp"
  "${PROJECT_SOURCE_DIR}/src/App/*.?pp"
  "${PROJECT_SOURCE_DIR}/src/Area/*.?pp"
)

set(IMG_FOLDER "${PROJECT_SOURCE_DIR}/data/img" CACHE PATH "image location")
#
# configure_file (
#    "${PROJECT_SOURCE_DIR}/fooGame.hpp.in"
#    "${PROJECT_BINARY_DIR}/fooGame.hpp"
# )

add_executable(fooGame ${SRCS})
target_link_libraries(fooGame sfml-graphics sfml-system sfml-window)
configure_file("${PROJECT_SOURCE_DIR}/src/Common.hpp.in" "${PROJECT_BINARY_DIR}/Common.hpp")
