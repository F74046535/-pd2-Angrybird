#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QBrush>
#include<QImage>
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the eventFilter
    qApp->installEventFilter(this);
    press=0;
    count=0;
    m_button=new QPushButton("leave!!",this);
    m_button->setGeometry(QRect(QPoint(800,50),QSize(100, 50)));
    connect(m_button, SIGNAL (clicked()), this, SLOT (exit()));
    //m_buttont=new QPushButton("restart!!",this);
    //m_buttont->setGeometry(QRect(QPoint(800,70),QSize(100, 50)));
    //connect(m_buttont, SIGNAL (clicked()), this, SLOT (restart()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    std::cout<<width()<<ui->graphicsView->height();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/thh.jpg")));
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));

    // Create bird (You can edit here)
    birdie = new Bird(0.0f,10.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdiee = new Bird(0.0f,10.0f,0.27f,&timer,QPixmap(":/blue.png").scaled(height()/9.0,height()/9.0),world,scene);
    yellowbird = new Yellow(0.0f,10.0f,0.27f,&timer,QPixmap(":/yellow.png").scaled(height()/9.0,height()/9.0),world,scene);
    whitebird = new White(0.0f,10.0f,0.27f,&timer,QPixmap(":/white.png").scaled(height()/9.0,height()/9.0),world,scene);

    // Setting the Velocity
    //birdie->setLinearVelocity(b2Vec2(5,5));
    itemList.push_back(birdie);
    piggy= new Bird(15.0,10.0f,0.27f,&timer,QPixmap(":/pig.png").scaled(height()/9.0,height()/9.0),world,scene);
    itemList.push_back(piggy);
   // shooter=new Bird(3.0f,20.0f,0.27f,&timer,QPixmap(":/shooter.png").scaled(height()/7.0,height()/7.0),world,scene);
    itemList.push_back(new Land(3.0f,5.0f,0.27f,0.26f,QPixmap(":/shooter.png").scaled(height()/7.0,height()/7.0),world,scene));
    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(GetLinearVelocity()));
    timer.start(100/6);
    Wood *wood=new Wood(10.0,20.0f,2.5f,1.0f,&timer,QPixmap(":/rocks.png").scaled(height()/5.0,height()/6.0),world,scene);
    itemList.push_back(wood);
    Wood *woodt=new Wood(10.0,40.0f,1.5f,1.5f,&timer,QPixmap(":/rocks.png").scaled(height()/6.0,height()/6.0),world,scene);
    itemList.push_back(woodt);
    Wood *woodtt=new Wood(10.0,50.0f,1.5f,1.5f,&timer,QPixmap(":/rocks.png").scaled(height()/6.0,height()/6.0),world,scene);
    itemList.push_back(woodtt);
    Wood *woodttt=new Wood(25.0,20.0f,2.5f,1.0f,&timer,QPixmap(":/rocks.png").scaled(height()/5.0,height()/6.0),world,scene);
    itemList.push_back(woodttt);
    Wood *woodtttt=new Wood(25.0,40.0f,1.5f,1.5f,&timer,QPixmap(":/rocks.png").scaled(height()/6.0,height()/6.0),world,scene);
    itemList.push_back(woodtttt);

}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {     count++;
          //printf("%d",count);
          if(count==5)
          {   birdies = new Bird(3.0f,8.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
              itemList.push_back(birdies);

              bomb=birdies;
          }
          if(count==10)
              a=true;
              x0=QCursor::pos().x();
              y0=QCursor::pos().y();
           if(count==15)
          {
              birdiees = new Bird(3.0f,8.0f,0.27f,&timer,QPixmap(":/blue.png").scaled(height()/9.0,height()/9.0),world,scene);
              itemList.push_back(birdiees);
              bomb=birdiees;
          }
            if(count==20)
            {  b=true;
              x0=QCursor::pos().x();
              y0=QCursor::pos().y();
            }
            if(count==25)
            {   yellowbirds = new Yellow(3.0f,8.0f,0.27f,&timer,QPixmap(":/yellow.png").scaled(height()/9.0,height()/9.0),world,scene);
                itemList.push_back(yellowbirds);
                bomb=yellowbirds;
            }
            if(count==30)
            {    c=true;
                 x0=QCursor::pos().x();
                 y0=QCursor::pos().y();
             }
            if(count==35)
            {
                whitebirds = new White(3.0f,8.0f,0.27f,&timer,QPixmap(":/white.png").scaled(height()/9.0,height()/9.0),world,scene);
                itemList.push_back(whitebirds);
                bomb=whitebirds;
            }
            if(count==40)
            {
                d=true;
                x0=QCursor::pos().x();
                y0=QCursor::pos().y();
            }
        /* TODO : add your code here */
        //std::cout << "Press !" << std::endl ;
        //delete birdie;
        //birdie = new Bird(0.0f,10.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
        //birdie->setLinearVelocity(b2Vec2(5,5));
        //itemList.push_back(birdie);
       // if(press==true)

    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
           if(a==true)
        {

             birdies->g_body->SetTransform(b2Vec2(((float)x0-480.0)*32.0/1000.0,18.0/2.0-((float)y0-600.0)*32.0/960.0),0);
             x0=QCursor::pos().x();
             y0=QCursor::pos().y();

             //birdies->setLinearVelocity(b2Vec2(30,5));

        }
         if(b==true)
        {
             birdiees->g_body->SetTransform(b2Vec2(((float)x0-480.0)*32.0/1000.0,18.0/2.0-((float)y0-600.0)*32.0/960.0),0);
             x0=QCursor::pos().x();
             y0=QCursor::pos().y();
        }
         if(c==true)
         {
             yellowbirds->g_body->SetTransform(b2Vec2(((float)x0-480.0)*32.0/1000.0,18.0/2.0-((float)y0-600.0)*32.0/960.0),0);
             x0=QCursor::pos().x();
             y0=QCursor::pos().y();
         }
         if(d==true)
         {
             whitebirds->g_body->SetTransform(b2Vec2(((float)x0-480.0)*32.0/1000.0,18.0/2.0-((float)y0-600.0)*32.0/960.0),0);
             x0=QCursor::pos().x();
             y0=QCursor::pos().y();
         }

    }
    if(event->type() == QEvent::MouseButtonRelease)
    {    press++;
        //printf("%d",press);
        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
        if(press<=2&&press%2==1)
        {delete birdie;}
         /*if(press==2)
         {birdies = new Bird(3.0f,8.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
         itemList.push_back(birdies);
          //press=true;
          //x0=QCursor::pos().x();
          //y0=QCursor::pos().y();
         }*/
        if(press==4){
            a=false;
            birdies->setLinearVelocity(b2Vec2(30,10));

        }
        if(press==5)
        {  delete birdiee; }
        if(press==8){
            b=false;
            birdiees->setLinearVelocity(b2Vec2(10,10));
        }
        if(press==9){
            delete yellowbird;
        }
        if(press==12){
            c=false;
            yellowbirds->setLinearVelocity(b2Vec2(30,10));
        }
        if(press==13){
            delete whitebird;
        }
        if(press==16){
            d=false;
            whitebirds->setLinearVelocity(b2Vec2(10,10));
            //GetLinearVelocity();
            //GetLinearVelocity();
            //if(j>3)
            //delete whitebirds;
            //if(piggy->getVV()>0)
                //delete whitebirds;
        }
    }
    return false;
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_S)
    {
        if(press==8)
        {
           egg = new Bird(11,18.0f,0.27f,&timer,QPixmap(":/egg.png").scaled(height()/5.0,height()/5.0),world,scene);
           itemList.push_back(egg);
        }
        if(press==12){
            yellowbirds->show();
        }
        if(press==16){
            whitebirds->showt();
        }

    }

}


void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
void MainWindow::handleButton()
{
    // change the text
    m_button->setText("leave!!");
    // resize button
    m_button->resize(100,100);
}
void  MainWindow::GetLinearVelocity()
{
    j=piggy->g_body->GetLinearVelocity().x;
    if(j!=0||piggy->g_body->GetAngularVelocity()!=0)
      {
        printf("as");
       // bomb->g_pixmap.setScale(2);
        //destroy(bomb->g_body);
        delete bomb;
        bomb=NULL;
    }
}

void MainWindow::exit()
{
    close();
}
/*void MainWindow::restart()
{
    itemList.clear();
    MainWindow *mainwindow=new MainWindow;
    mainwindow->show();
}*/



