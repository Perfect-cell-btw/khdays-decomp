/* Registers the texture data of the indexed entity record's model (0x184 bytes each) of the entity
 * manager. */

#include "game/engine.h"

extern int data_0204c208;

void func_0202ba44(int arg0) {
    func_0202ba68(data_0204c208 + 0xc4 + arg0 * 0x184);
}
