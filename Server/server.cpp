#include"server.hpp"
#include <cstdlib>


Server::Server(int port){
    //Createasocket
    serverSocket=socket(AF_INET, SOCK_STREAM,0);
    if(serverSocket == -1){
        std::cerr << "Error creating socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    //BindthesockettoaspecificIPandport
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port); //Portnumber

    if(bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1){
        std::cerr << "Error binding socket" << std::endl;
        close(serverSocket);
        exit(EXIT_FAILURE);
    }

    //Listenforincomingconnections
    if(listen(serverSocket, 10) == -1){
        std::cerr << "Error listening for connections" << std::endl;
        close(serverSocket);
        exit(EXIT_FAILURE);
    }

    std::cout << "Server listening on port " << port << "..." << std::endl;
}

Server::~Server(){
    //Closethesockets
    close(clientSocket);
    close(serverSocket);
}

void Server::acceptConnection(){
    //Acceptincomingconnections
    clientAddressLen = sizeof(clientAddress);
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);
    if(clientSocket == -1){
        std::cerr << "Error accepting connection" << std::endl;
        close(serverSocket);
        exit(EXIT_FAILURE);
    }

    std::cout << "Connection accepted from " << inet_ntoa(clientAddress.sin_addr) << ": " << ntohs(clientAddress.sin_port) << std::endl;
}

void Server::startChat(){
    char buffer[1024];

    while(true) {
        // Receivemessagefromtheclient
        memset(buffer, 0, sizeof(buffer));
        if(recv(clientSocket, buffer, sizeof(buffer), 0) <= 0){
            std::cerr << "Connection closed by client" << std::endl;
            break;
        }   

        //std::cout << "Client:" << buffer<< std::endl;

        //Sendmessagetotheclient
        //std::cout << "Server:";
        //std::cin.getline(buffer, sizeof(buffer));
        //send(clientSocket, buffer, strlen(buffer), 0);
        
        if(strcmp("open youtube", buffer) == 0)
        {
            send(clientSocket, "done!", strlen(buffer), 0);
            int status = std::system(Server::open_youtube_command);
        }
        else if(strcmp("open calculator", buffer) == 0)
        {
            send(clientSocket, "done!", strlen(buffer), 0);
            int status = std::system(Server::open_calculator);
        }
        else if (strcmp("open google", buffer) == 0)
        {
            send(clientSocket, "done!", strlen(buffer), 0);
            int status = std::system(Server::open_google);
        }
        else if(strcmp("open terminal", buffer) == 0)
        {
            send(clientSocket, "done!", strlen(buffer), 0);
            int status = std::system(Server::open_terminal);
        }
        else if(strcmp("open linkedin", buffer) == 0)
        {
            send(clientSocket, "done!", strlen(buffer), 0);
            int status = std::system(Server::open_linkedin);
        }
        else if(strcmp("go home", buffer) == 0)
        {
            send(clientSocket, "done!", strlen(buffer), 0);
            int status = std::system(Server::go_home);
        }
        else if (strcmp("power off", buffer) == 0)
        {
            send(clientSocket, "done!", strlen(buffer), 0);
            int status = std::system(Server::power_off);
        }
        else if (strcmp("sleep", buffer) == 0)
        {
            send(clientSocket, "done!", strlen(buffer), 0);
            int status = std::system(Server::sleep);
        }
        else if (strcmp("screenshot", buffer) == 0)
        {
            send(clientSocket, "done!", strlen(buffer), 0);
            int status = std::system(Server::screenshot);
        }
        else if (strcmp("open vscode", buffer) == 0)
        {
            send(clientSocket, "done!", strlen(buffer), 0);
            int status = std::system(Server::open_vscode);
        }
    }
}

