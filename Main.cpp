#include "CustomSliderWidget.hpp"
#include "ShoeWidget890.hpp"
#include "ShoeWidget1080.hpp"
#include "ShoeWidgetRoad.hpp"
#include "ShoeWidgetTrail.hpp"
#include "ShoeWidgetAtheletes.hpp"
#include "FormWidgetTry.hpp"
#include "FormWidgetPurchase.hpp"
#include "Global.hpp"
#include "AnimatorWidget.hpp"

#include <MultiWidgets/ImageWidget.hpp>
#include <MultiWidgets/Plugins.hpp>
#include <MultiWidgets/LayerWidget.hpp>
#include <MultiWidgets/RippleOverlay.hpp>
#include <ThreadedRendering/SimpleThreadedApplication.hpp>

#include <MultiWidgets/StayInsideParentOperator.hpp>

#include <MultiWidgets/TextBox.hpp>
#include <MultiWidgets/TextEdit.hpp>
#include <Radiant/Directory.hpp>

#include <MultiTouch/MultiTouch.hpp>

#include <Fluffy/CSSParser.hpp>
#include <Fluffy/StyleSheet.hpp>

#include <Resonant/ModuleRectPanner.hpp>



class Custom_Marker_Launcher : public virtual MultiWidgets::Widget
{
    int counter;
    bool didLaunch;

    public:
  // Normal constructor
  Custom_Marker_Launcher(MultiWidgets::Widget * parent)
      : Widget(parent)
  {
      didLaunch = false;

      setSize(parent->size());
      //setInputTransparent(true);
      setInputFlags(INPUT_USE_SINGLE_TAPS);
      setColor(0, 0, 0, 0);
      setDepth(0);
      raiseFlag(LOCK_DEPTH);

      counter = 0;
  }

  virtual ~Custom_Marker_Launcher() {}


  virtual void input(MultiWidgets::GrabManager & gm, float dt)
  {
    Widget::input(gm, dt);
    MultiTouch::Sample m_sample = gm.sample();


////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////FINGER VERSIONS//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//    if(m_sample.fingerCount() >= 1 && noActiveWidgets < 4)
//    {
//        if(!didLaunch)
//        {
//                CustomWidget::ShoeWidget890 * sw = new CustomWidget::ShoeWidget890(topParent());
//                sw->setSize(topParent()->size());
//                sw->setColor(0,0,0,0);
//                sw->setDepth(5);
//                sw->hide(true);
//                sw->setupTheShoeWidget890( m_sample.finger(0).tipLocation().x, m_sample.finger(0).tipLocation().y,0);

////                CustomWidget::FormWidgetPurchase * fw = new CustomWidget::FormWidgetPurchase(parent());
////                fw->setSize(parent()->size());
////                fw->setColor(0,0,0,0);
////                fw->setDepth(5);
////                fw->hide(true);
////                fw->setupTheFormWidgetPurchase( m_sample.finger(0).tipLocation().x, m_sample.finger(0).tipLocation().y);
//                //fw->addOperator(new MultiWidgets::StayInsideParentOperator());
//                //fw->setRotation(m_sample.marker(i).rotation());

//                didLaunch = true;
//                noActiveWidgets++;
//        }
//    }

//    if(m_sample.fingerCount() == 0)
//    {
//        didLaunch = false;
//    }

//    if(m_sample.fingerCount() >= 2 && noActiveWidgets > 0)
//    {
//        for (ChildIterator it = topParent()->childBegin(); it != topParent()->childEnd(); ++it) {
//            if(strcmp(it->name().c_str(), "launcher") != 0 && strcmp(it->name().c_str(), "anime") != 0
//                        && strcmp(it->name().c_str(), "ripple") != 0)
//            {
//                it->raiseFlag(DELETE_ME);
//                noActiveWidgets = 0;
//            }
//        }
//    }

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////DO NOT DELETE! IT'S THE MARKER CODE//////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
    if(m_sample.markerCount() > 0 && noActiveWidgets < 4)
    {
        if(!didLaunch)
        {
            for(unsigned int i = 0; i<m_sample.markerCount(); i++)
            {
                char launchCode[40];
                memset(launchCode,0,sizeof(launchCode));
                snprintf(launchCode,sizeof(launchCode)-1,"%llu",(unsigned long long)m_sample.marker(i).code());


                if(strcmp(launchCode, "178") == 0)
                {
                    CustomWidget::ShoeWidget890 * sw = new CustomWidget::ShoeWidget890(topParent());
                    sw->setSize(topParent()->size());
                    sw->setColor(0,0,0,0);
                    sw->setDepth(5);
                    sw->hide(true);
                    sw->setupTheShoeWidget890( m_sample.marker(i).centerLocation().x,
                                                m_sample.marker(i).centerLocation().y,m_sample.marker(i).rotation());
                }
                if(strcmp(launchCode, "126") == 0)
                {
                    CustomWidget::ShoeWidget1080 * sw = new CustomWidget::ShoeWidget1080(topParent());
                    sw->setSize(topParent()->size());
                    sw->setColor(0,0,0,0);
                    sw->setDepth(5);
                    sw->hide(true);
                    sw->setupTheShoeWidget1080( m_sample.marker(i).centerLocation().x,
                                              m_sample.marker(i).centerLocation().y,m_sample.marker(i).rotation());
                }
                if(strcmp(launchCode,"409") == 0)
                {
                    CustomWidget::ShoeWidgetRoad * sw = new CustomWidget::ShoeWidgetRoad(topParent());
                    sw->setSize(topParent()->size());
                    sw->setColor(0,0,0,0);
                    sw->setDepth(5);
                    sw->hide(true);
                    sw->setupTheShoeWidgetRoad( m_sample.marker(i).centerLocation().x,
                                               m_sample.marker(i).centerLocation().y,m_sample.marker(i).rotation());
                }
                if(strcmp(launchCode,"576") == 0)
                {
                    CustomWidget::ShoeWidgetTrail * sw = new CustomWidget::ShoeWidgetTrail(topParent());
                    sw->setSize(topParent()->size());
                    sw->setColor(0,0,0,0);
                    sw->setDepth(5);
                    sw->hide(true);
                    sw->setupTheShoeWidgetTrail( m_sample.marker(i).centerLocation().x,
                                               m_sample.marker(i).centerLocation().y,m_sample.marker(i).rotation());
                }
                if(strcmp(launchCode,"724") == 0)
                {
                    CustomWidget::ShoeWidgetAtheletes * sw = new CustomWidget::ShoeWidgetAtheletes(topParent());
                    sw->setSize(topParent()->size());
                    sw->setColor(0,0,0,0);
                    sw->setDepth(5);
                    sw->hide(true);
                    sw->setupTheShoeWidgetAtheletes(m_sample.marker(i).centerLocation().x,
                                               m_sample.marker(i).centerLocation().y,m_sample.marker(i).rotation());
                }

                if(strcmp(launchCode,"654") == 0)
                {
                    CustomWidget::FormWidgetPurchase * fw = new CustomWidget::FormWidgetPurchase(topParent());
                    fw->setSize(topParent()->size());
                    fw->setColor(0,0,0,0);
                    fw->setDepth(5);
                    fw->hide(true);
                    fw->setupTheFormWidgetPurchase(m_sample.marker(i).centerLocation().x, m_sample.marker(i).centerLocation().y);
                    fw->addOperator(new MultiWidgets::StayInsideParentOperator());
                    fw->setRotation(m_sample.marker(i).rotation());
                }
                if(strcmp(launchCode,"328") == 0)
                {
                    CustomWidget::FormWidgetTry * fw = new CustomWidget::FormWidgetTry(topParent());
                    fw->setSize(topParent()->size());
                    fw->setColor(0,0,0,0);
                    fw->setDepth(5);
                    fw->hide(true);
                    fw->setupTheFormWidgetTry(m_sample.marker(i).centerLocation().x, m_sample.marker(i).centerLocation().y);
                    fw->addOperator(new MultiWidgets::StayInsideParentOperator());
                    fw->setRotation(m_sample.marker(i).rotation());
                }

                didLaunch = true;
                noActiveWidgets++;
           }
        }
    }


    if(m_sample.markerCount() > 0 && noActiveWidgets > 0)
    {
        for(unsigned int i = 0; i<m_sample.markerCount(); i++)
        {
            char launchCode[40];
            memset(launchCode,0,sizeof(launchCode));
            snprintf(launchCode,sizeof(launchCode)-1,"%llu",(unsigned long long)m_sample.marker(i).code());

            //MASTER KILL!
            if(strcmp(launchCode,"986") == 0)
            {
                for (ChildIterator it = topParent()->childBegin(); it != topParent()->childEnd(); ++it) {
                    if(strcmp(it->name().c_str(), "launcher") != 0 && strcmp(it->name().c_str(), "anime") != 0
                                && strcmp(it->name().c_str(), "ripple") != 0)
                    {
                        it->raiseFlag(DELETE_ME);
                        noActiveWidgets = 0;
                    }
                }
            }
        }
    }

//    if(noActiveWidgets>0)
//    {
//        s1->raiseInputFlag(MultiWidgets::ImageWidget::INPUT_NONE);
//        s1->show();
//    }else
//    {
//        s1->raiseInputFlag(MultiWidgets::ImageWidget::INPUT_NONE);
//        s1->hide();
//    }

    if(m_sample.markerCount() == 0)
    {
        didLaunch = false;
    }
  }
};


int main(int argc, char ** argv)
{
  ThreadedRendering::SimpleThreadedApplication app;

  if(!app.simpleInit(argc, argv))
    return 1;


///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////AUDIO/////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
  Resonant::ModulePanner * panner = new Resonant::ModulePanner(0);
  panner->setId("panner");
  panner->setCaptureRadius(600);


  Resonant::SoundRectangle * r1 = new Resonant::SoundRectangle(Nimble::Vector2i(1266-600, 1080-1080), Nimble::Vector2i(600, 1080), 1.0f, 0, 1, 1);
  Resonant::SoundRectangle * r2 = new Resonant::SoundRectangle(Nimble::Vector2i(1266-600, 1080), Nimble::Vector2i(600, 1080), 1.0f, 0, 0, 0);

  panner->addSoundRectangle(r1);
  panner->addSoundRectangle(r2);


  // Create a DSPNetwork item to wrap the module
  Resonant::DSPNetwork::Item item;
  item.setModule(panner);

  // Add the wrapped module to the DSPNetwork
  Resonant::DSPNetwork::instance()->addModule(item);


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////ANIMATION///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
  MultiAnimate::AnimatorWidget * aminWidget =
  new MultiAnimate::AnimatorWidget(app.root());

  aminWidget->setSize(2532,2160);
  aminWidget->setLocation(0,0);
  aminWidget->setInputFlags(MultiWidgets::Widget::INPUT_PASS_TO_CHILDREN);
  aminWidget->setDepth(-1);
  aminWidget->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
  aminWidget->setColor(0,0,0,255);
  aminWidget->setName("anime");


  aminWidget->setupAnimations();

  Custom_Marker_Launcher * ml = new Custom_Marker_Launcher(app.root());
  ml->setLocation(0,0);
  ml->setSize(app.size());
  ml->setDepth(999);
  ml->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
  ml->setName("launcher");


//  CustomWidget::ShoeWidget890 * sw1 = new CustomWidget::ShoeWidget890(app.root());
//  sw1->setSize(app.root()->size());
//  sw1->setColor(0,0,0,0);
//  sw1->setDepth(5);
//  sw1->hide(true);
//  sw1->setupTheShoeWidget890( 100,100,0);

//  CustomWidget::ShoeWidget1080 * sw2 = new CustomWidget::ShoeWidget1080(app.root());
//  sw2->setSize(app.root()->size());
//  sw2->setColor(0,0,0,0);
//  sw2->setDepth(5);
//  sw2->hide(true);
//  sw2->setupTheShoeWidget1080( 100,100,0);

//  CustomWidget::ShoeWidgetRoad * sw3 = new CustomWidget::ShoeWidgetRoad(app.root());
//  sw3->setSize(app.root()->size());
//  sw3->setColor(0,0,0,0);
//  sw3->setDepth(5);
//  sw3->hide(true);
//  sw3->setupTheShoeWidgetRoad( 100,100,0);

//  CustomWidget::ShoeWidgetTrail * sw = new CustomWidget::ShoeWidgetTrail(app.root());
//  sw->setSize(app.root()->size());
//  sw->setColor(0,0,0,0);
//  sw->setDepth(5);
//  sw->hide(true);
//  sw->setupTheShoeWidgetTrail( 100,100,0);

//  CustomWidget::ShoeWidgetAtheletes * sw5 = new CustomWidget::ShoeWidgetAtheletes(app.root());
//  sw5->setSize(app.root()->size());
//  sw5->setColor(0,0,0,0);
//  sw5->setDepth(5);
//  sw5->hide(true);
//  sw5->setupTheShoeWidgetAtheletes( 100,100,0);


//  CustomWidget::FormWidgetTry * fw = new CustomWidget::FormWidgetTry(app.root());
//  fw->setSize(app.root()->size());
//  fw->setColor(0,0,0,0);
//  fw->setDepth(5);
//  fw->hide(true);
//  fw->setupTheFormWidgetTry(100, 100);

  CustomWidget::FormWidgetPurchase * fw1 = new CustomWidget::FormWidgetPurchase(app.root());
  fw1->setSize(app.root()->size());
  fw1->setColor(0,0,0,0);
  fw1->setDepth(5);
  fw1->hide(true);
  fw1->setupTheFormWidgetPurchase(100,100);


  MultiWidgets::RippleOverlay * rp = new MultiWidgets::RippleOverlay(app.root());
  rp->setLocation(0,0);
  rp->setDepth(0);
  rp->setSize(app.size());
  rp->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
  rp->setCSSType("rippler");

  app.setStyleFile("theCSS.css");
  rp->setStyle(app.style());

  rp->setName("ripple");


  // Run the application:
  return app.run();
}
