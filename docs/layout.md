# Code layout: what is where

This document maps the binary to the source tree, so a reader can find a system without knowing
its address.

## How finished decompilations lay out their code

| | zeldaret/oot | n64decomp/sm64 | pret/pokeplatinum | this repo |
|---|---|---|---|---|
| Game code | `src/code/` plus `src/overlays/{actors,effects,gamestates,misc}/ovl_<Name>/` | `src/{engine,game,menu,audio,...}/` | `src/{battle,applications,savedata,...}/`, named overlays | `src/engine/` plus `src/overlays/{scenes,screens,field,players,enemies,system}/ovNNN_<name>/` |
| System libraries | `src/libultra/` | `lib/` | `lib/` plus NitroSDK | `libs/{nitro,nns,msl,mobiclip}/` |
| Files | one per original translation unit (`z_en_horse.c` + `.h`) | one per translation unit | one per translation unit | one per function |
| Headers | `include/` with the shared structs | `include/` | `include/` mirroring `src/` | not yet |
| Unknown names | stay `func_8xxxxxxx` until documented | same | `unk_*`, `ov5_021D*` | same |

The common points are: directories say what the code does, not how it was matched; overlays sit
in named directories grouped by kind; shared types live in `include/`. KH Days fits the OoT model
closely -- every enemy is its own overlay, like OoT's actors.

## Layout

```
src/engine/                           the main module's game code, ITCM included
src/engine/data/                      its reconstructed DATA
src/overlays/scenes/ovNNN_<name>/     overlays loaded through the scene table
src/overlays/screens/ovNNN_<name>/    screens and menus loaded by a scene
src/overlays/field/ovNNN_<name>/      modules loaded inside the field scene (ov002)
src/overlays/players/ovNNN_<name>/    playable characters (four load slots each)
src/overlays/enemies/ovNNN_<name>/    one overlay per enemy or boss class
src/overlays/system/ovNNN_<name>/     boot, wireless, video, anti-tamper, shared enemy framework
    <overlay>/data/                   the overlay's reconstructed DATA
libs/<vendor>/<module>/{auto,calls}/  NitroSDK, NitroSystem, MSL and MobiClip C
libs/<vendor>/<module>/asm_stubs/     the libraries' own assembly
include/nitro/, include/nnsys/        NitroSDK and NitroSystem headers (the SDK's names)
docs/
```

Every function is one `.c` named after it. Overlay directories keep the `ovNNN` prefix: the number
is the FS overlay id the game loads by, and the build and tools key on it (`tools/srctree.py`
finds the directories). Overlays whose purpose is not established keep the bare `ovNNN` (the pret
convention); the confidence column below says which. `auto/` versus `calls/` (a function with or
without relocations) was a working-process split and is gone from `src/`; `libs/` still uses it.

Still to do, in this order:

- **Headers**: `include/` with the shared structs (actor, AI task, scene, script context, ...).
  Done so far:
  - the basic types: `nitro/types.h` (`u8`..`s64`, `vu*`, `BOOL`, `TRUE`/`FALSE`, `NULL`),
    `nitro/fx_types.h` (`fx16`..`fx64c`, `VecFx32`) and `nitro/os_types.h` (`OSIntrMode`, `OSTick`),
    which every source includes instead of repeating its typedefs; the dozen local names of the 3D
    vector are `VecFx32`. Under mwcc `u32`/`s32` are `long`, as in the SDK the game was built with;
    a few sources that only match with `int` spell `unsigned int`/`int` where it matters.
  - the NitroSDK and NitroSystem declarations the library sources used to copy in front of their
    functions (about 75,000 lines): `nitro/{hw,cp,fx,mi,os,pxi,spi,rtc,card,fs,ctrdg,gx,snd,wm}.h`
    and `nnsys/{fnd,gfd,snd,g2d,g3d}.h`, built from those copies (each type in the form most sources
    used). Sources that carry a variant of a type of their own (a partial view, an enum spelled as
    #defines) still declare that part locally, and function prototypes stay per source for now.
  - the first of the game's own: `game/mission_lobby.h`, the Mission Mode session context that
    ov006 and ov008 share (`MissionContext` with its message, entry and roster blocks) and the
    two overlays' globals (`MissionGlobals`, declared in `game/ov006_mission_mode_select.h` and
    `game/ov008_camp_menu.h`). It replaces 36 partial views of the context and the offset
    arithmetic of some 60 more sources in each overlay; the globals are declared with only the
    two words in use, since declared at their full 28 bytes mwcc addresses them differently.
  - `game/actor.h`, the enemy actor every enemy overlay builds on and ov107 runs (`Actor`,
    0x38c bytes: handler slots, flags, collision sphere, SRT block, state bytes, hit points, the
    two sorted lists). 443 sources use it instead of their partial views; a family's own fields
    after the shared part stay in the source as `struct { Actor base; ... }`. Where a source reads
    a field with another type than the shared one (a local vector type, a typed pointer, the
    other signedness), the access keeps that type with a cast. `tools/structconv.py` does the
    rewrite: it preprocesses a source with mwcc, maps every access through a view by type onto the
    shared member path, and keeps a source only if it still compiles to the same bytes.
  - `game/ai_task.h`, an actor's AI task (`AiTask`, the 0x28-byte entry CreateRegistryEntry puts
    in the actor's task list and ObjList_Update runs: three step callbacks, a start and a teardown
    callback, the running pass `slot`). Its state block is the creator's own type, so the members
    are declared through `AI_TASK_FIELDS(StateType)`: 713 enemy sources declare their task as
    `struct X { AI_TASK_FIELDS(TheirState) };` and read `pState`/`slot` without casts.
  Every compile gets `-i include`, and the build tracks header dependencies. Still per source:
  the function prototypes and most of the game's own structs.
- **Translation units**: grouping functions back into one `.c` per original file (per enemy, per
  menu, ...). The build verifies one function per file today. `src/engine/` gets its subsystem
  folders at that point: the boundaries below are approximate, and a prefix such as `Obj_` or
  `Game_` turns up in several of them, so splitting by address now would scatter each system.
- **`libs/` cleanup**: `libs/nitro/nns/` holds NitroSystem code filed under the NitroSDK, and
  several library functions still carry shallow names that describe their shape
  (`Party_SetActiveSlots` sits inside NitroSystem GFD).

## main (arm9)

| Range | Contents | Where |
|---|---|---|
| 0x02000000-0x02020808 | NitroSDK, NitroSystem and MSL runtime, in link order (crt0, OS, MI, GX, FX, SND, FS, CARD, CTRDG, PM/TP, RTC, fnd, gfd, g3d, snd, MSL) | `libs/`, apart from two game blocks linked into the range: `main()` and the frame/VBlank setup (0x02000bcc-0x0200108c) and the file loader and resource cache (0x0201e1d0-0x0201f79c), both in `src/engine/`. Library functions not yet identified by name sit in the `libs/` module their neighbours in link order belong to. |
| 0x02020834-0x0203d1bc | the game's own engine | `src/engine/` |
| ITCM 0x01ff8000 | hot SDK/NitroSystem code copied to ITCM (CP/FX, MI copies, G3D geometry), then the game's own hot code (0x01ffd0e8-0x01fffe68: collision casts, lists) | `libs/`, and the game block in `src/engine/` |

The engine range is laid out by translation unit, so subsystems come in contiguous runs
(approximate boundaries, to be refined when functions are grouped back into files):

| Around | Subsystem | Name prefixes seen |
|---|---|---|
| 0x02020834 | scene dispatch, frame callbacks, game actions, script VM front end, pause menu | `Scene_`, `Callbacks_`, `Game_`, `ScriptVm_`, `ScriptCmd_`, `PauseMenu_` |
| 0x02023000 | object/task system, game state | `Obj_`, `SubObject_`, `InstantiateClass`, `GameState_` |
| 0x02024000 | 2D backgrounds, graphics packs, archives, printf, bit arrays | `Bg_`, `Gfx_`, `Archive_`, `PrintfDest*`, `BitArray_` |
| 0x02026000 | NitroSystem G3D pieces linked into this range (joint animation, SBC) | `NNSi_G3d*`, `Sbc_` (in `libs/nns/g3d`) |
| 0x02029000 | collision: colliders, room boxes, quad tree | `Collider_`, `RoomBox_`, `QuadTree_` |
| 0x0202a000 | scene nodes, model animation sets | `SceneNode_`, `Anim_`, `ModelAnimSet_` |
| 0x0202b000 | entity manager, actors, rendering, movers | `EntityMgr_`, `Entity_`, `Actor_`, `Render_`, `Mover_` |
| 0x0202e000 | camera animation, quaternions, tile text rendering | `CamAnim_`, `Quat_`, `TileTextRenderer_` |
| 0x02030000 | session, message queue, OAM | `Session_`, `MsgQueue_`, `Oam_` |
| 0x02032000 | slot tables, sound manager, message/text database | `SlotTable_`, `SoundMgr_`, `MsgDb_` |
| 0x02035000 | party state and members | `PartyState_`, `PartyMember_` |
| 0x02036000 | tweens, timers, key repeat, geometry primitives (OBB, capsule, triangle) | `Tween_`, `Stopwatch_`, `OBB_`, `Capsule_` |
| 0x0203b000 | model nodes, SRT, joint models, angle helpers, allocation | `ModelNode_`, `Srt_`, `JointModel_`, `Angle_` |

## Overlays

Players: `ba/ch/<code>/` in each overlay's data names the character (`ro` Roxas, `xo` Xion,
`r2` dual-wield Roxas, ...). The same characters appear in four blocks (ov030-049, ov050-068,
ov070-087, ov088-104), the later ones with fewer characters; they are separate load slots,
presumably one per Mission Mode player. Enemies: every overlay from ov114 to ov301 registers one
entity class with the shared framework (ov107) and loads `Ms/<class>.p`; several classes have
two or three identical copies for the same reason. Enemy names are not established yet, so the
directories use the class id; strings that hint at a boss (`XionShare`, `xig_h_*`, `sa_h_R`) are
listed as evidence.

Each directory sits in the group its kind names: scene -> `scenes/`, sub-screen -> `screens/`,
field module -> `field/`, player -> `players/`, enemy -> `enemies/`, system -> `system/`.

Confidence: H = proven from code or runtime, M = strong evidence, L = best guess (the directory
keeps the bare `ovNNN` until it is confirmed).

| Overlay | Directory | Kind | Functions | Evidence | Confidence |
|---|---|---|---|---|---|
| ov000 | `ov000_title` | scene | 262 | Scene 1 (g_SceneTable); boot logo, title, new-game/load menus (/ttl/ttl.p2, UI/newgame, cm_save); runtime-verified | H |
| ov001 | `ov001_boot` | system | 8 | hardware/VRAM/touch init at boot (ov001_BootInit); DS Protect decrypts it | M |
| ov002 | `ov002_field` | scene | 1478 | Scene 2: all gameplay (story and mission) runs here; HUD, panels, field objects, script commands (/UI/btl, /ba/ch) | H |
| ov003 | `ov003` (proposed `ov003_multi_result`) | scene | 28 | Scene 3; /mrslt/data, per-character def.p.z. Not seen running; the one-player mission results are ov005 | L |
| ov004 | `ov004_calendar` | scene | 83 | Scene 5; UI/cal/*.pak | M |
| ov005 | `ov005_mission_result` | scene | 289 | Scene 6; UI/srslt; runtime: the results screen of a Mission Mode mission (mission points, hearts, munny, EXP, rewards), reached after it ends or is cancelled | H |
| ov006 | `ov006_mission_mode_select` | scene | 194 | Scene 7; UI/mlt; runtime-verified Mission Mode character select (NOT the title) | H |
| ov007 | `ov007_monologue` | scene | 14 | Scene 10; ui/mnl; runtime: Roxas's narration over his portrait after the clock-tower cutscene of day 255, advanced with A (Story Mode then goes 10 -> 5 -> 2) | H |
| ov008 | `ov008_camp_menu` | scene | 1235 | Scene 19; CAMPMENUMNGR (the KH pause/"camp" menu), mission list, shop, grid pages | M |
| ov009 | `ov009_camp_save` | scene | 255 | Scene 9; UI/cm/cm.p2 + cm_save | M |
| ov010 | `ov010` (proposed `ov010_system_message`) | scene | 7 | Scene 12; /UI/sys/sys_&.s.z | L |
| ov011 | `ov011` (proposed `ov011_staff_roll`) | scene | 40 | Scene 8; UI/sf (sf.p2, sffont) scrolling panes | L |
| ov012 | `ov012_opening` | scene | 42 | Scene 11; /op/op.p2 + MobiClip stream | M |
| ov013 | `ov013` (proposed `ov013_battle_collision`) | field module | 7 | col_btl resource task | L |
| ov014 | `ov014` (proposed `ov014_field_movers`) | field module | 37 | height-motion platforms, instance pools | L |
| ov015 | `ov015_field_pickups` | field module | 70 | spots, pickups, chests | M |
| ov016 | `ov016_field_breakables` | field module | 82 | kickable/breakable objects, followers | M |
| ov017 | `ov017_field_deposits` | field module | 45 | item deposit objects | M |
| ov018 | (no code or data) | empty | 0 | no code or data | H |
| ov019 | `ov019` | field module | 5 | record/stat high-water message (5 functions) | L |
| ov020 | `ov020` (proposed `ov020_field_walls`) | field module | 11 | col_wall script entities | L |
| ov021 | `ov021_prize_boxes` | field module | 31 | prize boxes and emblems | M |
| ov022 | `ov022_battle` | field module | 758 | player/party battle system: command input, hits, stun, actor update (/ba/ef) | M |
| ov023 | `ov023_event_script` | field module | 224 | event-script VM commands on actors/entities | H |
| ov024 | `ov024_mobiclip` | system | 108 | MobiClip video decoder/player (C++) | H |
| ov025 | `ov025_camp_menu_2` | sub-screen | 1003 | byte-level copy of the ov008 menu code (CAMPMENUMNGR) | M |
| ov026 | `ov026_shop` | sub-screen | 256 | UI/shop | M |
| ov027 | `ov027_game_over` | sub-screen | 43 | /gameover/data | H |
| ov028 | `ov028_dsprotect` | system | 9 | DS Protect anti-tamper (encrypted blocks) | H |
| ov029 | `ov029` | system | 2 | overlay slot acquire/release (2 functions) | L |
| ov030 | `ov030_player_roxas` | player | 41 | ba/ch/ro/ character resources | H |
| ov031 | `ov031_player_axel` | player | 33 | ba/ch/ax/ character resources | H |
| ov032 | `ov032_player_xigbar` | player | 34 | ba/ch/xi/ character resources | H |
| ov033 | `ov033_player_saix` | player | 27 | ba/ch/sa/ character resources | H |
| ov034 | `ov034_player_xaldin` | player | 33 | ba/ch/xa/ character resources | H |
| ov035 | `ov035_player_sora` | player | 31 | ba/ch/so/ character resources | H |
| ov036 | `ov036_player_demyx` | player | 40 | ba/ch/de/ character resources | H |
| ov037 | `ov037_player_larxene` | player | 31 | ba/ch/la/ character resources | H |
| ov038 | `ov038_player_lexaeus` | player | 39 | ba/ch/le/ character resources | H |
| ov039 | `ov039_player_luxord` | player | 37 | ba/ch/lu/ character resources | H |
| ov040 | `ov040_player_marluxia` | player | 32 | ba/ch/ma/ character resources | H |
| ov041 | `ov041_player_riku` | player | 33 | ba/ch/ri/ character resources | H |
| ov042 | `ov042_player_vexen` | player | 28 | ba/ch/ve/ character resources | H |
| ov043 | `ov043_player_xemnas` | player | 46 | ba/ch/xe/ character resources | H |
| ov044 | `ov044_player_xion` | player | 40 | ba/ch/xo/ character resources | H |
| ov045 | `ov045_player_zexion` | player | 27 | ba/ch/ze/ character resources | H |
| ov046 | `ov046_player_mickey` | player | 36 | ba/ch/mi/ character resources | H |
| ov047 | `ov047_player_donald` | player | 24 | ba/ch/do/ character resources | H |
| ov048 | `ov048_player_goofy` | player | 33 | ba/ch/go/ character resources | H |
| ov049 | `ov049_player_roxas_dual` | player | 29 | ba/ch/r2/ character resources | H |
| ov050 | `ov050_player_axel_2` | player | 33 | ba/ch/ax/ character resources | H |
| ov051 | `ov051_player_saix_2` | player | 27 | ba/ch/sa/ character resources | H |
| ov052 | `ov052_player_xigbar_2` | player | 34 | ba/ch/xi/ character resources | H |
| ov053 | `ov053_player_xaldin_2` | player | 33 | ba/ch/xa/ character resources | H |
| ov054 | `ov054_player_sora_2` | player | 31 | ba/ch/so/ character resources | H |
| ov055 | `ov055_player_demyx_2` | player | 40 | ba/ch/de/ character resources | H |
| ov056 | `ov056_player_larxene_2` | player | 31 | ba/ch/la/ character resources | H |
| ov057 | `ov057_player_lexaeus_2` | player | 39 | ba/ch/le/ character resources | H |
| ov058 | `ov058_player_luxord_2` | player | 37 | ba/ch/lu/ character resources | H |
| ov059 | `ov059_player_marluxia_2` | player | 32 | ba/ch/ma/ character resources | H |
| ov060 | `ov060_player_riku_2` | player | 33 | ba/ch/ri/ character resources | H |
| ov061 | `ov061_player_vexen_2` | player | 28 | ba/ch/ve/ character resources | H |
| ov062 | `ov062_player_xemnas_2` | player | 46 | ba/ch/xe/ character resources | H |
| ov063 | `ov063_player_xion_2` | player | 40 | ba/ch/xo/ character resources | H |
| ov064 | `ov064_player_zexion_2` | player | 27 | ba/ch/ze/ character resources | H |
| ov065 | `ov065_player_mickey_2` | player | 36 | ba/ch/mi/ character resources | H |
| ov066 | `ov066_player_donald_2` | player | 24 | ba/ch/do/ character resources | H |
| ov067 | `ov067_player_goofy_2` | player | 33 | ba/ch/go/ character resources | H |
| ov068 | `ov068_player_roxas_dual_2` | player | 29 | ba/ch/r2/ character resources | H |
| ov069 | `ov069` | sub-screen | 49 | item/recipe tallies over the mission list (UI/cm/msl) | L |
| ov070 | `ov070_player_axel_3` | player | 33 | ba/ch/ax/ character resources | H |
| ov071 | `ov071_player_saix_3` | player | 27 | ba/ch/sa/ character resources | H |
| ov072 | `ov072_player_xigbar_3` | player | 34 | ba/ch/xi/ character resources | H |
| ov073 | `ov073_player_xaldin_3` | player | 33 | ba/ch/xa/ character resources | H |
| ov074 | `ov074_player_sora_3` | player | 31 | ba/ch/so/ character resources | H |
| ov075 | `ov075_player_demyx_3` | player | 40 | ba/ch/de/ character resources | H |
| ov076 | `ov076_player_larxene_3` | player | 31 | ba/ch/la/ character resources | H |
| ov077 | `ov077_player_lexaeus_3` | player | 39 | ba/ch/le/ character resources | H |
| ov078 | `ov078_player_luxord_3` | player | 37 | ba/ch/lu/ character resources | H |
| ov079 | `ov079_player_marluxia_3` | player | 32 | ba/ch/ma/ character resources | H |
| ov080 | `ov080_player_riku_3` | player | 33 | ba/ch/ri/ character resources | H |
| ov081 | `ov081_player_vexen_3` | player | 28 | ba/ch/ve/ character resources | H |
| ov082 | `ov082_player_xion_3` | player | 40 | ba/ch/xo/ character resources | H |
| ov083 | `ov083_player_zexion_3` | player | 27 | ba/ch/ze/ character resources | H |
| ov084 | `ov084_player_mickey_3` | player | 36 | ba/ch/mi/ character resources | H |
| ov085 | `ov085_player_donald_3` | player | 24 | ba/ch/do/ character resources | H |
| ov086 | `ov086_player_goofy_3` | player | 33 | ba/ch/go/ character resources | H |
| ov087 | `ov087_player_roxas_dual_3` | player | 29 | ba/ch/r2/ character resources | H |
| ov088 | `ov088_player_axel_4` | player | 33 | ba/ch/ax/ character resources | H |
| ov089 | `ov089_player_saix_4` | player | 27 | ba/ch/sa/ character resources | H |
| ov090 | `ov090_player_xaldin_4` | player | 33 | ba/ch/xa/ character resources | H |
| ov091 | `ov091_player_sora_4` | player | 31 | ba/ch/so/ character resources | H |
| ov092 | `ov092_player_demyx_4` | player | 40 | ba/ch/de/ character resources | H |
| ov093 | `ov093_player_larxene_4` | player | 31 | ba/ch/la/ character resources | H |
| ov094 | `ov094_player_lexaeus_4` | player | 39 | ba/ch/le/ character resources | H |
| ov095 | `ov095_player_luxord_4` | player | 37 | ba/ch/lu/ character resources | H |
| ov096 | `ov096_player_marluxia_4` | player | 32 | ba/ch/ma/ character resources | H |
| ov097 | `ov097_player_riku_4` | player | 33 | ba/ch/ri/ character resources | H |
| ov098 | `ov098_player_vexen_4` | player | 28 | ba/ch/ve/ character resources | H |
| ov099 | `ov099_player_xion_4` | player | 40 | ba/ch/xo/ character resources | H |
| ov100 | `ov100_player_zexion_4` | player | 27 | ba/ch/ze/ character resources | H |
| ov101 | `ov101_player_mickey_4` | player | 36 | ba/ch/mi/ character resources | H |
| ov102 | `ov102_player_donald_4` | player | 24 | ba/ch/do/ character resources | H |
| ov103 | `ov103_player_goofy_4` | player | 33 | ba/ch/go/ character resources | H |
| ov104 | `ov104_player_roxas_dual_4` | player | 29 | ba/ch/r2/ character resources | H |
| ov105 | `ov105_wireless` | system | 80 | NitroSDK WM + wh.c wireless session | H |
| ov106 | `ov106` | sub-screen | 50 | ev/EV_DP.p2, tex_noise, dual3d_update, UI/hcnt | L |
| ov107 | `ov107_enemy_common` | system | 193 | shared enemy/object framework: AI tasks, regions, hit spheres, spawners (Ms/SharedEffect) | H |
| ov108 | (no code or data) | empty | 0 | no code or data | H |
| ov109 | (no code or data) | empty | 0 | no code or data | H |
| ov110 | (no code or data) | empty | 0 | no code or data | H |
| ov111 | (no code or data) | empty | 0 | no code or data | H |
| ov112 | (no code or data) | empty | 0 | no code or data | H |
| ov113 | (no code or data) | empty | 0 | no code or data | H |
| ov114 | `ov114_enemy_00` | enemy | 43 | entity class 0x00, Ms/00.p | H |
| ov115 | `ov115_enemy_01` | enemy | 47 | entity class 0x01, Ms/01.p | H |
| ov116 | `ov116_enemy_01_2` | enemy | 47 | entity class 0x01, Ms/01.p | H |
| ov117 | `ov117_enemy_02` | enemy | 39 | entity class 0x02, Ms/02.p | H |
| ov118 | `ov118_enemy_02_2` | enemy | 39 | entity class 0x02, Ms/02.p | H |
| ov119 | `ov119_enemy_03` | enemy | 56 | entity class 0x03, Ms/03.p | H |
| ov120 | `ov120_enemy_04` | enemy | 40 | entity class 0x04, Ms/04.p | H |
| ov121 | `ov121_enemy_04_2` | enemy | 40 | entity class 0x04, Ms/04.p | H |
| ov122 | `ov122_enemy_04_3` | enemy | 40 | entity class 0x04, Ms/04.p | H |
| ov123 | `ov123_enemy_05` | enemy | 47 | entity class 0x05, Ms/05.p | H |
| ov124 | `ov124_enemy_05_2` | enemy | 47 | entity class 0x05, Ms/05.p | H |
| ov125 | `ov125_enemy_06` | enemy | 66 | entity class 0x06, Ms/06.p | H |
| ov126 | `ov126_enemy_06_2` | enemy | 66 | entity class 0x06, Ms/06.p | H |
| ov127 | `ov127_enemy_07` | enemy | 36 | entity class 0x07, Ms/07.p | H |
| ov128 | `ov128_enemy_07_2` | enemy | 36 | entity class 0x07, Ms/07.p | H |
| ov129 | `ov129_enemy_07_3` | enemy | 36 | entity class 0x07, Ms/07.p | H |
| ov130 | `ov130_enemy_08` | enemy | 36 | entity class 0x08, Ms/08.p | H |
| ov131 | `ov131_enemy_09` | enemy | 55 | entity class 0x09, Ms/09.p | H |
| ov132 | `ov132_enemy_09_2` | enemy | 55 | entity class 0x09, Ms/09.p | H |
| ov133 | `ov133_enemy_09_3` | enemy | 55 | entity class 0x09, Ms/09.p | H |
| ov134 | `ov134_enemy_0a` | enemy | 39 | entity class 0x0a, Ms/0a.p | H |
| ov135 | `ov135_enemy_0a_2` | enemy | 39 | entity class 0x0a, Ms/0a.p | H |
| ov136 | `ov136_enemy_0a_3` | enemy | 39 | entity class 0x0a, Ms/0a.p | H |
| ov137 | `ov137_enemy_0b` | enemy | 64 | entity class 0x0b, Ms/0b.p | H |
| ov138 | `ov138_enemy_0b_2` | enemy | 64 | entity class 0x0b, Ms/0b.p | H |
| ov139 | `ov139_enemy_0c` | enemy | 45 | entity class 0x0c, Ms/0c.p | H |
| ov140 | `ov140_enemy_0c_2` | enemy | 45 | entity class 0x0c, Ms/0c.p | H |
| ov141 | `ov141_enemy_0d` | enemy | 57 | entity class 0x0d, Ms/0d.p | H |
| ov142 | `ov142_enemy_0d_2` | enemy | 57 | entity class 0x0d, Ms/0d.p | H |
| ov143 | `ov143_enemy_0d_3` | enemy | 57 | entity class 0x0d, Ms/0d.p | H |
| ov144 | `ov144_enemy_0e` | enemy | 38 | entity class 0x0e, Ms/0e.p | H |
| ov145 | `ov145_enemy_0f` | enemy | 38 | entity class 0x0f, Ms/0f.p | H |
| ov146 | `ov146_enemy_10` | enemy | 88 | entity class 0x10, Ms/10.p | H |
| ov147 | `ov147_enemy_11` | enemy | 62 | entity class 0x11, Ms/11.p | H |
| ov148 | `ov148_enemy_11_2` | enemy | 62 | entity class 0x11, Ms/11.p | H |
| ov149 | `ov149_enemy_12` | enemy | 57 | entity class 0x12, Ms/12.p | H |
| ov150 | `ov150_enemy_12_2` | enemy | 57 | entity class 0x12, Ms/12.p | H |
| ov151 | `ov151_enemy_13` | enemy | 56 | entity class 0x13, Ms/13.p | H |
| ov152 | `ov152_enemy_13_2` | enemy | 56 | entity class 0x13, Ms/13.p | H |
| ov153 | `ov153_enemy_14` | enemy | 45 | entity class 0x14, Ms/14.p | H |
| ov154 | `ov154_enemy_14_2` | enemy | 45 | entity class 0x14, Ms/14.p | H |
| ov155 | `ov155_enemy_14_3` | enemy | 45 | entity class 0x14, Ms/14.p | H |
| ov156 | `ov156_enemy_15` | enemy | 50 | entity class 0x15, Ms/15.p | H |
| ov157 | `ov157_enemy_15_2` | enemy | 50 | entity class 0x15, Ms/15.p | H |
| ov158 | `ov158_enemy_16` | enemy | 64 | entity class 0x16, Ms/16.p | H |
| ov159 | `ov159_enemy_16_2` | enemy | 64 | entity class 0x16, Ms/16.p | H |
| ov160 | `ov160_enemy_17` | enemy | 63 | entity class 0x17, Ms/17.p | H |
| ov161 | `ov161_enemy_18` | enemy | 60 | entity class 0x18, Ms/18.p | H |
| ov162 | `ov162_enemy_18_2` | enemy | 60 | entity class 0x18, Ms/18.p | H |
| ov163 | `ov163_enemy_19` | enemy | 56 | entity class 0x19, Ms/19.p | H |
| ov164 | `ov164_enemy_19_2` | enemy | 56 | entity class 0x19, Ms/19.p | H |
| ov165 | `ov165_enemy_19_3` | enemy | 56 | entity class 0x19, Ms/19.p | H |
| ov166 | `ov166_enemy_1a` | enemy | 55 | entity class 0x1a, Ms/1a.p | H |
| ov167 | `ov167_enemy_1a_2` | enemy | 55 | entity class 0x1a, Ms/1a.p | H |
| ov168 | `ov168_enemy_1a_3` | enemy | 55 | entity class 0x1a, Ms/1a.p | H |
| ov169 | `ov169_enemy_1b` | enemy | 57 | entity class 0x1b, Ms/1b.p | H |
| ov170 | `ov170_enemy_1b_2` | enemy | 57 | entity class 0x1b, Ms/1b.p | H |
| ov171 | `ov171_enemy_1c` | enemy | 56 | entity class 0x1c, Ms/1c.p | H |
| ov172 | `ov172_enemy_1c_2` | enemy | 56 | entity class 0x1c, Ms/1c.p | H |
| ov173 | `ov173_enemy_1d` | enemy | 51 | entity class 0x1d, Ms/1d.p | H |
| ov174 | `ov174_enemy_1d_2` | enemy | 51 | entity class 0x1d, Ms/1d.p | H |
| ov175 | `ov175_enemy_1e` | enemy | 55 | entity class 0x1e, Ms/1e.p | H |
| ov176 | `ov176_enemy_1e_2` | enemy | 55 | entity class 0x1e, Ms/1e.p | H |
| ov177 | `ov177_enemy_1e_3` | enemy | 55 | entity class 0x1e, Ms/1e.p | H |
| ov178 | `ov178_enemy_1f` | enemy | 62 | entity class 0x1f, Ms/1f.p | H |
| ov179 | `ov179_enemy_1f_2` | enemy | 62 | entity class 0x1f, Ms/1f.p | H |
| ov180 | `ov180_enemy_1f_3` | enemy | 62 | entity class 0x1f, Ms/1f.p | H |
| ov181 | `ov181_enemy_20` | enemy | 52 | entity class 0x20, Ms/20.p | H |
| ov182 | `ov182_enemy_20_2` | enemy | 52 | entity class 0x20, Ms/20.p | H |
| ov183 | `ov183_enemy_20_3` | enemy | 52 | entity class 0x20, Ms/20.p | H |
| ov184 | `ov184_enemy_20_4` | enemy | 52 | entity class 0x20, Ms/20.p | H |
| ov185 | `ov185_enemy_21` | enemy | 76 | entity class 0x21, Ms/21.p | H |
| ov186 | `ov186_enemy_21_2` | enemy | 76 | entity class 0x21, Ms/21.p | H |
| ov187 | `ov187_enemy_21_3` | enemy | 76 | entity class 0x21, Ms/21.p | H |
| ov188 | `ov188_enemy_22` | enemy | 48 | entity class 0x22, Ms/22.p | H |
| ov189 | `ov189_enemy_22_2` | enemy | 48 | entity class 0x22, Ms/22.p | H |
| ov190 | `ov190_enemy_22_3` | enemy | 48 | entity class 0x22, Ms/22.p | H |
| ov191 | `ov191_enemy_23` | enemy | 54 | entity class 0x23, Ms/23.p | H |
| ov192 | `ov192_enemy_23_2` | enemy | 54 | entity class 0x23, Ms/23.p | H |
| ov193 | `ov193_enemy_23_3` | enemy | 54 | entity class 0x23, Ms/23.p | H |
| ov194 | `ov194_enemy_24` | enemy | 50 | entity class 0x24, Ms/24.p | H |
| ov195 | `ov195_enemy_24_2` | enemy | 50 | entity class 0x24, Ms/24.p | H |
| ov196 | `ov196_enemy_24_3` | enemy | 50 | entity class 0x24, Ms/24.p | H |
| ov197 | `ov197_enemy_25` | enemy | 62 | entity class 0x25, Ms/25.p | H |
| ov198 | `ov198_enemy_25_2` | enemy | 62 | entity class 0x25, Ms/25.p | H |
| ov199 | `ov199_enemy_25_3` | enemy | 62 | entity class 0x25, Ms/25.p | H |
| ov200 | `ov200_enemy_26` | enemy | 60 | entity class 0x26, Ms/26.p | H |
| ov201 | `ov201_enemy_26_2` | enemy | 60 | entity class 0x26, Ms/26.p | H |
| ov202 | `ov202_enemy_27` | enemy | 56 | entity class 0x27, Ms/27.p | H |
| ov203 | `ov203_enemy_27_2` | enemy | 56 | entity class 0x27, Ms/27.p | H |
| ov204 | `ov204_enemy_28` | enemy | 54 | entity class 0x28, Ms/28.p | H |
| ov205 | `ov205_enemy_28_2` | enemy | 54 | entity class 0x28, Ms/28.p | H |
| ov206 | `ov206_enemy_29` | enemy | 63 | entity class 0x29, Ms/29.p | H |
| ov207 | `ov207_enemy_29_2` | enemy | 63 | entity class 0x29, Ms/29.p | H |
| ov208 | `ov208_enemy_2a` | enemy | 81 | entity class 0x2a, Ms/2a.p | H |
| ov209 | `ov209_enemy_2a_2` | enemy | 81 | entity class 0x2a, Ms/2a.p | H |
| ov210 | `ov210_enemy_2b` | enemy | 83 | entity class 0x2b, Ms/2b.p; n_shadow | H |
| ov211 | `ov211_enemy_2b_2` | enemy | 83 | entity class 0x2b, Ms/2b.p; n_shadow | H |
| ov212 | `ov212_enemy_2c` | enemy | 119 | entity class 0x2c, Ms/2c.p | H |
| ov213 | `ov213_enemy_2d` | enemy | 116 | entity class 0x2d, Ms/2d.p; sword | H |
| ov214 | `ov214_enemy_2e` | enemy | 50 | entity class 0x2e, Ms/2e.p | H |
| ov215 | `ov215_enemy_2e_2` | enemy | 50 | entity class 0x2e, Ms/2e.p | H |
| ov216 | `ov216_enemy_2f` | enemy | 50 | entity class 0x2f, Ms/2f.p | H |
| ov217 | `ov217_enemy_2f_2` | enemy | 50 | entity class 0x2f, Ms/2f.p | H |
| ov218 | `ov218_enemy_30` | enemy | 73 | entity class 0x30, Ms/30.p | H |
| ov219 | `ov219_enemy_31` | enemy | 42 | entity class 0x31, Ms/31.p | H |
| ov220 | `ov220_enemy_32` | enemy | 50 | entity class 0x32, Ms/32.p | H |
| ov221 | `ov221_enemy_33` | enemy | 84 | entity class 0x33, Ms/33.p | H |
| ov222 | `ov222_enemy_33_2` | enemy | 84 | entity class 0x33, Ms/33.p | H |
| ov223 | `ov223_enemy_34` | enemy | 91 | entity class 0x34, Ms/34.p | H |
| ov224 | `ov224_enemy_35` | enemy | 84 | entity class 0x35, Ms/35.p | H |
| ov225 | `ov225_enemy_36` | enemy | 87 | entity class 0x36, Ms/36.p | H |
| ov226 | `ov226_enemy_37` | enemy | 80 | entity class 0x37, Ms/37.p | H |
| ov227 | `ov227_enemy_38` | enemy | 84 | entity class 0x38, Ms/38.p | H |
| ov228 | `ov228_enemy_39` | enemy | 81 | entity class 0x39, Ms/39.p | H |
| ov229 | `ov229_enemy_39_2` | enemy | 81 | entity class 0x39, Ms/39.p | H |
| ov230 | `ov230_enemy_3a` | enemy | 74 | entity class 0x3a, Ms/3a.p | H |
| ov231 | `ov231_enemy_3b` | enemy | 65 | entity class 0x3b, Ms/3b.p | H |
| ov232 | `ov232_enemy_3b_2` | enemy | 65 | entity class 0x3b, Ms/3b.p | H |
| ov233 | `ov233_enemy_3c` | enemy | 81 | entity class 0x3c, Ms/3c.p | H |
| ov234 | `ov234_enemy_3d` | enemy | 21 | entity class 0x3d, Ms/3d.p | H |
| ov235 | `ov235_enemy_3e` | enemy | 97 | entity class 0x3e, Ms/3e.p; 1_1_sword, Ms/XionShare.p | H |
| ov236 | `ov236_enemy_3f` | enemy | 153 | entity class 0x3f, Ms/3f.p | H |
| ov237 | `ov237_enemy_40` | enemy | 86 | entity class 0x40, Ms/40.p | H |
| ov238 | `ov238_enemy_41` | enemy | 72 | entity class 0x41, Ms/41.p | H |
| ov239 | `ov239_enemy_42` | enemy | 42 | entity class 0x42, Ms/42.p; Ms/NBShare.p | H |
| ov240 | `ov240_enemy_43` | enemy | 42 | entity class 0x43, Ms/43.p; Ms/NBShare.p | H |
| ov241 | `ov241_enemy_44` | enemy | 26 | entity class 0x44, Ms/44.p | H |
| ov242 | `ov242_enemy_44_2` | enemy | 26 | entity class 0x44, Ms/44.p | H |
| ov243 | `ov243_enemy_45` | enemy | 26 | entity class 0x45, Ms/45.p | H |
| ov244 | `ov244_enemy_46` | enemy | 143 | entity class 0x46, Ms/46.p | H |
| ov245 | `ov245_enemy_47` | enemy | 264 | entity class 0x47, Ms/47.p | H |
| ov246 | `ov246_enemy_48` | enemy | 64 | entity class 0x48, Ms/48.p | H |
| ov247 | `ov247_enemy_48_2` | enemy | 64 | entity class 0x48, Ms/48.p | H |
| ov248 | `ov248_enemy_49` | enemy | 78 | entity class 0x49, Ms/49.p | H |
| ov249 | `ov249_enemy_4a` | enemy | 78 | entity class 0x4a, Ms/4a.p | H |
| ov250 | `ov250_enemy_4b` | enemy | 52 | entity class 0x4b, Ms/4b.p | H |
| ov251 | `ov251_enemy_4b_2` | enemy | 52 | entity class 0x4b, Ms/4b.p | H |
| ov252 | `ov252_enemy_4c` | enemy | 94 | entity class 0x4c, Ms/4c.p | H |
| ov253 | `ov253_enemy_4d` | enemy | 165 | entity class 0x4d, Ms/4d.p | H |
| ov254 | `ov254_enemy_4e` | enemy | 183 | entity class 0x4e, Ms/4e.p | H |
| ov255 | `ov255_enemy_4f` | enemy | 112 | entity class 0x4f, Ms/4f.p; Ms/XionShare.p | H |
| ov256 | `ov256_enemy_50` | enemy | 113 | entity class 0x50, Ms/50.p | H |
| ov257 | `ov257_enemy_51` | enemy | 95 | entity class 0x51, Ms/51.p; Ms/XionShare.p | H |
| ov258 | `ov258_enemy_52` | enemy | 81 | entity class 0x52, Ms/52.p | H |
| ov259 | `ov259_enemy_53` | enemy | 121 | entity class 0x53, Ms/53.p; sa_h_R | H |
| ov260 | `ov260_enemy_54` | enemy | 110 | entity class 0x54, Ms/54.p | H |
| ov261 | `ov261_enemy_55` | enemy | 35 | entity class 0x55, Ms/55.p; zero_ef_dummy | H |
| ov262 | `ov262_enemy_55_2` | enemy | 35 | entity class 0x55, Ms/55.p; zero_ef_dummy | H |
| ov263 | `ov263_enemy_57` | enemy | 65 | entity class 0x57, Ms/57.p | H |
| ov264 | `ov264_enemy_58` | enemy | 50 | entity class 0x58, Ms/58.p | H |
| ov265 | `ov265_enemy_59` | enemy | 65 | entity class 0x59, Ms/59.p | H |
| ov266 | `ov266_enemy_5a` | enemy | 119 | entity class 0x5a, Ms/5a.p | H |
| ov267 | `ov267_enemy_5a_2` | enemy | 119 | entity class 0x5a, Ms/5a.p | H |
| ov268 | `ov268_enemy_5b` | enemy | 81 | entity class 0x5b, Ms/5b.p | H |
| ov269 | `ov269_enemy_5c` | enemy | 50 | entity class 0x5c, Ms/5c.p | H |
| ov270 | `ov270_enemy_5c_2` | enemy | 50 | entity class 0x5c, Ms/5c.p | H |
| ov271 | `ov271_enemy_5d` | enemy | 60 | entity class 0x5d, Ms/5d.p | H |
| ov272 | `ov272_enemy_5e` | enemy | 56 | entity class 0x5e, Ms/5e.p | H |
| ov273 | `ov273_enemy_5f` | enemy | 116 | entity class 0x5f, Ms/5f.p; sword | H |
| ov274 | `ov274_enemy_60` | enemy | 63 | entity class 0x60, Ms/60.p | H |
| ov275 | `ov275_enemy_60_2` | enemy | 63 | entity class 0x60, Ms/60.p | H |
| ov276 | `ov276_enemy_61` | enemy | 50 | entity class 0x61, Ms/61.p | H |
| ov277 | `ov277_enemy_62` | enemy | 143 | entity class 0x62, Ms/62.p | H |
| ov278 | `ov278_enemy_63` | enemy | 153 | entity class 0x63, Ms/63.p | H |
| ov279 | `ov279_enemy_64` | enemy | 56 | entity class 0x64, Ms/64.p | H |
| ov280 | `ov280_enemy_65` | enemy | 65 | entity class 0x65, Ms/65.p | H |
| ov281 | `ov281_enemy_66` | enemy | 48 | entity class 0x66, Ms/66.p | H |
| ov282 | `ov282_enemy_67` | enemy | 83 | entity class 0x67, Ms/67.p; Sn_shadow | H |
| ov283 | `ov283_enemy_68` | enemy | 81 | entity class 0x68, Ms/68.p; xig_h_L, xig_h_R | H |
| ov284 | `ov284_enemy_69` | enemy | 33 | entity class 0x69, Ms/69.p | H |
| ov285 | `ov285_enemy_6a` | enemy | 23 | entity class 0x6a, Ms/6a.p | H |
| ov286 | `ov286_enemy_6a_2` | enemy | 23 | entity class 0x6a, Ms/6a.p | H |
| ov287 | `ov287_enemy_6b` | enemy | 26 | entity class 0x6b, Ms/6b.p | H |
| ov288 | `ov288_enemy_6b_2` | enemy | 26 | entity class 0x6b, Ms/6b.p | H |
| ov289 | `ov289_enemy_6b_3` | enemy | 26 | entity class 0x6b, Ms/6b.p | H |
| ov290 | `ov290_enemy_6c` | enemy | 3 | entity class 0x6c, Ms/6c.p | H |
| ov291 | `ov291_enemy_6d` | enemy | 32 | entity class 0x6d, Ms/6d.p | H |
| ov292 | `ov292_enemy_6e` | enemy | 31 | entity class 0x6e, Ms/6e.p | H |
| ov293 | `ov293_enemy_6f` | enemy | 37 | entity class 0x6f, Ms/6f.p | H |
| ov294 | `ov294_enemy_70` | enemy | 14 | entity class 0x70, Ms/70.p | H |
| ov295 | `ov295_enemy_70_2` | enemy | 14 | entity class 0x70, Ms/70.p | H |
| ov296 | `ov296_enemy_70_3` | enemy | 14 | entity class 0x70, Ms/70.p | H |
| ov297 | `ov297_enemy_71` | enemy | 39 | entity class 0x71, Ms/71.p | H |
| ov298 | `ov298_enemy_72` | enemy | 37 | entity class 0x72, Ms/72.p | H |
| ov299 | `ov299_enemy_73` | enemy | 31 | entity class 0x73, Ms/73.p | H |
| ov300 | `ov300_enemy_74` | enemy | 3 | entity class 0x74, Ms/74.p | H |
| ov301 | `ov301_enemy_75` | enemy | 18 | entity class 0x75, Ms/75.p | H |
| ov302 | `ov302` | field module | 25 | world-id record filters | L |
