#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QHash>
#include <QMessageBox>
#include <QAbstractButton>



QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;


private slots:
    void insertComparedSalesData(QString month, QString brand);
    void brandTapClicked();
    void monthIndexChanged();


    void monthPickButtonClicked();
    void durationPickButtonClicked();
    void searchButtonClicked();
    void hyundaiButttonClicked();
    void kiaButtonClicked();
    void genesisButtonClicked();
    void chevroletButtonClicked();
    void kgMobilityButtonClicked();
    void renaultButtonClicked();
    void bmwButtonClicked();
    void benzButtonClicked();
    void audiButtonClicked();
    void lexusButtonClicked();
    void porscheButtonClicked();

    QString monthlyTotalSalesFind(QString month, int type);
    void BrandTotalSalesByPeriodFind(QString extract1, QString extract2);
    void monthlyBrandTotalSalesFind(QString month);

    QString monthlySpecificBrandTotalSalesFind(QString month, QString brand);
    void monthlyModelTotalSalesFind(QString month, QString brand, QString totalSalesData);





};
#endif // WIDGET_H
