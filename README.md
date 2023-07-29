# IPC_Mechanism
IPC_Mechanism Repo

Unix Domain Socket Mechanism :(Socket communication between two processes running on the same machine)
    LINUX OS provide socket system calls
        Computer Layers :
            1. Application
            2. System call interface
            3. OS/Kernel
            4. Hardware layer
    Linux provide set of API called system call which  appliccation can invode to interact with the underlying OS
        e.g. malloc()
             free()
    Socket message types:
        1. Connection initiation request message :(CIR) 
            Used by the client process to establish a dedicated connection.
            Only after the connection has been established, then client send Service request message to server
        2. Service request message :(SRM)
            Client can send these msg to server once the connection is establsihed
            Through these messages, Client requests server to provoid a service.
    Socket state machine:
        1. When Server boots up : It creates a connection socket 
            also named as master socket file descriptor using socket()
            
        2. Master sockets creates client handles for Clients called as  data sockets
        3.  Once client handles are created, server carries out communtication using the client handle
        4. Server has to maintain the created client handles at server side
        5. accept() is the system call on server side to create client handles
        6. accept() return The client handles are known as FD, which is a positive numbers
        7. Cleint handles are known as Data Sockets
        8. Master/server socket FD called as Connection socket
    Code Walk for a Process A(Server):
        1. Remove the socket,if already exist
        2. Socket() : Cretae a new Sockte
        3. Specify the socket name
        4. bind()
        5.listen()
        6. accept()
        7. read() : read the recieved data
        8. write() : send back the result
        9. close the data socket
        10. close the connection socket
        11. remove the socket
        12. exit
        