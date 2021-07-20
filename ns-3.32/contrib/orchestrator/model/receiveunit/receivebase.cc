#include"receivebase.h"
namespace ns3{
    NS_LOG_COMPONENT_DEFINE("ReceiveBase");
    NS_OBJECT_ENSURE_REGISTERED(ReceiveBase);

    TypeId ReceiveBase::GetTypeId(void)
    {
        static TypeId tid = TypeId("ns3::ReceiveBase")
            .SetParent<Object>()
            .SetGroupName("Receive");

        return tid;
    }
}
