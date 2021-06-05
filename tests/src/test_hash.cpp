#ifdef RUN_CATCH


#include <catch2/catch.hpp>
#include <ph_hash/hash.hpp>





TEST_CASE ("")
{
    using namespace std;
    cout << "hi" << endl;
    cout << is_pod_v<int> << endl;
    //let's invoke this with a raw literal string known at compile time:
    auto hash = hash_function ("abc");
}












#endif
