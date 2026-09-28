extern void Scene_AdvanceToPending(void);
int Scene_StepAndContinue(void) { Scene_AdvanceToPending(); return 0; }
