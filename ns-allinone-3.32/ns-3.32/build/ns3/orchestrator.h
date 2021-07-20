/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H
#include"ns3/object.h"
#include"ns3/ptr.h"
#include"ns3/type-id.h"
#include"ns3/node.h"
#include"ns3/traced-value.h"
#include"ns3/task.h"
#include"ns3/resource-unit-container.h"
#include"ns3/resource-unit.h"
#include<map>
#include<vector>
#include<algorithm>
#include<list>
#include"tasklist.h"

namespace ns3 {
    class Task;
    class TaskTable{
        public:
            friend class Orchestrator;
            void GetTask(Ptr<Task> t);//task在各个list里面的排序是按照优先级进行排序的,优先级9>8，按照优先级由大到小进行排序
            void Print(void) const;       
            void CheckIn(Ptr<Task> t) const;//在对task的stata进行转换之前要确保该task存在于当前table中
            void CheckStataCorrect(Ptr<Task> t) const;//在对task进行resource分配前要确保该task当前状态是pending
            void PendingToRunning(Ptr<Task> t);//当task被从Pending转成Running时调用此函数，修改list的相应信息
            void RunningToDead(Ptr<Task> t);//当task被从Running转成Dead时调用此函数，修改list的相应信息
            Ptr<Task> FirstPriorInPending(void);
            bool PendingEmpty(void);//在挑选任务来执行之前要保证此时pending里面还有可执行的任务,为空时返回1。

        private:
            void InsertByPriority(Ptr<Task> t);
            void Printlist(const std::list<Ptr<Task>> &l) const;
            

        private:
            std::list<Ptr<Task>> m_unsubmitList;//先赞是用来存放那些发往远处机器的task
            std::list<Ptr<Task>> m_pendingList;
            std::list<Ptr<Task>> m_runningList;
            std::list<Ptr<Task>> m_deadList;

    };

    class Orchestrator:public Object{
        public:
            Orchestrator() = default;
            static TypeId GetTypeId(void);
            void SetNode(Ptr<Node> node);
            Ptr<Node> GetNode(void) const;
            void PrintStata(void) const;
            Ptr<Task> GenerateTask(std::string taskId,double requestecpu,double requestmem,std::size_t prior,const std::string& destinationMachineId="");
            bool ChooseOneToRun(void);
        private:
            void AssignTasktoResource(Ptr<Task> task);//目前的调度方式是从resource container中按照顺序，只要当前resource有能力接受这个任务，那么就分给当前的resource，当前resource资源不足了再挑选下一个resource分配当前任务
            void ReleaseTaskResource(Ptr<Task> task);//当该task调度完成后，把分配给该task的资源回收
            void ReceiveTask(Ptr<Task> t);
            void StataTransfer(Ptr<Task> t,int i);//i=0时是PendingToRunning,i=1时是RunningToDead
            std::string m_machineId="";
            Ptr<Node> m_node = NULL;
            std::map<std::string,std::string> m_taskAllocateTable;//记录相应task存放在resource container的哪个resource中，pair的first存放taskId作为关键字，因为本身一个task要被分配给一个resource。pair的second存放resourceId
            TaskTable m_taskStatusTable;
            //std::vector<std::map<std::string,int>> m_taskStatusTable;
//记录分配到当前结点的task的状态，在调度的时候会用到这个信息。
            
    };


}

#endif /* ORCHESTRATOR_H */

