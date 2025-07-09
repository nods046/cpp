#include <iostream>
#include <thread>
#include <chrono>

void protocolTimer(int timeout_ms) {
    std::cout << "Timer started for " << timeout_ms << " ms\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(timeout_ms));
    std::cout << "Timer expired\n";
}

int main() {
    protocolTimer(2000);
    return 0;
}