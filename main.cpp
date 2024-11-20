#include <stdint.h>
#include <stdio.h>

int main() {
    uint32_t testProgram[] = {0xE3A02001, 0xE20220FF}; // Testowe instrukcje ARM
    DecodeARMInstruction(testProgram, 0);  // Dekoduj pierwszą instrukcję
    DecodeARMInstruction(testProgram, 4);  // Dekoduj drugą instrukcję
    return 0;
}

void DecodeARMInstruction(uint32_t *codeBuffer, int pc) {
    uint32_t instruction = codeBuffer[pc / 4];  // ARM instrukcje są 32-bitowe
    uint32_t opcode = (instruction >> 21) & 0x7FF; // Przykładowe wyciąganie opcode
    uint32_t rd = (instruction >> 12) & 0xF;      // Rejestr docelowy
    uint32_t rn = (instruction >> 16) & 0xF;      // Pierwszy rejestr źródłowy
    uint32_t rm = instruction & 0xF;              // Drugi rejestr źródłowy

    printf("PC: 0x%08X | Opcode: 0x%03X | Rd: R%d | Rn: R%d | Rm: R%d\n",
           pc, opcode, rd, rn, rm);
}