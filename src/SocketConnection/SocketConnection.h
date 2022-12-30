
#ifndef TARGIL1_SOCKETCONNECTION_H
#define TARGIL1_SOCKETCONNECTION_H
#include <netinet/in.h>
#include <string>
#include "../Extractors/SocketExtractor.h"
#define NUM_CONNECTIONS 5
class SocketConnection {
private:
    sockaddr_in sin;
    int sock;
    SocketExtractor socketExtractor = SocketExtractor(-1);
public:
    /**
     * constructor create a SocketConnection
     * @param portNum - number of port
     * @param ip - ip addres
     * @param domain - ip gen
     * @param type - tcp\ udp
     */
    SocketConnection(const int portNum, unsigned long ip = INADDR_ANY , int domain= AF_INET, int type = SOCK_STREAM);
    /**
     * constructor craete a SocketConnection from a given file descriptor and sockaddr_in
     * @param sockEssential pair of int- file descriptor and sockaddr_in variable
     */
    SocketConnection(std::pair<int, sockaddr_in> sockEssential);
    /**
     * bind a socket to it's port number
     * @return int negative number- unsuccessful bind
     */
    int bind();
    /**
     * listen to in coming request to socket connection
     * @return int negative number- unsuccessful listen
     */
    int listen();
    /**
     * accept new connection to client
     * @return pair of new sock file descriptor and sockaddr_in
     */
    std::pair<int, sockaddr_in> accept();
    /**
     * connect to a server with given ip and port number
     * @return int negative number- unsuccessful connection
     */
    int connect();
    /**
     * get incoming message from connected socket
     * @return string of the message
     */
    std::string receive();
    /**
     * send message to connected socket
     * @param message sting of the meddage to send
     * @return int negative number- unsuccessful send
     */
    int send(const std::string& message);
    /**
     * close connection and ussage of socket
     * @return int negative number- unsuccessful close
     */
    int close();

    bool receiveNotFail();

    int getSock();


};


#endif //TARGIL1_SOCKETCONNECTION_H
