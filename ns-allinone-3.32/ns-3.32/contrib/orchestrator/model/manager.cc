#include"manager.h"
namespace ns3{
    NS_LOG_COMPONENT_DEFINE("Manager");
    NS_OBJECT_ENSURE_REGISTERED(Manager);

//    void Manager::GetTaskInfo(std::string taskId,double requestecpu,double requestmem,std::size_t prior,const std::string& destinationMachineId)
//    {
//        m_generateUnit->GetInfo(taskId,requestecpu,requestmem,prior,destinationMachineId);
//    }
//
//    void Manager::GenerateTask(void)
//    {
//        auto t = m_generateUnit->Generate();
//    }
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
