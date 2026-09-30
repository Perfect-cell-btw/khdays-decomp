/* Empty second callback of the task entry Ov213_ThirdForm_CreateAiTask creates. Like every empty
 * function it returns its first argument unchanged (the ROM is a bare `bx lr`); an object update
 * reads that as "stay in this state". */

void *Ov213_ThirdForm_AiTaskReleaseNoOp(void *arg)
{
    return arg;
}
