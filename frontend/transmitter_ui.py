# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'beacon_transmitter.ui'
#
# Created: Tue Mar 15 15:09:11 2016
#      by: PyQt4 UI code generator 4.10.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_transmitter_dialoge(object):
    def setupUi(self, transmitter_dialoge):
        transmitter_dialoge.setObjectName(_fromUtf8("transmitter_dialoge"))
        transmitter_dialoge.resize(573, 368)
        transmitter_dialoge.setSizeIncrement(QtCore.QSize(0, 0))
        self.btn_add_file = QtGui.QPushButton(transmitter_dialoge)
        self.btn_add_file.setGeometry(QtCore.QRect(380, 40, 96, 26))
        self.btn_add_file.setObjectName(_fromUtf8("btn_add_file"))
        self.list_files = QtGui.QListWidget(transmitter_dialoge)
        self.list_files.setGeometry(QtCore.QRect(20, 40, 256, 192))
        self.list_files.setObjectName(_fromUtf8("list_files"))
        self.btn_start_transmisison = QtGui.QPushButton(transmitter_dialoge)
        self.btn_start_transmisison.setGeometry(QtCore.QRect(390, 280, 141, 26))
        self.btn_start_transmisison.setObjectName(_fromUtf8("btn_start_transmisison"))
        self.progress_transmission = QtGui.QProgressBar(transmitter_dialoge)
        self.progress_transmission.setGeometry(QtCore.QRect(30, 280, 251, 23))
        self.progress_transmission.setProperty("value", 24)
        self.progress_transmission.setObjectName(_fromUtf8("progress_transmission"))
        self.btn_remove_file = QtGui.QPushButton(transmitter_dialoge)
        self.btn_remove_file.setGeometry(QtCore.QRect(380, 70, 96, 26))
        self.btn_remove_file.setObjectName(_fromUtf8("btn_remove_file"))
        self.btn_stop_transmission = QtGui.QPushButton(transmitter_dialoge)
        self.btn_stop_transmission.setGeometry(QtCore.QRect(390, 310, 141, 26))
        self.btn_stop_transmission.setObjectName(_fromUtf8("btn_stop_transmission"))

        self.retranslateUi(transmitter_dialoge)
        QtCore.QObject.connect(self.btn_remove_file, QtCore.SIGNAL(_fromUtf8("clicked()")), self.list_files.clearSelection)
        QtCore.QMetaObject.connectSlotsByName(transmitter_dialoge)

    def retranslateUi(self, transmitter_dialoge):
        transmitter_dialoge.setWindowTitle(_translate("transmitter_dialoge", "ui_Transmitter", None))
        self.btn_add_file.setText(_translate("transmitter_dialoge", "Add file", None))
        self.btn_start_transmisison.setText(_translate("transmitter_dialoge", "Start Transmission", None))
        self.btn_remove_file.setText(_translate("transmitter_dialoge", "Remove file", None))
        self.btn_stop_transmission.setText(_translate("transmitter_dialoge", "Stop Transmission", None))

