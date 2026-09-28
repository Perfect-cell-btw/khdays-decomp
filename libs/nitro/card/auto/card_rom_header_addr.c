/* NitroSDK card_rom.c: cardi_rom_header_addr, where the card ROM header copy lives (HW_ROM_HEADER_BUF). */

#include "nitro/types.h"

#define HW_ROM_HEADER_BUF 0x027ffe00
u32 data_020423e8 = HW_ROM_HEADER_BUF;
