CMAKE_MINIMUM_REQUIRED(VERSION 2.7)

project(lab4)

set(CMAKE_C_STANDARD 11)

add_executable(user user.c interface.c api.c list.c)
add_executable(cli cli.c interface.c api.c list.c)

add_library(list_static STATIC list.c)
add_library(api_static STATIC api.c)
add_library(list_dynamic SHARED list.c)
add_library(api_dynamic SHARED api.c)
target_link_libraries(api_dynamic list_dynamic)

add_executable(user_d user.c inteface.c)
target_link_libraries(user_d api_dynamic list_dynamic)

add_executable(cli_s cli.c interface.c)
target_link_libraries(cli_s api_static list_static)