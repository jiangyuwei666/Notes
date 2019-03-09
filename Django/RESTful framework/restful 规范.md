# restful 规范
1. 建议https协议
2. 域名
    https://www.xxx.com/api
    
    https://api.xxx.com/(跨域问题)
3. 版本
    
    https://www.xxx.com/api/v1
4. 路径使用名词

    https://www.xxx.com/api/v1/books
5. method
    * GET   取出资源。一项或多项
    * POST  新建资源
    * PUT   更新资源（修改后上传所有字段）
    * PATCH 更新资源（修改后上传修改字段）
    * DELETE    删除资源
6. 过滤，通过url传递参数进行过滤
    https://www.xxx.com/api/v1/books/?limit=10
7. 状态吗（状态码不够使用，使用code）
8. 错误处理
9. 返回结果
10. Hypermedia API (链向其他接口)