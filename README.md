# VecPP

A simple vector math library.

[![build][badge.build]][build]
[![build_win][badge.build_win]][build_win]
[![CircleCI](https://circleci.com/gh/FrancoisChabot/vecpp.svg?style=svg)](https://circleci.com/gh/FrancoisChabot/vecpp)

[badge.build]: https://travis-ci.org/FrancoisChabot/vecpp.svg?branch=master
[badge.build_win]: https://ci.appveyor.com/api/projects/status/t7tu1jqmc2wptl1c/branch/master?svg=true

[build]: https://travis-ci.org/FrancoisChabot/vecpp
[build_win]: https://ci.appveyor.com/project/FrancoisChabot/vecpp/branch/master

## Current State

In agressive initial development. The main types for the first release are in place, and the next step is implementing functionallities as needed on them, **This is not production ready** by any stretch of the imagination at the moment.

## Design Goals

* Strict adherance to C++ standard (no UB or strict aliasing violation)
* No multiple ways to achieve the same thing
* No external non-stl dependencies
* constexpr everything 
* Code is easy to follow and straightforward

## Documentation

The full documentation can be found in the `/docs` directory (either in markdown
or HTML depending on how you obtained the library).

An HTML version matching the current state of the master branch can always be 
found [here](https://francoischabot.github.io/vecpp/).

## Quick Start

### Prerequisites

All you need is a standard compliant C++17 compiler. The library is sytematically tested on the following compilers, but that does not
mean that earlier versions will not work.

Compiler | Version
---------|--------
GCC      | 7.3.0
clang    | 6.0.0
MSVC     | 14.15.26726

### Installation

#### include
VecPP is a header-only library. As such, all you need to do is make the 
contents of the `include` directory available to your compiler.

#### single-include
Alternatively, you can simply copy "vecpp_single.h" into your project and use 
that single freestanding header. (if you are cloning the raw source, you will
need to generate it using `-DVECPP_BUILD_SINGLE_HEADER`).

**Tip:** We maintain a copy of this file in sync with the master branch 
[here](https://github.com/FrancoisChabot/vecpp/tree/single_header). This can be 
used to quickly test generated code on [compiler explorer](godbolt.org). For 
example: like [this](https://gcc.godbolt.org/z/m_Gg-c).

#### CMake
Finally, while the cmake project is primarily used to manage tests and 
deployment, it's still set up as a proper target-exporting project. So you can 
use either `add_subdirectory(path/to/vecpp_source)` or `find_package(VecPP)` and
use `target_link_libraries(my_target VecPP::VecPP)`.

### Usage

#### Vectors

Vectors are declared using the `Vec<TYPE, SIZE>` template (preferably aliased).

Individual vector members are accessed through the `vec[index]` operator. There 
is no `.x`, `.y`, `.z` etc... members. This is because VecPP avoids redundancy 
in its interface as much as possible (see the design goals). 

```cpp
#include "vecpp/vecpp.h"
#include <iosteam>

using Vec3 = vecpp::Vec<float, 3>;
static_assert(sizeof(Vec3) == 3 * sizeof(float)); // guaranteed!

int main() {
  Vec3 ux = {1.0f, 0.0f, 0.0f};
  Vec3 uy = {0.0f, 1.0f, 0.0f};

  std::cout << "ux.x: " << ux[0] << "\n";

  std::cout << "ux x uy :" << cross(x, y) << "\n";
  std::cout << "ux . uy :" << dot(x, y) << "\n";
}
```

#### Angles

VecPP angles are strongly-typed, and correctly handle wraparounds and 
conversions under the hood.

```cpp
#include "vecpp/vecpp.h"

using Angle = vecpp::Angle<float>;
using vecpp::pi;

int main() {
  Angle a = Angle::from_rad(pi<float>);
  Angle b = Angle::from_deg(20.0f);

  Angle c = a + b; // is now holding -160deg
  Angle d = c - Angle::from_deg(160.0f); // contains 40deg

  float sin_val = sin(c);

  std::cout << "sin(" << c << ") = " << sin(c) << "\n";
  // prints: "sin(-160°) = -0.34202"
}
```

#### Matrices

```cpp
#include "vecpp/vecpp.h"

using Mat = vecpp::Matrix<float, 3, 3>;
using Vec = vecpp::Vec<float, 3>;


int main() {
  Vec a = {1.0f, 0.0f, 0.0f};
  Mat m = {
    1.0f, 0.0f, 0.0f,
    1.0f, 1.0f, 1.0f,
    0.0f, 1.0f , 0.0f
  };
  
  Vec b = m * a;
  std::cout << b << "\n";

}
```

## Acknowledgements

- [glm](https://glm.g-truc.net) is used as a reference point for many algorithms.
- [cppreference.com](https://cppreference.com) is used as a reference point for the documentation format.

## FAQS

### Why use this over GLM?

GLM is an amazing library, and right now, probably a better fit for your needs.

That being said, glm has a few drawbacks that stem from its design goals that 
vecpp aims to remedy.

- Closely following GLSL creates many layers of abstraction between the interface
  and implentation.
- Supporting C++ accross the spectrum of versions adds a lot of complexity.
- There are many ways to compile the library which leads to an inconsistent and 
  confusing API.
- The type system cannot be leveraged to its full potential (scalars must be
  scalar values for example).
- The current implementation relies on Undefined Behavior

### Why use this over eigen?

Eigen is another amazing library with a wide variety of uses.

In short: Eigen is a massive library that supports a very wide variety of usage 
patterns. If your needs are more specifically in line with what vecpp provide
you will find it to be a lot more straightforward to navigate. Less is more.

### Why does vecpp not provide aliases for commonly used templates?

Writing `vecpp::Vec<float, 3>` over and over again is annoying, verbose, and 
frankly makes code harder to read, but we think that the same goes for 
`vecpp::Vec3`. What we really want when writing linear algebra code, is to just 
use `Vec3`.

So, we expect that users will be aliasing their commonly used types within their 
project's namespace (or the global namespace, we don't judge). In that context, 
all `vecpp::Vec3` or `vecpp::Mat4` would provide is an unnecessary layer of 
indirection between our aliases and our underlying types.

Also, creating these aliases would force us to take positions on matters such as 
"should the default scalar type be `float` or `double`?", which we would rather 
avoid.

So a typical project making use of VecPP would likely have a header that looks
a lot like this:

```cpp
// vecmath.h
#include "vecpp/vecpp.h"

namespace my_ns {
  using Angle = vecpp::Angle<float>;
  using Vec3 = vecpp::Vec<float, 3>;
  using Mat4 = vecpp::Mat<float, 4, 4>;
  using Quat = vecpp::Quat<float>;
}
```

### constexpr code is broken!

Some functions need to have different implementations between runtime and 
compile-time evaluation (sqrt() for example), and unfortunately, there
is currently no known way to achieve that implicitely in C++17. Vecpp
employs a workaround in the form of the `ct()` (for compile-time) function/

The rule of thumb is: Write code as if everything magically works.

```cpp
using Vec3 = vecpp::Vec<float, 3>;
constexpr Vec3 val = {1.0f, 1.0f 1.0f};
constexpr Vec3 val_len = norm(val);
```

And if you see an error that looks like: 

> call to non-constexpr function ‘float vecpp::non_cste::sqrt(float)’

Then you can fix it by wrapping the offending operand with `ct()`:

```cpp
constexpr Vec3 val_len = norm(ct(val));
```

**N.B.** Only use `ct()` in `constexpr`s! Its usage triggers the use of slower
algorithms that are fine during compilation, but unsuitable for runtime.
