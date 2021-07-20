/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifdef  TASK_STATUS_H
#define TASK_STATUS_H
#include"ns3/object.h"
#include"ns3/ptr.h"
#include"ns3/type-id.h"
#include"ns3/node.h"
#include"ns3/traced-value.h"
namespace ns3 {

    class Status : public Object{
        public:
            explicit Status();
            static TypeId GetTypeId(void);
            static Status Unsubmitted();
            static Status Pending(void);
            static Status Running(void);
            static Status Dead(void);
            //void ChangeStatus(Status (*pf)(void));
        private:
            //explicit Status(int cate);
            int m_categoryInt;
            TraceValue<std::string> m_categoryString; //用于trace对外输出，string会比int更加直观
    };

}
#endif /* TASK_STATUS_H */

