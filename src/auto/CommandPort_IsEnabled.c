/* Always 0 in retail, so IsCommandAvailable reports ready without polling the port. */

int CommandPort_IsEnabled(void){ return 0; }
