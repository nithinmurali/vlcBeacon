# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'beacon_transmitter.ui'
#
# Created: Tue Mar 15 15:34:31 2016
#      by: pyside-uic 0.2.15 running on PySide 1.2.1
#
# WARNING! All changes made in this file will be lost!

from PySide import QtCore, QtGui

class Ui_transmitter_dialoge(object):
    def setupUi(self, transmitter_dialoge):
        transmitter_dialoge.setObjectName("transmitter_dialoge")
        transmitter_dialoge.resize(573, 368)
        transmitter_dialoge.setSizeIncrement(QtCore.QSize(0, 0))
        self.btn_add_file = QtGui.QPushButton(transmitter_dialoge)
        self.btn_add_file.setGeometry(QtCore.QRect(380, 40, 96, 26))
        self.btn_add_file.setObjectName("btn_add_file")
        self.list_files = QtGui.QListWidget(transmitter_dialoge)
        self.list_files.setGeometry(QtCore.QRect(20, 40, 256, 192))
        self.list_files.setObjectName("list_files")
        self.btn_start_transmisison = QtGui.QPushButton(transmitter_dialoge)
        self.btn_start_transmisison.setGeometry(QtCore.QRect(390, 280, 141, 26))
        self.btn_start_transmisison.setObjectName("btn_start_transmisison")
        self.progress_transmission = QtGui.QProgressBar(transmitter_dialoge)
        self.progress_transmission.setGeometry(QtCore.QRect(30, 280, 251, 23))
        self.progress_transmission.setProperty("value", 0)
        self.progress_transmission.setObjectName("progress_transmission")
        self.btn_remove_file = QtGui.QPushButton(transmitter_dialoge)
        self.btn_remove_file.setGeometry(QtCore.QRect(380, 70, 96, 26))
        self.btn_remove_file.setObjectName("btn_remove_file")
        self.btn_stop_transmission = QtGui.QPushButton(transmitter_dialoge)
        self.btn_stop_transmission.setGeometry(QtCore.QRect(390, 310, 141, 26))
        self.btn_stop_transmission.setObjectName("btn_stop_transmission")

        self.retranslateUi(transmitter_dialoge)
        QtCore.QObject.connect(self.btn_remove_file, QtCore.SIGNAL("clicked()"), self.list_files.clearSelection)
        QtCore.QMetaObject.connectSlotsByName(transmitter_dialoge)

    def retranslateUi(self, transmitter_dialoge):
        transmitter_dialoge.setWindowTitle(QtGui.QApplication.translate("transmitter_dialoge", "VLC Transmitter", None, QtGui.QApplication.UnicodeUTF8))
        self.btn_add_file.setText(QtGui.QApplication.translate("transmitter_dialoge", "Add file", None, QtGui.QApplication.UnicodeUTF8))
        self.btn_start_transmisison.setText(QtGui.QApplication.translate("transmitter_dialoge", "Start Transmission", None, QtGui.QApplication.UnicodeUTF8))
        self.btn_remove_file.setText(QtGui.QApplication.translate("transmitter_dialoge", "Remove file", None, QtGui.QApplication.UnicodeUTF8))
        self.btn_stop_transmission.setText(QtGui.QApplication.translate("transmitter_dialoge", "Stop Transmission", None, QtGui.QApplication.UnicodeUTF8))

