/* Ask the link layer whether the request is addressed to us, then let the
 * session decide. Both booleans are materialised explicitly -- 1 and 0 on
 * separate branches -- which is what the ROM does at each step. */
extern int ScriptVm_ReadOperandInt(void *request, int);
extern int Ov002_Link_AdvancePhase(int addressed);

int Ov002_IsRequestForUs(void *request, int arg1) {
    int addressed;

    if (ScriptVm_ReadOperandInt(request, arg1) != 0) {
        addressed = 1;
    } else {
        addressed = 0;
    }

    if (Ov002_Link_AdvancePhase(addressed) == 0) {
        return 0;
    }

    return 1;
}
