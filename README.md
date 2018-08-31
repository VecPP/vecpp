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
* No reliance on undefined behavior
* constexpr everything
* Be useful within a 3D simulation engine
* Stable results under fast-math
* No external non-stl dependencies
* Code is easy to follow and straightforward
* No multiple ways to achieve the same thing

## Quick Start

### Installation

Vecpp is a header-only library. As such, all you need to do is make the 
contents of the `include` directory avilable to your compiler

### Vectors

```cpp
#include "vecpp/vecpp.h"
#include <iosteam>

using Vec3 = vecpp::Vec<float, 3>;

int main() {
  Vec3 ux = {1.0f, 0.0f, 0.0f};
  Vec3 uy = {0.0f, 1.0f, 0.0f};

  std::cout << "ux x uy :" << cross(x, y) << "\n";
  std::cout << "ux . uy :" << dot(x, y) << "\n";
}
```

## Installation

Vecpp is a header-only library. As such, all you need to do is make the 
contents of the `include` directory avilable to your compiler and include the 
root header like so:

```
#include "vecpp/vecpp.h"
```

### Single header 

Alternatively, you can simply copy "include/vecpp/vecpp_single.h" into your
project and use that single freestanding header.

The project maintains an up-to-date version of this header, in sync with the 
`master` branch n a special `single_header` branch 
[here](https://github.com/FrancoisChabot/vecpp/tree/single_header)

**Tip:** This can be used to quickly test generated code on 
[compiler explorer](godbolt.org). For example like 
[this](https://gcc.godbolt.org/z/m_Gg-c).

**N.B.** The single header file is generated as part of the build process, so if 
you are cloning the git repository, it will not be present. You can generate it 
yourself like so: (you will need to have python installed)

```bash
cd vecpp/source/dir/location
git submodule update --init
mkdir _bld
cd _bld
cmake -DVECPP_BUILD_SINGLE_HEADER=ON ..
make generate_single_include
```

### Namespace

If, for some reason, the vecpp namespace conflicts with another top-level 
namespace or macro in your project, you can override it by defining the 
`VECPP_NAMESPACE` macro before including it.

```cpp
#define VECPP_NAMESPACE vpp
#include "vecpp/vecpp.h"
```

## Documentation

The full documentation matching the current state of the master branch can be 
found [here](https://francoischabot.github.io/vecpp/).

### Rebuilding documention

The documentation (in the docs/ diectory) should be legible in plain text. You 
can also generate the formatted version using [mkdocs](insert_link)
(v1.0 or above).

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
- GLSL basically cannot be reimplemented without relying on undefined behavior. 
- Supporting C++ accross the spectrum of versions adds a lot of complexity.
- There are many ways to compile the library which leads to an inconsistent and 
  confusing API.
- The type system cannot be leveraged to its full potential (scalars must be
  scalar values for example).

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

### What's with `vecpp::ct()`?

Some functions need to have different implementations between runtime and 
compile-time evaluation (sqrt() for example), and unfortunately, there
is currently no known way to achieve that implicitely in C++17.  
`ct()` is our workaround.

The rule of thumb is: Write code as if everything magically worked.

```cpp
using Vec3 = vecpp::Vec<float, 3>;
constexpr Vec3 val = {1.0f, 1.0f 1.0f};
constexpr Vec3 val_len = length(val);
```

And if you see an error that looks like: 

> call to non-constexpr function ‘float vecpp::sqrt_impl(float)’

Then you can fix it by wrapping the offending operand with `ct()`:

```cpp
constexpr Vec3 val_len = length(ct(val));
```