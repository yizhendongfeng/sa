﻿#ifndef SACHARTDATASVIEWWIDGET_H
#define SACHARTDATASVIEWWIDGET_H
#include <QWidget>
#include <QStringList>
class QwtPlotItemTreeModel;
class SAPlotDataModel;
class SAFigureWindow;
class QwtPlot;
class SACellInputWidget;
class QwtPlotItem;
class QwtPlotCurve;
namespace Ui {
class SAChartDatasViewWidget;
}
///
/// \brief 曲线数据查看窗口
///
class SAChartDatasViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SAChartDatasViewWidget(QWidget *parent = 0);
    ~SAChartDatasViewWidget();
    QwtPlotItemTreeModel* getTreeModel() const;
    void setFigure(SAFigureWindow *fig);
    SAPlotDataModel* getPlotModel() const;
private slots:
    void onTreeViewCurPlotItemClicked(const QModelIndex& index);
    //figure有图添加发送的信号
    void onChartAdded(QwtPlot* plot);
    //figure销毁
    void onFigureDestroy(QObject* obj);
private:
    //解析剪切板的数据 返回按照tab分隔解析的字符表的尺寸
    QSize getClipboardTextTable(QList<QStringList> &res);
    //处理ctrl + v事件
    void onCtrlVInTableView();
private:
    Ui::SAChartDatasViewWidget *ui;
    QwtPlotItemTreeModel* m_treeModel;
    SAPlotDataModel* m_tableModel;
    SAFigureWindow* m_figure;
};

#endif // SACHARTDATASVIEWWIDGET_H
