/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include"ns3/core-module.h"
#include"ns3/resource-unit.h"
#include"ns3/resource-unit-container.h"
#include"ns3/resource-unit-helper.h"
#include"ns3/object.h"
#include <iostream>
#include"ns3/task.h"
#include"ns3/manager.h"
#include"ns3/manager-helper.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace ns3;
void
TraceCpu (double oldValue, double newValue)
{
  std::cout << "the old value of cpu  " << oldValue << " has changed to " << newValue << std::endl;
}
void
TraceMem (double oldValue, double newValue)
{
  std::cout << "the old value of memory  " << oldValue << " has changed to " << newValue << std::endl;
}
void
StringTraceNowId (std::string oldValue, std::string newValue)
{
  std::cout << "At time _s,the old value of NowId " << oldValue << " has changed to " << newValue << std::endl;
}
void
StringTraceNowStatus (std::string oldValue, std::string newValue)
{
  std::cout << "At time _s,the old status of task " << oldValue << " has changed to " << newValue << std::endl;
}
int
main (int argc, char *argv[])
{

    NodeContainer nodes;
    nodes.Create(3);
    /* 向指定node安装资源部件*/
    ResourceHelper res;
    res.Install(nodes.Get(2));
    Ptr<Node> node = nodes.Get(2);
    Ptr<ResourceContainer> container= node->GetObject<ResourceContainer>();
    Ptr<Resource> re2 = CreateObject<Resource>();
    container->Add(re2);
    Ptr<Resource> MyResource = *(container->Begin());
    re2->TraceConnectWithoutContext ("RemainingMemory", MakeCallback (&TraceMem));
    re2->TraceConnectWithoutContext ("RemainingCpu", MakeCallback (&TraceCpu));
    MyResource->TraceConnectWithoutContext ("RemainingMemory", MakeCallback (&TraceMem));
    MyResource->TraceConnectWithoutContext ("RemainingCpu", MakeCallback (&TraceCpu));
    /* 向指定node安装调度部件*/
    ManagerHelper manager;
    manager.Install(nodes.Get(2));
    auto no_manager = nodes.Get(2)->GetObject<Manager>();
//    Task task1(1,2),task2(2,2),task3(2,3);
    MyResource->SetResourceId("2020001");
    MyResource->SetMemory(6);
    MyResource->SetCpu(6);
    re2->SetResourceId("2020002");
    re2->SetMemory(3);
    re2->SetCpu(4);
    no_manager->GetTaskInfo("s00001","2","2","3");


//    no_orh->GenerateTask("s00001",2,2,3);
//    no_orh->GenerateTask("s00002",1,1,2);
//    no_orh->GenerateTask("s00003",1,3,5,"acsda");
//    no_orh->GenerateTask("s00004",2,3,5);
//    no_orh->GenerateTask("s00005",4,3,5);
//    no_orh->PrintStata();
//    no_orh->ChooseOneToRun();
//    no_orh->ChooseOneToRun();
//    no_orh->ChooseOneToRun();
//    no_orh->ChooseOneToRun();
//    no_orh->ChooseOneToRun();
    
//    table.GetTask(t1);
//    table.GetTask(t2);
//    table.GetTask(t3);
//    table.GetTask(t4);
//    table.GetTask(t5);
//    table.GetTask(t6);
//    table.GetTask(t7);
//    table.GetTask(t8);
//    std::cout<<"--------------------------------------------------------------"<<std::endl;
//    no_orh->AssignTasktoResource(t3);
//    no_orh->AssignTasktoResource(t4);
//    no_orh->AssignTasktoResource(t5);
//    std::cout<<"--------------------------------------------------------------"<<std::endl;
//    no_orh->PrintStata();
//    no_orh->ReleaseTaskResource(t4);
//    std::cout<<"--------------------------------------------------------------"<<std::endl;
//    no_orh->PrintStata();
    /* 开始仿真*/
//    Simulator::Schedule(Seconds(0),&Resource::SetMemory,MyResource,0.2493);
//    Simulator::Schedule(Seconds(0),&Resource::SetCpu,MyResource,0.5);
//    Simulator::Stop(Seconds(10000000000000));
//    Simulator::Run();
//    Simulator::Destroy();
    return 0;

}
