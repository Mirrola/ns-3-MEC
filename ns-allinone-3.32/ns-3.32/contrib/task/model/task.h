/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef TASK_H
#define TASK_H
#include"ns3/object.h"
#include"ns3/ptr.h"
#include"ns3/type-id.h"
#include"ns3/node.h"
#include"ns3/traced-value.h"
#include"ns3/orchestratorbase.h"
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
namespace ns3 {
    class OrchestratorBase;
    class Task:public Object{
        friend class OrchestratorBase;
        friend class boost::serialization::access;
        public:
            Task(){m_requestCpu=0;m_requestMemory=0;      }
            static TypeId GetTypeId(void);
//            Task(std::string taskid,double requestcpu,double requestmem):m_taskId(taskid),m_requestCpu(requestcpu),m_requestMemory(requestmem
//){};
//            Task(double requestcpu,double requestmem):m_requestCpu(requestcpu),m_requestMemory(requestmem){};
//            Task(std::string id,double requestcpu,double requestmem,std::size_t prior,int cate);
//            Task(std::string taskid,double requestcpu,double requestmem,std::size_t prior,std::string machineid):m_taskId(taskid),m_requestCpu(requestcpu),m_requestMemory(requestmem),m_priority(prior),m_originMachineId(machineid){};
            std::string GetTId(void) const;
            double GetRCpu(void) const;
            double GetRMemory(void) const;
            void ChangePriority(std::size_t prior);
            std::size_t GetPriority(void) const;
            std::string GetOriginMId(void) const;
            void ChangeOriginMId(std::string originMId);
            void ChangeNowMId(std::string id);
            std::string GetNowMId(void) const;
            void ChangeDestinationMId(std::string id);
            std::string GetDestinationMId(void) const;
  		    template<class Ar> void serialize(Ar& ar, const unsigned int version)
  		    {
  		      ar & m_taskId;
              ar & m_requestCpu;
              ar & m_requestMemory;
              ar & m_priority;
              //ar & m_originMachineId;
              //ar & m_destinationMachineId;
              //ar & m_nowMachineId;
              //ar & m_categoryInt;
              //ar & m_categoryString;
  		    }
/*-------------------status public function--------------------------*/

            void Unsubmitted(void);//这一状态包括任务刚刚创建以及当前machine刚刚接收此任务
            void Pending(void);
            void Running(void);
            void Dead(void);
            std::string GetCategoryString(void) const;
            int GetCategoryInt(void) const;

       
            Task(std::string taskid,double requestcpu,double requestmem,std::size_t prior):m_taskId(taskid),m_requestCpu(requestcpu),m_requestMemory(requestmem),m_priority(prior){}
        private:
            std::string m_taskId="";              //任务的id
            double m_requestCpu;
            double m_requestMemory;
            std::size_t m_priority=0;           //任务的优先级
            std::string m_originMachineId="";    //生成任务的机器id
            TracedValue<std::string> m_destinationMachineId="";//空字符串可代表本机id
            TracedValue<std::string> m_nowMachineId="";  //表明任务当前所在machine的id
/*----------------------status information--------------------------*/
            void  ChangeStateInfo(int cate); 
            int m_categoryInt=2;
            TracedValue<std::string> m_categoryString="Pending"; //用于trace对外输出，string会比int更加直观
            


};
}
#endif /* TASK_H */

