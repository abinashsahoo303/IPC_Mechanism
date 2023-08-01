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
Signals: As a IPC mechanism
    Is a system message sent from one process to anaother.
    When a process recieve a Signal, Three things can happen
        1. Process execute the defailt action of the signal. e.g. When process recieves SIGTERN signal,process is terminated by default.
        2. Process do its customized processing on receiving the signal by executing the signal handle routine
        3. Process Ignore the signal
    Signal handler routine:
        A signal handler routine is a special function which is invoked when the process receives a signal.
        We need to register the routine against the type of signal.
        Signal handler routine are execited at teh highest priority, preempting the normal execution flow of the process.

    Types if Signal in Linux :
        30 signal are avialble in Linux.
        1. SIGINT - interrupt(i.e. Ctrl+C)
        2. SIGUSR1 and SIGUSR2 - User defined signals (Ftom process to another process)
        3. SIGKILL - Sent to process from kernel when Kill -9 invoked on PID. This signal cannot be caught by the process.
        4. SIGABRT - raised by abort() by the process itself.
        5. SIGTERM - raised when kill is invoked. Can be caught by the process to execute user defined action.
        6. SIGSEGV - Segmentation fault. Raised by the kernel to the process when illegal memory is referenced.
        8. SIGCHILD - When ever a child terminates, this signal is sent to the parent.
    Way of generating Signals in Linux:
        1. Raising a signal from OS to a process  e.g. Ctrl+c
        1. Sending a signal from Process A to itself using raise()
        3. Sending signal from Process A to Process B using kill()

Message_Queues:
    Enque and Deque
    Message queue idenntified by the ID(String )
    Message queue resides and managed by Kernel/OS

    API :
    Creation of msg queue
        mqd_t mq_open(const char *name, int oflag); -- 1
        mqd_t mq_open(const char *name, int oflag, mode_t mode, struct mq_attr * attr);
            name  : name of the message queue
            oflag : Operational falgs (e.g O_RDONLY, O_CREAT, O_RDWR)
            mode  : Permission set (Usually 0660)
            attr  : specify the max size to grow the queue and Hold data 
            mqd_t : file descriptor or Handle 

    Close of msg Queue
        int mq_close(mqd_t msgQ);

        Return value : (0- Success and -1- Failure)

    Send to msg queue/Enque
        int mq_send(mqd_t msgQ,char *msg_ptr,size_t msg_len,unsigned int msg_prio);

        Return value : (0- Success and -1- Failure)
    
    Recieve message from msg queue/Deque
        int mq_receive(mqd_t msgQ,char *msg_ptr,size_t msg_len,unsigned int msg_prio);

        Return value : (n_bytes of recieved msg- Success and -1- Failure)

    Destroying a message Queue
        int mq_unlink(const char *msgQ_name);

        Return value : (0- Success and -1- Failure)

        


