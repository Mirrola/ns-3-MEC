#include"task-table.h"
namespace ns3{
    NS_LOG_COMPONENT_DEFINE("TaskTable");
    NS_OBJECT_ENSURE_REGISTERED(TaskTable);
    void TaskTable::GetTask(Ptr<Task> t)
    {
        InsertByPriority(t);
    }
    void TaskTable::Print(void) const
    {
        std::cout<<"UnsubmitList information"<<std::endl;
        Printlist(m_unsubmitList);
        std::cout<<"PendingList information"<<std::endl;
        Printlist(m_pendingList);
        std::cout<<"RunningList information"<<std::endl;
        Printlist(m_runningList);
        std::cout<<"DeadList information"<<std::endl;
        Printlist(m_deadList);
    }
    void TaskTable::CheckIn(Ptr<Task> t) const
    {
        auto it = find_if(m_pendingList.begin(),m_pendingList.end(),[t](Ptr<Task> a){return a->GetTId()==t->GetTId();});
        if(it == m_pendingList.end())
        {
            std::cout<<"Task dosen't exist in this machine's Pending list,you can't schedule it "<<std::endl;
            abort();
        }
    }
    void TaskTable::CheckStataCorrect(Ptr<Task> t) const
    {
        if(t->GetCategoryInt() != 2)
        {
            std::cout<<"You can only change pending to running."<<std::endl;
            abort();
        }
    }
    void TaskTable::PendingToRunning(Ptr<Task> t)
    {
        auto it = find_if(m_pendingList.begin(),m_pendingList.end(),[t](Ptr<Task> a){return a->GetTId()==t->GetTId();});
//        if(it == m_pendingList.end())
//        {
//            std::cout<<"Task doesn't exist "<<std::endl;
//            abort();
//        }
        auto temp = *it;
        //m_unsubmitList.erase(it);
        m_pendingList.erase(it);
        temp->Running();
        InsertByPriority(temp);

    }
    void TaskTable::RunningToDead(Ptr<Task> t)
    {
        auto it = find_if(m_runningList.begin(),m_runningList.end(),[t](Ptr<Task> a){return a->GetTId()==t->GetTId();});
//        if(it == m_pendingList.end())
//        {
//            std::cout<<"Task doesn't exist "<<std::endl;
//            abort();
//        }
        auto temp = *it;
        m_runningList.erase(it);
        temp->Dead();
        InsertByPriority(temp);
    }
    void TaskTable::Printlist(const std::list<Ptr<Task>> &l) const
    {
        std::cout<<"TaskId"<<'\t'<<"cpu"<<'\t'<<"mem"<<'\t'<<"priority"<<'\t'<<"category"<<std::endl;
        for(auto i = l.begin();i!=l.end();++i)
        {
            std::cout<<(*i)->GetTId()<<'\t'<<(*i)->GetRCpu()<<'\t'<<(*i)->GetRMemory()<<'\t'<<(*i)->GetPriority()<<'\t'<<'\t'<<(*i)->GetCategoryString()<<std::endl;
        }
    }
    Ptr<Task> TaskTable::FirstPriorInPending(void)
    {
        return *m_pendingList.begin();
    }
    bool TaskTable::PendingEmpty(void)
    {
        return m_pendingList.empty();
    }
    void TaskTable::InsertByPriority(Ptr<Task> t)
    {
        std::list<Ptr<Task>> *l = nullptr;
        int cate = t->GetCategoryInt();
        switch(cate)
        {
            case 1:
                {
                    l = &m_unsubmitList;
                    break;
                }
            case 2:
                {
                    l = &m_pendingList;
                    break;
                }
            case 3:
                {
                    l = &m_runningList;
                    break;
                }
            case 4:
                {
                    l = &m_deadList;
                    break;
                }
            default:
                {
                    std::cout<<"Error: Task status doesn't match any category"<<std::endl;
                    abort();
                }
        }
        auto it = find_if(l->begin(),l->end(),[t](Ptr<Task> a){return  a->GetPriority()<t->GetPriority();});
        l->insert(it,t);
    }
}

