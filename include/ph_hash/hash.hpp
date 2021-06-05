#pragma once
#include <ph_concepts/concepts.hpp>



constexpr auto kL1CacheCapacity = 32768; // The L1 Data cache size
constexpr auto kSize = kL1CacheCapacity / sizeof(int);


constexpr auto hash_function (const char* str) -> size_t {
    // str = "abc"   ->    sum = 'a' + 'b' + 'c';    97 + 98 + 99
    auto sum = size_t{0};
    for (auto ptr = str; *ptr != '\0'; ++ptr)
        sum += *ptr;
    return sum;
}



template <typename T>
concept Collection = requires (T& t)
{
    typename T::element_type;
    typename T::size_type;
    {T::size} -> same_as <typename T::size_type>;
//    {t.begin ()} -> std::
};

template <typename T>
concept Data_structure = true;


template <typename T>
concept Container = Data_structure <T> and requires ()
{
    true;
};


