# 检索
* 从Student表中选取Sname列
    ```sql
    SELECT Sname
    FROM Student
    ```
* 从Student表中选取Sname和Ssex两列
    ```sql
    SELECT
    Sname,Ssex
    FROM
    Student
    ```
* 从表中选取所有列

    ```sql
    SELECT
    *
    FROM
    Student
    ```
* 限制行数
    ```sql
    SELECT
    TOP 5 Sname
    FROM
    Student
    ```
    选取Sname列的前5行
    </br>**不同的DBMS有不同的语句**
* 可以选择表达式。
    </br>比如这个表里只有年龄age，没有出生那一年出生的。
    ```sql
    SELECT
    2018-age
    FROM 
    Student
    ```
    这样得到的就是出生年份。
* 去除重复关键字 DISTINCT
    ```sql
    SELECT DISTINCT 
    Sno
    FROM
    Student
    ```
    选取Student表中的学号，并去重。
    </br>没有的时候，默认为关键字ALL
* 通过WHERE关键字来限定范围