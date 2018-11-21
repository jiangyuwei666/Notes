# redis的使用
## 连接
* 直接连接
    ```python
    from redis import StrictRedis
    redis = StrictRedis(host='localhost', port=6379, db=1)
    # 有密码时
    # redis = StrictRedis(host='localhost', port=6379, db=1, password='asdasdhdhjdj')
    ```
* 通过`ConnectionPool`连接
    ```python
    from redis import StrictRedis, ConnectionPool
    pool = ConnectionPool(host='localhost', port=6379, db=1)
    redis = StrictRedis(connection_pool=pool)
    ```
    其实直接连接也是在内部构造了一个ConnectionPool
* 通过url连接

    url支持三种格式如下
    ```
    redis://[:password]@host:port/db
    rediss://[:password]@host:port/db
    unix://[:password]@/path/to/socket.sock?db=db
    ```
    其中password有就写，没有就省略

    然后没有密码时`@`也可以省略
    ```python
    from redis import StrictRedis, ConnectionPool
    url = 'redis://@localhost:6379/1'
    # 省略@
    # url = 'redis://localhost:6379/1'
    # 有密码时
    # url = 'redis://ajsdj@localhost:6379/1'
    pool = ConnectionPool.from_url(url)
    redis = StrictRedis(connection_pool=pool)
    ```
## 使用
[静觅博客](https://cuiqingcai.com/5587.html)
总结一下部分常用分为两大类（键操作和值操作）
### 键操作
就是对存入的`key`进行增删改查
* exists(name)

    判断键`name`是否存在。如：`redis.exists('name')`
* 
### 值操作
#### 基本数据类型（字符串）
#### 列表
#### 集合（字典）
#### 有序集合


