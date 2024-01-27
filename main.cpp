#include "Server/server.hpp"


int main()
{
    Server myserver(8080);
    myserver.acceptConnection();
    myserver.startChat();
    return 0;
}
