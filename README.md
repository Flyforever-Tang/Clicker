# Clicker

**Automatic mouse Clicker**

----------

# 1.0
## Operation interface
![1](https://user-images.githubusercontent.com/54651776/158537437-265f7710-1258-4e02-9614-dcd1e2ce63fb.png)


## Instructions
- **x/y**(*InputText*)

Coordinates of the position you want to click, this is the **absolute coordinate** of your screen. For example, if the Screen resolution is **1920×1080**, then the coordinate of the top left corner is **(0,0)** and the lower right corner is **(1920,1080)**. 
> If you don't know the coordinate, you can just click on the window and drag the mouse to the target position to obtain the coordinate.
![1](https://user-images.githubusercontent.com/54651776/158537502-7ebe8141-be68-4218-9cc0-d2a4c5a491fe.gif)


- **Times**(*InputText*)

How many times you would like to click. If you enter any number **less than 0**, the program will keep clicking. 
> It you want to stop click anytime, just **move your mouse** so that the program can detect your moving and stop.

- **Interval**(*InputText*)

Interval(**unit: millisecond**) between each click.

- **Mode**(*ComboBox*)

You want to click whether **left** or **right**.

- **Start**(*Button*)

Start clicking.

----------

# 2.0

In version **2.0**, I changed the click behavior to be activated by **hotkeys** *F1*. You no longer need to measure the coordinates you want to click, and you can use this program when using other full screen programs more easily. </br>
At the same time, the program is packaged into a integrated exe file. I also provide a separate version of executable program and dll file in case you need it. (*./exe/exe\_ori*)</br>
This is a **Chinese version**, I hope it doesn't bring obstacles to your use.


## Operation interface
![2](https://user-images.githubusercontent.com/54651776/158537472-8790e442-410e-4fcd-a95f-a42698d79524.png)


## Instructions
- **次数**(*InputText*)

Same as **Times** of 1.0 version.

- **间隔**(*InputText*)

Same as **Interval** of 1.0 version.

- **模式**(*ComboBox*)

Same as **Mode** of 1.0 version. "左键" means "left" and "右键" means "right".

- **开始监听**(*Button*)

Start listening for hotkeys ***F1***. The program will start clicking in the current position of your mouse after you press ***F1***.

> Sometimes the keyboard hook may fail after long time waiting. If you find that the hotkey doesn't work, please click the **开始监听** button again. If it still doesn't work, try restarting the program.

- **停止监听**(*Button*)

Stop listening for hotkeys ***F1***.

# **Hope to be useful, and if you have any suggestions or problems, please leave a message. :)** #
