# vecpp

Vecpp is a simple vector math library.

vecpp has three main design goals:

* C++17
* No undefined behavior
* strict aliasing compliant
* constexpr everything
* Be useful within a 3D simulation engine

## What about GLM?

GLM is an amazing library, and currently, odds are pretty good that it's going to be a better match than vecpp for whatever you are trying to do. That being said...

### GLM is made complicated due to backwards-compatibility

By forcing users to use C++17 or more recent, the number of ways the library can be compiled is drastically reduced.

### GLM relies on undefined behavior a lot

GLM is stable on all major compilers, but it is not formally valid C++. This ranges from fairly minor things (using unions to perform type punning) to some major hacks (swizzling is crafty, but pure evil).
