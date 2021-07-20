/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef RESOURCE_UNIT_H
#define RESOURCE_UNIT_H
#include"ns3/object.h"
#include"ns3/ptr.h"
#include"ns3/type-id.h"
#include"ns3/node.h"
#include"ns3/nstime.h"
#include"ns3/traced-value.h"
#include<iostream>
namespace ns3 {

    class Resource:public Object {
        public:
            static TypeId GetTypeId(void);
            Resource();
            Resource(double cpu,double mem,std::string id);
            void SetMemory(double mem);
            double GetMemory(void) const;
            void SetCpu(double cpu);
            double GetCpu(void) const;
//            bool UpdateRemainingMemory(double mem,std::size_t button);//button == 0表示memory减少，button == 1表示memory增加
//            bool UpdateRemainingCpu(double cpu,std::size_t button);//button == 0表示memory减少，button == 1表示memory增加
            bool Allocate(double cpu,double mem);
            bool Release(double cpu,double mem);
            void SetNode(Ptr<Node> node);
            Ptr<Node> GetNode(void) const;
            void SetResourceId(const std::string &id);
            std::string GetResourceId(void) const;
        private:
            void DoDepleted(void);
            bool DoEnough(double cpu,double mem);

        private:
            Ptr<Node> m_node;
            //std::size_t type;  //用于标识这是云设备资源部件还是边、端的资源部件
            double m_initialCpu; //cpu分配单位暂时定为毫核
            double m_initialMemory;   //memory分配单位暂时没定
            std::string m_resourceId;
            double m_lowCpuTh=0;  //cpu的最低阈值，当m_remainingCpu小于此值时，机器会停止运作
            double m_lowMemoryTh=0; //memory的最低阈值，当m_remainingMemory小于此值时，机器会停止运作
            bool m_cpuUpdateEvent=false; //用于判断cpu资源部件是否被分配过
            bool m_memoryUpdateEvent=false; //用于判断memory资源部件是否被分配过
            bool m_depleted=false;  //当机器的cpu或者memory小于阈值时设为true
            Time m_lastUpdateTime;      //用于记录资源部件最后一次被更新的时间
            bool m_receiver;   //记录当前机器是否有发送部件
            bool m_transmator; //记录当前机器是否有接收部件
            TracedValue<double> m_remainingCpu;
            
            TracedValue<double> m_remainingMemory;
    };

}

#endif /* RESOURCE_UNIT_H */

