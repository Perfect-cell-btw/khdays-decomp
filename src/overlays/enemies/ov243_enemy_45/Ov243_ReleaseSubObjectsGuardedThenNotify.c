/* Destroys the enemy: its models and action resource, frees its waypoint table and destroys the
 * base object. */

extern void DestroyInstance();
extern void Ov107_ActionResource_Destroy();
extern void FreeInstanceMemory();
extern void Ov107_DestroyObject();

void Ov243_ReleaseSubObjectsGuardedThenNotify(int this_) {
    DestroyInstance(*(int *)(this_ + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(this_ + 0x390));
    DestroyInstance(*(int *)(this_ + 0x388));
    DestroyInstance(*(int *)(this_ + 0x394));
    if (*(int *)(this_ + 0x398) != 0) {
        FreeInstanceMemory(*(int *)(this_ + 0x398));
        *(int *)(this_ + 0x398) = 0;
    }
    Ov107_DestroyObject(this_);
}
