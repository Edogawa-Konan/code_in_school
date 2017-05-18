# -*- coding:utf-8 -*-
# -*- by prime -*-

import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from HW1.client import client


class Ui(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(640, 480)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.textEdit = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit.setGeometry(QtCore.QRect(130, 50, 371, 51))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.textEdit.setFont(font)
        self.textEdit.setObjectName("textEdit")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(240, 10, 171, 41))
        font = QtGui.QFont()
        font.setFamily("楷体")
        font.setPointSize(18)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.textBrowser = QtWidgets.QTextBrowser(self.centralwidget)
        self.textBrowser.setGeometry(QtCore.QRect(20, 170, 261, 211))
        self.textBrowser.setObjectName("textBrowser")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(110, 130, 101, 31))
        self.label_2.setObjectName("label_2")
        self.textBrowser_2 = QtWidgets.QTextBrowser(self.centralwidget)
        self.textBrowser_2.setGeometry(QtCore.QRect(300, 170, 291, 211))
        self.textBrowser_2.setObjectName("textBrowser_2")

        self.textBrowser.setAcceptRichText(False)
        self.textBrowser_2.setAcceptRichText(True)

        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(400, 130, 111, 31))
        self.label_3.setObjectName("label_3")
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton.setGeometry(QtCore.QRect(240, 390, 93, 28))
        self.pushButton.setObjectName("pushButton")

        self.pushButton.clicked.connect(self.url)

        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(10, 60, 121, 41))
        self.label_4.setTextFormat(QtCore.Qt.RichText)
        self.label_4.setObjectName("label_4")
        self.verticalScrollBar = QtWidgets.QScrollBar(self.textBrowser) #以当前文本框作为父节点创建滚动条
        self.verticalScrollBar.setGeometry(QtCore.QRect(260, 170, 21, 211))
        self.verticalScrollBar.setOrientation(QtCore.Qt.Vertical)
        self.verticalScrollBar.setObjectName("verticalScrollBar")
        self.verticalScrollBar_2 = QtWidgets.QScrollBar(self.textBrowser_2)
        self.verticalScrollBar_2.setGeometry(QtCore.QRect(570, 170, 21, 211))
        self.verticalScrollBar_2.setOrientation(QtCore.Qt.Vertical)
        self.verticalScrollBar_2.setObjectName("verticalScrollBar_2")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 640, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.showMessage('粗糙的不行的浏览器,不忍直视')
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        MainWindow.setWindowTitle('14130110069 -马源')

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)


    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "请输入url"))
        self.label_2.setText(_translate("MainWindow", "头部"))
        self.label_3.setText(_translate("MainWindow", "内容"))
        self.pushButton.setText(_translate("MainWindow", "确认"))
        self.label_4.setText(_translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#5555ff;\">http://</span></p></body></html>"))


    def url(self):
        h,b=client(self.textEdit.toPlainText())
        url=self.textEdit.toPlainText()
        print(repr(url))
        # h,b=op(url)
        self.textBrowser.clear()
        self.textBrowser_2.clear()

        self.textBrowser.setText(h)
        self.textBrowser_2.setText('#'+b)
        # self.textBrowser_2.setHtml('<b>hrhrhr</b>')


if __name__ == '__main__':
    app=QtWidgets.QApplication(sys.argv)
    my=Ui()
    window=QtWidgets.QMainWindow()
    my.setupUi(window)
    window.show()
    app.exec_()