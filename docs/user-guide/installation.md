# Installation

VecPP is a header-only library, so all you need to do is make the contents 
of the `include/` directory available to your compiler.

## CMake

You can use CMake (3.9 or above) to compile the tests and install the library.

On Linux computers:
```bash
mkdir bld
cd bld
cmake -DCMAKE_INSTALL_PREFIX=insert/install/path/here ..
make && ctest && make install
```