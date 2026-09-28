/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov008_MissionMenuBack. */
extern void *Ov008_MissionMenuBack();

void *func_ov008_02078154(int arg0) {
    return Ov008_MissionMenuBack(arg0);
}
