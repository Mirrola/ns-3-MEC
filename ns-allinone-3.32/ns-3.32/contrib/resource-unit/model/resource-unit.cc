/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "resource-unit.h"

namespace ns3 {

    NS_LOG_COMPONENT_DEFINE ("Resource");
 
    NS_OBJECT_ENSURE_REGISTERED (Resource);
    TypeId Resource::GetTypeId(void)
    {
        static TypeId tid = TypeId("ns3::Resource")
            .SetParent<Object>()
            .SetGroupName("MyResource")
            .AddConstructor<Resource>()
            .AddAttribute("ResourceInitialCpu","Initial cpu stored in Resource",DoubleValue(0),MakeDoubleAccessor(&Resource::m_initialCpu),MakeDoubleChecker<double>())
            .AddAttribute("ResourceInitialMemory","Initial memory stored in Resource",DoubleValue(0),MakeDoubleAccessor(&Resource::m_initialMemory),MakeDoubleChecker<double>())
            .AddTraceSource("RemainingCpu","Remaining cpu at Resource",MakeTraceSourceAccessor(&Resource::m_remainingCpu),"ns3::TracedValueCallback::Double")
            .AddTraceSource("RemainingMemory","Remianing memory at Resource",MakeTraceSourceAccessor(&Resource::m_remainingMemory),"ns3::TracedValueCallback::Double");
        return tid;
    }
    Resource::Resource()=default;
    Resource::Resource(double cpu,double mem,std::string id):m_initialCpu(cpu),m_initialMemory(mem),m_resourceId(id){}
    void Resource::SetMemory(double mem) 
    {
        if(m_memoryUpdateEvent==false)
        {
            m_remainingMemory = mem;
            m_memoryUpdateEvent=true;
        }
        m_initialMemory = mem;
    }
    double Resource::GetMemory(void) const
    {
        return m_initialMemory;
    }
    void Resource::SetCpu(double cpu)
    {
        if(m_cpuUpdateEvent==false)
        {
            m_remainingCpu = cpu;
            m_cpuUpdateEvent=true;
        }
        m_initialCpu = cpu;
    }
    double Resource::GetCpu(void) const
    {
        return m_initialCpu;
    }
//    void Resource::UpdateRemainingMemory(double mem,std::size_t button)
//    {
//        if(button==0)
//        {
//            m_remainingMemory -= mem;
//        }
//        else if(button==1)
//        {
//            m_remainingMemory += mem;
//        }
//    }
//    void Resource::UpdateRemainingCpu(double cpu,std::size_t button)
//    {
//        if(button==0)
//        {
//            m_remainingCpu -= cpu;
//        }
//        else if(button==1)
//        {
//            m_remainingCpu += cpu;
//        }
//    }
//    bool Resource::UpdateRemainingMemory(double mem,std::size_t button)
//    {
//        NS_LOG_FUNCTION(this);
//        NS_LOG_DEBUG("Resource:Updating remaining memory");
//        DoDepleted();
//        if(m_depleted)
//        {
//           return false;
//        }
//        if(button==0&&(m_remainingMemory-mem<m_lowMemoryTh))
//        {
//            NS_LOG_DEBUG("Resource:Can't allocate resource,because the remianing memory is not enough");
//            return false;
//        }
//        else if(button==0&&(m_remainingMemory-mem>m_lowMemoryTh))
//        {
//            m_remainingMemory -= mem;
//            return true;
//        }
//        return false;
//    }
//    bool Resource::UpdateRemainingCpu(double cpu,std::size_t button)
//    {
//        NS_LOG_FUNCTION(this);
//        NS_LOG_DEBUG("Resource:Updating remaining memory");
//        DoDepleted();
//        if(m_depleted)
//        {
//           return false;
//        }
//        if(button==0&&(m_remainingCpu-cpu<m_lowCpuTh))
//        {
//            NS_LOG_DEBUG("Resource:Can't allocate resource,because the remianing cpu is not enough");
//            return false;
//        }
//        else if(button==0&&(m_remainingCpu-cpu>m_lowCpuTh))
//        {
//            m_remainingCpu -= cpu;
//            return true;
//        }
//        return false;
//    }
    bool Resource::Allocate(double cpu,double mem)
    {
        NS_LOG_FUNCTION(this);
        NS_LOG_DEBUG("Resource:Allocatig remaining memory and cpu");
        DoDepleted();
        if(m_depleted==true)
        {
            return false;
        }
        else if(DoEnough(cpu,mem)==false)
        {
            return false;
        }
        else
        {
            m_remainingCpu-=cpu;
            m_remainingMemory-=mem;
            NS_LOG_DEBUG("Resource:Allocate successfully finished");
            return true;
        }
    }
    bool Resource::Release(double cpu,double mem)
    {
        m_remainingCpu+=cpu;
        m_remainingMemory+=mem;
        return true;
    }
    
    void Resource::SetNode(Ptr<Node> node)
    {
        NS_LOG_FUNCTION(this);
        NS_ASSERT(node!=NULL);
        m_node = node;
    }
    Ptr<Node> Resource::GetNode(void) const
    {
        return m_node;
    }
    void Resource::SetResourceId(const std::string &id)
    {
        m_resourceId = id;
    }
    std::string Resource::GetResourceId(void) const
    {
        return m_resourceId;
    }
/*
  * Private functions start here.
  */
    void Resource::DoDepleted(void)
    {
        if(m_remainingCpu<=m_lowCpuTh)
        {
            NS_LOG_FUNCTION (this);
            NS_LOG_DEBUG ("Resource: is depleted!");
            std::cout<<"Resource:cpu is depleted!"<<std::endl;
            m_depleted=true;
        }
        else if(m_remainingMemory<=m_lowMemoryTh)
        {
            NS_LOG_FUNCTION (this);
            NS_LOG_DEBUG ("Resource: is depleted!");
            std::cout<<"Resource:memory is depleted!"<<std::endl;
            m_depleted=true;
        }
        else
        {
            m_depleted=false;
        }
    }
    bool Resource::DoEnough(double cpu,double mem)
    {
        if(m_remainingCpu-cpu<m_lowCpuTh||m_remainingMemory-mem<m_lowMemoryTh)
        {
            NS_LOG_FUNCTION(this);
            NS_LOG_DEBUG("Resource: is not enough to be allocated");
            std::cout<<"Resource: is not enough to be allocated"<<std::endl;
            return false;
        }
        else
        {
            return true;
        }
    }

}

