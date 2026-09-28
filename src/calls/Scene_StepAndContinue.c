/* Advances to the pending scene; returns 0. */

extern void Scene_AdvanceToPending(void);
int Scene_StepAndContinue(void) { Scene_AdvanceToPending(); return 0; }
