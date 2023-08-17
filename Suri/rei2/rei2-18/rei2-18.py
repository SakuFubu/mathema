import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

#それぞれのテキストファイルからデータを読み込む
data0 = np.genfromtxt("data0.txt")
data1 = np.genfromtxt("data1.txt")
data2 = np.genfromtxt("data2.txt")
data3 = np.genfromtxt("data3.txt")
data4 = np.genfromtxt("data4.txt")
data5 = np.genfromtxt("data5.txt")
data6 = np.genfromtxt("data6.txt")
data7 = np.genfromtxt("data7.txt")


#画像を出力するための領域を作成
fig = plt.figure()

#領域の中でプロットする場所を決める
ax = fig.add_subplot(1,1,1)

#領域の中でプロットする場所を決める
ax.plot(data0[:,0],data0[:,1],color=cm.hsv(1/8.0),label="t=0.000")
ax.plot(data1[:,0],data1[:,1],color=cm.hsv(2/8.0),label="t=0.001")
ax.plot(data2[:,0],data2[:,1],color=cm.hsv(3/8.0),label="t=0.002")
ax.plot(data3[:,0],data3[:,1],color=cm.hsv(4/8.0),label="t=0.004")
ax.plot(data4[:,0],data4[:,1],color=cm.hsv(5/8.0),label="t=0.008")
ax.plot(data5[:,0],data5[:,1],color=cm.hsv(6/8.0),label="t=0.016")
ax.plot(data6[:,0],data6[:,1],color=cm.hsv(7/8.0),label="t=0.032")
ax.plot(data7[:,0],data7[:,1],color=cm.hsv(8/8.0),label="t=0.064")


# x,y軸に補助目盛線を設定
ax.grid(which = "major", axis = "both", alpha = 0.8,linestyle = "--", linewidth = 1)

# x,y軸の目盛設定
ax.set_xlabel("x",weight="bold",size="xx-large")
ax.set_ylabel("y",weight="bold",size="xx-large")

ax.set_xticks(np.arange(0,1.2,0.25))
#凡例を追加
ax.legend()

#プロットしたグラフを画像形式に保存する
plt.savefig("rei2-18.png")

#プロットしたグラフを出力する
plt.show()