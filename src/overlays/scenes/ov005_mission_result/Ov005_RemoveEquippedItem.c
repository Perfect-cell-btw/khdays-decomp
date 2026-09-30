/* Removes up to a quantity of an item from the equipment slots (last first) and lowers its count.
 */

#include "nitro/types.h"

typedef struct InventoryView {
    char opaque0[0x810];
    u8 firstItemCount;
    char opaque811[0xee0-0x811];
    u16 equippedItems[3][40];
} InventoryView;
extern InventoryView *gGameState;
void Ov005_RemoveEquippedItem(unsigned int itemId, int quantity) {
    int removed=0;
    int row,slot;
    for (row=2;row>=0;row--) {
        for (slot=39;slot>=0;slot--) {
            if (gGameState->equippedItems[row][slot]==itemId) {
                if (quantity<=0) goto done;
                gGameState->equippedItems[row][slot]=0;
                removed++;
                quantity--;
            }
        }
    }
done:
    {
        u8 *counts=&gGameState->firstItemCount;
        int count=counts[itemId];
        counts[itemId]=count>removed?count-removed:0;
    }
}
