# Dev guide

This part of the documentation is intended for people who want to contribute to 
VecPP. If you only want to use the library, you cansafely ignore everything in 
here.

## Coding style

`clang-format -style=file` should be a no-op. If some local formatting would be
objectively better (such as inlining a matrix constant), then turning off auto 
formatting is fine:

```
// clang-format off
...
// clang-format on
```
## Includes

With the exception of `vecpp/vecpp.h`, includes are always in 3 sections:

```
#include "vecpp/config.h"

#include "vecpp/..."
#include "vecpp/..."
#include "vecpp/..."

#include <system_header>
#include <system_header>
#include <system_header>
```

Every immediate dependency needs to be included in each dependant file.

## General Guidance

### No macros unless necesary

A good example of this is `vec/operations_per_member.h`. It would be tempting 
to make a `DISPATCH_BINARY()` macro to avoid repetition and prevent typos.

However, such macros tend to confuse debuggers, and make it harder to follow
the process. It also makes it hard to set breakpoints.