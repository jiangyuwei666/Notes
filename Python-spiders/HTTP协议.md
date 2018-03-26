# HTTP
HTTP,HyperText Transfer Protocol,超文本传输协议
1. HTTP是一个基于“请求与响应”模式的,无状态的应用层协议
    * “请求与响应“模式：
    </br>用户发送请求，服务器做出响应
    * 无状态：
    </br>第一次请求和第二次请求并没有什么关联
    * 应用层协议：
    </br>该协议工作在**TCP协议**之上
2. HTTP采用URL作为定位网络资源的标识符
    </br>URL就是一个将资源存在网上的路径，一个URL对应一个数据资源(类比电脑上一个文件的路径，只是把我的电脑换成了Internet)
    </br>URL的格式如下:
    ```html
    http://host[:port][path]
    ```
    * host 合法的Internet主机域名或者IP地址
    * port 端口号，不用管它，默认为80
    * path 请求资源的路径
3. HTTP对资源的操作

    ![HTTP对资源的操作](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/HTTP%E5%8D%8F%E8%AE%AE%E5%AF%B9%E8%B5%84%E6%BA%90%E7%9A%84%E6%93%8D%E4%BD%9C.jpg)

    * PATCH和PUT的区别就在于一个是局部更新，一个全部覆盖
        </br>比如有个User信息在URL上，里面有账号，姓名，电话，邮箱等等很多信息。

        </br>这个时候如果你需要修改一个电话号码，在发送请求的时候使用PATCH和PUT的区别就是一个是只传一个电话的值，而PUT是将改变值后的整个对象包括没有改变的也再传一次。(节省网络带宽)

        </br>如果你用PUT之传一个电话号码，没有把其他信息也提交上去的话，那么这个URL资源也就只剩下一个电话号码，其他信息就会被覆盖掉。
    * POST就是添加新的数据