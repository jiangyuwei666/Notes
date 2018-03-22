1.第三方库的requests模块的使用

requsts模块是python3引入的第三方库外援(很好用)

(1)requests.get()方法的使用，使用pip安装即可

首先我们要导入这个模块
```python
import requests
```
然后需要个网址
```python
url = "https://www.baidu.com/"
```
直接使用
```python
r = requests.get ( url )
```
然后我们试着输出一下结果
```python
print ( r )#这个输出  <Response [200]>
print ( type ( r ) )# <class 'requests.models.Response'>  他是这个类型
print ( r.text ) #这里打印的是网页源码
print ( type ( r.text ) ) #字符串类型
```
到这里大概了解了requests.get()方法的大概用法

(2)request.get()的第二个参数，params
```python
params = {} #这里的参数必须是一个字典
r = requests.get ( url , params )
```
这样就能把参数导进去，比如百度的界面，将参数进行设置，就能直接跳转到参数设定的搜索结果的界面
比如
```python
params = { 'key1': 'value1' , 'key2': 'value2' }
r = requests.get ( url , params )
print ( r.url ) #  一打印得到  https://www.baidu.com/?key2=value2&key1=value1
```
(3)requests还自带了一个json解析器，可以解析json数据
```python
r = requests.get ( url , params ).json()
```
这在解析动态异步加载的界面就很方便，使用
```pyhton
r = requests.get ( url , params ).json().get()
```
就可以直接查找需要获得的数据

(4)伪装浏览器

有的网站，具有反爬虫机制，会自动检测出你是不是爬虫，这个时候，就可以给自己的爬虫添加一个请求头headers将自己伪装成浏览器

headers有很多，在百度上一搜就有很多
```python
headers = {'user-agent': 'my-app/0.0.1'} #这只是其中一种
r = requests.get( url , headers = headers ) 
```
这样就可以了
</br>2.使用Xpath抓取你想要的东西

xpath其实就是通过路径找到你想要的东西，比如说你家住在胜利路牛逼小区a幢1单元1楼1号，通过这个我就能找到你，放在Xpath上，它就是通过选取XML文档的节点来一层一层的找到你想要的内容。

使用xpath时要用到 lxml包里的etree模块 直接用pip下载

直接用上面requests返回的结果
```python
s = etree.HTML( r.text )
```
(1)绝对路径和相对路径的区别

在了解Xpath语法之前，需要先弄清楚绝对路径和相对路径。

绝对路径，故名思意，绝对路径就是必须一层一层的严格按照结构来。比如我要找你的话，我必须要通过 a国b省c市d区e街f小区g单元h楼i号，一层也不能少。

但是如果全世界都只有一个小区叫牛逼小区，我们就不用前面的所有国，省，市，直接在牛逼小区中找g单元h楼i号。

放在电脑路径中，比如在D盘中有个test文件夹里又有a,b两个文件夹两个文件夹里都有c这个文件，a中还有d文件。

绝对路径D:\a\c这样找到a中的c文件 如果用相对路径找d D:\\d

这里就用双斜杠，这就是绝对路径和相对路径的区别

注意：相对路径可以获取所有满足条件的东西，譬如，这里我们使用 D:\\c 这个就可以得到两个c文件

(2)xpath的一些简单的语法

a.选取div节点中a中的所有元素(xpath返回的结果都是 列表 )
```python
list = s.xpath('//div//a/text()') #一般要加text()
```
b.选取div节点中属性class为abc的结果
```python
list = s.xpath('//div[@class="abc"]/text()')
```
c.选取div节点中，a节点的href属性的值
```python
list = s.xpath('//div//a/@href')
```
平时经常用到的就是这些了

**注意：当获取的是标签的属性时就不加/text()，在获取标签的内容时就要加上text()**

