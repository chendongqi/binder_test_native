#include <binder/IInterface.h>

namespace android {

class IBinderTestService: public IInterface
{
public:
    // 继承自IInterface的宏
    DECLARE_META_INTERFACE(BinderTestService);
    // 自己加如业务逻辑接口，真正实现在BinderTestServie中
    virtual status_t getMessage() = 0;
};

class BnBinderTestService: public BnInterface<IBinderTestService>
{
public:
    virtual status_t onTransact( uint32_t code, 
                                 const Parcel& data,
                                 Parcel* reply,
                                 uint32_t flags = 0);
};

};
