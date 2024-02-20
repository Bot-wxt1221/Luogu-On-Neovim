cmake_minimum_required(VERSION 3.15)

# set the project name
project(LuoguCLI)

SET(SRC_LIST main.c command.c user.c problem.c)

add_compile_definitions(MAX_COOKIE_SIZE=100)

string(TIMESTAMP COMPILE_TIME %Y%m%d-%H%M%S)

configure_file(compile.h.in compile.h)

# add the executable
add_executable(${PROJECT_NAME} ${SRC_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           )
