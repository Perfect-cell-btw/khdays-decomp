/* Activates the object (first word = 1). */

void Ov056_Activate(void *unused, void *self)
{
    *(int *)self = 1;
}
