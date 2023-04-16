#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../include/library.h"

Memoizor<long long int, int> memoizedFib(nullptr);

long long int fib(int n) {
    if (n <= 1) return n;
    return memoizedFib(n-1) + memoizedFib(n-2);
}

TEST_CASE("Memoizor computes correct results", "[Memoizor]") {
Memoizor<long long int, int> memoizedFib(fib);

REQUIRE(memoizedFib(0) == 0);
REQUIRE(memoizedFib(1) == 1);
REQUIRE(memoizedFib(2) == 1);
REQUIRE(memoizedFib(3) == 2);
REQUIRE(memoizedFib(4) == 3);
REQUIRE(memoizedFib(5) == 5);
}

TEST_CASE("Memoizor is faster than non-memoized function", "[Memoizor]") {
Memoizor<long long int, int> memoizedFib(fib);

auto start = std::chrono::high_resolution_clock::now();
fib(40);
auto end = std::chrono::high_resolution_clock::now();
auto nonMemoizedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

start = std::chrono::high_resolution_clock::now();
memoizedFib(40);
end = std::chrono::high_resolution_clock::now();
auto memoizedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

REQUIRE(memoizedTime < nonMemoizedTime);
}

TEST_CASE("Memoizor computes correct results for large inputs", "[Memoizor]") {
    Memoizor<long long int, int> memoizedFib(fib);


    REQUIRE(memoizedFib(50) == 12586269025);
    REQUIRE(memoizedFib(60) == 1548008755920);
    REQUIRE(memoizedFib(70) == 190392490709135);
}

TEST_CASE("Memoizor returns the same result for the same input", "[Memoizor]") {
    Memoizor<long long int, int> memoizedFib(fib);

    int result1 = memoizedFib(10);
    int result2 = memoizedFib(10);

    REQUIRE(result1 == result2);
}
Memoizor<int, int> memoizedFactorial(nullptr);
TEST_CASE("Memoizor works with different functions", "[Memoizor]") {
    auto factorial = [](int n) {
        if (n == 0) return 1;
        return n * memoizedFactorial(n - 1);
    };
    Memoizor<int, int> memoizedFactorial(factorial);

    REQUIRE(memoizedFactorial(0) == 1);
    REQUIRE(memoizedFactorial(1) == 1);
    REQUIRE(memoizedFactorial(2) == 2);
    REQUIRE(memoizedFactorial(3) == 6);
    REQUIRE(memoizedFactorial(4) == 24);
    REQUIRE(memoizedFactorial(5) == 120);
}