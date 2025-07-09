#include <iostream>
#include <vector>
#include <string>

class HARQBuffer {
    std::vector<std::string> buffer;
public:
    void storePDU(const std::string& pdu) {
        buffer.push_back(pdu);
    }

    std::string retransmit() {
        if (!buffer.empty()) {
            return buffer.back();
        }
        return "";
    }
};

int main() {
    HARQBuffer harq;
    harq.storePDU("PDU1");
    std::cout << "Retransmitting: " << harq.retransmit() << std::endl;
    return 0;
}