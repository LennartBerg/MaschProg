cmake_minimum_required(VERSION 3.5.0)
project(A07 VERSION 0.1.0 LANGUAGES C)

include(CTest)
add_subdirectory(tests)
enable_testing()

add_executable(A07 main.c svs_atoi.c)
target_link_libraries(A07 m)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_test(
  NAME Tests
  COMMAND Tests
)