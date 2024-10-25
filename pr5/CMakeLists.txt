
cmake_minimum_required(VERSION 3.10)
project(ConsoleUtility C)

set(CMAKE_C_STANDARD 99)

add_executable(ConsoleUtility src/main.c src/users.c src/processes.c src/log.c src/error.c)
