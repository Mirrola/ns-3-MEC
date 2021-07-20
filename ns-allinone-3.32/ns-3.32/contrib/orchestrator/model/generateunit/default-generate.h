#ifdef DEFAULTGENERATE_H
#define DEFAULTGENERATE_H
#include"ns3/generatetaskbase.h"
#include"ns3/task.h"
#include"ns3/task-table.h"
namespace ns3{
    class DefaultGenerate:public GenerateTaskBase{
        public:
            static TypeId GetTypeId(void);
            DefaultGenerate(Ptr<TaskTable> table,std::string Mid):GenerateTaskBase(table,Mid){}
            ~DefaultGenerate();
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
//            void GetInfo(std::string taskId,double requestecpu,double requestmem,std::size_t prior,const std::string& destinationMachineId)
//            {
//                m_taskId = taskId;
//                m_requestcpu =requestecpu;
//                m_requestmem = requestmem;
//                m_prior = prior;
//                m_destinationMachineId = destinationMachineId;
//            }
//        private:
//            std::string m_taskId;
//            double m_requestcpu;
//            double m_requestmem;
//            std::size_t m_prior;
//            std::string m_destinationMachineId = "";
    };
}
#endif /*  DEFAULTGENERATE_H    */
