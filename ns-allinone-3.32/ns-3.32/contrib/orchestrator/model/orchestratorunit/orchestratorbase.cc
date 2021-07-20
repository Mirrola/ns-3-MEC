#include"orchestratorbase.h"
namespace ns3{

    NS_LOG_COMPONENT_DEFINE("OrchestratorBase");
    NS_OBJECT_ENSURE_REGISTERED(OrchestratorBase);

    TypeId OrchestratorBase::GetTypeId(void)
    {
        static TypeId tid = TypeId("ns3::OrchestratorBase")
            .SetParent<Object>()
            .SetGroupName("MyOrchestrator");

        return tid;
    }
    void OrchestratorBase::SetNode(Ptr<Node> node)
    {
        m_node = node;
    }
    Ptr<Node> OrchestratorBase::GetNode(void) const
    {
        return m_node;
    }
}
