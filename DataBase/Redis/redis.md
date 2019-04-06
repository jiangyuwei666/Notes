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
|方法名|参数|功能|
| ------ | ------ | ------ |
|`set(name, value)`|name:key名；value:值名|对该键进行添加或者修改，成功返回`True`|
|`get(name)`|name:key名|通过键进行查找|
|`delete(name)`|name:key名|通过键名删除,删除成功返回`1`|
|`mget(keys, *args)`||通过多个键查找多个结果，返回一个列表|
|`keys(pattern)`|pattern:可以是一个正则表达式|返回符合匹配规则的所有结果，也是返回一个列表|
|`type(name)`|name:key名|返回一个字符串，表示类型（可以有`b'string'`和`b'list'`等）|
|`dbsize()`||返回库里有多少条数据|
|`move(name, db)`|name:键名;db:哪个数据库|将某一天移动到另外的数据库|
|`flushdb()`||删除某个库里的所有数据|
|`flushall()`||删除所有数据库（跑路专用）|
|`expire(name, tiem)`|name:键名;time:时间|超过了键的设定时间后就不能用了|
|``|||

### 值操作

#### 基本数据类型（字符串）
|方法名|参数|功能|
| ------ | ------ | ------ |
|`setnx(name, 1213123)`|||
|``|||
|``|||
|``|||
|``|||
|``|||
|``|||
|``|||
#### 列表
#### 集合（字典）
#### 有序集合


