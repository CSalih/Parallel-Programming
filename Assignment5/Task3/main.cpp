#include <iostream>
#include <cstdlib>
#include <string>
#include "Mergesort.h"
#include <vector>

// Will test if actual is same as expected
void compareArray(const int32_t *actual, const int32_t *expected, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (actual[i] != expected[i])
        {
            std::cout << "Actual: \t";
            Mergesort::print(actual, n);

            std::cout << "Expected: \t";
            Mergesort::print(expected, n);

            std::string msg = "Mergesort test failed at index " + std::to_string(i);
            throw msg;
        }
    }
    std::cout << "Mergesort test passed" << std::endl;
}

// Runs a set of tests
void runTests()
{
    int32_t a1[] = {4, 6, 8, 3, 2, 0, 1, 9, 7, 5};
    int32_t e1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int32_t a2[] = {2, 13, 17, 15, 19, 15, 16, 0, 9, 18, 17, 6, 14, 15, 16, 0, 3, 4, 7, 16};
    int32_t e2[] = {0, 0, 2, 3, 4, 6, 7, 9, 13, 14, 15, 15, 15, 16, 16, 16, 17, 17, 18, 19};

    int32_t a3[] = {2, 11, 16, 9, 17, 17, 1, 0, 2, 19, 18, 7, 4, 0, 7, 0, 19, 11, 16, 10};
    int32_t e3[] = {0, 0, 0, 1, 2, 2, 4, 7, 7, 9, 10, 11, 11, 16, 16, 17, 17, 18, 19, 19};

    int32_t a4[] = {6, 18, 8, 13, 6, 12, 16, 11, 1, 16, 10, 6, 17, 11, 0, 11, 14, 8, 14, 0};
    int32_t e4[] = {0, 0, 1, 6, 6, 6, 8, 8, 10, 11, 11, 11, 12, 13, 14, 14, 16, 16, 17, 18};

    // Sort and test
    int n = sizeof(a1) / sizeof(a1[0]);
    Mergesort::sort(a1, n);
    compareArray(a1, e1, n);

    n = sizeof(a2) / sizeof(a2[0]);
    Mergesort::sort(a2, n);
    compareArray(a2, e2, n);

    n = sizeof(a3) / sizeof(a3[0]);
    Mergesort::sort(a3, n);
    compareArray(a3, e3, n);

    // Test parallel
    n = sizeof(a4) / sizeof(a4[0]);
    Mergesort::sortParallel(a4, n);
    compareArray(a4, e4, n);
}

int main(int argc, char *argv[])
{
    // Check if argument is valid
    if (argc < 2)
    {
        std::cerr << "Provide size of the Matrix! Usage: ./Mergesort [--parallel] [--test] n" << std::endl;
        return EXIT_FAILURE;
    }

    // Get options
    bool parallel = false;
    bool test = false;
    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        if (arg == "-p" || arg == "--parallel")
        {
            parallel = true;
        }
        else if (arg == "-t" || arg == "--test")
        {
            test = true;
        }
        else if (arg == "-r" || arg == "--recursive")
        {
            test = true;
        }
    }

    // Run some tests
    if (test)
    {
        try
        {
            runTests();
        }
        catch (const std::string msg)
        {
            std::cerr << msg << std::endl;
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }

    // Get size of array
    int n = std::stoi(argv[argc - 1]);
    if (n <= 0)
    {
        std::cerr << "Invalid input! Size must be bigger than Zero." << std::endl;
        return EXIT_FAILURE;
    }

    // Allocate memory and fill
    int32_t *arr = (int32_t *)malloc(sizeof(int32_t) * n);
    if (arr == NULL)
    {
        std::cerr << "Can't allocate memory!" << std::endl;
        return EXIT_FAILURE;
    }
    Mergesort::fillWithRandomNumbers(arr, n);

    // Pretty print
    std::cout << "Array: \t";
    Mergesort::print(arr, n);

    // Sorting
    parallel ? Mergesort::sortParallel(arr, n) : Mergesort::sort(arr, n);

    // Pretty print
    std::cout << "Sorted: \t";
    Mergesort::print(arr, n);

    // Free allocated memory
    if (arr != NULL)
        free(arr);

    // say bye to os
    return EXIT_SUCCESS;
}