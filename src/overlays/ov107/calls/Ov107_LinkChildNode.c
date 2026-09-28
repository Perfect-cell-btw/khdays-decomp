/* Links a child into the owner's sorted child list (+0x44) and fires the child's attach callback. */

extern int *List_InsertSorted(int list, int stride, int max);

void Ov107_LinkChildNode(int owner, int child) {
    *(int *)(child + 4) = owner;
    *List_InsertSorted(owner + 0x44, 4, 100) = child;
    if (*(void (**)(int, int))(child + 0x28) != 0) {
        (*(void (**)(int, int))(child + 0x28))(child, owner);
    }
}
