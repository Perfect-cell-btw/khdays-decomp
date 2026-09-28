/* FrameStep_UpdateTaskQueue: drain the GFX command queue (ctx @ data_02047370). If the
 * time budget (ctx+0x10) is exhausted (>= 0x2400) flush the data cache once; then for each
 * queued command call Gfd_RunTransferTask(cmd, underBudget) and debit its cost (cmd[3]) from the
 * budget. NNSi_GfdGetFrontVramTransferTaskQueue fetches the next command, NNSi_GfdPopVramTransferTaskQueue advances/decrements.
 *
 * This was parked 4 bytes short, and the cause was INFRASTRUCTURE, not codegen: the ROM's
 * literal pool holds 0x02047370 TWICE (relocs at +128 and +132), and mwcc emits two pool
 * entries only for two DISTINCT symbols. With one name the budget read reuses the register
 * already holding the context and the second entry never exists. `data_02047370_budget` is
 * an alias at the same address in config/arm9/symbols.txt -- the same fix LatchPendingRequestOnce
 * needed for data_0204be08. gen_delinks/audit_progress filter on kind:function(...), so a
 * kind:bss alias is invisible to them and the 306 gate is unaffected.
 * If you meet a function that is exact except for its literal pool, count the pool entries
 * against the distinct symbols before blaming anything else. */
extern int *NNSi_GfdGetFrontVramTransferTaskQueue(int *q);
extern int NNSi_GfdPopVramTransferTaskQueue(int *q);
extern void Gfd_RunTransferTask(int *cmd, int flag);
extern void DC_StoreAll(void);
extern char data_02047370;
extern char data_02047370_budget;

void FrameStep_UpdateTaskQueue(void) {
    int *ctx = (int *)&data_02047370;
    int *cmd;
    unsigned char flag;

    cmd = NNSi_GfdGetFrontVramTransferTaskQueue(ctx);
    flag = *(unsigned int *)((char *)&data_02047370_budget + 0x10) < 0x2400;
    if (flag == 0) {
        DC_StoreAll();
    }
    if (NNSi_GfdPopVramTransferTaskQueue(ctx) != 0) {
        do {
            Gfd_RunTransferTask(cmd, flag);
            *(int *)((char *)ctx + 0x10) -= cmd[3];
            cmd = NNSi_GfdGetFrontVramTransferTaskQueue(ctx);
        } while (NNSi_GfdPopVramTransferTaskQueue(ctx) != 0);
    }
}
