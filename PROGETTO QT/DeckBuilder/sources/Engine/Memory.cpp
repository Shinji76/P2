#include "Memory.h"

Memory::Memory() {
}

Memory::Memory(std::vector<const AbstractCard*> memory) : memory(memory) {
}

Memory::~Memory() {
    
}

std::vector<const AbstractCard*> Memory::getMemory() const {
    return memory;
}

const AbstractCard* Memory::getCardFromID(int ID) const {
    return memory[ID];
}
