typedef struct TaskNode TaskNode;
typedef int (*TaskCallback)(TaskNode *node);

struct TaskNode {
    TaskCallback callback0;
    TaskCallback callback1;
    TaskCallback callback2;
    int payload;
    signed char result;
    signed char spawnedId;
    char padding12[2];
    int timer;
    signed char initialMode;
    signed char resourceKind;
    char padding1a[2];
};

extern int Load2DArrayU8(int kind, int index);
extern int Ov002_SetLapRunning(int kind, int requestedId);
extern int Ov002_NodeFinishLap(TaskNode *node);
extern int Ov002_NodeGetResult(TaskNode *node);

static inline void SetCallback(TaskCallback *slot, TaskCallback callback) {
    if ((int)callback != -1) {
        *slot = callback;
    }
}

int Ov013_TaskPollResourceReady(TaskNode *node) {
    int i;

    node->result = -2;
    if (node->initialMode == 0) {
        node->result = node->resourceKind;
        for (i = 0; i < 15; i++) {
            if (Load2DArrayU8(node->resourceKind, i) > 0) {
                node->timer = 0;
                return -2;
            }
        }
    }

    if (node->result != -2) {
        if (node->timer < 0x5fa0) {
            node->timer += 0x88;
            return -2;
        }

        for (i = 0; i < 15; i++) {
            node->result = node->resourceKind;
            if (Load2DArrayU8(node->resourceKind, i) > 0) {
                node->timer = 0;
                return -2;
            }
        }

        if (node->payload > 0) {
            node->spawnedId = Ov002_SetLapRunning(1, -1);
            if (node->spawnedId < 0) {
                return -2;
            }
            SetCallback(&node->callback0, Ov002_NodeFinishLap);
            SetCallback(&node->callback1, 0);
            SetCallback(&node->callback2, 0);
            return -2;
        }

        SetCallback(&node->callback0, Ov002_NodeGetResult);
        SetCallback(&node->callback1, 0);
        SetCallback(&node->callback2, 0);
    }

    return node->result;
}

