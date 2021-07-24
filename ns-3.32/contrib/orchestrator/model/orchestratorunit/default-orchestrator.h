#ifndef DEFAULTORCHESTRATOR_H
#define DEFAULTORCHESTRATOR_H
#include"ns3/orchestratorbase.h"
#include"ns3/task.h"
namespace ns3{
    class Task;
    class DefaultOrchestrator:public OrchestratorBase{

        private:
            Ptr<Task> m_task;
            std::map<std::string,std::string> m_taskAllocateTable;//记录相应task存放在resource container的哪个resource中，pair的first存放taskId作为关键字，因为本身一个task要被分配给一个resource。pair的second存放resourceId
            virtual void Release(Ptr<Task> task) override
            {
		        auto tableit = m_taskAllocateTable.find(task->GetTId());//tableit代表m_taskAllocateTable的迭代器
		        if(tableit==m_taskAllocateTable.end())
		        {
		            std::cerr<<"Can't release an non-existent task "<<std::endl;
		            abort();
		        }
		        std::string resourceId = tableit->second;
		        ResourceContainer container = *(m_node->GetObject<ResourceContainer>());
		        auto resourceIt = find_if(container.Begin(),container.End(),[resourceId](Ptr<Resource> r){return r->GetResourceId()==resourceId; });       
		        //auto resourceIt = find_if(container->Begin(),container->End(),[resourceId](ResourceContainer::Iterator r){return (*r)->GetResourceId()==resourceId;});
		        if(resourceIt==container.End())
		        {
		            std::cerr<<"Can't release resource, because Resource doesn't exist"<<std::endl;
		            abort();
		        }
		        Ptr<Resource> resource = *resourceIt;
		        resource->Release(task->GetRCpu(),task->GetRMemory());
		        StataTransfer(task,1);
            }
        public:
            DefaultOrchestrator(Ptr<TaskTable> table,Ptr<Node> node):OrchestratorBase(table,node){}
            virtual bool ChooseTask() override 
            {              
		        if(m_taskStatusTable->PendingEmpty())
		        {
		            std::cerr<<" has no pending task to run. "<<std::endl;
		            return 0;
		        }
		        m_task = m_taskStatusTable->FirstPriorInPending();
		        return 1;
		    }
            void StataTransfer(Ptr<Task> t,int i)
            {
		        if(i==0)
		        {
		            m_taskStatusTable->PendingToRunning(t);
		        }
		        else
		        {
		            m_taskStatusTable->RunningToDead(t);
		        }

            }
            virtual void Run() override
            {
		        m_taskStatusTable->CheckIn(m_task);
		        m_taskStatusTable->CheckStataCorrect(m_task);
		        Ptr<ResourceContainer> container = m_node->GetObject<ResourceContainer>();
		        for(auto it = container->Begin();it!=container->End();++it)
		        {
		            Ptr<Resource> resource = *it;
		            if(resource->Allocate(m_task->GetRCpu(),m_task->GetRMemory())==true)
		            {
		                StataTransfer(m_task,0);
		                m_taskAllocateTable.insert(std::make_pair(m_task->GetTId(),resource->GetResourceId()));
		                break; 
                    }
                }

            }
            void ReleaseResource()
            {
		        auto tableit = m_taskAllocateTable.find(m_task->GetTId());//tableit代表m_taskAllocateTable的迭代器
		        if(tableit==m_taskAllocateTable.end())
		        {
		            std::cerr<<"Can't release an non-existent task "<<std::endl;
		            abort();
		        }
		        std::string resourceId = tableit->second;
		        ResourceContainer container = *(m_node->GetObject<ResourceContainer>());
		        auto resourceIt = find_if(container.Begin(),container.End(),[resourceId](Ptr<Resource> r){return r->GetResourceId()==resourceId; });       
		        //auto resourceIt = find_if(container->Begin(),container->End(),[resourceId](ResourceContainer::Iterator r){return (*r)->GetResourceId()==resourceId;});
		        if(resourceIt==container.End())
		        {
		            std::cerr<<"Can't release resource, because Resource doesn't exist"<<std::endl;
		            abort();
		        }
		        Ptr<Resource> resource = *resourceIt;
		        resource->Release(m_task->GetRCpu(),m_task->GetRMemory());
		        StataTransfer(m_task,1);
		
            }

    };

};
#endif /* DEFAULTORCHESTRATOR_H*/
