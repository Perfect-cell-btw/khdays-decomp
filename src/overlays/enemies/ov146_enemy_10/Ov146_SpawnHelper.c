/* Spawn the ov146 actor's helper node (0203c5c0: 0x64/0xc, tick 020cf290, class 020cf320): it remembers
 * the actor and its +0x388 and +0x384 models, and the actor keeps it in +0x214. */
struct Ov146Helper { char *owner; int part; int model; };

extern int CreateRegistryEntry(int scene, int kind, int size, void *cb, void *cls, struct Ov146Helper **out);
extern void Ov146_HelperStart(void);
extern void Ov146_HelperTaskTeardown(void);

void Ov146_SpawnHelper(char *self)
{
    struct Ov146Helper *helper;

    CreateRegistryEntry(*(int *)(self + 0x3c), 0x64, 0xc, Ov146_HelperStart, Ov146_HelperTaskTeardown, &helper);
    helper->owner = self;
    helper->part = *(int *)(helper->owner + 0x388);
    helper->model = *(int *)(helper->owner + 0x384);
    *(struct Ov146Helper **)(self + 0x214) = helper;
}
