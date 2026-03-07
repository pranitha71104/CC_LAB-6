#include <iostream>
#include <unistd.h>

int main() {
    while (true) {
        std::cout << "Served by backend: " << getpid() << std::endl;
        sleep(5);
    }
    return 0;
}
