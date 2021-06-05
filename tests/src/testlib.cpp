#define RUN_CATCH

#if defined (RUN_CATCH)

#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>


auto main (int argc, char* argv[]) -> int
{
    int result = Catch::Session().run( argc, argv );
    return result;
}

#else


auto main (int argc, char* argv[]) -> int
{

}


#endif

