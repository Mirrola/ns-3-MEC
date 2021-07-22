#ifndef GENERATETASKBASE_H
#define GENERATETASKBASE_H
#include"ns3/object.h"
#include"ns3/ptr.h"
#include"ns3/type-id.h"
#include"ns3/node.h"
#include"ns3/traced-value.h"
#include"ns3/task.h"
#include"ns3/task-table.h"
#include <initializer_list>

namespace ns3{
    class GenerateTaskBase:public Object{
        public:
            static TypeId GetTypeId(void);
            GenerateTaskBase(Ptr<TaskTable> table,std::string Mid):m_taskStatusTable(table),m_machineId(Mid){}
            virtual ~GenerateTaskBase();
            virtual Ptr<Task> Generate(void)=0;
            //virtual void GetInfo(std::string taskId,double requestecpu,double requestmem,std::size_t prior,const std::string& destinationMachineId);
            virtual void GetInfo(std::initializer_list<std::string> taskInfo) =0;
        protected:
            Ptr<TaskTable> m_taskStatusTable;
            std::string m_machineId;
//            std::string m_taskId;
//            double m_requestcpu;
//            double m_requestmem;
//            std::size_t m_prior;
//            std::string m_destinationMachineId = "";
    };
}
#endif /* GENERATETASKBASE_H */
