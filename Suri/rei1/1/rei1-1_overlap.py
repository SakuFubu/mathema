import numpy as np
import matplotlib.pyplot as plt

#それぞれのテキストファイルからデータを読み込む
data1 = np.genfromtxt("rei1-1suti.txt")
data2 = np.genfromtxt("rei1-1kaiseki.txt")

#画像を出力するための領域を作成
fig = plt.figure()

#領域の中でプロットする場所を決める
plt.plot(data1[:,1],data1[:,3],color='blue',label="Suti")
plt.plot(data2[:,1],data2[:,3],color='green',label="Kaiseki")

#凡例を追加
plt.legend()

#プロットしたグラフを画像形式に保存する
plt.savefig("rei1-1a.png")

#プロットしたグラフを出力する
plt.show()