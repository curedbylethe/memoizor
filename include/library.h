#ifndef MEMOIZOR_LIBRARY_H
#define MEMOIZOR_LIBRARY_H

#include <functional>
#include <unordered_map>
#include "tuple"

namespace std {
    template<>
    struct hash<std::tuple<int>> {
        size_t operator()(const std::tuple<int>& key) const {
            return std::hash<int>()(std::get<0>(key));
        }
    };
}

// Memoizor is a class template that takes a function and returns a new function
// that caches the results of the original function for given arguments.
template<typename ReturnType, typename... Args>
class Memoizor {
public:
    // Constructor takes a function to memoize.
    Memoizor(std::function<ReturnType(Args...)> func) : func(func) {}

    // Overloaded function call operator that takes the same arguments as the original function.
    // If the result for the given arguments is already cached, it returns the cached result.
    // Otherwise, it calls the original function, caches the result, and returns it.
    ReturnType operator()(const Args&... args) {
        auto key = std::make_tuple(args...);
        auto it = cache.find(key);
        if (it == cache.end()) {
            it = cache.emplace(key, func(args...)).first;
        }
        return it->second;
    }

private:
    std::function<ReturnType(Args...)> func;
    std::unordered_map<std::tuple<Args...>, ReturnType> cache;
};

#endif //MEMOIZOR_LIBRARY_H
