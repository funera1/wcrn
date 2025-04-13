cmake_minimum_required(VERSION 3.15)
project(wcrn LANGUAGES C)

# Set the Rust library name
set(RUST_LIB_NAME wcrn)

# Set the output directory for the compiled library
set(CARGO_TARGET_DIR ${CMAKE_BINARY_DIR}/cargo)

# Add a custom target to build the Rust library
add_custom_target(${RUST_LIB_NAME}_build ALL
    COMMAND cargo build --release --target-dir ${CARGO_TARGET_DIR}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Building Rust library with Cargo"
)

# Specify the path to the compiled Rust library
set(RUST_LIB_PATH ${CARGO_TARGET_DIR}/release/lib${RUST_LIB_NAME}.a)

# Add the Rust library as a target
add_library(${RUST_LIB_NAME} STATIC IMPORTED GLOBAL)
add_dependencies(${RUST_LIB_NAME} ${RUST_LIB_NAME}_build)
set_target_properties(${RUST_LIB_NAME} PROPERTIES
    IMPORTED_LOCATION ${RUST_LIB_PATH}
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/include
)

# Optionally, link the Rust library to a C executable
add_executable(example examples/main.c)
target_link_libraries(example PRIVATE ${RUST_LIB_NAME})