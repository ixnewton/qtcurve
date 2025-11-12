/*****************************************************************************
 *   QtCurve Widget Test Application                                        *
 *   Displays various Qt widgets to test QtCurve theme styling              *
 *****************************************************************************/

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QSlider>
#include <QProgressBar>
#include <QLineEdit>
#include <QTextEdit>
#include <QListWidget>
#include <QTreeWidget>
#include <QTableWidget>
#include <QTabWidget>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QLabel>
#include <QDial>
#include <QScrollBar>
#include <QToolButton>
#include <QSplitter>
#include <QHeaderView>
#include <QTimer>

class WidgetTestWindow : public QMainWindow
{
    Q_OBJECT

public:
    WidgetTestWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        setWindowTitle("QtCurve Widget Test Application");
        resize(1000, 800);

        // Create menu bar
        createMenuBar();

        // Create toolbar
        createToolBar();

        // Create central widget with tabs
        QTabWidget *tabWidget = new QTabWidget(this);
        setCentralWidget(tabWidget);

        // Add different test pages
        tabWidget->addTab(createButtonsPage(), "Buttons");
        tabWidget->addTab(createInputsPage(), "Inputs");
        tabWidget->addTab(createProgressPage(), "Progress && Sliders");
        tabWidget->addTab(createViewsPage(), "Views");
        tabWidget->addTab(createContainersPage(), "Containers");

        // Create status bar with progress
        createStatusBar();

        // Start progress animation
        startProgressAnimation();
    }

private:
    QProgressBar *animatedProgress;
    QTimer *progressTimer;
    int progressValue = 0;

    void createMenuBar()
    {
        QMenuBar *menuBar = new QMenuBar(this);
        setMenuBar(menuBar);

        QMenu *fileMenu = menuBar->addMenu("&File");
        QAction *newAction = fileMenu->addAction("&New");
        newAction->setShortcut(QKeySequence::New);
        QAction *openAction = fileMenu->addAction("&Open");
        openAction->setShortcut(QKeySequence::Open);
        QAction *saveAction = fileMenu->addAction("&Save");
        saveAction->setShortcut(QKeySequence::Save);
        fileMenu->addSeparator();
        QAction *quitAction = fileMenu->addAction("&Quit");
        quitAction->setShortcut(QKeySequence::Quit);
        connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

        QMenu *editMenu = menuBar->addMenu("&Edit");
        QAction *copyAction = editMenu->addAction("&Copy");
        copyAction->setShortcut(QKeySequence::Copy);
        QAction *pasteAction = editMenu->addAction("&Paste");
        pasteAction->setShortcut(QKeySequence::Paste);
        editMenu->addSeparator();
        editMenu->addAction("&Preferences");

        QMenu *viewMenu = menuBar->addMenu("&View");
        QAction *toolbarAction = viewMenu->addAction("Show &Toolbar");
        toolbarAction->setCheckable(true);
        toolbarAction->setChecked(true);
        QAction *statusbarAction = viewMenu->addAction("Show &Statusbar");
        statusbarAction->setCheckable(true);
        statusbarAction->setChecked(true);

        menuBar->addMenu("&Help");
    }

    void createToolBar()
    {
        QToolBar *toolbar = addToolBar("Main Toolbar");
        toolbar->addAction("New");
        toolbar->addAction("Open");
        toolbar->addAction("Save");
        toolbar->addSeparator();
        toolbar->addAction("Cut");
        toolbar->addAction("Copy");
        toolbar->addAction("Paste");
        toolbar->addSeparator();

        QToolButton *menuButton = new QToolButton();
        menuButton->setText("Menu");
        menuButton->setPopupMode(QToolButton::InstantPopup);
        QMenu *menu = new QMenu(menuButton);
        menu->addAction("Option 1");
        menu->addAction("Option 2");
        menu->addAction("Option 3");
        menuButton->setMenu(menu);
        toolbar->addWidget(menuButton);
    }

    void createStatusBar()
    {
        QStatusBar *status = statusBar();
        
        // Add Dolphin-style status bar widgets
        QLabel *statusLabel = new QLabel("cantata (folder)", status);
        status->addWidget(statusLabel);
        
        status->addPermanentWidget(new QLabel("Zoom:", status));
        
        QSlider *zoomSlider = new QSlider(Qt::Horizontal, status);
        zoomSlider->setMinimum(0);
        zoomSlider->setMaximum(100);
        zoomSlider->setValue(41);
        zoomSlider->setMaximumWidth(150);
        status->addPermanentWidget(zoomSlider);
        
        // Constrain heights like Dolphin does - use zoom slider's minimum size hint
        const int zoomSliderHeight = zoomSlider->minimumSizeHint().height();
        
        // Add progress bar for disk usage
        QProgressBar *diskProgress = new QProgressBar(status);
        diskProgress->setMinimum(0);
        diskProgress->setMaximum(100);
        diskProgress->setValue(58);  // 58% used (41.4 GiB free out of ~100 GiB)
        diskProgress->setMaximumWidth(100);
        diskProgress->setTextVisible(false);
        diskProgress->setFixedHeight(zoomSliderHeight);  // Match Dolphin's constraint
        status->addPermanentWidget(diskProgress);
        
        QComboBox *statusCombo = new QComboBox(status);
        statusCombo->addItem("41.4 GiB free");
        statusCombo->addItem("50.2 GiB free");
        statusCombo->addItem("100 GiB free");
        statusCombo->setFixedHeight(zoomSliderHeight);  // Match Dolphin's constraint
        status->addPermanentWidget(statusCombo);
    }

    QWidget* createButtonsPage()
    {
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(page);

        // Push Buttons
        QGroupBox *pushGroup = new QGroupBox("Push Buttons");
        QHBoxLayout *pushLayout = new QHBoxLayout(pushGroup);
        pushLayout->addWidget(new QPushButton("Normal"));
        QPushButton *defaultBtn = new QPushButton("Default");
        defaultBtn->setDefault(true);
        pushLayout->addWidget(defaultBtn);
        QPushButton *disabledBtn = new QPushButton("Disabled");
        disabledBtn->setEnabled(false);
        pushLayout->addWidget(disabledBtn);
        QPushButton *flatBtn = new QPushButton("Flat");
        flatBtn->setFlat(true);
        pushLayout->addWidget(flatBtn);
        layout->addWidget(pushGroup);

        // Tool Buttons
        QGroupBox *toolGroup = new QGroupBox("Tool Buttons");
        QHBoxLayout *toolLayout = new QHBoxLayout(toolGroup);
        QToolButton *toolBtn = new QToolButton();
        toolBtn->setText("Tool");
        toolLayout->addWidget(toolBtn);
        QToolButton *raisedTool = new QToolButton();
        raisedTool->setText("Raised");
        raisedTool->setAutoRaise(false);
        toolLayout->addWidget(raisedTool);
        QToolButton *autoRaiseTool = new QToolButton();
        autoRaiseTool->setText("Auto");
        autoRaiseTool->setAutoRaise(true);
        toolLayout->addWidget(autoRaiseTool);
        layout->addWidget(toolGroup);

        // Check Boxes
        QGroupBox *checkGroup = new QGroupBox("Check Boxes");
        QVBoxLayout *checkLayout = new QVBoxLayout(checkGroup);
        QCheckBox *check1 = new QCheckBox("Unchecked");
        checkLayout->addWidget(check1);
        QCheckBox *check2 = new QCheckBox("Checked");
        check2->setChecked(true);
        checkLayout->addWidget(check2);
        QCheckBox *check3 = new QCheckBox("Partially Checked");
        check3->setTristate(true);
        check3->setCheckState(Qt::PartiallyChecked);
        checkLayout->addWidget(check3);
        QCheckBox *check4 = new QCheckBox("Disabled");
        check4->setEnabled(false);
        checkLayout->addWidget(check4);
        layout->addWidget(checkGroup);

        // Radio Buttons
        QGroupBox *radioGroup = new QGroupBox("Radio Buttons");
        QVBoxLayout *radioLayout = new QVBoxLayout(radioGroup);
        QRadioButton *radio1 = new QRadioButton("Option 1");
        radio1->setChecked(true);
        radioLayout->addWidget(radio1);
        radioLayout->addWidget(new QRadioButton("Option 2"));
        radioLayout->addWidget(new QRadioButton("Option 3"));
        QRadioButton *radio4 = new QRadioButton("Disabled");
        radio4->setEnabled(false);
        radioLayout->addWidget(radio4);
        layout->addWidget(radioGroup);

        layout->addStretch();
        return page;
    }

    QWidget* createInputsPage()
    {
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(page);

        // Line Edits
        QGroupBox *lineGroup = new QGroupBox("Line Edits");
        QVBoxLayout *lineLayout = new QVBoxLayout(lineGroup);
        QLineEdit *line1 = new QLineEdit();
        line1->setPlaceholderText("Normal line edit");
        lineLayout->addWidget(line1);
        QLineEdit *line2 = new QLineEdit("Text content");
        lineLayout->addWidget(line2);
        QLineEdit *line3 = new QLineEdit("Disabled");
        line3->setEnabled(false);
        lineLayout->addWidget(line3);
        QLineEdit *line4 = new QLineEdit();
        line4->setPlaceholderText("Password");
        line4->setEchoMode(QLineEdit::Password);
        lineLayout->addWidget(line4);
        layout->addWidget(lineGroup);

        // Combo Boxes
        QGroupBox *comboGroup = new QGroupBox("Combo Boxes");
        QVBoxLayout *comboLayout = new QVBoxLayout(comboGroup);
        QComboBox *combo1 = new QComboBox();
        combo1->addItems({"Filelight", "Baloo", "Disk Usage", "System Monitor", "Partition Manager"});
        comboLayout->addWidget(new QLabel("Select View:"));
        comboLayout->addWidget(combo1);
        QComboBox *combo2 = new QComboBox();
        combo2->setEditable(true);
        combo2->addItems({"Editable", "Combo", "Box"});
        comboLayout->addWidget(new QLabel("Editable Combo:"));
        comboLayout->addWidget(combo2);
        QComboBox *combo3 = new QComboBox();
        combo3->addItems({"Disabled"});
        combo3->setEnabled(false);
        comboLayout->addWidget(combo3);
        layout->addWidget(comboGroup);

        // Spin Boxes
        QGroupBox *spinGroup = new QGroupBox("Spin Boxes");
        QGridLayout *spinLayout = new QGridLayout(spinGroup);
        spinLayout->addWidget(new QLabel("Integer:"), 0, 0);
        QSpinBox *spin1 = new QSpinBox();
        spin1->setRange(0, 100);
        spin1->setValue(50);
        spinLayout->addWidget(spin1, 0, 1);
        spinLayout->addWidget(new QLabel("Double:"), 1, 0);
        QDoubleSpinBox *spin2 = new QDoubleSpinBox();
        spin2->setRange(0.0, 100.0);
        spin2->setValue(25.5);
        spin2->setDecimals(2);
        spinLayout->addWidget(spin2, 1, 1);
        layout->addWidget(spinGroup);

        // Text Edit
        QGroupBox *textGroup = new QGroupBox("Text Edit");
        QVBoxLayout *textLayout = new QVBoxLayout(textGroup);
        QTextEdit *textEdit = new QTextEdit();
        textEdit->setPlainText("Multi-line text editor\nLine 2\nLine 3");
        textEdit->setMaximumHeight(100);
        textLayout->addWidget(textEdit);
        layout->addWidget(textGroup);

        layout->addStretch();
        return page;
    }

    QWidget* createProgressPage()
    {
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(page);

        // Progress Bars
        QGroupBox *progressGroup = new QGroupBox("Progress Bars");
        QVBoxLayout *progressLayout = new QVBoxLayout(progressGroup);
        
        QProgressBar *progress1 = new QProgressBar();
        progress1->setValue(25);
        progressLayout->addWidget(new QLabel("25% Progress:"));
        progressLayout->addWidget(progress1);

        QProgressBar *progress2 = new QProgressBar();
        progress2->setValue(50);
        progressLayout->addWidget(new QLabel("50% Progress:"));
        progressLayout->addWidget(progress2);

        QProgressBar *progress3 = new QProgressBar();
        progress3->setValue(75);
        progressLayout->addWidget(new QLabel("75% Progress:"));
        progressLayout->addWidget(progress3);

        animatedProgress = new QProgressBar();
        animatedProgress->setValue(0);
        progressLayout->addWidget(new QLabel("Animated Progress:"));
        progressLayout->addWidget(animatedProgress);

        QProgressBar *progress5 = new QProgressBar();
        progress5->setMinimum(0);
        progress5->setMaximum(0);
        progressLayout->addWidget(new QLabel("Busy Indicator:"));
        progressLayout->addWidget(progress5);

        layout->addWidget(progressGroup);

        // Sliders
        QGroupBox *sliderGroup = new QGroupBox("Sliders");
        QGridLayout *sliderLayout = new QGridLayout(sliderGroup);
        
        sliderLayout->addWidget(new QLabel("Horizontal:"), 0, 0);
        QSlider *hSlider = new QSlider(Qt::Horizontal);
        hSlider->setRange(0, 100);
        hSlider->setValue(60);
        hSlider->setTickPosition(QSlider::TicksBelow);
        sliderLayout->addWidget(hSlider, 0, 1);

        sliderLayout->addWidget(new QLabel("Vertical:"), 1, 0);
        QSlider *vSlider = new QSlider(Qt::Vertical);
        vSlider->setRange(0, 100);
        vSlider->setValue(40);
        vSlider->setTickPosition(QSlider::TicksLeft);
        sliderLayout->addWidget(vSlider, 1, 1);

        layout->addWidget(sliderGroup);

        // Dial
        QGroupBox *dialGroup = new QGroupBox("Dial");
        QHBoxLayout *dialLayout = new QHBoxLayout(dialGroup);
        QDial *dial = new QDial();
        dial->setRange(0, 100);
        dial->setValue(70);
        dial->setNotchesVisible(true);
        dialLayout->addWidget(dial);
        layout->addWidget(dialGroup);

        // Scroll Bar
        QGroupBox *scrollGroup = new QGroupBox("Scroll Bars");
        QGridLayout *scrollLayout = new QGridLayout(scrollGroup);
        scrollLayout->addWidget(new QLabel("Horizontal:"), 0, 0);
        QScrollBar *hScroll = new QScrollBar(Qt::Horizontal);
        hScroll->setRange(0, 100);
        hScroll->setValue(30);
        scrollLayout->addWidget(hScroll, 0, 1);
        scrollLayout->addWidget(new QLabel("Vertical:"), 1, 0);
        QScrollBar *vScroll = new QScrollBar(Qt::Vertical);
        vScroll->setRange(0, 100);
        vScroll->setValue(50);
        scrollLayout->addWidget(vScroll, 1, 1);
        layout->addWidget(scrollGroup);

        layout->addStretch();
        return page;
    }

    QWidget* createViewsPage()
    {
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(page);

        // List Widget
        QGroupBox *listGroup = new QGroupBox("List Widget");
        QVBoxLayout *listLayout = new QVBoxLayout(listGroup);
        QListWidget *listWidget = new QListWidget();
        listWidget->setAlternatingRowColors(true);
        for (int i = 1; i <= 10; i++) {
            listWidget->addItem(QString("List Item %1").arg(i));
        }
        listWidget->setMaximumHeight(150);
        listLayout->addWidget(listWidget);
        layout->addWidget(listGroup);

        // Tree Widget
        QGroupBox *treeGroup = new QGroupBox("Tree Widget");
        QVBoxLayout *treeLayout = new QVBoxLayout(treeGroup);
        QTreeWidget *treeWidget = new QTreeWidget();
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setHeaderLabels({"Name", "Size", "Type"});
        QTreeWidgetItem *root1 = new QTreeWidgetItem(treeWidget, {"Documents", "4.2 MB", "Folder"});
        new QTreeWidgetItem(root1, {"file1.txt", "1.2 KB", "Text"});
        new QTreeWidgetItem(root1, {"file2.pdf", "2.1 MB", "PDF"});
        QTreeWidgetItem *root2 = new QTreeWidgetItem(treeWidget, {"Pictures", "15.8 MB", "Folder"});
        new QTreeWidgetItem(root2, {"photo1.jpg", "3.4 MB", "Image"});
        new QTreeWidgetItem(root2, {"photo2.png", "2.1 MB", "Image"});
        treeWidget->expandAll();
        treeWidget->setMaximumHeight(150);
        treeLayout->addWidget(treeWidget);
        layout->addWidget(treeGroup);

        // Table Widget
        QGroupBox *tableGroup = new QGroupBox("Table Widget");
        QVBoxLayout *tableLayout = new QVBoxLayout(tableGroup);
        QTableWidget *tableWidget = new QTableWidget(5, 3);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setHorizontalHeaderLabels({"Column 1", "Column 2", "Column 3"});
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 3; col++) {
                tableWidget->setItem(row, col, 
                    new QTableWidgetItem(QString("Cell %1,%2").arg(row).arg(col)));
            }
        }
        tableWidget->setMaximumHeight(150);
        tableLayout->addWidget(tableWidget);
        layout->addWidget(tableGroup);

        layout->addStretch();
        return page;
    }

    QWidget* createContainersPage()
    {
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(page);

        // Group Boxes
        QGroupBox *group1 = new QGroupBox("Group Box 1");
        QVBoxLayout *group1Layout = new QVBoxLayout(group1);
        group1Layout->addWidget(new QLabel("Content inside group box"));
        group1Layout->addWidget(new QPushButton("Button"));
        layout->addWidget(group1);

        QGroupBox *group2 = new QGroupBox("Checkable Group Box");
        group2->setCheckable(true);
        group2->setChecked(true);
        QVBoxLayout *group2Layout = new QVBoxLayout(group2);
        group2Layout->addWidget(new QLabel("This group can be toggled"));
        layout->addWidget(group2);

        // Splitter
        QGroupBox *splitterGroup = new QGroupBox("Splitter");
        QVBoxLayout *splitterLayout = new QVBoxLayout(splitterGroup);
        QSplitter *splitter = new QSplitter(Qt::Horizontal);
        QTextEdit *left = new QTextEdit();
        left->setPlainText("Left pane");
        QTextEdit *right = new QTextEdit();
        right->setPlainText("Right pane");
        splitter->addWidget(left);
        splitter->addWidget(right);
        splitterLayout->addWidget(splitter);
        layout->addWidget(splitterGroup);

        layout->addStretch();
        return page;
    }

    void startProgressAnimation()
    {
        progressTimer = new QTimer(this);
        connect(progressTimer, &QTimer::timeout, this, [this]() {
            progressValue = (progressValue + 1) % 101;
            if (animatedProgress) {
                animatedProgress->setValue(progressValue);
            }
        });
        progressTimer->start(50);
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    WidgetTestWindow window;
    window.show();
    
    return app.exec();
}

#include "qtcurve-widget-test.moc"
