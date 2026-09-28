/* Updates each used row's number tags (three digits, value and availability). */

#include "nitro/types.h"

typedef struct Ov009PageCursor {
    u8 pad000[0x14];
    u16 quantity;
    u8 pad016[6];
    int signedValue;
    u8 pad020[4];
    int state;
    int availability;
} Ov009PageCursor;

extern Ov009PageCursor *Ov009_GetPageA(void);
extern int Ov009_GetDecimalDigit(int part, int quantity);
extern void Ov009_ConfigureTagBySign(int tag, int value);
extern const int data_ov009_020560a8[3][8];

void Ov009_SaveMenu_UpdateNumbers(void)
{
    int parts[3] = {0, 0, 0};
    Ov009PageCursor *page = Ov009_GetPageA();
    int rowIndex = 0;

    do {
        if (page->state == 1) {
            int partIndex;
            int quantity = page->quantity;

            if (quantity > 999) {
                quantity = 999;
            }

            partIndex = 0;
            do {
                parts[partIndex] = Ov009_GetDecimalDigit(partIndex, quantity);
                partIndex++;
            } while (partIndex < 3);

            Ov009_ConfigureTagBySign(data_ov009_020560a8[rowIndex][5], parts[0]);
            Ov009_ConfigureTagBySign(data_ov009_020560a8[rowIndex][6], parts[1]);
            Ov009_ConfigureTagBySign(data_ov009_020560a8[rowIndex][7], parts[2]);
            Ov009_ConfigureTagBySign(data_ov009_020560a8[rowIndex][4], page->signedValue);
            Ov009_ConfigureTagBySign(
                data_ov009_020560a8[rowIndex][3],
                -(page->availability == 0)
            );
        }

        rowIndex++;
        page = (Ov009PageCursor *)((u8 *)page + 0x1c);
    } while (rowIndex < 3);
}
