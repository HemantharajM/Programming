/**
 * TOM alternated name for Communication[COM].
 * Here lies implementation for Server class.  
 */

#include "Socket.h"



class Tom_Server : protected Socket 
{
    public:
        //Override Socket configuration [Address Family, Type]
        void set_socket() override;

        //Override IP_address and Port No. 
        void set_ip_port() override;

        //Server Listen for any new connection at this port 
        void Tom_listen();

        //Server accept new connection and return socket for that connection.
        void Tom_accept();

        //Server send message over socket
       // void Tom_send() override;

        //Server receive message through socket
        void Tom_recv() override;

    private:
        int _connection_queue_len = 10;
        struct sockaddr_storage _client_address;
        socklen_t _client_len = sizeof(_client_address);
        char _address_buffer[100];
        SOCKET _socket_client;
};

