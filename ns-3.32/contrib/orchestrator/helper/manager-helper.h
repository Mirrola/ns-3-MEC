/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef MANAGER_HELPER_H
#define MANAGER_HELPER_H

#include "ns3/manager.h"
#include"ns3/attribute.h"
#include"ns3/object-factory.h"
#include"ns3/node-container.h"
#include"ns3/ptr.h"
#include"ns3/net-device.h"
#include"ns3/net-device-container.h"

namespace ns3 {

    class ManagerHelper{

        public:
            ~ManagerHelper();
            void Install(Ptr<Node> node) const;
            void Install(NodeContainer c) const;

        private:
            Ptr<Manager> DoInstall(Ptr<Node> node) const;
    };

}

#endif /* ORCHESTRATOR_HELPER_H */


