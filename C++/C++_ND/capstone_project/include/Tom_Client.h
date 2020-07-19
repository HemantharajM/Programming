/**
 * TOM alternated name for Communication[COM].
 * Here lies implementation for Client class.  
 */
#include "Socket.h"


class Tom_Client : public Socket
{
    public:
        //Set Socket configuration [Address Family, Type]
        void set_socket() override;

        //Establish connection between client socket to server 
        void connect();
};
