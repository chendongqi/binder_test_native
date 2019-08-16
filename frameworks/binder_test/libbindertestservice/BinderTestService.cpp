#include "BinderTestService.h"
#include <binder/IServiceManager.h>

#include <utils/Log.h>

# define LOG_TAG "BinderTestService"

namespace android{

void BinderTestService::instantiate() {
    ALOGW("BinderTestService instantiate");
    defaultServiceManager()->addService(
            String16("binder_test"), new BinderTestService());
}

BinderTestService::BinderTestService() {
    ALOGW("BinderTestService constructor");
}

BinderTestService::~BinderTestService()
{
    ALOGW("BinderTestService destroyed");
}

status_t BinderTestService::getMessage() {
    ALOGW("BinderTestService getMessage");
    status_t message = 100;
    return message;
}

}
