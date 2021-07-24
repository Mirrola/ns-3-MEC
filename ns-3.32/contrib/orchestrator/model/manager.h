#ifndef MANAGER_H
#define MANAGER_H
#include"ns3/object.h"
#include"ns3/ptr.h"
#include"ns3/type-id.h"
#include"ns3/node.h"
#include"ns3/traced-value.h"
#include"ns3/task-table.h"
#include"ns3/default-generate.h"
#include"ns3/default-orchestrator.h"
#include"ns3/default-receive.h"
#include"ns3/default-send.h"
#include<initializer_list>
namespace ns3{
    class OrchestratorBase;
    class GenerateTaskBase;
    class DefaultGenerate;
    class Manager:public Object{ //Manager作为任务生成部件、接收、发送、调度部件的集合体。
        public:
            static TypeId GetTypeId(void);
            Manager()=default;
            void GetTaskInfo(std::initializer_list<std::string> taskInfo);
            void GenerateTask(void);
            void ReceiveTask(Ptr<Task> t);
            //void SendTask(void);
            void RunTask(void);
            void ShowTaskStatus(void);
            void SetNode(Ptr<Node> node);
            Ptr<Node> GetNode(void) const;
        private:
            Ptr<TaskTable> m_taskStatusTable = CreateObject<TaskTable>();
            Ptr<Node> m_node;
            std::string m_machineId="";
//    DefaultOrchestrator orchestrateUnit(m_taskStatusTable,m_node);
//    DefaultGenerate generateUnit(m_taskStatusTable,m_machineId);
//    DefaultReceive receiveUnit(m_taskStatusTable,m_machineId);
//    DefaultSend sendUnit;
            Ptr<OrchestratorBase> m_orchestratorUnit;
            Ptr<GenerateTaskBase> m_generateUnit;
            Ptr<DefaultReceive> m_receiveUnit;
            Ptr<DefaultSend> m_sendUnit;
//
//            Ptr<OrchestratorBase> m_orchestratorUnit = CreateObject<DefaultOrchestrator>(m_taskStatusTable,m_node);
//            Ptr<GenerateTaskBase> m_generateUnit=CreateObject<DefaultGenerate>(m_taskStatusTable,m_machineId);
//            Ptr<DefaultReceive> m_receiveUnit=CreateObject<DefaultReceive>(m_taskStatusTable,m_machineId);
//            Ptr<DefaultSend> m_sendUnit = CreateObject<DefaultSend>();

//\            Ptr<OrchestratorBase> m_orchestratorUnit = Create<DefaultOrchestrator>(m_taskStatusTable,m_node);
//\            Ptr<GenerateTaskBase> m_generateUnit=Create<DefaultGenerate>(m_taskStatusTable,m_machineId);
//\            Ptr<DefaultReceive> m_receiveUnit=Create<DefaultReceive>(m_taskStatusTable,m_machineId);
//\            Ptr<DefaultSend> m_sendUnit = Create<DefaultSend>();
            
    };
}

#endif /* MANAGER_H */
