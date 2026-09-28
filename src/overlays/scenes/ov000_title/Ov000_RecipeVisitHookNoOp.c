/* Empty hook FindLastCraftableRecipe calls with (self, entry, units) for each candidate. Like every
 * empty function it returns its first argument unchanged (the ROM is a bare `bx lr`); an object
 * update reads that as "stay in this state". */

void *Ov000_RecipeVisitHookNoOp(void *arg)
{
    return arg;
}
