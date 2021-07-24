#ifndef ORCHESTRATORBASE_H
#define ORCHESTRATORBASE_H
#include"ns3/object.h"
#include"ns3/ptr.h"
#include"ns3/type-id.h"
#include"ns3/node.h"
#include"ns3/traced-value.h"
#include"ns3/resource-unit-container.h"
#include"ns3/resource-unit.h"
#include"ns3/task-table.h"
namespace ns3{
    class SendBase;
    class TaskTable;
    class Task;
    class OrchestratorBase:public Object{
        public:
            static TypeId GetTypeId(void);
            OrchestratorBase(Ptr<TaskTable> table,Ptr<Node> node):m_taskStatusTable(table),m_node(node){}
            virtual ~OrchestratorBase(){}
            virtual bool ChooseTask()=0;//按照某种规则挑选出任务
            virtual void Run()=0;//运行挑选出的任务
            virtual void Release(Ptr<Task> task)=0;//任务结束时，释放占用的资源
            void SetNode(Ptr<Node> node);
            Ptr<Node> GetNode(void) const;

        protected:
            Ptr<TaskTable> m_taskStatusTable;
            Ptr<Node> m_node;
    };
}
#endif  /*  ORCHESTRATORBASE_H  */
