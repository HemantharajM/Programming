/**
 *  This test program explains the usuage of the [TOM] communication Protocol
 *  This works as time publisher, continuously send data to the clients wherenver publisher has data
 */

//#include "./../include/Socket.h"
#include "./../include/Tom_Publisher.h"
#include <thread>
#include <chrono>

int main()
{
    std::string addr = "127.0.0.1";
    std::string port_no = "8082"; //Port no
    std::string topic_name = "time_server.com";
    Tom_Publisher publisher(addr,port_no,topic_name,2,2);

    publisher.run();

    std::string msg = "Hello ";

    int i = 0;
    while (i < 10)
    {
        publisher.push(msg + std::to_string(i) + "\n");
        publisher.pub();
        i++;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }

}