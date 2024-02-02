cmake_minimum_required(VERSION 3.15)

# set the project name
project(LuoguCLI)

SET(SRC_LIST main.c command.c user.c file.c)

add_compile_definitions(MAX_COOKIE_SIZE=100)

# add the executable
add_executable(${PROJECT_NAME} ${SRC_LIST})

