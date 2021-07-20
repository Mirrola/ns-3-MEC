#ifndef TASKTABLE_H
#define TASKTABLE_H
#include"ns3/object.h"
#include"ns3/ptr.h"
#include"ns3/type-id.h"
#include"ns3/node.h"
#include"ns3/traced-value.h"
#include"ns3/task.h"
#include<algorithm>
#include<list>
namespace ns3{
    class Task;
    class TaskTable:public Object{
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
}
#endif /* TASKTABLE_H */
