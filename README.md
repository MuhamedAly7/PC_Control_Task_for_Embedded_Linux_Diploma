# PC_Control_Task_for_Embedded_Linux_Diploma
The project leverages a server-client architecture, where the C++ server listens for incoming connections and executes commands received from the mobile client. This enables me to perform various actions remotely, enhancing the flexibility and accessibility of my PC.

## Getting Started

### Prerequisites

- C++ compiler
- Make

### Installation

1. **Clone the repository:**
   
    ```bash
    git clone [repository_url]
    ```

2. **Navigate to the project directory:**
   
    ```bash
    cd Mobile-PC-Control-Project
    ```

3. **Build the project using the Makefile:**
   
    ```bash
    make
    ```

### Usage

Run the project with:

```bash
make run
```
This will start the server and listen for incoming connections. Connect your mobile device to control your PC remotely.

## Cleaning Up

To clean the compiled binaries and objects, use:

```bash
make clean
```
## Features    
- Open applications: YouTube, Calculator, Google, Terminal, LinkedIn, VSCode.
- Control system functions: power off, sleep, take screenshots.

