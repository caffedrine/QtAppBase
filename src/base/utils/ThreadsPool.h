#ifndef _SERVICES_THREADSPOOL_H_
#define _SERVICES_THREADSPOOL_H_

#include "base/LibCfg.h"
#include "base/extensions/QThreadPoolExtended.h"

class DLL_DECL_SPEC ThreadsPool
{
public:
    ThreadsPool(int max_threads_count = 5);
    ~ThreadsPool() = default;
    QThreadPoolExtended *ThreadsPoolPtr();
protected:

private:
    QThreadPoolExtended threadsPool;
};

#endif // _SERVICES_THREADSPOOL_H_