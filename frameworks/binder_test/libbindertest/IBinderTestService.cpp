#include "IBinderTestService.h"
#include <binder/Parcel.h>
#include <binder/IInterface.h>
#include <binder/IBinder.h>
#include <utils/Log.h>

# define LOG_TAG "BinderTestService"

namespace android {

enum {
    GET_MESSAGE = IBinder::FIRST_CALL_TRANSACTION
};

// Binder的代理端
class BpBinderTestService: public BpInterface<IBinderTestService>
{
public:
    BpBinderTestService(const sp<IBinder>& impl)
        : BpInterface<IBinderTestService>(impl)
    {
    }

    // 这个是bp端将业务功能通过binder传递到BinderTestService
    virtual status_t getMessage()
    {
        ALOGW("IBinderTestService BpBinderTestService getMessage start");
        Parcel data, reply;
        data.writeInterfaceToken(IBinderTestService::getInterfaceDescriptor());
        remote()->transact(GET_MESSAGE, data, &reply);
        status_t message = reply.readInt32();
        ALOGW("IBinderTestService BpBinderTestService getMessage reply=%d", message);// 读取onTransaction中从service端调用返回后写入到reply中的数据，有多个时，按照写入顺序读取
        return message;
    }
};

// IInterface中的宏实现
IMPLEMENT_META_INTERFACE(BinderTestService, "android.IBinderTestService");

status_t BnBinderTestService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch (code) {
        case GET_MESSAGE: {
            CHECK_INTERFACE(IBinderTestService, data, reply);
            ALOGW("IBinderTestService BnBinderTestService onTransact GET_MESSAGE");
            ALOGW("IBinderTestService BnBinderTestService onTransact GET_MESSAGE getMessage=%d", getMessage());
            reply->writeInt32(getMessage());// 如果有多个值就以此写入，读取时按照写入顺序读取
            return 0;// 这里返回什么不重要，关键是要把返回值写入到reply中，带回给Bp端的transact。
        } break;
    }
    return 0;
}

};  // namespace android
