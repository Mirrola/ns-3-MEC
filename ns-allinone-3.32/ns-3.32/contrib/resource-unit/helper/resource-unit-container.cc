#include"resource-unit-container.h"
#include"ns3/names.h"
namespace ns3{

    NS_OBJECT_ENSURE_REGISTERED(ResourceContainer);
    TypeId ResourceContainer::GetTypeId(void)
    {
        static TypeId tid = TypeId("ns3::ResourceContainer")
            .SetParent<Object>()
            .SetGroupName("MyResource")
            .AddConstructor<ResourceContainer>();
        return tid;
    }
    ResourceContainer::ResourceContainer(){}
    ResourceContainer::~ResourceContainer(){}
    ResourceContainer::ResourceContainer(Ptr<Resource> resource)
    {
        NS_ASSERT(resource!=NULL);
        m_resources.push_back(resource);
    }
    ResourceContainer::ResourceContainer(std::string resourceName)
    {
        Ptr<Resource> resource = Names::Find<Resource>(resourceName);
        NS_ASSERT(resource!=NULL);
        m_resources.push_back(resource);
    }
    ResourceContainer::ResourceContainer(const ResourceContainer &a,const ResourceContainer &b)
    {
        *this = a;
        Add(b);
    }
    ResourceContainer::Iterator ResourceContainer::Begin(void) 
    {
        return m_resources.begin();
    }
    ResourceContainer::Iterator ResourceContainer::End(void) 
    {
        return m_resources.end();
    }
    uint32_t ResourceContainer::GetN(void) 
    {
       return m_resources.size();
    }
    Ptr<Resource> ResourceContainer::Get(uint32_t i) 
    {
        return m_resources[i];
    }
    void ResourceContainer::Add(ResourceContainer container)
    {
        for(Iterator i =container.Begin();i!=container.End();++i)
        {
            m_resources.push_back(*i);
        }
    }
    void ResourceContainer::Add(Ptr<Resource> resource)
    {
        NS_ASSERT(resource!=NULL);
        m_resources.push_back(resource);
    }
    void ResourceContainer::Add(std::string sourceName)
    {
        Ptr<Resource> resource = Names::Find<Resource>(sourceName);
        NS_ASSERT(resource!=NULL);
        m_resources.push_back(resource);
    }

}
