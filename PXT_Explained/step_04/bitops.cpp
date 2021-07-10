#include "pxt.h"
#include <bitset>

PN_(Demonstrating Bit Operations (TDD-Style))

void shift_ops() {
    unsigned bits = 0b101010;
    PX_("00101010", std::bitset<8>{bits});
    bits <<= 1;
    PX_("01010100", std::bitset<8>{bits});
    bits <<= 1;
    PX_("10101000", std::bitset<8>{bits});
    bits >>= 3;
    PX_("00010101", std::bitset<8>{bits});
}

void bitor_ops() {    
    unsigned bits = 0b101010;
    PX_("00101010", std::bitset<8>{bits});
    bits |= 0b100;
    PX_("..TODO..", std::bitset<8>{bits});
    bits |= 0b111;
    PX_("..TODO..", std::bitset<8>{bits});
}

void bitxor_ops() {
    std::bitset<8> bits = 0b101010;
    PX_("00101010", bits);
    bits ^= 0b100;
    PX_("..TODO..", bits);
    bits ^= 0b111;
    PX_("..TODO..", bits);    
}

void bitand_ops() {
    std::bitset<8> bits = 0b101010;
    PX_("00101010", bits);
    bits &= ~0b10;
    PX_("..TODO..", bits);
}

int main() {
    shift_ops();
//  bitor_ops();
//  bitxor_ops();
//  bitand_ops();
}
