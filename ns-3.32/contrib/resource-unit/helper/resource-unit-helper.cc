/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "resource-unit-helper.h"
#include"ns3/config.h"
#include"ns3/names.h"

namespace ns3 {

    ResourceHelper::~ResourceHelper(){}
    ResourceContainer ResourceHelper::Install(Ptr<Node> node)const
    {
        return Install(NodeContainer(node));
    }
    ResourceContainer ResourceHelper::Install(NodeContainer c) const
    {
        ResourceContainer container;
        for(NodeContainer::Iterator i=c.Begin();i!=c.End();++i)
        {
            Ptr<Resource> src = DoInstall(*i);
            container.Add(src);
            Ptr<ResourceContainer> ResourceContainerOnNode=(*i)->GetObject<ResourceContainer>();
            if(ResourceContainerOnNode==NULL)
            {
                ObjectFactory fac;
                fac.SetTypeId("ns3::ResourceContainer");
                ResourceContainerOnNode = fac.Create<ResourceContainer>();
                ResourceContainerOnNode->Add(src);
                (*i)->AggregateObject(ResourceContainerOnNode);
            }
            else
            {
                ResourceContainerOnNode->Add(src);
            }
        }
        return container;
    }
    ResourceContainer ResourceHelper::Install(std::string nodeName)const
    {
        Ptr<Node> node=Names::Find<Node>(nodeName);
        return Install(node);
    }
    ResourceContainer ResourceHelper::InstallAll(void) const
    {
        return Install(NodeContainer::GetGlobal());
    }

    /* private part*/

    Ptr<Resource> ResourceHelper::DoInstall(Ptr<Node> node) const
    {
        NS_ASSERT(node!=NULL);
        ObjectFactory fac;
        fac.SetTypeId("ns3::Resource");
        Ptr<Resource> resource = fac.Create<Resource>();
        NS_ASSERT(resource!=NULL);
        resource->SetNode(node);
        return resource;
    }
        
}

