# -*- coding:utf-8 -*-
# -*- by prime -*-

from math import cos, sqrt, pi
import numpy as n_
import matplotlib.pylab as p_



def dct(x, y, v, u, n):
    def alpha(a):
        if a == 0:
            return sqrt(1.0 / n)
        else:
            return sqrt(2.0 / n)
    return alpha(u) * alpha(v) * cos(((2 * x + 1) * (u * pi)) / (2 * n)) * cos(((2 * y + 1) * (v * pi)) / (2 * n))


if __name__ == '__main__':
    print("Running DCT")
    n = 8  #8维方阵

    maxV = n
    maxU = n

    imageSet = []
    for u in range(0, maxU):
        for v in range(0, maxV):
            basisImg = n_.zeros((n, n)) #创建n维矩阵，用0填充。
            print(basisImg)
            for y in range(0, n):
                for x in range(0, n):
                    basisImg[y, x] = dct(x, y, v, u, n)
            imageSet.append(basisImg)


    # Instead of looping, we can choose one basis(u,v)
    # v = 0
    # u = 0
    # basisImg = n_.zeros((n,n))
    # for y in range(0, n):
    #     for x in range(0, n):
    #         basisImg[y,x] = dct(x, y, v, u, n)


    displayRows = maxV
    displayCols = maxU
    p_.figure("DCT")
    for i in range(0, len(imageSet)):
        p_.subplot(displayRows, displayCols, i + 1) #画64个图
        p_.axis('off') #关闭坐标尺
        p_.imshow(imageSet[i], cmap='nipy_spectral')


    '''
     subplot(nrows, ncols, plot_number)

    Where *nrows* and *ncols* are used to notionally split the figure
    into ``nrows * ncols`` sub-axes, and *plot_number* is used to identify
    the particular subplot that this function is to create within the notional
    grid. *plot_number* starts at 1, increments across rows first and has a
    maximum of ``nrows * ncols``.
    '''
    # p_.savefig('_dct_' + str(n) + 'x' + str(n) + '_' + str(maxU) + 'x' + str(maxV) + '.png')
    p_.show()


    print("Complete")

