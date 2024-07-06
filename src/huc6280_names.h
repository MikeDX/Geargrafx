/*
 * Geargrafx - PC Engine / TurboGrafx Emulator
 * Copyright (C) 2024  Ignacio Sanchez

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/
 *
 */
#ifndef HUC6280_NAME_H
#define HUC6280_NAME_H

#include "types.h"

static const GG_OPCode_Info k_opcode_names[256] = {
    { "BRK", GG_OPCode_Type_Implied },
    { "ORA $(%02X,X)", GG_OPCode_Type_1b },
    { "SXY", GG_OPCode_Type_Implied },
    { "ST0 #$%02X", GG_OPCode_Type_1b },
    { "TSB $%02X", GG_OPCode_Type_1b },
    { "ORA $%02X", GG_OPCode_Type_1b },
    { "ASL $%02X", GG_OPCode_Type_1b },
    { "RMB 0,$%02X", GG_OPCode_Type_1b },
    { "PHP", GG_OPCode_Type_Implied },
    { "ORA #$%02X", GG_OPCode_Type_1b },
    { "ASL A", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "TSB $%04X", GG_OPCode_Type_2b },
    { "ORA $%04X", GG_OPCode_Type_2b },
    { "ASL $%04X", GG_OPCode_Type_2b },
    { "BBR 0,$%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "BPL $%04X  [%+d]", GG_OPCode_Type_1b_Relative },
    { "ORA ($%02X),Y", GG_OPCode_Type_1b },
    { "ORA ($%02X)", GG_OPCode_Type_1b },
    { "ST1 #$%02X", GG_OPCode_Type_1b },
    { "TRB $%02X", GG_OPCode_Type_1b },
    { "ORA $%02X,X", GG_OPCode_Type_1b },
    { "ASL $%02X,X", GG_OPCode_Type_1b },
    { "RMB 1,$%02X", GG_OPCode_Type_1b },
    { "CLC", GG_OPCode_Type_Implied },
    { "ORA $%04X,Y", GG_OPCode_Type_2b },
    { "INC A", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "TRB $%04X", GG_OPCode_Type_2b },
    { "ORA $%04X,X", GG_OPCode_Type_2b },
    { "ASL $%04X,X", GG_OPCode_Type_2b },
    { "BBR 1,$%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "JSR $%04X", GG_OPCode_Type_2b },
    { "AND $(%02X,X)", GG_OPCode_Type_1b },
    { "SAX", GG_OPCode_Type_Implied },
    { "ST2 #$%02x", GG_OPCode_Type_1b },
    { "BIT $%02X", GG_OPCode_Type_1b },
    { "AND $%02X", GG_OPCode_Type_1b },
    { "ROL $%02X", GG_OPCode_Type_1b },
    { "RMB 2,$%02X", GG_OPCode_Type_1b },
    { "PLP", GG_OPCode_Type_Implied },
    { "AND #$%02X", GG_OPCode_Type_1b },
    { "ROL A", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "BIT $%04X", GG_OPCode_Type_2b },
    { "AND $%04X", GG_OPCode_Type_2b },
    { "ROL $%04X", GG_OPCode_Type_2b },
    { "BBR 2,$%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "BMI $%04X  [%+d]", GG_OPCode_Type_1b_Relative },
    { "AND ($%02X),Y", GG_OPCode_Type_1b },
    { "AND ($%02X)", GG_OPCode_Type_1b },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "BIT $%02X,X", GG_OPCode_Type_1b },
    { "AND $%02X,X", GG_OPCode_Type_1b },
    { "ROL $%02X,X", GG_OPCode_Type_1b },
    { "RMB3 $%02X", GG_OPCode_Type_1b },
    { "SEC", GG_OPCode_Type_Implied },
    { "AND $%04X,Y", GG_OPCode_Type_2b },
    { "DEC A", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "BIT $%04X,X", GG_OPCode_Type_2b },
    { "AND $%04X,X", GG_OPCode_Type_2b },
    { "ROL $%04X,X", GG_OPCode_Type_2b },
    { "BBR3 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "RTI", GG_OPCode_Type_Implied },
    { "EOR $(%02X,X)", GG_OPCode_Type_1b },
    { "SAY", GG_OPCode_Type_Implied },
    { "TMA #$%02X", GG_OPCode_Type_1b },
    { "BSR $%04X", GG_OPCode_Type_2b },
    { "EOR $%02X", GG_OPCode_Type_1b },
    { "LSR $%02X", GG_OPCode_Type_1b },
    { "RMB4 $%02X", GG_OPCode_Type_1b },
    { "PHA", GG_OPCode_Type_Implied },
    { "EOR #$%02X", GG_OPCode_Type_1b },
    { "LSR A", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "JMP $%04X", GG_OPCode_Type_2b },
    { "EOR $%04X", GG_OPCode_Type_2b },
    { "LSR $%04X", GG_OPCode_Type_2b },
    { "BBR4 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "BVC $%04X  [%+d]", GG_OPCode_Type_1b_Relative },
    { "EOR ($%02X),Y", GG_OPCode_Type_1b },
    { "EOR ($%02X)", GG_OPCode_Type_1b },
    { "TAM #$%02X", GG_OPCode_Type_1b },
    { "CSL", GG_OPCode_Type_Implied },
    { "EOR $%02X,X", GG_OPCode_Type_1b },
    { "LSR $%02X,X", GG_OPCode_Type_1b },
    { "RMB5 $%02X", GG_OPCode_Type_1b },
    { "CLI", GG_OPCode_Type_Implied },
    { "EOR $%04X,Y", GG_OPCode_Type_2b },
    { "PHY", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "EOR $%04X,X", GG_OPCode_Type_2b },
    { "LSR $%04X,X", GG_OPCode_Type_2b },
    { "BBR5 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "RTS", GG_OPCode_Type_Implied },
    { "ADC $(%02X,X)", GG_OPCode_Type_1b },
    { "CLA", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "STZ $%02X", GG_OPCode_Type_1b },
    { "ADC $%02X", GG_OPCode_Type_1b },
    { "ROR $%02X", GG_OPCode_Type_1b },
    { "RMB6 $%02X", GG_OPCode_Type_1b },
    { "PLA", GG_OPCode_Type_Implied },
    { "ADC #$%02X", GG_OPCode_Type_1b },
    { "ROR A", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "JMP ($%04X)", GG_OPCode_Type_2b },
    { "ADC $%04X", GG_OPCode_Type_2b },
    { "ROR $%04X", GG_OPCode_Type_2b },
    { "BBR6 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "BVS $%04X  [%+d]", GG_OPCode_Type_1b_Relative },
    { "ADC ($%02X),Y", GG_OPCode_Type_1b },
    { "ADC ($%02X)", GG_OPCode_Type_1b },
    { "TII $%04X,$%04X,$%04X", GG_OPCode_Type_2b_2b_2b },
    { "STZ $%02X,X", GG_OPCode_Type_1b },
    { "ADC $%02X,X", GG_OPCode_Type_1b },
    { "ROR $%02X,X", GG_OPCode_Type_1b },
    { "RMB7 $%02X", GG_OPCode_Type_1b },
    { "SEI", GG_OPCode_Type_Implied },
    { "ADC $%04X,Y", GG_OPCode_Type_2b },
    { "PLY", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "JMP $(%04X,X)", GG_OPCode_Type_2b },
    { "ADC $%04X,X", GG_OPCode_Type_2b },
    { "ROR $%04X,X", GG_OPCode_Type_2b },
    { "BBR7 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "BRA $%04X  [%+d]", GG_OPCode_Type_1b_Relative },
    { "STA $(%02X,X)", GG_OPCode_Type_1b },
    { "CLX", GG_OPCode_Type_Implied },
    { "TST #$%02X,$%02X", GG_OPCode_Type_1b_1b },
    { "STY $%02X", GG_OPCode_Type_1b },
    { "STA $%02X", GG_OPCode_Type_1b },
    { "STX $%02X", GG_OPCode_Type_1b },
    { "SMB0 $%02X", GG_OPCode_Type_1b },
    { "DEY", GG_OPCode_Type_Implied },
    { "BIT #$%02X", GG_OPCode_Type_1b },
    { "TXA", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "STY $%04X", GG_OPCode_Type_2b },
    { "STA $%04X", GG_OPCode_Type_2b },
    { "STX $%04X", GG_OPCode_Type_2b },
    { "BBS0 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "BCC $%04X  [%+d]", GG_OPCode_Type_1b_Relative },
    { "STA ($%02X),Y", GG_OPCode_Type_1b },
    { "STA ($%02X)", GG_OPCode_Type_1b },
    { "TST #$%02X,$%04X", GG_OPCode_Type_1b_2b },
    { "STY $%02X,X", GG_OPCode_Type_1b },
    { "STA $%02X,X", GG_OPCode_Type_1b },
    { "STX $%02X,Y", GG_OPCode_Type_1b },
    { "SMB1 $%02X", GG_OPCode_Type_1b },
    { "TYA", GG_OPCode_Type_Implied },
    { "STA $%04X,Y", GG_OPCode_Type_2b },
    { "TXS", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "STZ $%04X", GG_OPCode_Type_2b },
    { "STA $%04X,X", GG_OPCode_Type_2b },
    { "STZ $%04X,X", GG_OPCode_Type_2b },
    { "BBS1 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "LDY #$%02X", GG_OPCode_Type_1b },
    { "LDA $(%02X,X)", GG_OPCode_Type_1b },
    { "LDX #$%02X", GG_OPCode_Type_1b },
    { "TST #$%02X,$%02X,X", GG_OPCode_Type_1b_1b },
    { "LDY $%02X", GG_OPCode_Type_1b },
    { "LDA $%02X", GG_OPCode_Type_1b },
    { "LDX $%02X", GG_OPCode_Type_1b },
    { "SMB2 $%02X", GG_OPCode_Type_1b },
    { "TAY", GG_OPCode_Type_Implied },
    { "LDA #$%02X", GG_OPCode_Type_1b },
    { "TAX", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "LDY $%04X", GG_OPCode_Type_2b },
    { "LDA $%04X", GG_OPCode_Type_2b },
    { "LDX $%04X", GG_OPCode_Type_2b },
    { "BBS2 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "BCS $%04X  [%+d]", GG_OPCode_Type_1b_Relative },
    { "LDA ($%02X),Y", GG_OPCode_Type_1b },
    { "LDA ($%02X)", GG_OPCode_Type_1b },
    { "TST #$%02X,$%04X,X", GG_OPCode_Type_1b_2b },
    { "LDY $%02X,X", GG_OPCode_Type_1b },
    { "LDA $%02X,X", GG_OPCode_Type_1b },
    { "LDX $%02X,Y", GG_OPCode_Type_1b },
    { "SMB3 $%02X", GG_OPCode_Type_1b },
    { "CLV", GG_OPCode_Type_Implied },
    { "LDA $%04X,Y", GG_OPCode_Type_2b },
    { "TSX", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "LDY $%04X,X", GG_OPCode_Type_2b },
    { "LDA $%04X,X", GG_OPCode_Type_2b },
    { "LDX $%04X,Y", GG_OPCode_Type_2b },
    { "BBS3 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "CPY #$%02X", GG_OPCode_Type_1b },
    { "CMP $(%02X,X)", GG_OPCode_Type_1b },
    { "CLY", GG_OPCode_Type_Implied },
    { "TDD $%04X,$%04X,$%04X", GG_OPCode_Type_2b_2b_2b },
    { "CPY $%02X", GG_OPCode_Type_1b },
    { "CMP $%02X", GG_OPCode_Type_1b },
    { "DEC $%02X", GG_OPCode_Type_1b },
    { "SMB4 $%02X", GG_OPCode_Type_1b },
    { "INY", GG_OPCode_Type_Implied },
    { "CMP #$%02X", GG_OPCode_Type_1b },
    { "DEX", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "CPY $%04X", GG_OPCode_Type_2b },
    { "CMP $%04X", GG_OPCode_Type_2b },
    { "DEC $%04X", GG_OPCode_Type_2b },
    { "BBS4 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "BNE $%04X  [%+d]", GG_OPCode_Type_1b_Relative },
    { "CMP ($%02X),Y", GG_OPCode_Type_1b },
    { "CMP ($%02X)", GG_OPCode_Type_1b },
    { "TIN $%04X,$%04X,$%04X", GG_OPCode_Type_2b_2b_2b },
    { "CSH", GG_OPCode_Type_Implied },
    { "CMP $%02X,X", GG_OPCode_Type_1b },
    { "DEC $%02X,X", GG_OPCode_Type_1b },
    { "SMB5 $%02X", GG_OPCode_Type_1b },
    { "CLD", GG_OPCode_Type_Implied },
    { "CMP $%04X,Y", GG_OPCode_Type_2b },
    { "PHX", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "CMP $%04X,X", GG_OPCode_Type_2b },
    { "DEC $%04X,X", GG_OPCode_Type_2b },
    { "BBS5 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "CPX #$%02X", GG_OPCode_Type_1b },
    { "SBC $(%02X,X)", GG_OPCode_Type_1b },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "TIA $%04X,$%04X,$%04X", GG_OPCode_Type_2b_2b_2b },
    { "CPX $%02X", GG_OPCode_Type_1b },
    { "SBC $%02X", GG_OPCode_Type_1b },
    { "INC $%02X", GG_OPCode_Type_1b },
    { "SMB6 $%02X", GG_OPCode_Type_1b },
    { "INX", GG_OPCode_Type_Implied },
    { "SBC #$%02X", GG_OPCode_Type_1b },
    { "NOP", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "CPX $%04X", GG_OPCode_Type_2b },
    { "SBC $%04X", GG_OPCode_Type_2b },
    { "INC $%04X", GG_OPCode_Type_2b },
    { "BBS6 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative },

    { "BEQ $%04X  [%+d]", GG_OPCode_Type_1b_Relative },
    { "SBC ($%02X),Y", GG_OPCode_Type_1b },
    { "SBC ($%02X)", GG_OPCode_Type_1b },
    { "TAI $%04X,$%04X,$%04X", GG_OPCode_Type_2b_2b_2b },
    { "SET", GG_OPCode_Type_Implied },
    { "SBC $%02X,X", GG_OPCode_Type_1b },
    { "INC $%02X,X", GG_OPCode_Type_1b },
    { "SMB7 $%02X", GG_OPCode_Type_1b },
    { "SED", GG_OPCode_Type_Implied },
    { "SBC $%04X,Y", GG_OPCode_Type_2b },
    { "PLX", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "NOP (UNOF)", GG_OPCode_Type_Implied },
    { "SBC $%04X,X", GG_OPCode_Type_2b },
    { "INC $%04X,X", GG_OPCode_Type_2b },
    { "BBS7 $%02X,$%04X  [%+d]", GG_OPCode_Type_1b_1b_Relative }
};

#endif /* HUC6280_NAME_H */