import numpy as np
import matplotlib.pyplot as plt

#それぞれのテキストファイルからデータを読み込む
data = np.genfromtxt("rei2-14.txt")


#画像を出力するための領域を作成
fig = plt.figure()

#領域の中でプロットする場所を決める
ax = fig.add_subplot(1,1,1)

#領域の中でプロットする場所を決める
ax.plot(data[0,:],data[1,:],color='blue',label="t=0.001")
ax.plot(data[0,:],data[2,:],color='red',label="t=0.002")
ax.plot(data[0,:],data[3,:],color='green',label="t=0.004")
ax.plot(data[0,:],data[4,:],color='cyan',label="t=0.008")
ax.plot(data[0,:],data[5,:],color='pink',label="t=0.16")
ax.plot(data[0,:],data[6,:],color='gray',label="t=0.032")
ax.plot(data[0,:],data[7,:],color='yellow',label="t=0.064")


# x,y軸に補助目盛線を設定
ax.grid(which = "major", axis = "both", alpha = 0.8,linestyle = "--", linewidth = 1)

# x,y軸の目盛設定
ax.set_xlabel("x",weight="bold",size="xx-large")
ax.set_ylabel("y",weight="bold",size="xx-large")

#凡例を追加
ax.legend()

#プロットしたグラフを画像形式に保存する
plt.savefig("rei2-14.png")

#プロットしたグラフを出力する
plt.show()