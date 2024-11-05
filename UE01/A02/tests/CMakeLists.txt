project(Tests LANGUAGES C)

add_library(cJSON lib/cJSON/cJSON.c)
add_executable(Tests test.c ../printTypes.c)
target_link_libraries(Tests cJSON m)