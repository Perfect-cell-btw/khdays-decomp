/* Spawn a child object via CreateRegistryEntry, link it back to this object, store it at +0x214 and
 * seed the child's +0xf0 vector from the constant at data_02041dc8. */
struct w3 { int a, b, c; };
extern const struct w3 data_02041dc8;
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov266_stateInitClearSlots_2(int);
void Ov266_CreateAiTask_2(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x18, (void *)&Ov266_stateInitClearSlots_2, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(param_1 + 0x214) = obj;
    *(struct w3 *)(*(int *)obj + 0xf0) = data_02041dc8;
}
