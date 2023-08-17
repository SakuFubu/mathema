import numpy as np
import matplotlib.pyplot as plt

#それぞれのテキストファイルからデータを読み込む
data1 = np.genfromtxt("rei1-2suti.txt")
data2 = np.genfromtxt("rei1-2kaiseki.txt")

#画像を出力するための領域を作成
fig = plt.figure()

#領域の中でプロットする場所を決める
ax1 = fig.add_subplot(1,2,1)
ax2 = fig.add_subplot(1,2,2)

#数値解析の結果をプロットする
ax1.plot(data1[:,1], data1[:,3])
ax1.set_title("Suti")

#解析解の結果をプロットする
ax2.plot(data2[:,1], data2[:,3])
ax2.set_title("Kaiseki")

#プロットしたグラフを画像形式に保存する
plt.savefig("rei1-2.png")

#プロットしたグラフを出力する
plt.show()