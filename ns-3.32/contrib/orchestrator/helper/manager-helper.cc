/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "manager-helper.h"
#include"ns3/config.h"
#include"ns3/names.h"
#include<iostream>

namespace ns3 {

    ManagerHelper::~ManagerHelper(){}
    void ManagerHelper::Install(Ptr<Node> node) const
    {
        Install(NodeContainer(node));
    }
    void ManagerHelper::Install(NodeContainer c) const
    {
        for(NodeContainer::Iterator i= c.Begin();i!=c.End();++i)
        {
            Ptr<Manager> src = DoInstall(*i);
            Ptr<Manager> ManagerOnNode = (*i)->GetObject<Manager>();
            if(ManagerOnNode == NULL)
            {
                (*i)->AggregateObject(src);
            }
            else
            {
                std::cout<<"Code goes wrong, each node can only have one orchestrator"<<std::endl;
            }
        }

    }

    /*     private  part        */
    Ptr<Manager> ManagerHelper::DoInstall(Ptr<Node> node) const
    {
        NS_ASSERT(node!=NULL);
        ObjectFactory fac;
        fac.SetTypeId("ns3::Manager");
        Ptr<Manager> manager = fac.Create<Manager>();
        NS_ASSERT(manager!=NULL);
        manager->SetNode(node);
        return manager;
    }

}

