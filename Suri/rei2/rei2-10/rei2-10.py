import numpy as np
import matplotlib.pyplot as plt

#それぞれのテキストファイルからデータを読み込む
data = np.genfromtxt("rei2-10.txt")

#画像を出力するための領域を作成
fig = plt.figure()

#領域の中でプロットする場所を決める
ax = fig.add_subplot(1,1,1)

#領域の中でプロットする場所を決める
ax.plot(data[:,0],data[:,1],color='blue',label="tank1")
ax.plot(data[:,0],data[:,2],color='red',label="tank2")

# x,y軸に補助目盛線を設定
ax.grid(which = "major", axis = "both", alpha = 0.8,linestyle = "--", linewidth = 1)

#凡例を追加
ax.legend()

#プロットしたグラフを画像形式に保存する
plt.savefig("rei2-10.png")

#プロットしたグラフを出力する
plt.show()