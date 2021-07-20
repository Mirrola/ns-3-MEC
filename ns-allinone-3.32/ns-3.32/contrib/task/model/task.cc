/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "task.h"
#include<iostream>
#include"ns3/string.h"
namespace ns3 {

    NS_LOG_COMPONENT_DEFINE("Task");
    NS_OBJECT_ENSURE_REGISTERED(Task);

    TypeId Task::GetTypeId(void)
    {
        static TypeId tid = TypeId("ns3::Task")
            .SetParent<Object>()
            .SetGroupName("MyTask")
            .AddConstructor<Task>()
            .AddAttribute("TaskDestinationMachineId","Destination machine id of this task",StringValue(""),MakeStringAccessor(&Task::m_destinationMachineId),MakeStringChecker())
            .AddAttribute("TaskNowMachineId","Present machine id of this task",StringValue(""),MakeStringAccessor(&Task::m_nowMachineId),MakeStringChecker())
            .AddTraceSource("TaskDestinationMachineId","Destination machine id of this task",MakeTraceSourceAccessor(&Task::m_destinationMachineId),"ns3::Task::TracedCallback")
            .AddTraceSource("TaskPresentMachineId","Present mechine id of this task",MakeTraceSourceAccessor(&Task::m_nowMachineId),"ns3::Task::TracedCallback")
            .AddTraceSource("CategoryString","String type of present status category",MakeTraceSourceAccessor(&Task::m_categoryString),"ns3::Status::TracedCallback");
            return tid;
    }
//    Task::Task() = default;
//    Task::Task(std::string id,double requestcpu,double requestmem,std::size_t prior,int cate):m_taskId(id),m_requestCpu(requestcpu),m_requestMemory(requestmem),m_priority(prior),m_categoryInt(cate)
//    {
//        switch(m_categoryInt)
//        {
//            case 1:
//                {
//                    m_categoryString = "Unsubmitted";
//                    break;
//                }
//            case 2:
//                {
//                    m_categoryString = "Pending";
//                    break;
//                }
//            case 3:
//                {
//                    m_categoryString = "Running";
//                    break;
//                }
//            case 4:
//                {
//                    m_categoryString = "Dead";
//                    break;
//                }
//            default:
//                {
//                    std::cout<<"Program goes wrong,m_categoryString doesn't have default value"<<std::endl;   
//                }
//        }
//    }
    std::string Task::GetTId(void) const
    {
        return m_taskId;
    }
    double Task::GetRCpu(void) const
    {
        return m_requestCpu;
    }
    double Task::GetRMemory(void) const
    {
        return m_requestMemory;
    }
    void Task::ChangePriority(std::size_t prior)
    {
        m_priority = prior;
    }
    std::size_t Task::GetPriority(void) const
    {
        return m_priority;
    }
    std::string Task::GetOriginMId(void) const
    {
        return m_originMachineId;
    }
    void Task::ChangeOriginMId(std::string originMId)
    {
        m_originMachineId = originMId;
    }
    void Task::ChangeNowMId(std::string id) 
    {
        m_nowMachineId = id; 
    }
    std::string Task::GetNowMId(void) const
    {
        return m_nowMachineId;
    }
    void Task::ChangeDestinationMId(std::string id)
    {
        m_destinationMachineId = id;
    }
    std::string Task::GetDestinationMId(void) const
    {
        return m_destinationMachineId;
    }
/*-----------------------status private function---------------------*/
    void Task::ChangeStateInfo(int cate)
    {
        m_categoryInt = cate;
        switch(m_categoryInt)
        {
            case 1:
                {
                    m_categoryString = "Unsubmitted";
                    break;
                }
            case 2:
                {
                    m_categoryString = "Pending";
                    break;
                }
            case 3:
                {
                    m_categoryString = "Running";
                    break;
                }
            case 4:
                {
                    m_categoryString = "Dead";
                    break;
                }
            default:
                {
                    std::cout<<"Program goes wrong,m_categoryString doesn't have default value"<<std::endl;   
                }
        }

    }
/*---------------------public status funtion------------------------*/
    void Task::Unsubmitted(void)
    {
        ChangeStateInfo(1);
    }
    void Task::Pending(void)
    {
        ChangeStateInfo(2);
    }
    void Task::Running(void)
    {
        ChangeStateInfo(3);
    }
    void Task::Dead(void)
    {
        ChangeStateInfo(4);
    }
    std::string Task::GetCategoryString(void) const
    {
        return m_categoryString;
    }
    int Task::GetCategoryInt(void) const
    {
        return m_categoryInt;
    }
}

