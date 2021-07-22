#include"manager.h"
namespace ns3{
    NS_LOG_COMPONENT_DEFINE("Manager");
    NS_OBJECT_ENSURE_REGISTERED(Manager);

    void Manager::GetTaskInfo(std::initializer_list<std::string> taskInfo)
    {
        m_generateUnit->GetInfo(taskInfo);
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
}
