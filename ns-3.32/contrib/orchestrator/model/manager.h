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
            Manager();
            void GetTaskInfo(std::initializer_list<std::string> taskInfo);
            void GenerateTask(void);
            void ReceiveTask(Ptr<Task> t);
            void SendTask(void);
            void RunTask(void);
            void SetNode(Ptr<Node> node);
            Ptr<Node> GetNode(void) const;
        private:
            Ptr<TaskTable> m_taskStatusTable = CreateObject<TaskTable>();
            Ptr<Node> m_node;
            std::string m_machineId="";
            Ptr<OrchestratorBase> m_orchestratorUnit = CreateObject<DefaultOrchestrator>(m_taskStatusTable,m_node);
            Ptr<GenerateTaskBase> m_generateUnit=CreateObject<DefaultGenerate>(m_taskStatusTable,m_machineId);
            Ptr<DefaultReceive> m_receiveUnit=CreateObject<DefaultReceive>(m_taskStatusTable,m_machineId);
            Ptr<SendBase> m_sendUnit;

            
    };
}

#endif /* MANAGER_H */
