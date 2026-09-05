#pragma once

// Compatibility wrapper for MSVC.
// This file used to be empty and shadowed the compiler stdint.h.
// Keep libnfc includes working while exposing standard integer limits.

#ifdef _MSC_VER
#include_next <stdint.h>
#else
#include <stdint.h>
#endif
