import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
from matplotlib.colors import Normalize

t_list = [0,0.5,1,2,4,8]

# dataの個数分ループを回す
for num in range(6):
    filename = "data%d.txt"%(num)
    data = np.genfromtxt(filename)
    
# 配列の形を整形（一次行列 → 二次行列）
    a = data.reshape(40,40)

# 画像を出力するための領域を作成
    fig = plt.figure()

# 領域の中でプロットする場所を決める
    plt.pcolormesh(a, linewidth=0.1,edgecolors='gray',norm=Normalize(vmin=0, vmax=10))

# グリッドした時のx軸とy軸でできる四角形の整形
    ax = plt.gca()
    ax.set_aspect('equal')      # 正方形
    ax.minorticks_on()          # 副目盛の追加

# タイトル
    plt.title("data%d, t = %f"%(num,t_list[num]),fontweight='bold')
    
# ラベルの名前の強調
    plt.xlabel('X', fontsize=24)
    plt.ylabel('Y', fontsize=24)

# カラーバー作成
    plt.colorbar ()

# プロットしたグラフを画像形式に保存する
    outputfilename = "rei3-19_%d.png"%(num)
    plt.savefig(outputfilename)

# プロット
    plt.show()

