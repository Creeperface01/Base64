cmake_minimum_required(VERSION 3.7)
project(Base64)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES base64.h base64.c)
add_library(Base64 ${SOURCE_FILES})