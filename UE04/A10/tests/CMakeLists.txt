project(Tests LANGUAGES C)

add_executable(Tests test.c ../sample.c ../memtools.c)
target_link_libraries(Tests m)
