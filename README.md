# Memoizor

Memoizor is a C++ library that provides a simple and easy-to-use interface for memoizing functions.

## Features

- Header-only library: no need to build or link against a library file
- Easy to use: just include the `library.h` header file and create a `Memoizor` object
- Works with any function: can memoize any function that can be passed to a `std::function` object

## Usage

To use the `Memoizor` library in your C++ project, simply include the `library.h` header file and create a `Memoizor` object for the function you want to memoize:

```cpp
#include "library.h"
#include "iostream"

Memoizor<long long int, int> memoizedFactorial(nullptr);

long long int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * memoizedFactorial(n - 1);
    }
}

int main() {
    int n;
    std::cin >> n;
    memoizedFactorial = Memoizor<long long int, int>(factorial);
    long long int result = memoizedFactorial(n);
    std::cout << result << std::endl;
}
```
The `Memoizor` class template takes two template parameters: the return type of the function and the types of its arguments. In the example above, we create a `Memoizor<int, int>` object to memoize the `fib` function, which takes an `int` argument and returns an `int`.

Once you have created a `Memoizor` object for your function, you can call it just like you would call the original function. The Memoizor object will automatically cache the results of previous calls to the function and return the cached result if the function is called again with the same arguments.

Building and Testing
The `Memoizor` library is a header-only library, so there is no need to build it. However, if you want to run the unit tests for the library, you can do so using CMake.

First, make sure that Catch2 is installed on your system. You can install it using a package manager or by building it from source.

Next, create a build directory and navigate to it:

```
mkdir build
cd build
```
Then, run CMake to generate the build files:

```
cmake ..
```
Finally, run CTest to build and run the tests:

```
ctest
```

If all tests pass, you should see output similar to this:

```
Test project /path/to/memoizor/build
Start 1: test_memoizor
1/1 Test #1: test_memoizor ....................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.01 sec
```
## License
The `Memoizor` library is licensed under the MIT License. See the LICENSE file for more information.


