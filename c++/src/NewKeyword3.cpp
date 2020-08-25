#include <cstdio>
#include <cstdlib>
#include <new>
// replacement of a minimal set of functions:
void* operator new(std::size_t sz) {
    std::printf("global op new called, size = %u\n", sz);
    void *ptr = std::malloc(sz);
    if (ptr)
        return ptr;
    else
        throw std::bad_alloc{};
}
void operator delete(void* ptr) noexcept
{
    std::puts("global op delete called");
    std::free(ptr);
}
int main() {
     int* p1 = new int;
     delete p1;

     int* p2 = new int[10]; // guaranteed to call the replacement in C++11
     delete[] p2;
}
