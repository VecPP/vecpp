# Performance

This document details how to get the maximum oomph out of VecPP.

## Principles

### The compiler is smart

By and large, VecPP relies on the compiler as much as possible. In fact, VecPP
intentionally avoids using simd intrinsincs and assembly as much as possible, and
lets the compiler figure things out for itself.

## Compiler flags

### SIMD

Make sure you tell your compiler to use simd instructions. `-mavx` and the like 
will help a lot.

### Stack Protection

`-fstack-protector-strong` can hurt VecPP performance a lot. Also, it is enabled 
by default on Ubuntu systems.

## Align structures

When combined with SIMD, this has a major performance impact.

```
struct My_vec_traits : public vecpp::Vec_Traits {
  enum {
    align = 32,
  };
};

using Vec4 = vecpp::Vec<float, 4, My_vec_traits>;
```

### constexpr as much as possible.

For anything that is known at compile-time, `constexpr` will make a big 
difference (even over `const`).

```
constexpr Vec3 x = cross(up, right);
```

### Only use ct() to address constexpr compilation failures. 

`ct()` is not a "go fast" flag. It's a "compiler-friendly" flag.