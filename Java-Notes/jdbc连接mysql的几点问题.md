# 几个bug
### 配置SSL
报错如下
```
Sat Jun 30 15:44:07 CST 2018 WARN: Establishing SSL connection without server's identity verification is not recommended. According to MySQL 5.5.45+, 5.6.26+ and 5.7.6+ requirements SSL connection must be established by default if explicit option isn't set. For compliance with existing applications not using SSL the verifyServerCertificate property is set to 'false'. You need either to explicitly disable SSL by setting useSSL=false, or set useSSL=true and provide truststore for server certificate verification.
```
在连接用的Url后添加```useSSL=true```关键字就行了

比如
```java
public static final String url = "jdbc:mysql://localhost:3306/选修课管理系统?useSSL=true"
```
### 
报错如下
```
java.sql.SQLException: The server time zone value '�й���׼ʱ��' is unrecognized or represents more than one time zone. You must configure either the server or JDBC driver (via the serverTimezone configuration property) to use a more specifc time zone value if you want to utilize time zone support.
at com.mysql.cj.jdbc.exceptions.SQLError.createSQLException(SQLError.java:695)
```
添加关键字
```java
characterEncoding=UTF-8&server
```

见识了以上几个小问题后，最终的Url是这样的
```java
    public static final String url = "jdbc:mysql://localhost:3306/选修课管理系统?useSSL=true&useUnicode=true&characterEncoding=UTF-8&serverTimezone=UTC";
```