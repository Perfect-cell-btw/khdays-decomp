#ifndef GAME_ENEMY_ID_H
#define GAME_ENEMY_ID_H

/* Enemy class ids: the id each enemy overlay (ov114-ov301) registers its factory under with the
 * shared enemy framework (Ov107_RegisterHandler), the index of its resource pack Ms/<id>.p and of
 * its name in the battle UI's name list UI/btl/<lang>/enemy.s. Named after that English list; the
 * model is the one Ms/<id>.p holds.
 *
 * The name list agrees with the packs wherever a model is named (shadow, Yellow, Icecube, n_shadow,
 * DS01, xigbar, ...), and ov002's name panel (Ov002_BuildPanelLabels) swaps 0x53 and 0x54 for list
 * entries 0x75 and 0x76, "Anti-Saix" and "Anti-Riku", under two mode bits. Those two entries are
 * alternative names, not classes: class 0x75 has no name of its own. Classes shown under the same
 * name carry their id (four Xion, two Pete, a second Shadow). 0x56 and 0x6c have no pack; 0x56 has
 * no overlay either. */

#define ENEMY_SHADOW              0x00  /* Shadow (model "shadow") */
#define ENEMY_YELLOW_OPERA        0x01  /* Yellow Opera (model "Yellow") */
#define ENEMY_POSSESSOR           0x02  /* Possessor (model "Posessar") */
#define ENEMY_HOVER_GHOST         0x03  /* Hover Ghost (model "006") */
#define ENEMY_SOLDIER             0x04  /* Soldier (model "007") */
#define ENEMY_DIRE_PLANT          0x05  /* Dire Plant (model "Creepplant") */
#define ENEMY_WATCHER             0x06  /* Watcher (model "011") */
#define ENEMY_BULKY_VENDOR        0x07  /* Bulky Vendor (model "012") */
#define ENEMY_RARE_VENDOR         0x08  /* Rare Vendor (model "013") */
#define ENEMY_MINUTE_BOMB         0x09  /* Minute Bomb (model "014") */
#define ENEMY_BAD_DOG             0x0a  /* Bad Dog (model "015") */
#define ENEMY_LIL_CANNON          0x0b  /* Li'l Cannon (model "017") */
#define ENEMY_ICY_CUBE            0x0c  /* Icy Cube (model "Icecube") */
#define ENEMY_LOUDMOUTH           0x0d  /* Loudmouth (model "Loudness") */
#define ENEMY_RED_CARD_SOLDIER    0x0e  /* Red Card Soldier (model "002") */
#define ENEMY_BLACK_CARD_SOLDIER  0x0f  /* Black Card Soldier (model "001") */
#define ENEMY_BARRIER_MASTER      0x10  /* Barrier Master (model "BM01") */
#define ENEMY_CYMBAL_MONKEY       0x11  /* Cymbal Monkey (model "S_Monkey") */
#define ENEMY_FLARE_NOTE          0x12  /* Flare Note (model "F_Loudness") */
#define ENEMY_BUBBLE_BEAT         0x13  /* Bubble Beat (model "W_Loudness") */
#define ENEMY_FIRE_PLANT          0x14  /* Fire Plant (model "F_Creepplant") */
#define ENEMY_BLIZZARD_PLANT      0x15  /* Blizzard Plant (model "I_Creepplant") */
#define ENEMY_ICE_CANNON          0x16  /* Ice Cannon (model "036") */
#define ENEMY_SWITCH_LAUNCHER     0x17  /* Switch Launcher (model "037") */
#define ENEMY_STORM_BOMB          0x18  /* Storm Bomb (model "032") */
#define ENEMY_SKATER_BOMB         0x19  /* Skater Bomb (model "033") */
#define ENEMY_SCARLET_TANGO       0x1a  /* Scarlet Tango (model "F_Opera") */
#define ENEMY_TURQUOISE_MARCH     0x1b  /* Turquoise March (model "W_Opera") */
#define ENEMY_GREY_CAPRICE        0x1c  /* Grey Caprice (model "Sp_Opera") */
#define ENEMY_SAPPHIRE_ELEGY      0x1d  /* Sapphire Elegy (model "P_Opera") */
#define ENEMY_STRIPED_ARIA        0x1e  /* Striped Aria (model "T_Opera") */
#define ENEMY_PINK_CONCERTO       0x1f  /* Pink Concerto (model "Flo_Opera") */
#define ENEMY_MEGA_SHADOW         0x20  /* Mega-Shadow (model "B_shadow") */
#define ENEMY_MASSIVE_POSSESSOR   0x21  /* Massive Possessor (model "B_Posessar") */
#define ENEMY_SERGEANT            0x22  /* Sergeant (model "008") */
#define ENEMY_POISON_PLANT        0x23  /* Poison Plant (model "BCreepplant") */
#define ENEMY_SNAPPER_DOG         0x24  /* Snapper Dog (model "016") */
#define ENEMY_TRICKY_MONKEY       0x25  /* Tricky Monkey (model "BS_Monkey") */
#define ENEMY_GUARDIAN            0x26  /* Guardian (model "039") */
#define ENEMY_DETONATOR           0x27  /* Detonator (model "034") */
#define ENEMY_SNOWY_CRYSTAL       0x28  /* Snowy Crystal (model "B_Icecube") */
#define ENEMY_LARGE_ARMOR         0x29  /* Large Armor (model "largebody") */
#define ENEMY_CLAY_ARMOR          0x2a  /* Clay Armor (model "Rockarmor") */
#define ENEMY_NEOSHADOW           0x2b  /* Neoshadow (model "n_shadow") */
#define ENEMY_VEIL_LIZARD         0x2c  /* Veil Lizard (model "020") */
#define ENEMY_INVISIBLE           0x2d  /* Invisible (model "Invisible") */
#define ENEMY_MORNING_STAR        0x2e  /* Morning Star (model "029") */
#define ENEMY_SCORCHING_SPHERE    0x2f  /* Scorching Sphere (model "028") */
#define ENEMY_LOCK                0x30  /* Lock (model "037") */
#define ENEMY_SHOCK               0x31  /* Shock (model "038") */
#define ENEMY_BARREL              0x32  /* Barrel (model "039") */
#define ENEMY_TAILBUNKER          0x33  /* Tailbunker (model "030") */
#define ENEMY_WAVECREST           0x34  /* Wavecrest (model "031") */
#define ENEMY_AVALANCHE           0x35  /* Avalanche (model "032") */
#define ENEMY_PHANTOMTAIL         0x36  /* Phantomtail (model "035") */
#define ENEMY_WINDSTORM           0x37  /* Windstorm (model "033") */
#define ENEMY_DUSTFLIER           0x38  /* Dustflier (model "034") */
#define ENEMY_DUAL_BLADE          0x39  /* Dual Blade (model "A_knight") */
#define ENEMY_BLITZ_SPEAR         0x3a  /* Blitz Spear (model "AE_knight") */
#define ENEMY_AIR_BATTLER         0x3b  /* Air Battler (model "040") */
#define ENEMY_STALWART_BLADE      0x3c  /* Stalwart Blade (model "SA2_knight") */
#define ENEMY_BALL                0x3d  /* Ball (model "058_ball") */
#define ENEMY_XION_3E             0x3e  /* Xion */
#define ENEMY_GUARD_ARMOR         0x3f  /* Guard Armor (model "001_body") */
#define ENEMY_CRIMSON_PRANKSTER   0x40  /* Crimson Prankster (model "031A") */
#define ENEMY_PETE_41             0x41  /* Pete (model "015") */
#define ENEMY_DUSK                0x42  /* Dusk (model "050") */
#define ENEMY_SAMURAI             0x43  /* Samurai (model "051") */
#define ENEMY_LUMIERE             0x44  /* Lumiere (model "004") */
#define ENEMY_COGSWORTH           0x45  /* Cogsworth (model "005") */
#define ENEMY_DARKSIDE            0x46  /* Darkside (model "DS01") */
#define ENEMY_INFERNAL_ENGINE     0x47  /* Infernal Engine (model "014") */
#define ENEMY_JUMBO_CANNON        0x48  /* Jumbo Cannon (model "038") */
#define ENEMY_CHILL_RIPPER        0x49  /* Chill Ripper (model "AI_knight") */
#define ENEMY_HEAT_SABER          0x4a  /* Heat Saber (model "AF_knight") */
#define ENEMY_GIGAS_SHADOW        0x4b  /* Gigas Shadow (model "B2_shadow") */
#define ENEMY_RULER_OF_THE_SKY    0x4c  /* Ruler of the Sky */
#define ENEMY_LEECHGRAVE          0x4d  /* Leechgrave (model "004A") */
#define ENEMY_ANTLION             0x4e  /* Antlion (model "B5_01body") */
#define ENEMY_XION_4F             0x4f  /* Xion (model "B50B_01body") */
#define ENEMY_CROOKED_CHARIOT     0x50  /* Crooked Chariot */
#define ENEMY_XION_51             0x51  /* Xion (model "B50C_body") */
#define ENEMY_XION_52             0x52  /* Xion (model "051A") */
#define ENEMY_SAIX                0x53  /* Saix (model "016") */
#define ENEMY_RIKU                0x54  /* Riku (model "B13_01body") */
#define ENEMY_ZERO                0x55  /* Zero (model "e_zer_hb") */
#define ENEMY_SHADOW_56           0x56  /* Shadow (model "S_shadow") */
#define ENEMY_SKY_GRAPPLER        0x57  /* Sky Grappler (model "042") */
#define ENEMY_SPIKED_CRAWLER      0x58  /* Spiked Crawler (model "036") */
#define ENEMY_AERIAL_MASTER       0x59  /* Aerial Master (model "043") */
#define ENEMY_LURK_LIZARD         0x5a  /* Lurk Lizard (model "021") */
#define ENEMY_LAND_ARMOR          0x5b  /* Land Armor (model "SRockarmor") */
#define ENEMY_BULLY_DOG           0x5c  /* Bully Dog (model "047") */
#define ENEMY_DESTROYER           0x5d  /* Destroyer (model "042") */
#define ENEMY_LIVING_POD          0x5e  /* Living Pod (model "041") */
#define ENEMY_ORCUS               0x5f  /* Orcus (model "SInvisible") */
#define ENEMY_SOLID_ARMOR         0x60  /* Solid Armor (model "Slargebody") */
#define ENEMY_ZIP_SLASHER         0x61  /* Zip Slasher (model "SA_knight") */
#define ENEMY_DARK_FOLLOWER       0x62  /* Dark Follower (model "SDS01") */
#define ENEMY_POWERED_ARMOR       0x63  /* Powered Armor (model "S001_body") */
#define ENEMY_CARRIER_GHOST       0x64  /* Carrier Ghost (model "046") */
#define ENEMY_ARTFUL_FLYER        0x65  /* Artful Flyer (model "041") */
#define ENEMY_COMMANDER           0x66  /* Commander (model "045") */
#define ENEMY_NOVASHADOW          0x67  /* Novashadow (model "Sn_shadow") */
#define ENEMY_XIGBAR              0x68  /* Xigbar (model "xigbar") */
#define ENEMY_TENTACLAW           0x69  /* Tentaclaw (model "004D") */
#define ENEMY_CREEPWORM           0x6a  /* Creepworm (model "004E") */
#define ENEMY_TRAINING_BARREL     0x6b  /* Training Barrel (model "taru") */
#define ENEMY_DUMMY_PLAYER        0x6c  /* Dummy Player */
#define ENEMY_PETE_6D             0x6d  /* Pete (model "015") */
#define ENEMY_EMERALD_SERENADE    0x6e  /* Emerald Serenade (model "Es_Opera") */
#define ENEMY_DESERTER            0x6f  /* Deserter (model "060") */
#define ENEMY_SHADOW_GLOB         0x70  /* Shadow Glob (model "057_body") */
#define ENEMY_MYSTERY_71          0x71  /* shown as "? ? ? ?" (model "016") */
#define ENEMY_MYSTERY_72          0x72  /* shown as "? ? ? ?" (model "017") */
#define ENEMY_TURRET              0x73  /* Turret (model "E001") */
#define ENEMY_DEVICE              0x74  /* Device (model "lasObj") */
#define ENEMY_TT_LEAF             0x75  /* no name of its own (model "tt_leaf") */

#endif /* GAME_ENEMY_ID_H */
