/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef ORCHESTRATOR_HELPER_H
#define ORCHESTRATOR_HELPER_H

#include "ns3/orchestrator.h"
#include"ns3/attribute.h"
#include"ns3/object-factory.h"
#include"ns3/node-container.h"
#include"ns3/ptr.h"
#include"ns3/net-device.h"
#include"ns3/net-device-container.h"

namespace ns3 {

    class OrchestratorHelper{

        public:
            ~OrchestratorHelper();
            void Install(Ptr<Node> node) const;
            void Install(NodeContainer c) const;

        private:
            Ptr<Orchestrator> DoInstall(Ptr<Node> node) const;
    };

}

#endif /* ORCHESTRATOR_HELPER_H */

