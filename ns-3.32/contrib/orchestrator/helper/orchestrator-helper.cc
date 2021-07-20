/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "orchestrator-helper.h"
#include"ns3/config.h"
#include"ns3/names.h"
#include<iostream>

namespace ns3 {

    OrchestratorHelper::~OrchestratorHelper(){}
    void OrchestratorHelper::Install(Ptr<Node> node) const
    {
        Install(NodeContainer(node));
    }
    void OrchestratorHelper::Install(NodeContainer c) const
    {
        for(NodeContainer::Iterator i= c.Begin();i!=c.End();++i)
        {
            Ptr<Orchestrator> src = DoInstall(*i);
            Ptr<Orchestrator> OrchestratorOnNode = (*i)->GetObject<Orchestrator>();
            if(OrchestratorOnNode == NULL)
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
    Ptr<Orchestrator> OrchestratorHelper::DoInstall(Ptr<Node> node) const
    {
        NS_ASSERT(node!=NULL);
        ObjectFactory fac;
        fac.SetTypeId("ns3::Orchestrator");
        Ptr<Orchestrator> orchest = fac.Create<Orchestrator>();
        NS_ASSERT(orchest!=NULL);
        orchest->SetNode(node);
        return orchest;
    }

}

