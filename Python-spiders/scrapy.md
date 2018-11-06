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

## 编写爬虫
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

    

这个父类中常用的几个方法如下：
* parse(self, response)

    当没有制定Response的回调时，这是默认的回调方法。负责处理`response`对象，并从中提取想要的数据或者返回下一步的请求。所以这个方法必须`yield`一个请求或者`Item`。
* 