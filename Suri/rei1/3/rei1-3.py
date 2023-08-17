import numpy as np
import matplotlib.pyplot as plt

#それぞれのテキストファイルからデータを読み込む
data1 = np.genfromtxt("rei1-3.txt")

#画像を出力するための領域を作成
fig = plt.figure()

#領域の中でプロットする場所を決める
ax1 = fig.add_subplot(1,1,1)

#数値解析の結果をプロットする
ax1.plot(data1[:,1], data1[:,3])
ax1.set_title("Suti")

#プロットしたグラフを画像形式に保存する
plt.savefig("rei1-3.png")

#プロットしたグラフを出力する
plt.show()