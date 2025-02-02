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

#ifndef EMU_H
#define	EMU_H

#include "../../../src/geargrafx.h"

#ifdef EMU_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

EXTERN u8* emu_frame_buffer;
EXTERN u8* emu_debug_background_buffer;
EXTERN int emu_debug_background_buffer_width;
EXTERN int emu_debug_background_buffer_height;

EXTERN bool emu_audio_sync;
EXTERN bool emu_debug_disable_breakpoints;
EXTERN bool emu_savefiles_dir_option;
EXTERN bool emu_savestates_dir_option;
EXTERN char emu_savefiles_path[4096];
EXTERN char emu_savestates_path[4096];

EXTERN void emu_init(void);
EXTERN void emu_destroy(void);
EXTERN void emu_update(void);
EXTERN void emu_load_rom(const char* file_path);
EXTERN void emu_key_pressed(GG_Controllers controller, GG_Keys key);
EXTERN void emu_key_released(GG_Controllers controller, GG_Keys key);
EXTERN void emu_pause(void);
EXTERN void emu_resume(void);
EXTERN bool emu_is_paused(void);
EXTERN bool emu_is_empty(void);
EXTERN void emu_reset(void);
EXTERN void emu_audio_mute(bool mute);
EXTERN void emu_audio_reset(void);
EXTERN bool emu_is_audio_enabled(void);
EXTERN void emu_save_ram(const char* file_path);
EXTERN void emu_load_ram(const char* file_path);
EXTERN void emu_save_state_slot(int index);
EXTERN void emu_load_state_slot(int index);
EXTERN void emu_save_state_file(const char* file_path);
EXTERN void emu_load_state_file(const char* file_path);
EXTERN void emu_get_runtime(GG_Runtime_Info& runtime);
EXTERN void emu_get_info(char* info);
EXTERN GeargrafxCore* emu_get_core(void);
EXTERN void emu_debug_step_over(void);
EXTERN void emu_debug_step_into(void);
EXTERN void emu_debug_step_out(void);
EXTERN void emu_debug_step_frame(void);
EXTERN void emu_debug_break(void);
EXTERN void emu_debug_continue(void);

EXTERN void emu_video_no_sprite_limit(bool enabled);
EXTERN void emu_set_overscan(int overscan);
EXTERN void emu_save_screenshot(const char* file_path);

#undef EMU_IMPORT
#undef EXTERN
#endif	/* EMU_H */