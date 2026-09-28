extern void Task_MarkFinished();

struct sub { unsigned char pad[0xad]; unsigned char flag; };
struct outer { int x; struct sub **p; };

void Ov244_FinishIfOwnerIdle(struct outer *a) {
    if ((*a->p)->flag == 0) {
        Task_MarkFinished(a);
    }
}
