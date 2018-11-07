# scrapy框架学习
scrapy是一个基于Twisted的异步处理框架。使用python实现的爬虫框架。模块之间耦合度低，可扩展性强。
## 安装
```
pip install scrapy
```
或者
```
conda install scrapy
```
## 创建项目
在相应目录下打开cmd，通过命令创建项目
```
scrapy startproject douban
```
这个时候项目已经创建成功了，用pycharm打开，项目文件应是如此。

![qqq](http://ww1.sinaimg.cn/large/006BhB5Oly1fwr80f87r3j30bf05cjrd.jpg)

## [Spider -- 编写爬虫](https://scrapy-chs.readthedocs.io/zh_CN/1.0/topics/spiders.html)
在项目目录下打开命令行输入

或者直接在pycharm的终端（Terminal）里面直接输入。
```
scrapy genspider douban_spider www.douban.com
```
其中`scrapy genspider`是命令关键字。
`douban_spider`是创建的爬虫文件名。
`www.douban.com`会解析成创建的允许的爬虫域名和入口url放在列表中。

然后在spider文件夹下就会多一个`douban_spider.py`的文件，就可以在这里面编写爬虫类。

爬虫类继承自`scrapy.Spider`类。

父类中常用的几个属性如下：
* name

    这是爬虫的‘名字’，不能重复。调用爬虫时会用到这个属性。

* allowed_domains

    允许的域名。是一个列表。只有在这些域名下的地址才能进行爬取。

* start_urls

    起始的入口urls。如果没有实现`start_requests()`方法，就会默认从这个方法中找到起始的爬去站点。

* crawler
    
    通过`from_crawler()`设置的，代表的是本spider类对应的Crawler**对象**。

    这个对象包含很多项目的组件，利用它可以获取项目的一些配置信息，如最常见的获取项目设置信息，即settings
* settings

    就是项目中的配置信息.

这个父类中常用的几个方法如下：
* parse(self, response)

    当没有制定Response的回调时，这是默认的回调方法。负责处理`response`对象，并从中提取想要的数据或者返回下一步的请求。所以这个方法必须`yield`一个请求或者`Item`。
* start_requsts(self)

    返回第一次的请求，直接重写这个方法。

    就相当于自己实现了一下请求`start_urls`。用`scrapy.Request()`来发送GET请求。用`scrapy.FromRequest()`来发送POST请求。

* closed()

    当Spider关闭的时候，该方法会被调用，一般是用来释放一些资源等。

## [Item Pipline](https://scrapy-chs.readthedocs.io/zh_CN/1.0/topics/item-pipeline.html)
item pipline是项目的管道。在这个管道中，主要用来对数据进行一些处理或者说存到数据库中等操作。

在Spider中产生的`Item`会传到item pipline，被Item Pipline会根据优先级顺次调用，完成一连串的处理过程。比如数据清洗，存储等。

所以我们编写的Item Pipline主要分一下几种：
* 清理数据
* 验证爬去数据，检查爬取字段
* 查重并丢弃重复内容
* 将爬去结果保存到数据库

在自己定义的Item Pipline中需要实现的方法主要需要实现以下几个方法：
* process_item(self, item, spider) **必须实现的**

    处理item的方法。item是spider里传过来的item，spider是正在运行的spider实例。

    这个方法能两种返回值，**成功的时候返回的普通的处理后的item。如果是失败的话抛出DropItem异常**。

* open_spider(self, spider) 和 close_spider(self, spider)

    分别在Spider开始时和结束时调用。可以做一些开启和关闭数据库的连接等操作。
* from_crawler(cls, crawler)

    这个方法是个类方法，重写的时候需要用`@classmethod`表示，其中`crawler`就是上面介绍Spider时提到的那个`crawler`。可以通过它拿到Scrapy组件的一些配置信息。

    这个方法最后需要返回一个Class实例。

下面的代码就是创造一个将数据存储到数据库的Item Pipline
```python
import pymongo

class MongoPipeline(object):

    collection_name = 'scrapy_items'

    def __init__(self, mongo_uri, mongo_db):
        self.mongo_uri = mongo_uri
        self.mongo_db = mongo_db

    @classmethod
    def from_crawler(cls, crawler):
        return cls(
            mongo_uri=crawler.settings.get('MONGO_URI'),
            mongo_db=crawler.settings.get('MONGO_DATABASE', 'items')
        )

    def open_spider(self, spider):
        self.client = pymongo.MongoClient(self.mongo_uri)
        self.db = self.client[self.mongo_db]

    def close_spider(self, spider):
        self.client.close()

    def process_item(self, item, spider):
        self.db[self.collection_name].insert(dict(item))
        return item
```
在`settings.py`中有如下的配置信息。

在这里需要将你的pipline名称填上去，后面的数来控制优先级，数字越小，优先级越高。优先级的范围是0~1000。

```
# Configure item pipelines
# See https://doc.scrapy.org/en/latest/topics/item-pipeline.html
ITEM_PIPELINES = {
   'douban.pipelines.MongoPipeline': 300,
}
```
