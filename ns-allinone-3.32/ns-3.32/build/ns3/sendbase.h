#ifndef SENDBASE_H
#define SENDBASE_H
#include"ns3/object.h"
#include"ns3/ptr.h"
#include"ns3/type-id.h"
#include"ns3/node.h"
#include"ns3/traced-value.h"
#include"ns3/task.h"
namespace ns3{
    class Task;
    class SendBase:public Object{
        public:
            static TypeId GetTypeId(void);
            SendBase();
            virtual ~SendBase();
            virtual void FindDestination(void)=0;
            void GetTask(Ptr<Task> t);
            void SetNode(Ptr<Node> node);
            Ptr<Node> GetNode(void) const;

        protected:
            virtual std::string MIdToIp();//该函数负责将machineid转换成相应的ip地址
            virtual void TransferIpToApplication();
            TracedValue<std::string> m_destination;//这里具体是保存ip地址呢还是保存machineid呢？我想让他直观地显示出来，那就保存machineid吧。函数部分还要有一个machineid转ip地址的函数
             //根据相应地算法找到目的地址之后，具体的发送环节就会由application来执行，所以需要把destination这个变量发给app，这时候就用到node了。因为node里面保存了安装在上面的app的container。node在这里就起到一个中间桥梁的作用
            Ptr<Task> m_task;
            Ptr<Node> m_node;
    };
}
#endif /* SENDBASE_H */
