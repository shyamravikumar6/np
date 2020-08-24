## Previous year questions 
- SMTP & POP3 are the protocols which are responsible for the email communication, SMTP is responsible for     outgoing mail & POP3 is responsible for retrieving mail.
- POP3: Post Office Protocol (Responsible for retrieve email)
 - IMAP: Internet Message Access protocol (Responsible for store and view)
 MIME: Multi purpose Internet Mail Extensions (For media) 

 ### Eulier tutoient 
 -  ϕ(n)=(p−1)×(q−1)

n=pq

2880=pq−p−q+1

128=p+q...................(1)

3007=pq.....................(2)

Using (1) & (2)

q2−128q+3007

Roots:

−b±b2−4ac−−−−−−−√2a128±(128)2−4×1×3007−−−−−−−−−−−−−−−−−√2128±6621942=97✓ & 622=31

## ARP(automatic repeat process)
Address Resolution Protocol
- If a machine talks to another machine in the same network, it requires its physical or MAC address. But ,since the application has given the destination's IP address it requires some mechanism to bind the IP address with its MAC address.
- This is done through Address Resolution protocol (ARP).
- IP address of the destination node is broadcast and the destination node informs the source of its MAC address.

    Assume broadcast nature of LAN
    Broadcast IP address of the destination
    Destination replies it with its MAC address.
    Source maintains a cache of IP and MAC address bindings 

- But this means that every time machine A wants to send packets to machine B, A has to send an ARP packet to resolve the MAC address of B and hence this will increase the traffic load too much, so to reduce the communication cost computers that use ARP maintains a cache of recently acquired IP_to_MAC address bindings, i.e. 
they dont have to use ARP repeatedly. ARP Refinements Several refinements of ARP are possible: When machine A wants to send packets to macine B, it is possible that machine B is going to send packets to machine A in the near future.So to avoid ARP for machine B, A should put its IP_to_MAC address binding in the special packet while requesting for the MAC address of B. Since A broadcasts its initial request for the MAC address of B, every machine on the network should extract and store in its cache the IP_to_MAC address binding of A When a new machine appears on the network (e.g. when an operating system reboots) it can broadcast its IP_to_MAC address binding so that all other machines can store it in their caches. This will eliminate a lot of ARP packets by all other machines, when they want to communicate with this new machine.


Example displaying the use of Address Resolution Protocol:

Consider a scenario where a computer tries to contact some remote machine using ping program, assuming that there has been no exchange of IP datagrams previously between the two machines and therefore arp packet must be sent to identify the MAC address of the remote machine.
The arp request message (who is A.A.A.A tell B.B.B.B where the two are IP addresses) is broadcast on the local area network with an Ethernet protocol type 0x806. The packet is discarded by all the machines except the target machine which responds with an arp response message (A.A.A.A is hh:hh:hh:hh:hh:hh where hh:hh:hh:hh:hh:hh is the Ethernet source address). This packet is unicast to the machine with IP address B.B.B.B. Since the arp request message included the hardware address (Ethernet source address) of the requesting computer, target machine doesn't require another arp message to figure it out. 

![](https://www.cse.iitk.ac.in/users/dheeraj/cs425/lec13.html)



## Cdir subnetting submask  questions? 
 An organization requires a range of IP addresses to assign one to each of its 1500 computers. The organization has approached an Internet Service Provider (ISP) for this task. The ISP uses CIDR and serves the requests from the available IP address space 202.61.0.0/17. The ISP wants to assign an address space to the organization which will minimize the number of routing entries in the ISP’s router using route aggregation. Which of the following address spaces are potential candidates from which the ISP can allot any one to the organization?
I. 202.61.84.0/21
II. 202.61.104.0/21
III. 202.61.64.0/21
IV. 202.61.144.0/21


### Tcp connection

- Tcp is connection-oriented. A connection-oriented transpot protocol establishes  a virtual path  between  source and destination. All the segments belonging to message are sent over this virtual path. We may wonder how Tcp uses IP services which is connection oreinted, since it controls over all connection in Tcp through virual path 

#### In TCP, connection-oriented transmission requires three phases: connection estab-
lishment, data transfer, and connection termination.

Tcp connection Establisment

### Data Link layer 
- Frame 
The data link layer, on the other hand, needs to pack bits into frames, so that each
frame is distinguishable from another. Our postal system practices a type of framing.
The simple act of inserting a letter into an envelope separates one piece of information
from another; the envelope serves as the delimiter. In addition, each envelope defines
the sender and receiver addresses since the postal system is a many-to-many carrier
facility.

####  Bit oriented protcol  
In this protocol 8 bit of code is added as delimiter for the next frame so                                                                                                                                                                                                                                                                                                                                                                                                                                                      ### Flow control 
it is data link layer is based on automatic repeat request, which is the retransmission of the data.      

Protocols 
  
   1) Noiseless- simple and stop and wait 
   2) noisy channel - stop and wait ARQ,Go-back-N arq and selective repeat arq;

   n a real-life network, the data link protocols are implemented as bidirectional;
data flow in both directions. In these protocols the flow and error control information such
as ACKs and NAKs is included in the data frames in a technique called piggybacking.



  Node1                 Node2 
   | get data             | deliver data to the network 
     make frame           | extract data
   |  send frame          |receive frame 
   |______________________| 

sender side                                               

         while(true){ 
          WaitForEvent();                                  
          if(Event has request){                              
              getData();
              makeFrame();
              sendFrame();
          }

                         
         } 

    reciever side 


    while(true){
        WaitforEvent();
        if(Event_notification()){
            getFrame();
            extractData();
            sendData();
        }
    }

    stop and  wait 

    sender's 

    while(true){
        waitforevent();
        if(request from network and can sendframe){
            getData();
            makeframe();
            sendframe();
            sendframe=0;
        }

        waitforevent();
        if(Event(arrival_notification)){
            Receiveframe();
            sendframe=1;
        }
    }
  reciever side;
     while(true){
        waitforevent();
        if(request from network and can sendframe){
    
            recieveframe();
            extractdata();
            sendframe();
        }


       Noiseless chanel 

       sender side;
       cansend =1;
       n=0;
        while(true){
        waitforevent();
        cansend=1;
        if(Event(Request) and cansend)
                getData();
                makeFrame(sn);
                storeFrame(sn);
                startTimer();
                sn=sn+1;
                cansend=0;
                }
            Waitforevent();
            if(Event(notificationArrival)){
                RecieveFrame(ackno);
                if(acknotcorrupted){
                    stopTimer();
                    purgeFrame(sn);
                    cansen=1;
                }
                
                if (Event (TimeOUt)
II The timer expired
{
StartTimer();
ResendFrame(Sn_l);
//Resend a copy check
}

n=0;
  while(true){
      waitforevent();
      if(Event(frameA)){
          if(corruptedframe){
              sleep();
              if(sequence=rn){}
          }
          ExtractData();
          rn =rn+1;
      }
  }

  Go back -N ARQ

   major differnce between go-back n and stop and wait arq is pipeling 


  sender side 's 
    
    n=0;
     
     waitForEvent();

     if(Event(Arrivalnotification)){
         
     }

- Efficency of transmission 
  Total cycle time = Tt(data) + Tp(data) + 
                    Tt(acknowledgement) + Tp(acknowledgement)
              =  Tt(data) + Tp(data) + Tp(acknowledgement)
         =   Tt + 2*Tp


## capcity pipeling 

    Capacity = Bandwidth(B) * Propagation(Tp)
        
 For Full Duplex channels, 
 Capacity = 2*Bandwidth(B) * Propagation(Tp)

 ## capacity pipeling  
 - T1 units ------  sends 1 packets
  - 1 units ----- sends 1/T1;
  - T1+2*Tp ----sends (T1+2*Tp)/T1;
    maximun packets can be send is 1+2a;
    