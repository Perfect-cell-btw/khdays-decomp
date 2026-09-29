/* Ov008_DrawStringOptShadow -- draw a string, optionally with a 1px drop shadow (param_5) one colour
 * darker. Flags are fixed at 0x411.
 *
 * PROVENANCE: byte-identical twin of Ov025_DrawStringOptShadow -- same code, this overlay's own
 * globals, propagated mechanically and verified byte-exact.
 * The scene-identity phrasing that came with the twin source (Mission Mode / char select /
 * ov025 panel) is the REP's, NOT established for ov008, so it was removed rather than
 * carried over. What IS measured: ov008's own strings include UI/mlt/res.p2 (the same pack
 * ov006 loads) plus UI/cm/*.p2 and ba/ch/*, so resource detail naming those is sound; the
 * scene label is not. The offsets and logic below are this function's -- the code is
 * byte-identical to the rep.
 */

#include "game/engine.h"

void Ov008_DrawStringOptShadow(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    if (param_5 != 0) {
        Text_DrawDirectional_2(param_1, param_2 + 1, param_3 + 1, param_4 - 1, 0x411, param_6);
    }
    Text_DrawDirectional_2(param_1, param_2, param_3, param_4, 0x411, param_6);
}
