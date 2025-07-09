#include <iostream>
#include <bitset>

struct MACHeader {
    uint8_t rntiType : 3;
    uint8_t lcId     : 5;
};

int main() {
    MACHeader header;
    header.rntiType = 3;
    header.lcId = 27;

    std::cout << "RNTI Type: " << (int)header.rntiType << ", LCID: " << (int)header.lcId << std::endl;
    return 0;
}