#include"generatetaskbase.h"
namespace ns3{
    NS_LOG_COMPONENT_DEFINE("GenerateTaskBase");
    NS_OBJECT_ENSURE_REGISTERED(GenerateTaskBase);

    TypeId GenerateTaskBase::GetTypeId(void)
    {
        static TypeId tid = TypeId("ns3::GenerateTaskBase")
            .SetParent<Object>()
            .SetGroupName("GenerateTask");

        return tid;
    }
//    void GenerateTaskBase::GetInfo(std::string taskId,double requestecpu,double requestmem,std::size_t prior,const std::string& destinationMachineId)
//    {
//        m_taskId = taskId;
//        m_requestcpu =requestecpu;
//        m_requestmem = requestmem;
//        m_prior = prior;
//        m_destinationMachineId = destinationMachineId;
//
//    }

}
