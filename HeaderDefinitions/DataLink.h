#pragma once
/**
* 
* @Author: Billy Ndegwah Micah [ billyndegz13@gmail.com ]
* 
*/



#ifndef DATALINK_LAYER
#define DATALINK_LAYER
#include "HeaderDefinitions.h"

class DataLinkHeader {
private:
    LogicalLinkControl logicalControl;
    bool frameStart{ true };
    Protocol protocolType;
    const char* control;
    const char* data;
    FrameErrorCheck errorCheck;
    bool frameStop{ true };


public:
    DataLinkHeader();

    ~DataLinkHeader();
    int checkErrors();
    int frameDelimiting();
    MacAddress attachAddress();

};
 

#endif // !DATALINK_LAYER

#ifndef NETWORK_LAYER

struct Segment{

    // Functions:
    // [Addressing end devices(IPv4 or IPv6), Encapsulation, Routing,
    //    De - encapsulation]
    void addressEndDevice();
    void routing();
    void encapsulateL3();
    void de_encapsulateL3();
};

#endif // !NETWORK_LAYER


#ifndef TRANSPORT_LAYER

struct TcpProtocol {
    int sourcePort : 16;
    int destinationPort : 16;
    int sequenceNumber : 32;
    int acknowledgementNumber : 32;
    int reserved : 6;
    int controlBits : 6;
    int windowSize : 16;
    int urgent : 16;
    int headerLength : 4;
    int checksum;
};

struct UdpProtocol {
    int sourcePort : 16;
    int destinationPort : 16;
    int length : 16;
    int checksum;
};

#endif // !TRANSPORT_LAYER



#ifndef PROTOCOL
#define PROTOCOL

struct LogicalLinkControl {
    Ipv4 address;
    Ipv6 addressOne;
};

struct MacAddress {
    const char* macAddress;
};

enum Protocol {
    // some common protocols include the below
    ICMP,
    TCP,
    UDP
};

#endif // !PROTOCOL

#ifndef IPV4

struct Ipv4 {
    int headerSize{ 20 };
    int version : 4;
    int differentiatedService : 8;
    /**
     * @brief 
     * IPV4 technology uses identification, flags and fragmented
     * offset to reorder packets as they're being received.
    */
    int identification;
    int flags;
    int fragmentedOfset;
    // limit the packets life just incase it doesn't reach the 
    // destination within the desired time.
    int timeToLive : 8;
    Protocol protocol;
    int headerChecksum;
    const char* sourceIPV4;
    const char* destinationIPV4;

};


#endif // !IPV4

#ifndef IPV6

struct Ipv6 {
    int headerSize{ 40 };
    int version : 4;
    int trafficControl : 8;
    int flowLabel : 20;
    int payloadLength : 16;
    // next header in IPV6 is similar to the IPV4's protocol
    // field which points to the targeted protocol intended to
    // receive the packet.
    const char* nextHeader;
    int hopLimit : 8;
    const char* sourceIPV6;
    const char* destinationIPV6;

};


#endif // !IPV6

