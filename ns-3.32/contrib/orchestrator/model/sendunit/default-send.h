#ifndef DEFAULTSEND_H
#define DEFAULTSEND_H
#include"ns3/object.h"
#include"ns3/ptr.h"
#include"ns3/type-id.h"
#include"ns3/node.h"
#include"ns3/traced-value.h"
#include"ns3/sendbase.h"
#include"ns3/task.h"
namespace ns3{
    class Task;
    class DefaultSend:public SendBase{
        public:
            static TypeId GetTypeId(void);
            DefaultSend()=default ;
            void GetTask(Ptr<Task> task)
            {
                m_task = task;
            }
            virtual void FindDestination(void) override
            {
                //m_destination = m_task->GetDestinationMId();
                ;
            }
        private:
            virtual void TransferIpToApplication() override
            {
                ;
            }
            Ptr<Task> m_task;

    };

}
#endif /* DEFAULTSEND_H */
