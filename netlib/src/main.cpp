#include "TcpSocket.h" //  /usr/local/include/Sockets
                       // /usr/local/lib
#include <iostream>
#include <Sockets/StdoutLog.h>
#include <Sockets/SocketHandler.h>
#include <Sockets/TcpSocket.h>
#include <stdio.h>

#include <UdpSocket.h>

class TestSocket : public TcpSocket
{
public:
	TestSocket(ISocketHandler& h) : TcpSocket(h) {
		SetLineProtocol();
	}
	void OnConnect() {
		printf("TestSocket connected, sending QUIT\n");
		Send( "quit\n" );
	}
	void OnConnectFailed() {
		printf("TestSocket::OnConnectFailed\n");
		SetCloseAndDelete();
	}
	void OnLine(const std::string& line) {
		printf("TestSocket: %s\n", line.c_str());
	}
	void OnDelete() {
		printf("TestSocket::OnDelete()\n");
	}
#ifdef ENABLE_RESOLVER
	void OnResolved(int id,ipaddr_t a,port_t port) {
		printf("TestSocket::OnResolved():  %d,  %08x:%d\n", id, a, port);
		TcpSocket::OnResolved(id,a,port);
	}
#endif
};

int main(int argc,char *argv[])
{
#if 1
	StdoutLog log;	
	SocketHandler h(&log);
	TcpSocket ts(h);
	h.Add(&ts);
	ts.Open("192.168.10.201", 8953);
	//h.open();
	//ts.
//ts.OnSocks4Connect();
//	
//	h.Select(0,0);
	bool bl =false;// = ts.Connecting();
	ts.SetConnected(true);
	std::cout << bl << std::endl;
	int i =1;
	std::string str;
	str = "aaaaaaaaaaaaaa";
	while( i > 0)
	{
		ts.Send(str, 0);
		i--;
	}


	while(1);
#else
	SocketHandler h;
	StdoutLog log;
	h.RegStdLog(&log);
	UdpSocket s(h);
	
	s.Open("192.168.10.201", 8952);
	s.SendTo("192.168.10.201", 8952, "Using SendTo with address to send");
	if (!s.Open("192.168.10.201", 8952))
	{
		printf("Exiting...\n");
		exit(-1);
	}
	for (int i = 0; i < argc; i++)
	{
		s.Send(argv[i]);
		printf("%s \n",argv[i]);
	}
#endif
	return 0;
}
