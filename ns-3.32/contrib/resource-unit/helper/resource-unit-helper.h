/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef RESOURCE_UNIT_HELPER_H
#define RESOURCE_UNIT_HELPER_H

#include"ns3/attribute.h"
#include"ns3/object-factory.h"
#include"ns3/node-container.h"
#include"ns3/ptr.h"
#include"ns3/net-device.h"
#include"ns3/net-device-container.h"
#include"resource-unit-container.h"
#include "ns3/resource-unit.h"

//参考energy-model-helper.h

namespace ns3 {

    class ResourceHelper{
        public:
            ~ResourceHelper();
            void Set(std::string name,const AttributeValue &v);
            ResourceContainer Install(Ptr<Node> node) const;
            ResourceContainer Install(NodeContainer c) const;
            ResourceContainer Install(std::string nodeName) const;
            ResourceContainer InstallAll(void) const;

        private:
            Ptr<Resource> DoInstall(Ptr<Node> node) const;

    };

}

#endif /* RESOURCE_UNIT_HELPER_H */

