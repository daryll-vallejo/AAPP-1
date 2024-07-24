cmake_minimum_required(VERSION 3.6.0)
project(AAPP-1)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS
    "${PROJECT_SOURCE_DIR}/include/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.c"
)

add_executable(AAPP-1 ${SRCS})

# Copy model files to the output directory
file(COPY ${PROJECT_SOURCE_DIR}/model/AAPP-1.dat
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/model/AAPP-normalization-1.dat
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})