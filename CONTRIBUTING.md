# Contributing to VecPP

## How can I contribute?

### Reporting Bugs

#### Before submitting a bug report

* **Do a quick search** through the open bugs to see if this is not already present
and still open.

#### How to write a great bug

The single best thing you can do is provide a test case that exhibits the bug.
The test case should be written in a way that can justy be dropped within VecPP's
testing framework. You can find tons of examples in the `tests/` directory.

For example:
```cpp
TEST("Vector->Scalar modulo operator doesn't work") {
  using Vec = vecpp::Vec3<int, 3>;

  REQUIRE(Vec{1,2,3} % 3 == Vec{1, 2, 0});
}
```

We understand that this is not always possible, we just ask for a best effort 
here.

### Requesting features

VecPP is still a very young library, we more than welcome suggestions on how to
improve it.

### Submitting pull requests

Feel free to send pull requests in our direction! Here's a checklist to increase
your chance of us integrating your change:

- Must haves:
  - `clang-format -i -style=file` should be a no-op for your changed source files
  - A clear description of what the change does.
  - Every CI test passes.
- Must have if it makes sense:
  - A reference to the issue your change addresses. (We might ask you to file
    a matching issue if it makes sense.)
  - Unit tests that would have failed prior to the change, and pass now
