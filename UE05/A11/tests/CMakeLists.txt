project(Tests LANGUAGES C)

add_executable(Tests test.c ../memtools.c)
target_link_libraries(Tests m)
