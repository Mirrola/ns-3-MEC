#include"sendbase.h"
namespace ns3{
    
    NS_LOG_COMPONENT_DEFINE("SendBase");
    NS_OBJECT_ENSURE_REGISTERED(SendBase);

    TypeId SendBase::GetTypeId(void)
    {
        static TypeId tid = TypeId("ns3::SendBase")
            .SetParent<Object>()
            .SetGroupName("Send")
            .AddTraceSource("Destiantion","represent the machineid of destinetion machine",MakeTraceSourceAccessor(&SendBase::m_destination),"ns3::Status::TracedCallback");
            return tid;
    }
    void SendBase::GetTask(Ptr<Task> t)
    {
        m_task = t;
    }
    void SendBase::SetNode(Ptr<Node> node)
    {
        m_node = node;
    }
    Ptr<Node> SendBase::GetNode(void) const
    {
        return m_node;
    }



}
