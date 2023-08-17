import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

#それぞれのテキストファイルからデータを読み込む
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
ax.plot(data1[:,0],data1[:,1],color=cm.hsv(1/7.0),label="t=0.001")
ax.plot(data2[:,0],data2[:,1],color=cm.hsv(2/7.0),label="t=0.002")
ax.plot(data3[:,0],data3[:,1],color=cm.hsv(3/7.0),label="t=0.004")
ax.plot(data4[:,0],data4[:,1],color=cm.hsv(4/7.0),label="t=0.008")
ax.plot(data5[:,0],data5[:,1],color=cm.hsv(5/7.0),label="t=0.16")
ax.plot(data6[:,0],data6[:,1],color=cm.hsv(6/7.0),label="t=0.032")
ax.plot(data7[:,0],data7[:,1],color=cm.hsv(7/7.0),label="t=0.064")

# x,y軸に補助目盛線を設定
ax.grid(which = "major", axis = "both", alpha = 0.8,linestyle = "--", linewidth = 1)

# x,y軸の目盛設定
ax.set_xlabel("x",weight="bold",size="xx-large")
ax.set_ylabel("y",weight="bold",size="xx-large")

#凡例を追加
ax.legend()

#プロットしたグラフを画像形式に保存する
plt.savefig("rei2-15.png")

#プロットしたグラフを出力する
plt.show()