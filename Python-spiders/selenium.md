# selenium
selenium是一个功能自动化测试工具
使用selenium可以使代码就像人一样对浏览器的网页进行如点击，输入等想要的操作
## 一些使用
* ```webdriver.Chrome()```和```close()```

    这个方法返回一个```WebDriver```的对象，调用这个方法的时候系统会自动弹出一个谷歌浏览器的空白页，如下图。

    ![谷歌浏览器空白页]()

    使用这个方法之前先要导包
    ```python
    from selenium import webdriver
    import time

    browser = webdriver.Chrome()
    time.sleep(2)
    browser.close()
    ```
    这样就能先打开一个空白网页，2s过后就把它关闭了

    当然不止谷歌浏览器，比如还能通过
    ```python
    rowser = webdriver.Firefox()
    browser = webdriver.Edge()
    ```
    等打开火狐、IE浏览器或者是别的浏览器，前提是配置好相应的文件
* 登陆站点

    与```requests```一样，直接用```get```方法就行了
    ```python
    browser.get('http://www.baidu.com')
    ```
* 具体操作

    * 输入点击等

        操作的主要思路其实和网页内容的抓取一致，都是先找到某个控件的标签，再通过标签的某一些属性值定位到该控件，再初始化```WebElement```的对象就可以对该控件进行操作。
        代码如下：
        ```python
        from selenium import webdriver  
        from selenium.webdriver.common.keys import Keys
        browser.get('http://www.baidu.com')
        inp = browser.find_element_by_id('kw')
        inp.send_keys("python")
        print(type(inp))
        btn = browser.find_element_by_id('su')
        btn.click()
        time.sleep(2)
        inp.clear()
        inp.send_keys("selenium")
        time.sleep(2)
        inp.send_keys(Keys.ENTER)
        ```
        首先使用```get()```方法打开了百度的首页
        解释一下上述代码，上面通过```id```的属性值，用```browser.find_element_by_id()```找到了两个控件，分别是输入框和搜索键。然后相应的操作
        比如
        ```python
        inp.send_keys("python")
        inp.send_keys("selenium")
        ```
        再搜索框里输入
        ```python
        btn.click()
        inp.send_keys(Keys.ENTER)
        ```
        这两个分别是通过点击搜索键和按回车进行搜索

    * 前进和后退

        调用```foward()```和```back()```可以让浏览器向前或向后。

    * 动作连

        介绍静觅大佬教学的网页，并补充一点.
        涉及到动作链的操作，比如拖拽等，就要使用带webdriver的ActionChains,代码如下
        ```python
        from selenium import webdriver
        from selenium.webdriver import ActionChains
        import time

        browser = webdriver.Chrome()
        browser.get('http://www.runoob.com/try/try.php?filename=jqueryui-api-droppable')
        browser.switch_to.frame('iframeResult')
        drag = browser.find_element_by_class_name('ui-draggable')
        drop = browser.find_element_by_class_name('ui-droppable')
        actions = ActionChains(browser)
        actions.drag_and_drop(drag, drop)
        actions.perform()
        time.sleep(2)
        browser.close()
        ```
        解释一下代码，其他的没什么好说的，主要从```actions```开始
        首先是从该浏览器获取一个```ActionChains```的实例。
        调用```drag_and_drop()```方法，说我们要执行拖拽的动作链。最后调用```perform()```执行动作就行了。
        
        这里要特别强调一下```browser.switch_to.frame('iframeResult')```

        ![菜鸟教程]()

        从这里可以看到，所要使用的两个标签全部再一个```<iframe>```标签下。一般打开网页，定位节点时，都是在最顶层的父级frame里面，如果还有子frame的话，就没法直接定位。这个时候就要用```switch_to.frame()```切换到该节点所在的frame，里面的参数就时这一层标签的```id```。还有```switch_to.parent_frame()```切换到父frame。

    * 执行脚本

        除此之外，还支持执行脚本。selenium的api里没有的功能，全部都可以通过javascript语言执行。比如向下滑动界面到底部，或者弹出窗口
        ```python
        browser = webdriver.Chrome()
        browser.get('https://www.toutiao.com/')
        browser.execute_script('window.scrollTo(0, document.body.scrollHeight)')
        browser.execute_script('alert("你好,python")')
        time.sleep(2)
        browser.close()
        ```
    * 获取节点信息

    * 操作选项卡

        一个窗口可以同时由很多个选项卡放着不同的网页，也可以通过selenium来对其进行操作。
        ```python
        from selenium import webdriver
        import time

        browser = webdriver.Chrome()
        browser.get('http://www.baidu.com')
        browser.execute_script('window.open()')
        print(browser.window_handles)
        time.sleep(1)
        browser.switch_to.window(browser.window_handles[0])
        time.sleep(1)
        browser.switch_to.window(browser.window_handles[1])
        browser.get('http://www.baidu.com')
        browser.close()
        ```
        比如以上代码。
        首先我们通过执行JS的代码```window.open()```来打开新的标签页。然后browser对象有个属性是```window_handels```
        这个属性是个列表，里面放的就是相应的标签页，可以通过脚标来访问。比如用```switch_to.window()```来切换到指定的标签页。最后我们还可以发现，这个```close()```的是关闭当前标签页，并不是关闭浏览器。