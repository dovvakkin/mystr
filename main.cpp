#include "mystr/mystr.h"

int main() {
    mystr a(11);
    mystr b(12);
    mystr c(1);

    std::cout << (a + b) << std::endl;

    return 0;
}