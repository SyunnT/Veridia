cmake_minimum_required(VERSION 3.25)
project(VeridiaCore
    VERSION 0.1.0
    LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(VERIDIA_EXPORT)

set(API_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/../include")
set(CONF_INCLUDE_DIR "${CMAKE_BINARY_DIR}/conf")

configure_file(
    cmake/Configurations.h.in
    ${CONF_INCLUDE_DIR}/Configurations.h
    @ONLY
)

include_directories(
    ${API_INCLUDE_DIR}
    ${CONF_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}
)

add_library(${PROJECT_NAME} SHARED
    api/api.cpp
    app/app.cpp
)