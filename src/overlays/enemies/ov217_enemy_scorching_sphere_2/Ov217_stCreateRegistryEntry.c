/* Creates the object's state-machine registry entry (starting in its init state), links it to the
 * object and its model (+0x384) and stores it at +0x214. */

extern void CreateRegistryEntry();
extern void Ov217_stInitSlotsFlags6(void);

void Ov217_stCreateRegistryEntry(int param_1) {
    int *local_10;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x7c, Ov217_stInitSlotsFlags6, 0, &local_10);
    *local_10 = param_1;
    local_10[1] = *(int *)(*local_10 + 0x384);
    *(int **)(param_1 + 0x214) = local_10;
}
