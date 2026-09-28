/* NitroSDK os_irqTable.c / os_irqHandler.c: the ARM9 interrupt handler table and the thread queue
 * of OS_WaitIrq, both in DTCM .data (0x027e0000-0x027e0060).  Every IRQ source starts on
 * OS_IrqDummy (OS_IrqDummy) except the four timers and the four DMA channels, whose SDK
 * handlers dispatch the per-channel callbacks. */

typedef void (*OSIrqFunction)(void);

typedef struct OSThreadQueue {
    struct OSThread *head;
    struct OSThread *tail;
} OSThreadQueue;

#define OS_IRQ_TABLE_MAX 22

extern void OS_IrqDummy(void);  /* OS_IrqDummy */
extern void OSi_IrqTimer0(void);
extern void OSi_IrqTimer1(void);
extern void OSi_IrqTimer2(void);
extern void OSi_IrqTimer3(void);
extern void OSi_IrqDma0(void);
extern void OSi_IrqDma1(void);
extern void OSi_IrqDma2(void);
extern void OSi_IrqDma3(void);

/* OS_IRQTable */
OSIrqFunction data_027e0000[OS_IRQ_TABLE_MAX] = {
    OS_IrqDummy,  /* VBlank */
    OS_IrqDummy,  /* HBlank */
    OS_IrqDummy,  /* VCounter */
    OSi_IrqTimer0,  /* timer 0 */
    OSi_IrqTimer1,  /* timer 1 */
    OSi_IrqTimer2,  /* timer 2 */
    OSi_IrqTimer3,  /* timer 3 */
    OS_IrqDummy,  /* serial communication */
    OSi_IrqDma0,    /* DMA 0 */
    OSi_IrqDma1,    /* DMA 1 */
    OSi_IrqDma2,    /* DMA 2 */
    OSi_IrqDma3,    /* DMA 3 */
    OS_IrqDummy,  /* key */
    OS_IrqDummy,  /* cartridge */
    OS_IrqDummy,  /* (not used) */
    OS_IrqDummy,  /* (not used) */
    OS_IrqDummy,  /* IPC sync */
    OS_IrqDummy,  /* IPC FIFO send */
    OS_IrqDummy,  /* IPC FIFO receive */
    OS_IrqDummy,  /* card data */
    OS_IrqDummy,  /* card IREQ */
    OS_IrqDummy,  /* geometry command FIFO */
};

/* OSi_IrqThreadQueue: threads sleeping in OS_WaitIrq (empty). */
#pragma explicit_zero_data on
OSThreadQueue data_027e0058 = { 0, 0 };
#pragma explicit_zero_data off
