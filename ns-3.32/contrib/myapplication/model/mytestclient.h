/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef TEST_UDP_ECHO_CLIENT_H
#define TEST_UDP_ECHO_CLIENT_H

#include "ns3/application.h"
#include "ns3/event-id.h"
#include "ns3/ptr.h"
#include "ns3/ipv4-address.h"
#include "ns3/traced-callback.h"
#include "ns3/task.h"
#include "ns3/manager.h"
namespace ns3 {

class Socket;
class Packet;

    class TestUdpEchoClient : public Application
    {
        public:
	        static TypeId GetTypeId(void);
	        
	        TestUdpEchoClient();
	        virtual ~TestUdpEchoClient();
	        
	        void SetRemote(Address ip, uint16_t port);
	
	        void SetRemote(Address addr);
	
	//      void SetDataSize(uint32_t dataSize);
	
	        uint32_t GetDataSize(void) const;
	
	        void SetFill (std::string fill);

            std::string Serialization(const Task& t);
            
            std::pair<Ptr<Task>,bool> Deserialization(const std::string& t);

            void ReceiveTask(const Task& t);//接受一个任务之后发送出去


	
        
        protected:
            virtual void DoDispose(void);

        private:
            
	  	    virtual void StartApplication (void);
	  		virtual void StopApplication (void);
	  		
	  		  /**
	  		   * \brief Schedule the next packet transmission
	  		   * \param dt time interval between packets.
	  		   */
	  		void ScheduleTransmit (Time dt);
	  		  /**
	  		   * \brief Send a packet
	  		   */
	  		void Send (void);
	  		
	  		  /**
	  		   * \brief Handle a packet reception.
	  		   *
	  		   * This function is called by lower layers.
	  		   *
	  		   * \param socket the socket the packet was received to.
	  		   */
	  		  void HandleRead (Ptr<Socket> socket);
	  		
//	  		  uint32_t m_count; //!< Maximum number of packets the application will send
//	  		  Time m_interval; //!< Packet inter-send time
	  		  uint32_t m_size; //!< Size of the sent packet
  		
	  		  uint32_t m_dataSize; //!< packet payload size (must be equal to m_size)
	  		  uint8_t *m_data; //!< packet payload data
	  		
//	  		  uint32_t m_sent; //!< Counter for sent packets
	  		  Ptr<Socket> m_socket; //!< Socket
	  		  Address m_peerAddress; //!< Remote peer address
	  		  uint16_t m_peerPort; //!< Remote peer port
	  		  EventId m_sendEvent; //!< Event to send the next packet
	  		
	  		  /// Callbacks for tracing the packet Tx events
	  		  TracedCallback<Ptr<const Packet> > m_txTrace;
	  		
	  		  /// Callbacks for tracing the packet Rx events
	  		  TracedCallback<Ptr<const Packet> > m_rxTrace;
	  		  
	  		  /// Callbacks for tracing the packet Tx events, includes source and destination addresses
	  		  TracedCallback<Ptr<const Packet>, const Address &, const Address &> m_txTraceWithAddresses;
	  		  
	  		  /// Callbacks for tracing the packet Rx events, includes source and destination addresses
	  		  TracedCallback<Ptr<const Packet>, const Address &, const Address &> m_rxTraceWithAddresses;

              Task m_task; 
            
              //Task m_readyToSend;

    };

}

#endif /* TEST_UDP_ECHO_CLIENT_H */

