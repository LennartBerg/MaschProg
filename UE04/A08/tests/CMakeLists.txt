project(Tests LANGUAGES C)

add_executable(Tests test.c ../ll.c)
target_link_libraries(Tests m)
