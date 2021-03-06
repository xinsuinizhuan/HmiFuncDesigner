#ifndef TCPIPMODBUS_H
#define TCPIPMODBUS_H

#include <QObject>
#include "../IVendorPlugin/IVendorPlugin.h"
#include "TCPIPModbusImpl.h"


class TCPIPModbus : public QObject, IVendorPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID DevicePluginInterface_iid FILE "TCPIPModbus.json")
    Q_INTERFACES(IVendorPlugin)

public:
    TCPIPModbus();
    ~TCPIPModbus();

    // 初始化设备
    bool initailizeDevice(void* pObj) Q_DECL_OVERRIDE;
    // 连接设备
    bool connectDevice(void* pObj) Q_DECL_OVERRIDE;
    // 断开设备连接
    bool disconnectDevice(void* pObj) Q_DECL_OVERRIDE;
    // 反初始化设备
    bool unInitailizeDevice(void* pObj) Q_DECL_OVERRIDE;

    // 写变量前处理
    bool beforeWriteIOTag(IOTag* pTag) Q_DECL_OVERRIDE;
    // 写变量
    int writeIOTag(IPort *pPort, IOTag* pTag) Q_DECL_OVERRIDE;
    // 写变量后处理
    bool afterWriteIOTag(IOTag* pTag) Q_DECL_OVERRIDE;

    // 读变量前处理
    bool beforeReadIOTag(IOTag* pTag) Q_DECL_OVERRIDE;
    // 读变量
    int readIOTag(IPort *pPort, IOTag* pTag) Q_DECL_OVERRIDE;
    // 读变量后处理
    bool afterReadIOTag(IOTag* pTag) Q_DECL_OVERRIDE;

private:
    TCPIPModbusImpl m_TCPIPModbusImplObj;

};

#endif // TCPIPMODBUS_H
