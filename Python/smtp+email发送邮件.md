# 使用smtp和email包发送邮件
网页是通过HTTP协议传输，而邮件就是通过SMTP(Simple Mail Transfer Protocol , 单邮件传输协议)
</br>并且与网络一样，网络服务器的客户端就是各种浏览器。而Email服务器的客户端是像Sendmail等应用。
</br>所以说本地有sendmail等客户端，代码中就不用使用别人的SMTP服务器。
代码如下
```python
import smtplib
from email.mime.text import MIMEText
from email.header import Header

mail_host = 'smtp.qq.com'#服务器名称
mail_user = '*******@qq.com'
mail_password = '******' #注意这里

sender = '*******@qq.com'
receiver = ['*******@qq.com']#收件人需要放在列表里面，所以可以同时给多人发送

message = MIMEText("用python发送邮件，tonyma",'plain','utf-8')
message['From'] = Header("daddy",'utf-8')#发件人
message['To'] = Header("son",'utf-8')#收件人(因为是qq邮箱有可能不会显示出来，而是显示名字)
message['Subject'] = Header("TONY MOM" , 'utf-8')#发送的标题

smtpObj = smtplib.SMTP()#创建实例
smtpObj.connect( mail_host , 25 )#链接服务器，端口号默认为25
smtpObj.login( mail_user , mail_password )#通过账号和授权码登陆
smtpObj.sendmail(sender,receiver,message.as_string())
print('发送成功')
smtpObj.quit()#退出登陆
```
```mail_password```不是自己的登陆密码，而是申请的授权码。
```as_string()```是Return the entire formatted message as a string，翻译过来就是返回整个格式化的message字符串。
* 授权码的申请
</br>在 设置->账户->开启服务->POP3/SMTP服务 花一毛钱发个短信申请就行了

![申请授权码]()