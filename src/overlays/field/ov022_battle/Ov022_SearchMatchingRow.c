/* Checks the actor's four ability rows: builds the mask of matching abilities and the amount they
 * grant, when enabled. */

extern int Slot_EvalPackedParam(int kind, unsigned int packedArg);

struct Ov022MatchPair020a22f0 {
    unsigned int packedArg;
    unsigned int maskShift;
};

struct Ov022MatchTable020a22f0 {
    struct Ov022MatchPair020a22f0 pairs[4];
};

extern struct Ov022MatchTable020a22f0 data_ov022_020b26b0;

struct Ov022Object020a22f0 {
    unsigned char _pad00[9];
    unsigned char kind;
};

#pragma opt_propagation off
int Ov022_SearchMatchingRow(struct Ov022Object020a22f0 *obj, int enabled,
                         unsigned int *outMatchMask,
                         unsigned char *outAmount)
{
    unsigned int * volatile outMatchMaskSpill = outMatchMask;
    int runSearch;
    struct Ov022MatchTable020a22f0 *source;
    struct Ov022MatchTable020a22f0 table;
    unsigned int one;
    struct Ov022MatchPair020a22f0 *pairs;
    int amount;
    unsigned int matchMask;

    amount = 0;
    matchMask = 0;
    source = &data_ov022_020b26b0;
    switch ((int)outAmount) {
    case 0:
        runSearch = enabled;
        break;
    default:
        runSearch = enabled;
        break;
    }
    table = *source;
    pairs = table.pairs;

    if (runSearch == 0) {
        goto outputs;
    }

    {
        int index = 0;
        one = 1;
        runSearch = 0xa000;
        do {
            if (Slot_EvalPackedParam(obj->kind, pairs[index].packedArg) != 0) {
                amount = runSearch;
                matchMask |= one << pairs[index].maskShift;
            }
            index++;
        } while (index < 4);
    }

outputs:
    {
        unsigned int *output = outMatchMaskSpill;
        if (output != 0 && matchMask != 0) {
            *output = matchMask;
        }
    }
    if (outAmount != 0) {
        *outAmount = (char)(amount >> 12);
    }
    return matchMask != 0;
}
