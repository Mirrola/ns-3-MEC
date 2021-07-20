#ifndef RECEIVEBASE_H
#define RECEIVEBASE_H
#include"ns3/object.h"
#include"ns3/ptr.h"
#include"ns3/type-id.h"
#include"ns3/traced-value.h"
#include"ns3/task-table.h"
namespace ns3{
    class ReceiveBase:public Object{
       public:
            static TypeId GetTypeId(void);
            ReceiveBase(Ptr<TaskTable> table,std::string mid):m_taskStatusTable(table),m_machineId(mid){}
            virtual ~ReceiveBase();
            virtual void HandleReceive(void)=0;//这个名字起的不太好，他的主要工作就是判断接收到的task或job后续是怎处理。
 //           virtual void DelieverToSend(void)=0;
 //           virtual void DelieverToOrchestrator(void)=0;
       protected:
            Ptr<TaskTable> m_taskStatusTable;
            std::string m_machineId;
    };
}
#endif /* RECEIVEBASE_H */
