/* Empty second callback of the task entry Ov273_CreateAiTask_2 creates. Like every empty function
 * it returns its first argument unchanged (the ROM is a bare `bx lr`); an object update reads that
 * as "stay in this state". */

void *Ov273_AiTaskReleaseNoOp(void *arg)
{
    return arg;
}
