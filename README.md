# 推箱子
嘲风写于2018年大一上学期，参考了学长的推箱子项目

## 简介

该项目为2018年大一上学期学长课堂实战班内容，分别写了控制台版本和EGE版本，因为一些特殊原因，还写了EasyX版本（后面没有进行bug的修复、功能添加及优化）。

## 项目结构
***
* [tuixiangzi-control]()
* [tuixiangzi-EasyX]()
* [tuixiangzi-EGE]()
***
### tuixiangzi-control

该文件夹下存放着控制台版本推箱子
C语言的控制台游戏推箱子，创新点在于实现了连续撤回及地图编辑器的功能。

代码文件：

|文件名|说明|
|--|--|
|head.h|项目头文件，函数申明|
|main.cpp|程序入口main()函数所在文件|
|init.cpp|程序初始化init()函数所在文件|
|event.cpp|程序事件判定函数所在文件|
|update.cpp|程序数据更新，如文件读取等函数所在文件|
|render.cpp|程序渲染函数所在文件|


![初始界面](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/control/init.png)
![开始游戏界面](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/control/sence1.png)
![操作说明](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/control/caozuoshuoming.png)
![游戏界面](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/control/game.png)
![暂停界面](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/control/pause.png)
![自定义说明界面](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/control/custom.png)
![自定义界面](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/control/custommap.png)
![流程图](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/control/liuchengtu.png)

### tuixiangzi-EGE

该文件夹下存放着EGE版本推箱子

使用了EGE图形库的推箱子，相较于控制台版，增添了选关功能，同样具有连续撤回及地图编辑器的功能。

代码文件：

|文件名|说明|
|--|--|
|head.h|项目头文件，函数申明|
|main.cpp|程序入口main()函数所在文件|
|init.cpp|程序初始化init()函数所在文件|
|event.cpp|程序事件判定函数所在文件|
|update.cpp|程序数据更新，如文件读取等函数所在文件|
|render.cpp|程序渲染函数所在文件|

#### 初始界面

![初始界面](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/ege/init.png)

#### 开始游戏界面

![开始游戏界面](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/ege/sence1.png)

#### 操作说明

![操作说明](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/ege/caozuoshuoming.png)

#### 游戏界面

![游戏界面](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/ege/game.png)

#### 暂停界面

![暂停界面](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/ege/pause.png)

#### 过关界面

![过关界面](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/ege/pass.png)

#### 自定义界面

![自定义界面](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/ege/custom.png)

#### 流程图

![流程图](https://github.com/Sirichaofeng/tuixiangzi/blob/master/image/control/liuchengtu.png)

### tuixiangzi-EasyX

该文件夹下存放着~~残次品~~EasyX版本推箱子。
