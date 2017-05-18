# -*- coding:utf-8 -*-
# -*- by prime -*-

import sys
from HW2.client import FTP
from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(640, 480)

        font=QtGui.QFont()
        font.setFamily('Arial')
        font.setBold(True)
        font.setPointSize(10)


        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(10, 20, 72, 15))
        self.label.setObjectName("label")
        self.lineEdit = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit.setGeometry(QtCore.QRect(110, 20, 281, 31))
        self.lineEdit.setObjectName("lineEdit")
        self.lineEdit_2 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_2.setGeometry(QtCore.QRect(110, 60, 281, 31))
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.lineEdit_3 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_3.setGeometry(QtCore.QRect(110, 100, 281, 31))
        self.lineEdit_3.setEchoMode(QtWidgets.QLineEdit.Password)
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(10, 70, 72, 15))
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(10, 110, 72, 15))
        self.label_3.setObjectName("label_3")
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton.setGeometry(QtCore.QRect(500, 10, 93, 28))
        self.pushButton.setObjectName("pushButton")
        self.pushButton_2 = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_2.setGeometry(QtCore.QRect(500, 50, 93, 28))
        self.pushButton_2.setObjectName("pushButton_2")
        self.pushButton_3 = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_3.setGeometry(QtCore.QRect(500, 90, 93, 28))
        self.pushButton_3.setObjectName("pushButton_3")

        self.pushButton.clicked.connect(self.login)
        self.pushButton_2.clicked.connect(self.List)
        self.pushButton_3.clicked.connect(self.Quit)

        self.textBrowser = QtWidgets.QTextBrowser(self.centralwidget)
        self.textBrowser.setGeometry(QtCore.QRect(30, 170, 256, 192))
        self.textBrowser.setObjectName("textBrowser")
        self.textBrowser.setFont(font)
        self.textBrowser_2 = QtWidgets.QTextBrowser(self.centralwidget)
        self.textBrowser_2.setGeometry(QtCore.QRect(320, 170, 256, 192))
        self.textBrowser_2.setObjectName("textBrowser_2")
        self.textBrowser_2.setFont(font)

        self.verticalScrollBar = QtWidgets.QScrollBar(self.textBrowser)
        self.verticalScrollBar.setGeometry(QtCore.QRect(270, 170, 16, 191))
        self.verticalScrollBar.setOrientation(QtCore.Qt.Vertical)
        self.verticalScrollBar.setObjectName("verticalScrollBar")
        self.verticalScrollBar_2 = QtWidgets.QScrollBar(self.textBrowser_2)
        self.verticalScrollBar_2.setGeometry(QtCore.QRect(560, 170, 16, 191))
        self.verticalScrollBar_2.setOrientation(QtCore.Qt.Vertical)
        self.verticalScrollBar_2.setObjectName("verticalScrollBar_2")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(90, 150, 72, 15))
        self.label_4.setObjectName("label_4")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(410, 150, 72, 15))
        self.label_5.setObjectName("label_5")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 640, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600; color:#ff00ff;\">服务器ip:</span></p></body></html>"))
        self.label_2.setText(_translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#5500ff;\">用户名:</span></p></body></html>"))
        self.label_3.setText(_translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#aa0000;\">密码:</span></p></body></html>"))
        self.pushButton.setText(_translate("MainWindow", "connect"))
        self.pushButton_2.setText(_translate("MainWindow", "List"))
        self.pushButton_3.setText(_translate("MainWindow", "quit"))
        self.label_4.setText(_translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#78c852;\">命令通道</span></p></body></html>"))
        self.label_5.setText(_translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#78c852;\">数据通道</span></p></body></html>"))

    def login(self):
        address=self.lineEdit.text()
        account=self.lineEdit_2.text()
        password=self.lineEdit_3.text()
        self.net=FTP(address)
        self.textBrowser.setText(self.net.login(account,password))
        self.textBrowser.append('-'*35)
        self.textBrowser_2.append('-'*35)

    def List(self):
        sh=self.net.List()
        for x in sh[0]:
            self.textBrowser.append(x+'\n')
        self.textBrowser_2.append(sh[1])
        self.textBrowser.append('-' * 35)
        self.textBrowser_2.append('-' * 35)

    def Quit(self):
        sh=self.net.Quit()
        for x in sh[0]:
            self.textBrowser.append(x+'\n')
        self.textBrowser_2.append(sh[1])
        self.textBrowser.append('-' * 35)
        self.textBrowser_2.append('-' * 35)

if __name__ == '__main__':
    app=QtWidgets.QApplication(sys.argv)
    my=Ui_MainWindow()
    win=QtWidgets.QMainWindow()
    my.setupUi(win)
    win.show()
    app.exec_()