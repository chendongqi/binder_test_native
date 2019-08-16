# define LOG_TAG "BinderTestService"

#include <binder/IServiceManager.h>

#include "libbindertestservice/BinderTestService.h"
#include <utils/Log.h>

using namespace android;// 引用命名空间

int main(int argc, char** argv) {
    ALOGE("binder test client start!!!");
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("binder_test"));
    sp<IBinderTestService> service = interface_cast<IBinderTestService>(binder);
    if (service != NULL) {
        //int message = service->getMessage();
        ALOGE("get remote message %d", service->getMessage());
    }

    return 0;
}
