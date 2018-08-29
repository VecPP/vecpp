# vecpp

A simple vector math library.

[![build][badge.build]][build]
[![build_win][badge.build_win]][build_win]

[badge.build]: https://travis-ci.org/FrancoisChabot/vecpp.svg?branch=master
[badge.build_win]: https://ci.appveyor.com/api/projects/status/t7tu1jqmc2wptl1c/branch/master?svg=true

[build]: https://travis-ci.org/FrancoisChabot/vecpp
[build_win]: https://ci.appveyor.com/project/FrancoisChabot/vecpp/branch/master

VecPP has three main design goals:

* C++17
* No undefined behavior
* strict aliasing compliant
* constexpr everything
* Be useful within a 3D simulation engine

## Documentation

The full documentation matching the current state of the master branch can be found 
[here](https://francoischabot.github.io/vecpp/).

## What about GLM?

GLM is an amazing library, and currently, odds are pretty good that it's going to be a better match than vecpp for whatever you are trying to do. That being said...

### GLM is made complicated due to backwards-compatibility

By forcing users to use C++17 or more recent, the number of ways the library can be compiled is drastically reduced.

### GLM relies on undefined behavior a lot

GLM is stable on all major compilers, but it is not formally valid C++. This ranges from fairly minor things (using unions to perform type punning) to some major hacks (swizzling is crafty, but pure evil).
