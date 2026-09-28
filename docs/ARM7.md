# The ARM7 binary

The decomp covers the ARM9 only. This is a map of the ARM7 binary for whoever adds it, read
from its code. Addresses are ARM7 addresses. Names follow NitroSDK where the code is
unmistakable; the sound loop, for instance, is identified by its place in `SndThread`, as in
the SDK's `snd_main.c`.

## Layout

- Loaded at `0x02380000` from ROM offset `0x317200`, `0x26f28` bytes; the entry is the load
  address.
- crt0's module parameters at `+0x1d0` point to two autoload blocks (the list at
  `0x023a6f10`, the data from `+0x1e8`):
  - `0x037f8000`: `0xf4b0` bytes plus `0x3e64` of BSS -- the SDK's OS, PXI, SND, SPI and
    friends, in ARM7 WRAM;
  - `0x027e0000`: `0x17878` bytes plus `0x1968` of BSS.
- Stacks: SVC `0x0380ffc0`, IRQ `0x0380ff80`, system `0x0380fb7c`.
- The main function calls `SND_Init(6)` at `0x037f83bc`.

## Sound

| Address | Function |
| ---: | --- |
| `037feef8` | `SND_Init` |
| `037ff008` | `SndThread` |
| `037ff1c0` | `SND_UpdateExChannel` |
| `03801f1c` | `SND_CommandProc` (a switch over command ids 0..0x21) |
| `037fff54` | `SND_SeqMain` |
| `037ff3ac` | `SND_ExChannelMain` |
| `03801c8c` | `SND_UpdateSharedWork` |
| `037feec4` | `SND_CalcRandom` (`x = x * 1664525 + 1013904223`) |
| `03801ed8` | `SND_CommandInit` |
| `038025cc` | the PXI callback: an address goes to the command queue, 0 wakes the thread |
| `037fefec` | the periodic handler, every `0xaa8` ticks |
| `037fecac` | `SND_CalcTimer` |
| `037fedd8` | `SND_CalcChannelVolume` |
| `037fe69c` | `SND_Enable` |
| `037fe7bc` | `SND_SetMasterVolume` |
| `037fe7cc` | `SND_SetOutputSelector` |
| `037fea20` | `SND_StopChannel` |
| `037fe708` | `SND_BeginSleep` (with `SND_EndSleep`, the only callers of the SoundBias BIOS call) |
| `037fe760` | `SND_EndSleep` |

`SndThread`'s loop runs `SND_UpdateExChannel`, `SND_CommandProc`, `SND_SeqMain`,
`SND_ExChannelMain`, `SND_UpdateSharedWork` and `SND_CalcRandom`, as in the SDK.

Alarm messages the ARM7 sends back are `alarmNo | id << 8`, which is how the ARM9's
`SNDi_CallAlarmHandler` reads them.

## OS and PXI

| Address | Function |
| ---: | --- |
| `037fc054` | `OS_CreateThread` |
| `037fc5c8` | `OS_InitContext` |
| `037fc290` | `OS_SleepThread` |
| `037fc2e4` | `OS_WakeupThread` |
| `037fc36c` | `OS_WakeupThreadDirect` |
| `037fc6ac` | `OS_InitMessageQueue` |
| `037fc6d4` | `OS_SendMessage` |
| `037fc760` | `OS_ReceiveMessage` |
| `037fd21c` | `OS_GetTick` (timer 0 at F/64) |
| `037fd3a0` | `OS_CreateAlarm` |
| `037fd3b0` | `OSi_InsertAlarm` |
| `037fd4dc` | `OS_SetAlarm` |
| `037fd54c` | `OS_SetPeriodicAlarm` |
| `037fd5c0` | `OS_CancelAlarm` |
| `037fd658` | `OSi_AlarmHandler` |
| `037fde70` | `OS_Panic` |
| `037fdd00` | `OS_DisableInterrupts` |
| `037fdd14` | `OS_RestoreInterrupts` |
| `037fe39c` | `PXI_SetFifoRecvCallback` |
| `037fe410` | `PXI_SendWordByFifo` |

## BIOS calls

Thumb stubs from `038037b4` to `0380382c`; SWI 1Ah-1Ch, the sound tables, are at
`03803824`-`0380382c`.

## Shared with the ARM9

The ARM7 keeps the X/Y word at `0x027fffa8`: X, Y and debug in bits 10, 11 and 13 (active low)
and the hinge in bit 15 (1 = lid closed). It reads `0x2c00` with nothing held and the lid open.
The ARM9 folds it into KEYINPUT as `(KEYINPUT | *0x027fffa8) ^ 0x2fff` (see `Pad_Sample`).
