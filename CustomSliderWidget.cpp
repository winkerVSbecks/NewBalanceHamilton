#include "CustomSliderWidget.hpp"
#include "ImageWithClose.hpp"
#include "Global.hpp"

#include <MultiWidgets/Plugins.hpp>
#include <MultiWidgets/ListWidget.hpp>
#include <MultiWidgets/ImageWidget.hpp>
#include <MultiWidgets/VideoWidget.hpp>

#include <MultiWidgets/StayInsideParentOperator.hpp>
#include <MultiWidgets/BringToTopOperator.hpp>
#include <MultiWidgets/LimitScaleOperator.hpp>


#include <string.h>
#include <Radiant/Directory.hpp>
#include <Nimble/Random.hpp>

#include <math.h>
#include <cstring>


class Video_Receiver : public virtual MultiWidgets::Widget
{
    MultiWidgets::VideoWidget * myVI;

    public:
  // Normal constructor
  Video_Receiver(MultiWidgets::Widget * parent)
      : Widget(parent)
  {
    setInputFlags(0);

    for (ChildIterator it = parent->childBegin(); it != parent->childEnd(); ++it)
    {

        if(strcmp(it->name().c_str(), "bg") == 0)
        {
            Nimble::RandomUniform m_random(Radiant::TimeStamp::getTime());

            myVI = new MultiWidgets::VideoWidget();
            it->addChild(myVI);

            float x1 = it->location().x;
            float x2 = it->location().x+600*cos(it->rotation());

            float y1 = it->location().y-600*sin(it->rotation());
            float y2 = it->location().y+600*sin(it->rotation());

            float tqx = m_random.randMinMax(x1,x2);
            float tqy = m_random.randMinMax(y1,y2);

            myVI ->setLocation(tqx, tqy);

            myVI->hide(true);
            myVI->setHeight(300);
            myVI->setDepth(99);
            parent->addChild(myVI);
            myVI->addOperator(new MultiWidgets::StayInsideParentOperator());
        }
    }
  }

  virtual ~Video_Receiver() {}


  virtual void processMessage(const char * id, Radiant::BinaryData & data)
  {

      std::string s = id;

      s.erase(s.end()-3, s.end());
      s.append("mp4");

      for (ChildIterator it = parent()->childBegin(); it != parent()->childEnd(); ++it)
      {

          if(strcmp(it->name().c_str(), "bg") == 0)
          {
              Nimble::RandomUniform m_random(Radiant::TimeStamp::getTime());

              float x1 = it->location().x;
              float x2 = it->location().x+600*cos(it->rotation());

              float y1 = it->location().y;
              float y2 = it->location().y+600*sin(it->rotation());

              float tqx = m_random.randMinMax(x1,x2);
              float tqy = m_random.randMinMax(y1,y2);

              myVI ->setLocation(tqx, tqy);

              myVI->show(true);
              myVI->load(s);
              myVI->setScale(0.5);
              myVI->setRotation(it->rotation());
              myVI->setValue("pan-audio", 1);
          }
      }


  }
};



class Image_Receiver : public virtual MultiWidgets::Widget
{

    public:
  // Normal constructor
  Image_Receiver(MultiWidgets::Widget * parent)
      : Widget(parent)
  {
    setInputFlags(0);
  }

  virtual ~Image_Receiver() {}

  virtual void processMessage(const char * id, Radiant::BinaryData & data)
  {
      for (ChildIterator it = parent()->childBegin(); it != parent()->childEnd(); ++it)
      {

          if(strcmp(it->name().c_str(), "bg") == 0)
          {

              Nimble::RandomUniform m_random(Radiant::TimeStamp::getTime());

              CustomWidget::ImageWithClose * im = new CustomWidget::ImageWithClose(parent());
              float x1 = it->location().x;
              float x2 = it->location().x+600*cos(it->rotation());

              float y1 = it->location().y;
              float y2 = it->location().y+600*sin(it->rotation());


              float tqx = m_random.randMinMax(x1,x2);
              float tqy = m_random.randMinMax(y1,y2);

              im->setupTheImageWithClose(id, tqx, tqy, it->rotation(), 300, 300);
              im->hide();
          }
      }
  }



};


namespace CustomWidget
{

  CustomSliderWidget::CustomSliderWidget(MultiWidgets::Widget * parent)
      : Widget(parent)
  {}

  CustomSliderWidget::~CustomSliderWidget()
  {}

  void CustomSliderWidget::makeSlider(bool Ath, const char * path)
  {
      Image_Receiver * im_receiver = new Image_Receiver(parent()->parent()); //->parent()
      im_receiver->setLocation(300, 300);
      im_receiver->hide(true);

      Video_Receiver * vi_receiver = new Video_Receiver(parent()->parent()); //parent()->
      vi_receiver->setLocation(300, 300);
      vi_receiver->hide(true);


      MultiWidgets::ListWidget * im_list = new MultiWidgets::ListWidget(parent());
      MultiWidgets::ListWidget * vi_list = new MultiWidgets::ListWidget(parent());
      MultiWidgets::ListWidget * at_list = new MultiWidgets::ListWidget(parent());

      if(Ath)
      {
          im_list->CSSBoxModel::setLocation(858,1284);
          im_list->CSSBoxModel::setSize(500,100);
      }
      else
      {
          im_list->CSSBoxModel::setLocation(808,1111);
          im_list->CSSBoxModel::setSize(600,100);
      }

      im_list->setColor("#4C4C4C");
      im_list->setOrientation(MultiWidgets::ListWidget::Orientation());
      parent()->addChild(im_list);


      if(Ath)
      {
          vi_list->CSSBoxModel::setLocation(935,1430);
          vi_list->CSSBoxModel::setSize(350,100);
      }
      else
      {
          vi_list->CSSBoxModel::setLocation(858,1266);
          vi_list->CSSBoxModel::setSize(500,100);
      }

      vi_list->setColor("#4C4C4C");
      vi_list->setOrientation(MultiWidgets::ListWidget::Orientation());
      parent()->addChild(vi_list);


      if(Ath)
      {
          at_list->CSSBoxModel::setLocation(860,1145);
          at_list->CSSBoxModel::setSize(900,100);
      }
      else
      {
          at_list->CSSBoxModel::setLocation(938,1430);
          at_list->CSSBoxModel::setSize(400,100);
      }

      at_list->setColor("#4C4C4C");
      at_list->setOrientation(MultiWidgets::ListWidget::Orientation());
      parent()->addChild(at_list);

      const char * dirpath =  "/images";
      const char * dirpathVid = "/videos";
      const char * dirpathArts = "/articles";

      char result1[40];
      char result2[40];
      char result3[40];
      sprintf(result1, "%s%s", path, "/images");
      sprintf(result2, "%s%s", path, "/videos");
      sprintf(result3, "%s%s", path, "/articles");

      dirpath = result1;
      dirpathVid = result2;
      dirpathArts = result3;

      // Open directories with images and videos:
      Radiant::Directory directory(dirpath, "dds,jpeg,jpg,png");
      Radiant::Directory directoryVid(dirpathVid, "dds,jpeg,jpg,png");
      Radiant::Directory directoryArts(dirpathArts, "dds,jpeg,jpg,png");

      // Create image widgets for each file in the directory
      for(int i = 0; i < directory.count(); i++) {

        MultiWidgets::ImageWidget * im = new MultiWidgets::ImageWidget(topParent());
        im->load(directory.fileNameWithPath(i));
        im->setHeight(50);
        im->eventAddListener("singletap", directory.fileNameWithPath(i).c_str(), im_receiver);
        im->setBorder(25);
        im->setBorderColor("#4C4C4C");
        im->resizeToFit(Nimble::Vector2(50,50));

        im_list->addItem(im);
      }

      // Create image widgets for each file in the directory
      for(int i = 0; i < directoryArts.count(); i++) {

        MultiWidgets::ImageWidget * at = new MultiWidgets::ImageWidget(topParent());
        at->load(directoryArts.fileNameWithPath(i));
        at->setHeight(50);
        at->eventAddListener("singletap", directoryArts.fileNameWithPath(i).c_str(), im_receiver);
        at->setBorder(25);
        at->setBorderColor("#4C4C4C");
        at->resizeToFit(Nimble::Vector2(50,50));

        at_list->addItem(at);
      }

      // Create image widgets for each file in the directory
      for(int i = 0; i < directoryVid.count(); i++) {

        MultiWidgets::ImageWidget * vi = new MultiWidgets::ImageWidget(topParent());
        vi->load(directoryVid.fileNameWithPath(i));
        vi->setBorder(25);
        vi->setBorderColor("#4C4C4C");
        vi->setHeight(50);
        vi->eventAddListener("singletap", directoryVid.fileNameWithPath(i).c_str(), vi_receiver);
        vi->resizeToFit(Nimble::Vector2(50,50));
        vi->setMomentum(momentumForAll);

        vi_list->addItem(vi);
      }
  }

  CUSTOM_WIDGET(CustomSliderWidget, "queue.customsliderwidget", "winkerVSbecks",
                "Custom Slider Widget", "NewBalance");
}
