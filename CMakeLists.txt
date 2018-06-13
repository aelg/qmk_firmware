
project(qmz)
cmake_minimum_required(VERSION 3.11)

file(GLOB_RECURSE SOURCES "*.carrs")
set(SOURCES ${SOURCES} keyboards/ergodox_ez/keymaps/lime/keymap.c)

include_directories(tmk_core/common)
include_directories(quantum)
include_directories(quantum/audio)
include_directories(quantum/process_keycode)
include_directories(keyboards/ergodox_ez)
include_directories(${CMAKE_SOURCE_DIR})

add_compile_options(-include config.h)
add_definitions(-DQMK_KEYBOARD_H=\"ergodox_ez.h\")

add_executable(dummy ${SOURCES})

