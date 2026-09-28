/* Whether an item may appear in the grid: items 513-630 and a fixed list of special items are
 * excluded. */

int Ov008_IsGridItemEligible(int itemId)
{
    if (513 <= itemId && itemId <= 630) {
        return 0;
    }

    switch (itemId) {
    case 1:
    case 12:
    case 392:
    case 403:
    case 404:
    case 405:
    case 406:
    case 407:
    case 408:
    case 409:
    case 410:
    case 411:
    case 412:
    case 413:
    case 414:
    case 415:
    case 416:
    case 450:
    case 451:
    case 452:
    case 456:
    case 457:
        return 0;
    default:
        return 1;
    }
}

