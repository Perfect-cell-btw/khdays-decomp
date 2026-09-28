/* Empty hook called with 1 when the campaign menu opens and 0 when a mission starts. Like every
 * empty function it returns its first argument unchanged (the ROM is a bare `bx lr`); an object
 * update reads that as "stay in this state". */

void *Ov008_CampaignModeHookNoOp(void *arg)
{
    return arg;
}
