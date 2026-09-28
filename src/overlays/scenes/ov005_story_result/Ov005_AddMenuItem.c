/* Adds one of an item to the reward list (the first row, or the second for item 1). */

#include "nitro/types.h"
typedef struct Ov005MenuItemHeader {char data[0x24c];} Ov005MenuItemHeader;
extern char *data_ov005_0205b80c;
extern void Ov005_PopulateMenuItem(Ov005MenuItemHeader *,unsigned int,int,int);
void Ov005_AddMenuItem(unsigned int itemId) {
    Ov005_PopulateMenuItem((Ov005MenuItemHeader *)(data_ov005_0205b80c+0x4c98)+itemId,(u16)itemId,1,itemId==1?1:0);
}
