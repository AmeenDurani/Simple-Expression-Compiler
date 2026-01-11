cmake_minimum_required(VERSION 3.15)
project(SimpleExpressionCompiler VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/lexer.cpp
    src/main.cpp
)

# Executable
add_executable(expr-compiler ${SOURCES})

# Optional: Enable optimization in Release mode
if(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(expr-compiler PRIVATE -O3)
endif()

# Installation rules (optional)
install(TARGETS expr-compiler DESTINATION bin)

# Print build info
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")