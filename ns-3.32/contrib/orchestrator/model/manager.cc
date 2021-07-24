#include"manager.h"
namespace ns3{
    NS_LOG_COMPONENT_DEFINE("Manager");
    NS_OBJECT_ENSURE_REGISTERED(Manager);

    
    TypeId Manager::GetTypeId(void)
    {
        static TypeId tid = TypeId("ns3::Manager")
            .SetParent<Object>()
            .SetGroupName("MyManager")
            .AddConstructor<Manager>();
            
        return tid;
    }
    void Manager::GetTaskInfo(std::initializer_list<std::string> taskInfo)
    {
        m_generateUnit->GetInfo(taskInfo);
        m_generateUnit->Generate();
    }

    void Manager::GenerateTask(void)
    {
        auto t = m_generateUnit->Generate();
    }
    void Manager::ReceiveTask(Ptr<Task> t)
    {
        m_receiveUnit->ReceiveTask(t);
    }
    void Manager::RunTask(void)
    {
        m_orchestratorUnit->ChooseTask();
        m_orchestratorUnit->Run();
    }
    void Manager::ShowTaskStatus(void)
    {
        m_taskStatusTable->Print();
    }
    void Manager::SetNode(Ptr<Node> node)
    {
        m_node = node;
        m_orchestratorUnit = Create<DefaultOrchestrator>(m_taskStatusTable,m_node);
        m_generateUnit = Create<DefaultGenerate>(m_taskStatusTable,m_machineId);
        m_receiveUnit = Create<DefaultReceive>(m_taskStatusTable,m_machineId);
        m_sendUnit = Create<DefaultSend>();
    }
    Ptr<Node> Manager::GetNode(void) const
    {
        return m_node;
    }

} 
