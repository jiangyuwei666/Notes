# matplotlib
matplotlib是python的一个2D绘制库，可以在命令行使用
```
pip install matplotlib
```
anaconda里面自带的也有
## 绘制饼型
```python
import matplotlib.pyplot as plt         #以plt作为pyplot的别称导入
data = [100,500,300]                    #饼图中的数据  
fig = plt.figure(dpi=80)               # dpi(Dot Per Inch)即分辨率
plt.pie(data,                          # 每个饼块的实际数据，如果大于1，会进行归一化，计算percentage  
        explode=[0.0,0.0,0.1],               # 每个饼块离中心的距离  
        colors=['y','r','g'],               # 每个饼块的颜色,黄红绿  
        labels=['A part','B part','C part'], # 每个饼块的标签  
        labeldistance=1.2,                   # 每个饼块标签到中心的距离  
        autopct='%1.1f%%',                  # 百分比的显示格式  
        pctdistance=0.4,                     # 百分比到中心的距离  
        shadow=True,                         # 每个饼块是否显示阴影  
        startangle=0,                        # 默认从x轴正半轴逆时针起  
        radius=1                           # 饼块的半径  
        )  
plt.savefig(r'F:\\test\\test.png')          #保存图片
plt.show()  
```
效果如图

![matplotlib饼]()

这里有个小坑，就是保存图片必须放在前面，不然就会保存一张空白的图片
</br>原因是因为在```plt.show()```调用了之后，就已经创建了新的，可以类比流，你输出来后流里面就没有东西了。所以```plt.savefig()```要放在前面。
* savefig()
    </br>里面可以设置图片的大小分辨率
    ```python
    savefig(r'test.png' , dpi = 100)
    ```
* colors
    </br>颜色可选范围

    ![matplotlib饼颜色]()