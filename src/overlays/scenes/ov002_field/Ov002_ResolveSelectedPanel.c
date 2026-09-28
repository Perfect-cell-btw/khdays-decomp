extern int Ov002_Roster_GetFirstMember(void);
extern int Ov002_CanAcceptSlotRequest(void);
extern unsigned int Ov002_DismissIfState4(unsigned int handle);
/* Resolve the currently-selected panel's resource, or 0 if none is active. */
unsigned int Ov002_ResolveSelectedPanel(void) {
    unsigned int handle;
    if (Ov002_Roster_GetFirstMember() != -1 && (handle = Ov002_CanAcceptSlotRequest()) != 0) {
        return Ov002_DismissIfState4(handle);
    }
    return 0;
}
