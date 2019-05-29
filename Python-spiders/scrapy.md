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

scrapy 配置详解
```python
# 1. 爬虫名称，不是spider,name里的名称，而是整个爬虫项目的名称，
# 很多网站都会有自己的爬虫(百度，谷歌等都有)。
BOT_NAME = 'scrapy_learn'

# 2. 爬虫应用路径
SPIDER_MODULES = ['scrapy_learn.spiders']
NEWSPIDER_MODULE = 'scrapy_learn.spiders'

# 3. 客户端 user-agent请求头，常伪造成浏览器
USER_AGENT = 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/64.0.3282.167 Safari/537.36'

# 4. 是否遵循爬虫规则，正经的要遵循，但我们搞爬虫都不正经
ROBOTSTXT_OBEY = False

# 5. 并发请求数，默认16
CONCURRENT_REQUESTS = 32

# 6. 延迟下载秒数，默认0
DOWNLOAD_DELAY = 3

# 7. 单域名访问并发数，并且延迟下次秒数也应用在每个域名，比CONCURRENT_REQUESTS更加细致的并发
CONCURRENT_REQUESTS_PER_DOMAIN = 16

# 单IP访问并发数，如果有值则忽略：CONCURRENT_REQUESTS_PER_DOMAIN，
# 并且延迟下次秒数也应用在每个IP
CONCURRENT_REQUESTS_PER_IP = 16

# 8. 是否支持cookie，cookiejar进行操作cookie，默认支持
COOKIES_ENABLED = True
# 是否是调试模式，调试模式下每次得到cookie都会打印
COOKIES_DEBUG = True

# 9. Telnet用于查看当前爬虫的信息(爬了多少，还剩多少等)，操作爬虫(暂停等)等...，
# cmd中:telnet 127.0.0.1 6023(6023是专门给爬虫用的端口)
# telnet 命令
# est() 检查引擎状态
# engine.pass 暂停引擎， 还有很多命令，在网上可搜
TELNETCONSOLE_ENABLED = True

# 10. 默认请求头
#DEFAULT_REQUEST_HEADERS = {
#   'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
#   'Accept-Language': 'en',
#}

# 中间件，需要详细讲，另写
# Enable or disable spider middlewares
# See https://doc.scrapy.org/en/latest/topics/spider-middleware.html
#SPIDER_MIDDLEWARES = {
#    'scrapy_learn.middlewares.ScrapyLearnSpiderMiddleware': 543,
#}
# Enable or disable downloader middlewares
# See https://doc.scrapy.org/en/latest/topics/downloader-middleware.html
#DOWNLOADER_MIDDLEWARES = {
#    'scrapy_learn.middlewares.ScrapyLearnDownloaderMiddleware': 543,
#}

# 11. 定义pipeline处理请求
# See https://doc.scrapy.org/en/latest/topics/item-pipeline.html
ITEM_PIPELINES = {
   'scrapy_learn.pipelines.ScrapyLearnPipeline': 300,
}

# 12. 自定义扩展，基于信号进行调用
# See https://doc.scrapy.org/en/latest/topics/extensions.html
EXTENSIONS = {
   # 'scrapy.extensions.telnet.TelnetConsole': None,
}

# 自动限速算法(智能请求)
# See https://doc.scrapy.org/en/latest/topics/autothrottle.html
AUTOTHROTTLE_ENABLED = True
# 第一次下载延迟几秒
AUTOTHROTTLE_START_DELAY = 5
# 最大延迟
AUTOTHROTTLE_MAX_DELAY = 60
# 波动范围，不用管
#AUTOTHROTTLE_TARGET_CONCURRENCY = 1.0
# Enable showing throttling stats for every response received:
#AUTOTHROTTLE_DEBUG = False

# 做缓存的，以后说
# See https://doc.scrapy.org/en/latest/topics/downloader-middleware.html#httpcache-middleware-settings
#HTTPCACHE_ENABLED = True
#HTTPCACHE_EXPIRATION_SECS = 0
#HTTPCACHE_DIR = 'httpcache'
#HTTPCACHE_IGNORE_HTTP_CODES = []
#HTTPCACHE_STORAGE = 'scrapy.extensions.httpcache.FilesystemCacheStorage'

# 13. 爬虫允许的最大深度，可以通过meta查看当前深度；0表示无深度
DEPTH_LIMIT = 4

# DEPTH_PRIORITY只能设置为0或1，
# 0深度优先，一下找到底，然后再找其他的
# 1广度优先，一层一层找
# 他们内部的原理就是根据response.meta里的depth(层数)来找。
# DEPTH_PRIORITY = 0
```