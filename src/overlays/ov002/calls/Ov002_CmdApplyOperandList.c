/* Script command: read a count, then that many operands, and apply them as a list.
 *
 * The operands are eight bytes apart, the first one giving the count and the rest being read into
 * a list on the stack before 0206d468 is handed the whole thing. When bit 2 of the global mode
 * byte is set the command is skipped entirely and the handler reports one; a command that ran
 * reports zero.
 *
 * The shape follows the sibling handler at 020751fc: the first operand is read before the walking
 * pointer moves on, and each later operand goes through a temporary before it is stored, which is
 * what keeps the store post-incrementing. The guard has to wrap the body rather than return early,
 * or the two tails come out the other way round.
 */

typedef unsigned char u8;

extern int ScriptVm_ReadOperandInt(void *vm, char *operand);
extern void Ov002_ResetPendingIds(void *items, int count);
extern u8 data_0204c240;

int Ov002_CmdApplyOperandList(void *vm, char *table) {
    void *items[8];
    int count;
    int i;
    char *first = table;

    table += 8;
    count = ScriptVm_ReadOperandInt(vm, first);
    if ((data_0204c240 & 4) == 0) {
        for (i = 0; i < count; i++) {
            void *x = ScriptVm_ReadOperandInt(vm, table);
            table += 8;
            items[i] = x;
        }
        Ov002_ResetPendingIds(items, count);
        return 0;
    }
    return 1;
}
