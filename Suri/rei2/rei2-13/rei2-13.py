import numpy as np
import matplotlib.pyplot as plt
import math

#それぞれのテキストファイルからデータを読み込む
data = np.genfromtxt("rei2-13.txt")


#画像を出力するための領域を作成
fig = plt.figure()

#領域の中でプロットする場所を決める
ax = fig.add_subplot(1,1,1)

#領域の中でプロットする場所を決める
ax.plot(data[:,0],data[:,1],color='blue',label="Condenser1")
ax.plot(data[:,0],data[:,6],color='red',label="Condenser6")


# x,y軸に補助目盛線を設定
ax.grid(which = "major", axis = "both", alpha = 0.8,linestyle = "--", linewidth = 1)

# x,y軸の目盛設定
ax.set_xticks(np.arange(0,8*math.pi,math.pi))
ax.set_yticks(np.arange(0,10,1))

#凡例を追加
ax.legend()

#プロットしたグラフを画像形式に保存する
plt.savefig("rei2-13.png")

#プロットしたグラフを出力する
plt.show()