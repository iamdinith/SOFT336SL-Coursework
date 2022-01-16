#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <calculations.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    calculations *cal;

    double answer;

private slots:
    void on_nameCB_1_currentTextChanged();

    void on_conversionTypeCB_currentTextChanged();

    void enableNegatives();

    void disableNegatives();

    void clearAndSetComboBoxItems(QStringList list);

    void setInitialUnit(QString unit);

    void setAnswerAndFormula(double answer, QString formula);

    void setDecimals();

    void convert();

    void on_nameCB_2_currentTextChanged();


    void on_pushButton_toggled(bool checked);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
