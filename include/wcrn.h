#ifndef RUST_C_API_H
#define RUST_C_API_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Function prototypes for the Rust library
int rust_function(); // Example function
size_t get_stack_size(uint32_t fidx, uint32_t offset);

#ifdef __cplusplus
}
#endif

#endif // RUST_C_API_H