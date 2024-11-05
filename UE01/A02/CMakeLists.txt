cmake_minimum_required(VERSION 3.5.0)
project(A02 VERSION 0.1.0 LANGUAGES C)

include(CTest)
add_subdirectory(tests)
enable_testing()

add_executable(A02 main.c printTypes.c)
target_link_libraries(A02 m)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_test(
  NAME Tests
  COMMAND Tests
)