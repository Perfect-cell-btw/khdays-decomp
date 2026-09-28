/* Stores the listener position and its normalised up vector (cross product of the two axes). */

extern void VEC_CrossProduct();
extern void VEC_Normalize();
extern char *data_0204c234;

typedef struct { int x, y, z; } Vec3;

void SoundMgr_SetListener(Vec3 *src, Vec3 *a, Vec3 *b)
{
    char *base;
    Vec3 local;

    base = data_0204c234;
    VEC_CrossProduct(a, b, &local);
    VEC_Normalize(&local, base + 0xb44d8);
    *(Vec3 *)(base + 0xb44cc) = *src;
}
