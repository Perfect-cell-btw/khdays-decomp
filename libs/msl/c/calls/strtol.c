/* MSL strtol (kept under its ROM symbol name, which the callers use): converts through __strtoul
 * (__strtoul) reading the string with __StringRead (CharCursor_Control), stores the end pointer, and
 * clamps to LONG_MIN / LONG_MAX with errno (data_0204bd7c) = ERANGE on overflow. */
typedef struct {
    char *NextChar;
    int NullCharDetected;
} __InStrCtrl;

extern unsigned long __strtoul(int base, int max, int (*ReadProc)(void *, int, int),
                                   void *ReadProcArg, int *chars_scanned, int *negative,
                                   int *overflow);   /* __strtoul */
extern int CharCursor_Control(void *isc, int ch, int action);   /* __StringRead */
extern int data_0204bd7c;

long strtol(const char *str, char **end, int base)
{
    unsigned long value;
    int count, negative, overflow;
    __InStrCtrl isc;

    isc.NextChar = (char *)str;
    isc.NullCharDetected = 0;

    value = __strtoul(base, 0x7fffffff, CharCursor_Control, (void *)&isc, &count, &negative, &overflow);

    if (end)
        *end = (char *)str + count;

    if (overflow || (!negative && value > 0x7fffffff) || (negative && value > 0x80000000)) {
        value = (negative ? 0x80000000 : 0x7fffffff);
        data_0204bd7c = 0x22;
    } else if (negative)
        value = -value;

    return (long)value;
}
