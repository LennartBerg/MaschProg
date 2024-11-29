project(Tests LANGUAGES C)

add_executable(Tests test.c)
target_link_libraries(Tests m)
