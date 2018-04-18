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