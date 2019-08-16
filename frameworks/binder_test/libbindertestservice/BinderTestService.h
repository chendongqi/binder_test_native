#ifndef ANDROID_BINDERTESTSERVICE_H
#define ANDROID_BINDERTESTSERVICE_H

#include "libbindertest/IBinderTestService.h"

namespace android {

class BinderTestService: public BnBinderTestService
{
public: 
    static void instantiate();
    // IBinderTestServie中的接口
    virtual status_t getMessage();
    BinderTestService();
    virtual ~BinderTestService();
};

};
#endif
