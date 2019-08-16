# define LOG_TAG "BinderTestService"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>

#include "libbindertestservice/BinderTestService.h"
#include <utils/Log.h>

using namespace android;// 引用命名空间

int main(int argc, char** argv) {
    ALOGE("main_binder_test start!!!");
    BinderTestService::instantiate();
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}
