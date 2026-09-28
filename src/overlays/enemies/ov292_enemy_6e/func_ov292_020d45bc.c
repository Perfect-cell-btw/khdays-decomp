/* Allocator vtable hook: frees `block` through Ov292_StepSteering from the heap at allocator+4.
 * Twin of AllocatorFreeForExpHeap. */
extern void *Ov292_StepSteering();

void *func_ov292_020d45bc(void **allocator, void *block) {
    return Ov292_StepSteering(allocator[1], block);
}
