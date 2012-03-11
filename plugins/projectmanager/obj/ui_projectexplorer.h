/********************************************************************************
** Form generated from reading UI file 'projectexplorer.ui'
**
** Created: Sun Mar 11 13:49:44 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTEXPLORER_H
#define UI_PROJECTEXPLORER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectExplorer
{
public:
    QAction *actionClose_Project;
    QAction *actionDelete;
    QGridLayout *gridLayout;
    QTreeWidget *projectTree;

    void setupUi(QWidget *ProjectExplorer)
    {
        if (ProjectExplorer->objectName().isEmpty())
            ProjectExplorer->setObjectName(QString::fromUtf8("ProjectExplorer"));
        ProjectExplorer->resize(203, 420);
        actionClose_Project = new QAction(ProjectExplorer);
        actionClose_Project->setObjectName(QString::fromUtf8("actionClose_Project"));
        actionDelete = new QAction(ProjectExplorer);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        gridLayout = new QGridLayout(ProjectExplorer);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        projectTree = new QTreeWidget(ProjectExplorer);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        projectTree->setHeaderItem(__qtreewidgetitem);
        projectTree->setObjectName(QString::fromUtf8("projectTree"));
        projectTree->setContextMenuPolicy(Qt::CustomContextMenu);
        projectTree->setIconSize(QSize(24, 24));
        projectTree->header()->setVisible(false);

        gridLayout->addWidget(projectTree, 0, 0, 1, 1);


        retranslateUi(ProjectExplorer);

        QMetaObject::connectSlotsByName(ProjectExplorer);
    } // setupUi

    void retranslateUi(QWidget *ProjectExplorer)
    {
        ProjectExplorer->setWindowTitle(QApplication::translate("ProjectExplorer", "Form", 0, QApplication::UnicodeUTF8));
        actionClose_Project->setText(QApplication::translate("ProjectExplorer", "Close Project", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("ProjectExplorer", "Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProjectExplorer: public Ui_ProjectExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTEXPLORER_H
