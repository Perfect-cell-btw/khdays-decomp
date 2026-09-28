/* Stores the value into the word the object's pointer (+8) points to. */

void Obj_SetIndirectWord(int **p, int v)
{
    *p[2] = v;
}
