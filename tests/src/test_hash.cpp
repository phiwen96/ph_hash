#ifdef RUN_CATCH


#include <catch2/catch.hpp>
#include <algorithms/array.hpp>
#include <algorithms/common.hpp>
#include <algorithms/opcode.hpp>
#include <algorithms/vm.hpp>
#include <algorithms/compiler.hpp>
#include <algorithms/token.hpp>
#include <algorithms/lexeme.hpp>
#include <algorithms/scanner.hpp>
#include <algorithms/operator.hpp>
#include <unordered_map>
#include <algorithms/overload.hpp>




auto readFile (const char* path) -> char*
{
    FILE* file = fopen (path, "rb");
    
    if (file == NULL)
    {
        fprintf (stderr, "Could not open file because of existance or access rights\"%s\".\n", path);
        exit (74);
    }
    
    // we seek to the very end using fseek()
    fseek (file, 0L, SEEK_END);
    
    // we call ftell() which tells us how many bytes we are from the start of the file
    size_t fileSize = ftell (file);
    rewind (file);
    
    char* buffer = (char*) malloc (fileSize + 1);
    
    if (buffer == NULL)
    {
        fprintf (stderr, "Not enough memory to read \"%s\".\n", path);
        exit (74);
    }
    
    
    size_t bytesRead = fread (buffer, sizeof (char), fileSize, file);
    
    if (bytesRead < fileSize)
    {
        fprintf (stderr, "Could not read file \"%s\".\n", path);
        exit (74);
    }
    
    buffer [bytesRead] = '\0';
    
    fclose (file);
    return buffer;
}

TEST_CASE ("")
{
    
}

#endif
