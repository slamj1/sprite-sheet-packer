#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "SpriteAtlas.h"
#include "SpritesTreeWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void refreshFormats();
    void refreshOpenRecentMenu();

    void refreshAtlas(SpriteAtlas* atlas = NULL);

    void openSpritePackerProject(const QString& fileName);
    void saveSpritePackerProject(const QString& fileName);

private slots:
    void openRecent();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionAddSprites_triggered();
    void on_actionAddFolder_triggered();
    void on_actionRemove_triggered();
    void on_actionRefresh_triggered();
    void on_actionPublish_triggered();
    void on_actionAbout_triggered();
    void on_actionPreferences_triggered();

    // zoom control
    void on_toolButtonZoomOut_clicked();
    void on_toolButtonZoomIn_clicked();
    void on_toolButtonZoom1x1_clicked();
    void on_toolButtonZoomFit_clicked();
    void on_zoomSlider_valueChanged(int value);

    void on_maxTextureSizeComboBox_currentTextChanged(const QString &arg1);
    void on_destFolderToolButton_clicked();
    void on_dataFormatSetupToolButton_clicked();
    void on_addScalingVariantPushButton_clicked();

    void spritesTreeWidgetItemSelectionChanged();
    void removeScalingVariant();

private:
    Ui::MainWindow*      ui;
    QGraphicsScene*     _scene;
    SpritesTreeWidget*  _spritesTreeWidget;
    QString             _currentProjectFileName;
    QToolButton*        _openButton;
};

#endif // MAINWINDOW_H
