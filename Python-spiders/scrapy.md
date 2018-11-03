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
```
scrapy genspider douban_spider www.douban.com
```
其中`scrapy genspider`是命令关键字。
`douban_spider`是创建的爬虫文件名。
`www.douban.com`会解析成创建的允许的爬虫域名和入口url放在列表中。

打开项目