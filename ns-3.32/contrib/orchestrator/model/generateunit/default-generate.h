#ifndef DEFAULTGENERATE_H
#define DEFAULTGENERATE_H
#include"ns3/generatetaskbase.h"
#include"ns3/task.h"
#include"ns3/task-table.h"
#include <initializer_list>
#include "boost/lexical_cast.hpp"
namespace ns3{
    class DefaultGenerate:public GenerateTaskBase{
        public:
            static TypeId GetTypeId(void)
		    {
		        static TypeId tid = TypeId("ns3::DefaultGenerate")
		            .SetParent<Object>()
		            .SetGroupName("MyGenerate");
		        return tid;
		    }

            DefaultGenerate(Ptr<TaskTable> table,std::string Mid):GenerateTaskBase(table,Mid){}
            virtual Ptr<Task> Generate() override
            {
               // auto now_orche = m_node.GetObject<OrchestratorBase>();
		        Task orinewtask(m_taskId,m_requestcpu,m_requestmem,m_prior);
		        Ptr<Task> newtask = CreateObject<Task>(orinewtask);
		        
		        newtask->ChangeOriginMId(m_machineId);
		        if(!m_destinationMachineId.empty())
		        {
		            //newtask->ChangeDestinationMId(destinationMachineId);
		            //newtask->Unsubmitted();
                    //这里直接调用继续进行转发，但是逻辑还理不太清。目前想法是直接把task传给app，直接发送然后跳出这个函数。

		        }
		        else
		        {
		            newtask->ChangeDestinationMId(m_machineId);
               //     当目标地址为空时，发送目标就为本机地址，直接把任务加到本机的pending表
		        }
		        newtask->ChangeNowMId(m_machineId);
                m_taskStatusTable->GetTask(newtask);
		        //if(destinationMachineId.empty())
		        //{
		        //    ReceiveTask(newtask);
		        //}
		        return newtask;
            }
            virtual void GetInfo(std::initializer_list<std::string> taskInfo) override
            {
                auto it = taskInfo.begin();
                m_taskId = *(it++);
                m_requestcpu =boost::lexical_cast<double>(*it++);
                m_requestmem = boost::lexical_cast<double>(*it++);
                m_prior = boost::lexical_cast<std::size_t>(*it++);
                m_destinationMachineId = *(it);
            }
        private:
            std::string m_taskId;
            double m_requestcpu;
            double m_requestmem;
            std::size_t m_prior;
            std::string m_destinationMachineId = "";
    };
}
#endif /*  DEFAULTGENERATE_H    */
