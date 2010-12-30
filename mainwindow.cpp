#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	userModel = new QStringListModel();
	ui->userListView->setModel(userModel);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::addUser()
{
	QString username = ui->usernameLineEdit->text();
	if(username == "")
	{
		return;
	}
	int n = userModel->rowCount();
	userModel->insertRows(n,1);
	QModelIndex index = userModel->index(n);
	userModel->setData(index,username);
}
