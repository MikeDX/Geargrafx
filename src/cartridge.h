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

#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include "common.h"

class Cartridge
{
public:
    Cartridge();
    ~Cartridge();
    void Init();
    void Reset();
    u32 GetCRC();
    bool IsReady();
    int GetROMSize();
    int GetROMBankCount();
    const char* GetFilePath();
    const char* GetFileName();
    const char* GetFileExtension();
    u8* GetROM();
    bool LoadFromFile(const char* path);
    bool LoadFromBuffer(const u8* buffer, int size);

private:
    bool LoadFromZipFile(const u8* buffer, int size);
    void GatherROMInfo();
    void GatherInfoFromDB();

private:
    u8* m_rom;
    int m_rom_size;
    int m_rom_bank_count;
    bool m_ready;
    char m_file_path[512];
    char m_file_name[512];
    char m_file_extension[512];
    u32 m_crc;
};

#endif /* CARTRIDGE_H */