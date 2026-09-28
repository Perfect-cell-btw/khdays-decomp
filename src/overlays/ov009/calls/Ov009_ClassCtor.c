/* Class pfnCtor: stores the root, initializes the menu and milestones and waits for the commit. */

typedef void (*Ov009Callback)(void);

extern void *data_ov009_020563e0;
extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov009_Menu_Init(int mode);
extern void Ov009_UpdateCompletionMilestones(void);
extern void Ov009_WaitCommitPage(void);

Ov009Callback Ov009_ClassCtor(void)
{
    data_ov009_020563e0 = NNSi_FndGetCurrentRootHeap();
    Ov009_Menu_Init(0);
    Ov009_UpdateCompletionMilestones();
    return Ov009_WaitCommitPage;
}
