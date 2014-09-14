#ifndef UDP_H
#define UDP_H

#include <cstring>
#include <windows.h>

struct UDP__WSA{
    UDP__WSA(){
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2,2), &wsaData);
    }
    ~UDP__WSA(){
        WSACleanup();
    }
}UDP__WSA__;

bool validIp(std::string ip){
    if(ip.size()<7||ip.size()>15) return false;
    ip+='.';
    for(int i=0; i<ip.size();){
        if(ip[i]=='.'){
            if(i==0) return false;
            int n = atoi(ip.substr(0,i).c_str());
            if(n<0||n>255) return false;
            ip.erase(0,i+1);
            i=0;
        }else ++i;
    }

    return true;
}

int UDPSend(std::string ip, unsigned short port, std::string msg){
    if(!validIp(ip)) return 1;
    int iResult;

    SOCKET SendSocket = INVALID_SOCKET;
    sockaddr_in RecvAddr;

    SendSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(SendSocket == INVALID_SOCKET){
        WSACleanup();
        return 3;
    }
    RecvAddr.sin_family = AF_INET;
    RecvAddr.sin_port = htons(port);
    RecvAddr.sin_addr.s_addr = inet_addr(ip.c_str());
    iResult = sendto(SendSocket, msg.c_str(), msg.size(), 0, (SOCKADDR *) &RecvAddr, sizeof (RecvAddr));
    if(iResult == SOCKET_ERROR){
        closesocket(SendSocket);
        WSACleanup();
        return 4;
    }

    iResult = closesocket(SendSocket);
    if(iResult == SOCKET_ERROR){
        return 5;
    }

    return 0;
}

std::string UDPRecv(int port, bool blocking=false, size_t maxSize=1024){
    std::string msg;
    if(maxSize==0){
        return msg;
    }

    SOCKET RecvSocket;
    sockaddr_in RecvAddr;
    sockaddr_in SenderAddr;

    int SenderAddrSize = sizeof(SenderAddr);

    char RecvBuf[maxSize];
    int BufLen = maxSize;

    RecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(RecvSocket == INVALID_SOCKET){
        return msg;
    }
    RecvAddr.sin_family = AF_INET;
    RecvAddr.sin_port = htons(port);
    RecvAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(RecvSocket, (SOCKADDR *) & RecvAddr, sizeof (RecvAddr)) != 0){
        return msg;
    }

    if(!blocking){
        DWORD nonBlocking = 1;
        if(ioctlsocket(RecvSocket,FIONBIO,&nonBlocking )!=0){
            return msg;
        }
    }

    if((BufLen=recvfrom(RecvSocket, RecvBuf, BufLen, 0, (SOCKADDR*)&SenderAddr, &SenderAddrSize))==SOCKET_ERROR){
        return msg;
    }

    closesocket(RecvSocket);

    msg = inet_ntoa(SenderAddr.sin_addr);
    msg+='-';
    for(int i=0; i<BufLen; i++)
        msg += RecvBuf[i];

    return msg;
}

std::string popIp(std::string& msg){
    std::string ip;
    if(msg.size()<8) return ip;
    int i=7;
    for(; i<=16 && i<msg.size(); i++)
        if(msg[i]=='-')
            break;
        else if(i==msg.size()-1) return ip;

    if(!validIp(msg.substr(0,i))) return ip;

    ip = msg.substr(0,i);
    msg.erase(0,i+1);
    return ip;
}

#endif // UDP_H
