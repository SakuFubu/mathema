import numpy as np
import matplotlib.pyplot as plt

#それぞれのテキストファイルからデータを読み込む
data = np.genfromtxt("rei2-12.txt")


#画像を出力するための領域を作成
fig = plt.figure()

#領域の中でプロットする場所を決める
ax = fig.add_subplot(1,1,1)

#領域の中でプロットする場所を決める
ax.plot(data[:,0],data[:,1],color='blue',label="tank1")
ax.plot(data[:,0],data[:,2],color='red',label="tank2")
ax.plot(data[:,0],data[:,3],color='green',label="tank3")
ax.plot(data[:,0],data[:,4],color='cyan',label="tank4")
ax.plot(data[:,0],data[:,5],color='pink',label="tank5")
ax.plot(data[:,0],data[:,6],color='gray',label="tank6")


# x,y軸に補助目盛線を設定
ax.grid(which = "major", axis = "both", alpha = 0.8,linestyle = "--", linewidth = 1)

# x,y軸の目盛設定

#凡例を追加
ax.legend()

#プロットしたグラフを画像形式に保存する
plt.savefig("rei2-12.png")

#プロットしたグラフを出力する
plt.show()