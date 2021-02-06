# simpleSocket
Sockets as easy as in python !

### Importing lib
If you want to init lib, you should put `simpleSocket.h` file within the same directory as C file.

Then, import it using `#include "simpleSocket.h"` !

### Creating new socket
You can create a new socket with `newSocket(ip, port)`.
Function will return socket, so full command is `socket = newSocket(ip,port)`
*note : ip is a string, and port is an integer*


### Sending data
Sending data protocol is `send(socket variable, data, lenght of data, 0)`
So sending hello world on a socket named `sock1`lead to type (I know, I didn't add the semicolon at the end of line) : `send(sock1,"Hello world",strlen("Hello world"),0)`


### Receiving data
For receiving data, you should enter `recv(socket variable, variable to write, lenght to read, 0)`
Lenght to read is the lenght of tcp buffer that will be read (it is never fully instant, so a buffer stores data, and we read this buffer).

So receiving 64 bits of data from a socket named `sock1`, and writing received data to a `textVariable` variable will lead to `recv(sock1,textVariable,64,0)` !


### Example
Here's an example of
```c
#include "simplesocket.h"
#include <stdio.h>

int main() {
  int sock1;
  char buffer[100] = "Hello world";
  char recvbuffer[100];
  sock1 = newSocket("52.20.16.20",30000);
  send(sock1,buffer,strlen(buffer),0);
  recv(sock1,recvbuffer,100,0);
  printf("received : %s\n",recvbuffer);
}
```
