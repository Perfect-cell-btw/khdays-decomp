/* Resolves the mission enemy's state handler: 0x21 clears the owner block's +0x124 request,
 * enters mode 0x2f through the +0x664 hook and returns the 3e24 tick; 0x22 seeds the block's
 * +0xc speed with 0xf6 (scaled by 1.5 at 20 fps), clears +4 / +0x124, enters mode 0x30
 * and returns the 4168 tick; 0x23 enters mode 0x31 and returns the 43dc tick. Unknown states
 * return no handler.
 *
 * In case 0x21 the handler is assigned BEFORE the zero store: the store reuses the handler's
 * initial zero (r5) as its source, and with the assignment first mwcc emits the `mov r5,#0`
 * at the top of the function (the ROM's second instruction) instead of after the switch
 * compare. */

#include "game/engine.h"

extern void Ov043_HoverStep(void);
extern void Ov043_ChargeStep(void);
extern void Ov043_LandingStep(void);
extern char *data_ov043_020b58e0;

static inline int FX_Mul(int a, int b)
{
    return (int)(((long long)a * b + 0x800) >> 12);
}

void *Ov043_ResolveStateHandler(char *self, int nState)
{
    char *pBlock = data_ov043_020b58e0 + 0x138 + 0x2c00;
    void *pHandler = 0;

    switch (nState) {
    case 0x21:
        pHandler = (void *)&Ov043_HoverStep;
        *(int *)(pBlock + 0x124) = 0;
        (*(void (**)(char *, int))(self + 0x664))(self, 0x2f);
        break;
    case 0x22:
        *(int *)(pBlock + 0xc) = 0xf6;
        pHandler = (void *)&Ov043_ChargeStep;
        if (GetFrameRateMode() == 1) {
            *(int *)(pBlock + 0xc) = FX_Mul(*(int *)(pBlock + 0xc), 0x1800);
        }
        *(int *)(pBlock + 4) = 0;
        *(int *)(pBlock + 0x124) = 0;
        (*(void (**)(char *, int))(self + 0x664))(self, 0x30);
        break;
    case 0x23:
        pHandler = (void *)&Ov043_LandingStep;
        (*(void (**)(char *, int))(self + 0x664))(self, 0x31);
        break;
    }
    return pHandler;
}
