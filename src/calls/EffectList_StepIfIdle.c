extern void *NNSi_FndGetCurrentRootHeap(void);
extern void  EffectList_Step(void);

int EffectList_StepIfIdle(void) {
    void **h = (void **)NNSi_FndGetCurrentRootHeap();
    if (*h == 0) {
        EffectList_Step();
    }
    return 0;
}
