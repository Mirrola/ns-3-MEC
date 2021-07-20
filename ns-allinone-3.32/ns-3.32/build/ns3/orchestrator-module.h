
#ifdef NS3_MODULE_COMPILATION
# error "Do not include ns3 module aggregator headers from other modules; these are meant only for end user scripts."
#endif

#ifndef NS3_MODULE_ORCHESTRATOR
    

// Module headers:
#include "default-generate.h"
#include "default-orchestrator.h"
#include "default-receive.h"
#include "default-send.h"
#include "generatetaskbase.h"
#include "manager.h"
#include "orchestratorbase.h"
#include "receivebase.h"
#include "sendbase.h"
#include "task-table.h"
#endif
