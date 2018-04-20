cmake_minimum_required(VERSION 3.9)
project(battleshipl3info C)

set(CMAKE_C_STANDARD 11)

add_executable(battleshipl3info src/server/main.c src/server/server.c)