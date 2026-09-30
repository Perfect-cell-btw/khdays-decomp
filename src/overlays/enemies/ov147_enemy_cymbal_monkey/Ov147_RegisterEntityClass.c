/* Registers Ov147_CreateNamedEntity as the factory for enemy class 0x11 (Cymbal Monkey) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov147_CreateNamedEntity(int);

void Ov147_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_CYMBAL_MONKEY, Ov147_CreateNamedEntity);
}
