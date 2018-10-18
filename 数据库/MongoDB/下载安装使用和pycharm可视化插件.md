# MongoDB上手
MongoDB是一个轻量的非关系数据库，存储内容有点像json。
## 下载
到[官网](https://www.mongodb.com/download-center#atlas)点击`Community Server`就能看到下载键，下载后安装就行。

这个版本自动帮你配置好文件和服务，别的都不用担心。
## pycharm可视化工具
mongo4idea是一个在pycharm上的可视化工具，很好用

在[mongo plugin](https://plugins.jetbrains.com/plugin/7141-mongo-plugin)的网站下载压缩包，导入pycharm就行。
## 使用
导入后先点开左边的mongoDB，然后再点绿色的那把改刀。选好bin目录下的mongo.exe，测试，应该没有问题。

最后再点加号，随便命名一个Label， 就能通过代码往里面加东西了。
## 连接
先通过`pip install pymongo`下载`pymongo`库。

然后通过代码连接
```python
import pymongo
client = pymongo.MongoClient(host="localhost", port=27017)

client = pymongo.MongoClient('mongodb://localhost:27017/')
```