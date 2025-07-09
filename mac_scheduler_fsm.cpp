#include <iostream>
enum class MACState { IDLE, WAIT_GRANT, TX, RETX };

bool grantAvailable() { return true; }
bool reTxRequired() { return false; }
void transmitData() { std::cout << "Data transmitted\n"; }
void retransmit() { std::cout << "Data retransmitted\n"; }

void macScheduler(MACState& state) {
    switch(state) {
        case MACState::IDLE:
            if (grantAvailable()) state = MACState::TX;
            break;
        case MACState::TX:
            transmitData(); state = MACState::WAIT_GRANT;
            break;
        case MACState::WAIT_GRANT:
            if (reTxRequired()) state = MACState::RETX;
            else state = MACState::IDLE;
            break;
        case MACState::RETX:
            retransmit(); state = MACState::WAIT_GRANT;
            break;
    }
}

int main() {
    MACState state = MACState::IDLE;
    for (int i = 0; i < 5; ++i) {
        macScheduler(state);
    }
    return 0;
}