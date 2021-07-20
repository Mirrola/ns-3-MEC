#ifndef RESOURCE_CONTAINER_H
#define RESOURCE_CONTAINER_H
#include"ns3/resource-unit.h"
#include"ns3/object.h"
#include<vector>
#include<stdint.h>
namespace ns3{

    class ResourceContainer:public Object{

        public:

            typedef std::vector<Ptr<Resource>>::iterator Iterator;

        public:
            static TypeId GetTypeId(void);
            ResourceContainer();
            ~ResourceContainer();
            ResourceContainer(Ptr<Resource> resource);
            ResourceContainer(std::string resourceName);
            ResourceContainer(const ResourceContainer &a,const ResourceContainer &b);
            Iterator Begin(void) ;
            Iterator End(void) ;
            uint32_t GetN(void) ;
            Ptr<Resource> Get(uint32_t i) ;
            void Add(ResourceContainer container);
            void Add(Ptr<Resource> resource);
            void Add(std::string sourceName);
        
//        private:
//            void DoDispose(void);
//            void DoInitialize(void);
//参考energy-source-container.h  .cc

        private:
            std::vector<Ptr<Resource>> m_resources;


    };
}
 #endif /* RESOURCE_CONTAINER_H */
