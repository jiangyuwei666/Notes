# Socket网络编程
<这里应该有一个解释>
## 用TCP实现简单的客户端和服务端交互
首先先编写服务端
</br>服务端一般有五个步骤:
1. 创建socket对象，并绑定到本地IP与端口
    </br>本地的IP可以通过cmd查看输入```ipconfig/all```

    ![查看本地IP地址](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/%E6%9F%A5%E7%9C%8Bip%E5%9C%B0%E5%9D%80.png)

2. 设置监听
3. 进入循环，一直接受客户端的连接
4. 接受数据，并发送数据（这里开了新的线程调用方法）
5. 传输完了后，关闭socket
```python
import socket
import threading
import time
def dealClient(sock , addr):
    print( 'Accept new connection from %s:%s...' %addr )
    sock.send(b'hello,im server')#可以看出发送的时候都是用的字节串
    while True:
        data = sock.recv(1024)#接受TCP套字的数据，数据以字符串的形式返回，1024表示可以接受的最大的数据量字节数
        time.sleep(1)
        if not data or data.decode('utf-8') == 'exit' :
            break
        print('-->>%s!' %data.decode('utf-8'))#将字符串先进行解码得到我们看得懂的字符串
        sock.send(('loop_msg:%s!'%data.decode('utf-8')).encode('utf-8'))#发送的时候，把需要发送的内容先进行编码，得到字节串然后发送出去
    sock.close()#关闭socket
    print('Connection from %s:%s closed' % addr)

if __name__ == '__main__':
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)#创建一个socket，AF_INET是使用IPv4进行服务器之间的网络通信；SOCK_STREAM流式socket，用于TCP；这两个用来参数用来创建TCP socket
    s.bind(('10.0.117.140',9999))#socket 绑定本机的IP与端口
    #监听连接
    s.listen(5)#5是最大监听数量，至少为1
    print('waiting for connection...')
    while True:#这个循环表示一直在监听，不断的接受客户端的请求，只要有新的连接就会被捕捉到进行下一次循环（由上面知道，最多有5个）
        #接受一个新的连接
        sock , addr = s.accept()#返回一个新的socket对象以及ip地址(返回的应该是个元组，后面才能实现打印)
        t = threading.Thread(target=dealClient , args=(sock,addr))#开一个新的线程z执行dealClient方法，来处理TCP连接
        t.start()#线程开始工作
```
接着创建客户端:
1. 创建实例，连接地址
2. 连接后发送数据，接受数据
3. 传完了后，关闭socket
```python
import socket
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)#初始化Socket
s.connect(('10.0.117.140',9999))#连接的IP和端口
print('-->>'+s.recv(1024).decode('utf-8'))#输出服务端第一次发送过来的消息（hello,im server）
s.send(b'hello,im client')#第一次发送的消息
print('-->>'+s.recv(1024).decode('utf-8'))#输出服务端第二次发送过来的消息（loop_msg:）
s.send(b'exit')#发送exit，使服务端的dealClient方法里的循环终止
s.close()#关闭socket
```
这里应该先运行服务端的程序再运行客户端的程序
</br>服务端的运行结果
```
waiting for connection...
Accept new connection from **.0.***.***:61866...
-->>hello,im client!
Connection from **.0.***.***:61866 closed
```
IP就不放出来了
</br>客户端的运行结果
```
-->>hello,im server
-->>loop_msg:hello,im client!
```
交互的过程是:
1. 首先服务端创建好了socket对象，用```bind()```方法绑定本地IP和端口，然后设置最大的监听数量为5(就是允许5个客户端)，接着输出等待连接。然后等待客户端连接进来。
2. 客户端创建号socket对象 ，用```connect()```连接IP和端口
3. 服务端检查到有客户端连接进来了，执行了循环里的逻辑：开辟了一个新的线程来执行服务端里写好的```dealClient```方法
    1. 先输出了获取的连接的地址
    2. 发送了一则消息，可以看到是用的字节串
    2. 客户端接受消息，再编码打印出来 客户端发送消息(im client),服务端接受并输出，再发送消息(loop),客户端再接受并打印。最后发送exit。在用循环持续交互接受和发送消息，如果收到的信息是exit就结束交互。
    4. 在方法的最后关闭连接
4. 客户端关闭连接
5. 此时客户端已经执行完毕，但是服务端依旧在循环。
</br>可以在客户端里也添加循环实现实时交互,把客户端的```s.send(b'exit')```改成如下循环
```python
while(True):
    msg = input('客户端发送的信息：')
    if 'exit' == msg :
        s.send(b'exit')
        break
    s.send( msg.encode('utf-8') )
```
就可以持续的交互，并且想退出时就直接退出
</br>再重新运行客户端，又会连接上服务端。