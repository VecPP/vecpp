# Installation

VecPP is a header-only library, so all you need to do is make the contents 
of the `include/` directory available to your compiler.

## CMake

You can use CMake (3.9 or above) to compile the tests and install the library.

Option                    | What                                          | Requirements
--------------------------|-----------------------------------------------|-----
VECPP_BUILD_SINGLE_HEADER | build `vecpp_single.h`                        | `python` and git submodules fetched
VECPP_BUILD_DOCS          | builds the html version of the documentation  | [mkdocs](https://www.mkdocs.org/)
VECPP_BUILD_TESTS         | builds the unit tests                         |

On Linux:
```bash
mkdir bld
cd bld
cmake -DVECPP_BUILD_SINGLE_HEADER=ON -DCMAKE_INSTALL_PREFIX=insert/install/path/here ..
make && make install
```