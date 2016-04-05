#!/usr/bin/python
''' impliments transmitter frontend '''

import sys

from PySide.QtGui import *
from PySide.QtCore import *
from PySide import QtGui, QtCore

from beacon_transmitter import Ui_transmitter_dialoge

class TransmittWindow(QMainWindow, Ui_transmitter_dialoge):

    def __init__(self):
        super(TransmittWindow, self).__init__()
        self.setupUi(self)
        
        self.pathlist = []

        self.assign_widgets()
        self.show()

    #assign signals to slots
    def assign_widgets(self):
        ''' connect signals and slots or assign callbacks '''
        self.btn_add_file.clicked.connect(self.handle_button_fileAdd)
        self.btn_remove_file.clicked.connect(self.handle_button_fileRemove)
        pass

	def update_list(self):
		for file in self.pathlist:
			self.list_files.addItem(file)
		pass

    def handle_button_fileAdd(self):
        ''' choose button callback'''
        dialog = QtGui.QFileDialog(self)
        if dialog.exec_() == QtGui.QDialog.Accepted:
            files = dialog.selectedFiles()
            for file in files:
        		if file not in self.pathlist:
		    		self.pathlist.append(file)
		    		print file	
			for file in self.pathlist:
				self.list_files.addItem(file)
			pass
        dialog.deleteLater()

    def handle_button_fileRemove(self):
		self.list_files.clear()

if __name__ == '__main__':
    APP = QApplication(sys.argv)
    MAIN_WIN = TransmittWindow()
    RET = APP.exec_()
    sys.exit(RET)
