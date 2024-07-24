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

#ifndef HUC6270_INLINE_H
#define HUC6270_INLINE_H

#include "huc6270.h"
#include "huc6280.h"

inline bool HuC6270::Clock()
{
    bool frame_ready = false;

    if (m_vpos < HUC6270_ACTIVE_DISPLAY_START)
    {
        //Debug("HuC6270 during top blanking");
    }
    else if (m_vpos < HUC6270_BOTTOM_BLANKING_START)
    {
        //Debug("HuC6270 during active display");
    }
    else if (m_vpos < HUC6270_SYNC_START)
    {
        //Debug("HuC6270 during bottom blanking");
    }
    else
    {
        //Debug("HuC6270 during sync");
    }

    if (m_hpos > 256)
    {
        //Debug("HuC6270 during horizontal blanking");
    }

    m_hpos++;

    if (m_hpos > 341)
    {
        m_hpos = 0;
        m_vpos++;

        if (m_vpos > HUC6270_LINES)
        {
            frame_ready = true;
            m_vpos = 0;
            if (m_register[HUC6270_REG_CR] & HUC6270_VBLANK_CR)
            {
                m_status_register |= HUC6270_VBLANK_SR;
                m_huc6280->AssertIRQ1(true);
            }
        }
    }

    return frame_ready;
}

inline u8 HuC6270::ReadRegister(u32 address)
{
    switch (address & 0x03)
    {
        case 0:
        {
            // Status register
            // Debug("HuC6270 read status register");
            u8 ret = m_status_register & 0x7F;
            m_huc6280->AssertIRQ1(false);
            m_status_register &= 0x40;
            return ret;
            break;
        }
        case 2:
            // Data register (LSB)
            return ReadDataRegister(false);
            break;
        case 3:
            // Data register (MSB)
            return ReadDataRegister(true);
            break;
        default:
            Debug("HuC6270 invalid read at %06X", address);
            return 0x00;
    }
}

inline void HuC6270::WriteRegister(u32 address, u8 value)
{
    switch (address & 0x03)
    {
        case 0:
            // Address register
            m_address_register = value & 0x1F;
            // Debug("HuC6270 write address register: %02X", m_address_register);
            break;
        case 2:
            // Data register (LSB)
            WriteDataRegister(value, false);
            break;
        case 3:
            // Data register (MSB)
            WriteDataRegister(value, true);
            break;
        default:
            Debug("HuC6270 invalid write at %06X, value=%02X", address, value);
            break;
    }
}

inline void HuC6270::DirectWrite(u32 address, u8 value)
{
    switch (address)
    {
        case 0x1FE000:
            // Debug("HuC6270 direct write (ST0) at %06X, value=%02X", address, value);
            break;
        case 0x1FE002:
            // Debug("HuC6270 direct write (ST1) at %06X, value=%02X", address, value);
            break;
        case 0x1FE003:
            // Debug("HuC6270 direct write (ST2) at %06X, value=%02X", address, value);
            break;
        default:
            // Debug("HuC6270 invalid direct write at %06X, value=%02X", address, value);
            break;
    }

    WriteRegister(address, value);
}

inline u8 HuC6270::ReadDataRegister(bool msb)
{
    if (m_address_register == HUC6270_REG_VRR)
    {
        // Debug("HuC6270 read VRR (%s): %02X", msb ? "MSB" : "LSB", m_register[HUC6270_REG_VWR]);
        if (msb)
        {
            u8 ret = m_read_buffer >> 8;
            int increment = k_read_write_increment[(m_register[HUC6270_REG_CR] >> 11) & 0x03];
            m_register[HUC6270_REG_MARR] = (m_register[HUC6270_REG_MARR] + increment) & 0x7FFF;
            m_read_buffer = m_vram[m_register[HUC6270_REG_MARR] & 0x7FFF];
            // Debug("HuC6270 MARR inncremented %02X to %04X", increment, m_register[HUC6270_REG_MARR]);
            return ret;
        }
        else
        {
            return m_read_buffer & 0xFF;
        }
    }
    else
    {
        Debug("HuC6270 invalid read data register: %02X", m_address_register);
        return m_register[HUC6270_REG_VWR] & 0xFF;
    }
}

inline void HuC6270::WriteDataRegister(u8 value, bool msb)
{
    if (m_address_register <= 0x13 && m_address_register != 0x03 && m_address_register != 0x04)
    {
        m_register[m_address_register] = msb ? (m_register[m_address_register] & 0x00FF) | (value << 8) : (m_register[m_address_register] & 0xFF00) | value;
        m_register[m_address_register] &= k_register_mask[m_address_register];
    }

    switch (m_address_register)
    {
        case HUC6270_REG_MAWR:
            // Debug("HuC6270 write MAWR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_MARR:
            // Debug("HuC6270 write MARR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            if (msb)
                m_read_buffer = m_vram[m_register[HUC6270_REG_MARR] & 0x7FFF];
            break;
        case HUC6270_REG_VWR:
            // Debug("HuC6270 write VWR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            if (msb)
            {
                m_vram[m_register[HUC6270_REG_MAWR] & 0x7FFF] = m_register[HUC6270_REG_VWR];
                int increment = k_read_write_increment[(m_register[HUC6270_REG_CR] >> 11) & 0x03];
                m_register[HUC6270_REG_MAWR] = (m_register[HUC6270_REG_MAWR] + increment) & 0x7FFF;
                // Debug("HuC6270 MAWR inncremented %02X to %04X", increment, m_register[HUC6270_REG_MAWR]);
            }
            break;
        case HUC6270_REG_CR:
            // Debug("HuC6270 write CR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_RCR:
            // Debug("HuC6270 write RCR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_BXR:
            // Debug("HuC6270 write BXR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_BYR:
            // Debug("HuC6270 write BYR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_MWR:
            // Debug("HuC6270 write MWR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_HSR:
            // Debug("HuC6270 write HSR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_HDR:
            // Debug("HuC6270 write HDR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_VPR:
            // Debug("HuC6270 write VPR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_VDR:
            // Debug("HuC6270 write VDR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_VCR:
            // Debug("HuC6270 write VCR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_DCR:
            // Debug("HuC6270 write DCR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_SOUR:
            // Debug("HuC6270 write SOUR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_DESR:
            // Debug("HuC6270 write DESR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_LENR:
            // Debug("HuC6270 write LENR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        case HUC6270_REG_DVSSR:
            // Debug("HuC6270 write DVSSR (%s) %02X: %04X", msb ? "MSB" : "LSB", value, m_register[m_address_register]);
            break;
        default:
            Debug("HuC6270 invalid write data register %02X: %02X", m_address_register, value);
            break;
    }
}

#endif /* HUC6270_INLINE_H */