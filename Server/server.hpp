#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>


class Server {
private:
    int serverSocket;
    int clientSocket;

    sockaddr_in serverAddress;
    sockaddr_in clientAddress;
    socklen_t clientAddressLen;
    
    // executed commands
    const char *open_youtube_command = "gnome-terminal -- /usr/bin/firefox https://www.youtube.com; exit";
    const char *open_calculator = "/usr/bin/gnome-calculator";
    const char *open_google = "gnome-terminal -- /usr/bin/firefox https://www.google.com; exit";
    const char *open_terminal = "/bin/terminator";
    const char *open_linkedin = "gnome-terminal -- /usr/bin/firefox https://www.linkedin.com; exit";
    const char *power_off = "gnome-terminal -- systemctl poweroff";
    const char *go_home = "gnome-terminal -- nautilus /home/; exit";
    const char *sleep = "gnome-terminal -- systemctl suspend";
    const char *screenshot = "gnome-screenshot";
    const char *open_vscode = "code ~/Documents/";

public:
    Server(int port);
    ~Server();
    void acceptConnection();
    void startChat();
};
