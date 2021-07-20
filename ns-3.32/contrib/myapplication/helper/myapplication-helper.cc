/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "myapplication-helper.h"
#include "ns3/udp-echo-server.h"
#include "ns3/udp-echo-client.h"
#include "ns3/uinteger.h"
#include "ns3/names.h"

namespace ns3 {

TestUdpEchoClientHelper::TestUdpEchoClientHelper (Address address, uint16_t port)
{
  m_factory.SetTypeId (TestUdpEchoClient::GetTypeId ());
  SetAttribute ("RemoteAddress", AddressValue (address));
  SetAttribute ("RemotePort", UintegerValue (port));
}

TestUdpEchoClientHelper::TestUdpEchoClientHelper (Address address)
{
  m_factory.SetTypeId (TestUdpEchoClient::GetTypeId ());
  SetAttribute ("RemoteAddress", AddressValue (address));
}

void 
TestUdpEchoClientHelper::SetAttribute (
  std::string name, 
  const AttributeValue &value)
{
  m_factory.Set (name, value);
}

void
TestUdpEchoClientHelper::SetFill (Ptr<Application> app, std::string fill)
{
  app->GetObject<TestUdpEchoClient>()->SetFill (fill);
}

//void
//TestUdpEchoClientHelper::SetFill (Ptr<Application> app, uint8_t fill, uint32_t dataLength)
//{
//  app->GetObject<TestUdpEchoClient>()->SetFill (fill, dataLength);
//}
//
//void
//TestUdpEchoClientHelper::SetFill (Ptr<Application> app, uint8_t *fill, uint32_t fillLength, uint32_t dataLength)
//{
//  app->GetObject<TestUdpEchoClient>()->SetFill (fill, fillLength, dataLength);
//}

ApplicationContainer
TestUdpEchoClientHelper::Install (Ptr<Node> node) const
{
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
TestUdpEchoClientHelper::Install (std::string nodeName) const
{
  Ptr<Node> node = Names::Find<Node> (nodeName);
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
TestUdpEchoClientHelper::Install (NodeContainer c) const
{
  ApplicationContainer apps;
  for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
    {
      apps.Add (InstallPriv (*i));
    }

  return apps;
}

Ptr<Application>
TestUdpEchoClientHelper::InstallPriv (Ptr<Node> node) const
{
  Ptr<Application> app = m_factory.Create<TestUdpEchoClient> ();
  node->AddApplication (app);

  return app;
}


}

