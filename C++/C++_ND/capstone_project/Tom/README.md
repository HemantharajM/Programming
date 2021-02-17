## __TOM__ [COMMUNICATION PROTOCOL]

This is basic communication protocol. It is portable because it is compatible with __BERKLEY SOCKET__ and __WINSOCK__. It is in developement stage.

#### __Build__ :
Inside Tom folder:
    mkdir build
    cd build
    cmake ../
    make

#### __Run__ :
    ./group_msg
    Program ask for user input
    Enter -> 127.0.0.1
    Enter -> 8081 [Depending up availability you will get this port] , Otherwise random port will be generated
    Enter -> group_msg.com [Kind of domain name, other subscriber can find it easily]

    Then: If you enter msg 
          It will be broadcast to all the connected clients.
          For client connection use => $Telnet 127.0.0.1 8081
          This client will connected and start to receive the broadcast msg.

#### __Additional Library__:
No extra Library needed, Library related for socket programming. Implement using __Berkley Socket__ and __Win Sock__. This is already avaible in the Linux system.

#### __Project Detail__ :
This Project is aimed to create communication protocol like ROS. It is in development stage.

Socket class, it is interface for socket programming.

Abstract Base class:  Socket.h -> Socket()                  addressinfo() hints
                                  ~Socket()                 ip_addr 
                                  set_socket()              port_number
                                  set_ip_port()             host_name
                                  create_socket()
                                  Tom_bind()
                                  store_socket_dns()
                                  Tom_close

Publisher is one high level of socket. Whenever it has data, it broadcast to all of its connected clients

Tom_publisher Inherit Socket Class: Tom_Publisher()        max_client_number
                                    ~Tom_Publisher()       clients_socket
                                    run()                  msg_queue_len
                                    push()                 msg_queue
                                    pub()
                                    Tom_listen()
                                    Tom_accept()
                                    close_clients_socket


Still Developing:Tom_Subscriper, Tom_Server, Tom_Client, Tom_Peer [Unwritten code]


#### _FILE and CLASS Structure__ :
* Inside /include :
    1.Socket.h  - Basic socket programming interface. Abstract class provide necessary function for using socket such as socket, bind, close.  
    2.Tom_Publisher.h - Inherite Socket class. Add extra features related to Publisher such as listen(), send(), set_ip_port(), msg_queue.

* Inside /src :
    1.Socket.cpp
    2.Tom_Publisher.cpp
    3.group_msg.cpp - Program explains the usability of the Tom_Publisher protocol. 

* dns.txt - Domain Name Server in txt file. Hold all the __Publisher__ information such as __Host Name__, __IP addr__, __Port No__ necessary for __Subscriber__[Not written] to know about Publisher detail to communicate.

* CMakeLists.txt - Build project details.

#### __Output Behaviour__ :

#### __Rubric Points__ :

* __Loops, Functions, I/O__:
    1.Contol Structure and Function -
        Implemented throughout all cpp file.

    2.Read or Write file - 
        In file Socket.cpp and Line no. 77 - store_socket_dns function.
    
    3.Accept Input from user - 
        In file group_msg.cpp and line no. [20 to 25] - from user input set ip_addr and socket port no.

* __Object Oriented Programming__:

    1.The project uses Object Oriented Programming techniques.
        File Socket.h and Tom_Publisher.h

    2.Classes use appropriate access specifiers for class members.
        File Socket.h and Tom_Publisher.h

    3.Class constructors utilize member initialization lists.
        Inside File Tom_Publisher.cpp Line No. 6 -> Initialize _addr and _port_no

    4.Classes abstract implementation details from their interfaces.
        File Socket.h and Tom_Publisher.h
        
    5.Classes encapsulate behavior.
        File Socket.h and Tom_Publisher.h -> both class have their respective data and method like 
                                             Socket.h -> hints, bind_address
                                             Tom_Publisher.h -> msg_queue, client_sockets

    6.Classes follow an appropriate inheritance hierarchy.
        File Tom_Publisher.h -> which is inherited from Abstract Socket Class

    7.Overloaded functions allow the same function to operate on different parameters.
        IN File Socket.h and Line No. [79 to 82] -> both Tom_close() and Tom_close(SOCKET)

    8.Derived class functions override virtual base class functions.
        In File Tom_Publisher.h and Line No. [45 to 49] -> both set_socket and set_ip_port override default Socket.h method to change IPV4 or IPv6 and IP_address and port_no.

    9.Templates generalize functions in the project.
	

* __Memory Management__:
    
    1.The project makes use of references in function declarations
        IN File Tom_Publisher.cpp and line no. 96 - getaddressinfo
    2.The project uses destructors appropriately.
        
    3.The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.

    4.The project follows the Rule of 5.

    5.The project uses move semantics to move data, instead of copying it, where possible.
        In file Tom_Publisher.cpp and line no. [94 and 95] - release the memory instead of copying it.
    6.The project uses smart pointers instead of raw pointers
        In file Tom_Publisher.h and line no. [74 and 75] - used unique ptr

* __Concurrency__:

    1.The project uses multithreading.
        Inside file Tom_Publisher.cpp  and Line No. 25 -> To run the Tom_Publisher behaviour as separate thread.

    2.A promise and future is used in the project.

    3.A mutex or lock is used in the project
        Inside file Tom_Publisher.cpp and Line No. 71, 113, 154 -> To protect console and _client_socket data which modified by Behaviour accept thread and read from main thread.

    4.A condition variable is used in the project.
