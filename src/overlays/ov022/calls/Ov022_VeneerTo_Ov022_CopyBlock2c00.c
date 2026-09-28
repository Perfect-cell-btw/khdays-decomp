/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov022_CopyBlock2c00. */
extern void *Ov022_CopyBlock2c00();

void *Ov022_VeneerTo_Ov022_CopyBlock2c00() {
    return Ov022_CopyBlock2c00();
}
