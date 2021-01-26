#include <iostream>

struct AllocationMetrics {
    uint32_t TotalAllocated;
    uint32_t TotalFreed;
    uint32_t CurrentUsuage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes\n";
    s_AllocationMetrics.TotalAllocated += size;
    return malloc(size);
}

void operator delete(void* memory, size_t size)
{
    std::cout << "Freeing " << size << " bytes\n";
    s_AllocationMetrics.TotalFreed += size;
    free(memory);
}

struct Object {
    int x, y, z;
};

void PrintMemoryUsuage()
{
    std::cout << "Memory Usuage : " << s_AllocationMetrics.CurrentUsuage() << " bytes\n";
}

int main()
{
    PrintMemoryUsuage();
    Object* obj = new Object;
    obj->x = 1;
    obj->y = 2;
    obj->z = 3;
    std::cout << "x = " << obj->x << " y = " << obj->y << " z = " << obj->z << std::endl;
    PrintMemoryUsuage();

    delete obj;
    PrintMemoryUsuage();
    
    // Small strings are not allocated on heap
    std::string smallStr = "Small String";

    // Big strings are allocated on heap
    std::string bigStr = "Big string is allocated on heap";

    return 0;
}
