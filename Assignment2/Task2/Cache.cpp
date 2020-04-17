#include <iostream>

#include "Cache.h"

// Declare the size 
Cache::Cache(int n)
{
    csize = n;
}

// Refers key x with in the LRU cache
void Cache::refer(int32_t* x)
{
    // not present in cache
    if (ma.find(x) == ma.end()) {
        ++cacheMiss;
        // cache is full
        if (dq.size() == csize) {
            // delete least recently used element 
            int last = dq.back();

            // Pops the last elmeent 
            dq.pop_back();

            // Erase the last 
            ma.erase(&last);
        }
    }
    else {
        // present in cache 
        dq.erase(ma[x]);
        ++cacheHit;
    }

    // update reference 
    dq.push_front(*x);
    ma[x] = dq.begin();
}

// Function to display contents of cache 
void Cache::display()
{
    // Iterate in the deque and print 
    // all the elements in it 
    for (auto it = dq.begin(); it != dq.end();
        it++)
        std::cout << (*it) << " ";

    std::cout << std::endl << "Hit: " << cacheHit << " Miss: " << cacheMiss << std::endl;
}

void Cache::displayMisses()
{
    std::cout << "Miss: " << cacheMiss << std::endl;
}
