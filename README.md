# VecPP

A simple vector math library.

[![build][badge.build]][build]
[![build_win][badge.build_win]][build_win]

[badge.build]: https://travis-ci.org/FrancoisChabot/vecpp.svg?branch=master
[badge.build_win]: https://ci.appveyor.com/api/projects/status/t7tu1jqmc2wptl1c/branch/master?svg=true

[build]: https://travis-ci.org/FrancoisChabot/vecpp
[build_win]: https://ci.appveyor.com/project/FrancoisChabot/vecpp/branch/master

## Design Goals

* C++17
* No undefined behavior
* strict aliasing compliant
* constexpr everything
* Be useful within a 3D simulation engine

## Installation

Vecpp is a header-only library. As such all you need to do is to make the 
contents of the `include` directory avilable to your compiler are include the 
root header like so:

```
#include "vecpp/vecpp.h"
```

### C++17

Vecpp expects your compiler to have the proper options set for C++17 
or above compilation. 

compiler | option
---------|-------
gcc      | -std=c++17
clang    | -std=c++17
MSVC     | /std:c++17

Alternatively, if your project uses CMake 3.9 or above, you can simply use:

```
set(CMAKE_CXX_STANDARD 17)
```

### Single header 

Alternatively, you can simply copy the "include/vecpp/vecpp_single.h" into your
project and use that single freestanding header.

The project maintains an up-to-date version of this header, in sync with the 
`master` in a special `single_header` branch [here](https://github.com/FrancoisChabot/vecpp/tree/single_header)


**Tip:** This can be used to quickly test generated code on [compiler explorer](godbolt.org). For example like [this](https://gcc.godbolt.org/z/m_Gg-c).


**N.B.** The single header file is generated as part of the build process, so if you
are cloning the git repository, it will not be present. You can have to generate
 it yourself like so: (you will need to have python installed)

```bash
cd vecpp/source/dir/location
git submodule init
git submodule iniupdate
mkdir _bld
cd _bld
cmake -DVECPP_BUILD_SINGLE_HEADER=ON ..
make generate_single_include
```

### Namespace

If, for some reason, the vecpp namespace conflicts with another top-level 
namespace or macro in your project, you can override it by defining the 
`VECPP_NAMESPACE` macro before including it.

```
#define VECPP_NAMESPACE vpp
#include "vecpp/vecpp.h"
```

## Documentation

The full documentation matching the current state of the master branch can be 
found [here](https://francoischabot.github.io/vecpp/).

## Acknowledgements

- [glm](https://glm.g-truc.net) Is used as a reference point for most algorithms.
- [cppreference.com](https://cppreference.com) Is used as a reference point for the documentation format