#include"ns3/receivebase.h"
#include"ns3/task.h"
namespace ns3{
    class DefaultReceive:public ReceiveBase{
        public:
            static TypeId GetTypeId(void);
            DefaultReceive(Ptr<TaskTable> table,std::string mid):ReceiveBase(table,mid){}

            ~DefaultReceive();
            void ReceiveTask(Ptr<Task> task)//这一部分不在基类中声明是可能接收到的不是task而是一个job(由多个task组成)，接收的形式都大不一样
            {
                m_task = task;
                HandleReceive();
            }
            virtual void HandleReceive(void) override//这个判断还得改
            {
                auto id = m_task->GetDestinationMId();
                if(id==m_machineId)
                {
                    m_taskStatusTable->GetTask(m_task);
                }
                else
                {
                    //传给app进行转发
                }
            }
        private:
            Ptr<Task> m_task;
    };
}
