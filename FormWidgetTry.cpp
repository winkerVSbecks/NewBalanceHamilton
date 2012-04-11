#include "FormWidgetTry.hpp"
#include "Global.hpp"
#include "ImageWithClose.hpp"

#include <MultiWidgets/ListWidget.hpp>
#include <MultiWidgets/ImageWidget.hpp>
#include <MultiWidgets/Plugins.hpp>
#include <MultiWidgets/TextEdit.hpp>
#include <MultiWidgets/TextBox.hpp>
#include <MultiWidgets/Keyboard.hpp>
#include <MultiWidgets/TimerDial.hpp>

#include <MultiWidgets/StayInsideParentOperator.hpp>

#include <string.h>
#include <Radiant/Directory.hpp>

#include <MultiTouch/MultiTouch.hpp>

#include <fstream>
#include <iostream>
using std::cerr;
using std::endl;

namespace CustomWidget
{
  FormWidgetTry::FormWidgetTry(MultiWidgets::Widget * parent)
      : Widget(parent)
  {
    m_nothingEmpty = false;
    m_accepted = false;
  }


  FormWidgetTry::~FormWidgetTry()
  {}

  void FormWidgetTry::setupTheFormWidgetTry(float x, float y)
  {

      bg =  new MultiWidgets::ImageWidget(parent());
      bg->load("forms/register/p_bg.png");
      bg->setSize(766,656);
      bg->setLocation(x-500, y-500);
      bg->setInputTransparent(true);
      bg->setDepth(4);
      //bg->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      bg->addOperator(new MultiWidgets::StayInsideParentOperator());
      bg->setInputFlags(MultiWidgets::Widget::INPUT_DEFAULT | MultiWidgets::Widget::INPUT_PASS_TO_CHILDREN);
      bg->setMomentum(momentumForAll);

//      timer = new MultiWidgets::TimerDial(bg, 60, 20);
//      timer->eventAddListener("timeout", "kill", this);
//      timer->hide();

      accept = new MultiWidgets::ImageWidget(bg);
      accept->load("forms/register/accept.png");
      accept->setSize(766,656);
      accept->setLocation(0,0);
      accept->setDepth(8);
      accept->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      accept->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      accept->eventAddListener("interactionbegin", "accepted", this);


      cust_name = new MultiWidgets::TextEdit(bg, "");
      cust_name->CSSBoxModel::setSize(320, 21);
      cust_name->setLocation(132+15,267+34);
      cust_name->setColor(255,255,255,255);
      cust_name->setInputFlags(MultiWidgets::Widget::INPUT_USE_SINGLE_TAPS);
      cust_name->setDepth(4);
      cust_name->setTextFlags(MultiWidgets::TextEdit::TEXT_NO_LINE_BREAKS);

      cust_add = new MultiWidgets::TextEdit(bg, "");
      cust_add->CSSBoxModel::setSize(305, 20);
      cust_add->setLocation(147+15, 303+34);
      cust_add->setColor(255,255,255,255);
      cust_add->setInputFlags(MultiWidgets::Widget::INPUT_USE_SINGLE_TAPS);
      cust_add->setDepth(4);
      cust_add->setTextFlags(MultiWidgets::TextEdit::TEXT_NO_LINE_BREAKS);

      cust_city = new MultiWidgets::TextEdit(bg, "");
      cust_city->CSSBoxModel::setSize(171, 20);
      cust_city->setLocation(147+15, 337+34);
      cust_city->setColor(255,255,255,255);
      cust_city->setInputFlags(MultiWidgets::Widget::INPUT_USE_SINGLE_TAPS);
      cust_city->setDepth(4);
      cust_city->setTextFlags(MultiWidgets::TextEdit::TEXT_NO_LINE_BREAKS);

      cust_prov = new MultiWidgets::TextEdit(bg, "");
      cust_prov->CSSBoxModel::setSize(54, 20);
      cust_prov->setLocation(398+15, 337+34);
      cust_prov->setColor(255,255,255,255);
      cust_prov->setInputFlags(MultiWidgets::Widget::INPUT_USE_SINGLE_TAPS);
      cust_prov->setDepth(4);
      cust_prov->setTextFlags(MultiWidgets::TextEdit::TEXT_NO_LINE_BREAKS);

      cust_em = new MultiWidgets::TextEdit(bg, "");
      cust_em->CSSBoxModel::setSize(252, 20);
      cust_em->setLocation(200+15, 374+34);
      cust_em->setColor(255,255,255,255);
      cust_em->setInputFlags(MultiWidgets::Widget::INPUT_USE_SINGLE_TAPS);
      cust_em->setDepth(4);
      cust_em->setTextFlags(MultiWidgets::TextEdit::TEXT_NO_LINE_BREAKS);
      cust_em->setFaceSize(12);

      cust_ph = new MultiWidgets::TextEdit(bg, "");
      cust_ph->CSSBoxModel::setSize(252, 20);
      cust_ph->setLocation(200+15, 411+34);
      cust_ph->setColor(255,255,255,255);
      cust_ph->setInputFlags(MultiWidgets::Widget::INPUT_USE_SINGLE_TAPS);
      cust_ph->setDepth(4);
      cust_ph->setTextFlags(MultiWidgets::TextEdit::TEXT_NO_LINE_BREAKS);

      skill_test = new MultiWidgets::TextEdit(bg, "");
      skill_test->CSSBoxModel::setSize(43, 20);
      skill_test->setLocation(398+62, 337+146);
      skill_test->setColor(255,255,255,255);
      skill_test->setInputFlags(MultiWidgets::Widget::INPUT_USE_SINGLE_TAPS);
      skill_test->setDepth(4);
      skill_test->setTextFlags(MultiWidgets::TextEdit::TEXT_NO_LINE_BREAKS);


      cust_name->eventAddListener("interactionbegin", "cust_name", this);
      cust_add->eventAddListener("interactionbegin", "cust_add", this);
      cust_city->eventAddListener("interactionbegin", "cust_city", this);
      cust_prov->eventAddListener("interactionbegin", "cust_prov", this);
      cust_em->eventAddListener("interactionbegin", "cust_em", this);
      cust_ph->eventAddListener("interactionbegin", "cust_ph", this);
      skill_test->eventAddListener("interactionbegin", "skill_test", this);



      MultiWidgets::ImageWidget * saver = new MultiWidgets::ImageWidget(bg);
      saver->load("forms/purchase/submit.png");
      saver->setSize(139,81);
      saver->setLocation(511,528);
      saver->setDepth(7);
      saver->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      saver->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      saver->eventAddListener("interactionbegin", "save", this);

      MultiWidgets::ImageWidget * rules = new MultiWidgets::ImageWidget(bg);
      rules->load("forms/register/rules.png");
      rules->setSize(141,80);
      rules->setLocation(111,527);
      rules->setDepth(7);
      rules->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      rules->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      rules->eventAddListener("interactionbegin", "rules", this);

      close = new MultiWidgets::ImageWidget(bg);
      close->setAutoBringToTop(true);
      close->setDepth(100);
      close->setInputFlags(MultiWidgets::Widget::INPUT_USE_SINGLE_TAPS);
      close->load("shoeWidget/closeIM.png");
      close->setLocation(bg->width()-130,90);
      close->setSize(80,80);
      close->eventAddListener("interactionbegin", "kill", this);


      t860 = new MultiWidgets::ImageWidget(bg);
      t860->load("forms/register/860.png");
      t860->setSize(766,656);
      t860->setLocation(0,0);
      t860->setDepth(5);
      t860->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      t860->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      t860->eventAddListener("interactionbegin", "860", this);

      t890 = new MultiWidgets::ImageWidget(bg);
      t890->load("forms/register/890.png");
      t890->setSize(766,656);
      t890->setLocation(0,0);
      t890->setDepth(5);
      t890->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      t890->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      t890->eventAddListener("interactionbegin", "890", this);


      t890_2 = new MultiWidgets::ImageWidget(bg);
      t890_2->load("forms/register/890_2.png");
      t890_2->setSize(766,656);
      t890_2->setLocation(0,0);
      t890_2->setDepth(5);
      t890_2->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      t890_2->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      t890_2->eventAddListener("interactionbegin", "890_2", this);

      t940 = new MultiWidgets::ImageWidget(bg);
      t940->load("forms/register/940.png");
      t940->setSize(766,656);
      t940->setLocation(0,0);
      t940->setDepth(5);
      t940->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      t940->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      t940->eventAddListener("interactionbegin", "940", this);

      t1080 = new MultiWidgets::ImageWidget(bg);
      t1080->load("forms/register/1080.png");
      t1080->setSize(766,656);
      t1080->setLocation(0,0);
      t1080->setDepth(5);
      t1080->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      t1080->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      t1080->eventAddListener("interactionbegin", "1080", this);

      t1400 = new MultiWidgets::ImageWidget(bg);
      t1400->load("forms/register/1400.png");
      t1400->setSize(766,656);
      t1400->setLocation(0,0);
      t1400->setDepth(5);
      t1400->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      t1400->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      t1400->eventAddListener("interactionbegin", "1400", this);

      troad = new MultiWidgets::ImageWidget(bg);
      troad->load("forms/register/road.png");
      troad->setSize(766,656);
      troad->setLocation(0,0);
      troad->setDepth(5);
      troad->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      troad->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      troad->eventAddListener("interactionbegin", "road", this);

      ttrail = new MultiWidgets::ImageWidget(bg);
      ttrail->load("forms/register/trail.png");
      ttrail->setSize(766,656);
      ttrail->setLocation(0,0);
      ttrail->setDepth(5);
      ttrail->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      ttrail->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      ttrail->eventAddListener("interactionbegin", "trail", this);

      tother = new MultiWidgets::ImageWidget(bg);
      tother->load("forms/register/other.png");
      tother->setSize(766,656);
      tother->setLocation(0,0);
      tother->setDepth(5);
      tother->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      tother->setInputFlags(MultiWidgets::Widget::INPUT_USE_TAPS);
      tother->eventAddListener("interactionbegin", "other", this);

      selected = new MultiWidgets::ImageWidget(bg);
      selected->load("forms/register/null.png");
      selected->setSize(766,656);
      selected->setLocation(0,0);
      selected->setDepth(6);
      selected->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
      selected->setInputFlags(MultiWidgets::Widget::INPUT_NONE);
  }

  void FormWidgetTry::input(MultiWidgets::GrabManager & gm, float dt)
 {
   Widget::input(gm, dt);
   MultiTouch::Sample m_sample = gm.sample();

//   if(bg->grabFingerCount())
//   {
//       timer->resetIdleTime();
//   }
 }


  void FormWidgetTry::processMessage(const char * id, Radiant::BinaryData & data)
  {
      std::wstring ws1 = cust_name->text();
      std::string cn(ws1.begin(), ws1.end());

      std::wstring ws2 = cust_add->text();
      std::string ca(ws2.begin(), ws2.end());

      std::wstring ws3 = cust_city->text();
      std::string cc(ws3.begin(), ws3.end());

      std::wstring ws4 = cust_prov->text();
      std::string cp(ws4.begin(), ws4.end());

      std::wstring ws5 = cust_em->text();
      std::string em(ws5.begin(), ws5.end());

      std::wstring ws6 = cust_ph->text();
      std::string ph(ws6.begin(), ws6.end());

      std::wstring ws7 = skill_test->text();
      std::string st(ws7.begin(), ws7.end());

      if(   strcmp(cn.c_str(), "") == 0 || strcmp(cn.c_str(), " ") == 0
                    || strcmp(em.c_str(), "") == 0 || strcmp(em.c_str(), " ") == 0
                        || strcmp(ph.c_str(), "") == 0 || strcmp(ph.c_str(), " ") == 0
                            || strcmp(st.c_str(), "") == 0 || strcmp(st.c_str(), " ") == 0
                                || strcmp(shoeType.c_str(), "") == 0 || strcmp(shoeType.c_str(), " ") == 0
                                    || !m_accepted)
      {
          m_nothingEmpty = false;
      }
      else
      {
          m_nothingEmpty = true;
      }


      if(strcmp(id, "kill") == 0)
      {
          for (ChildIterator it = childBegin(); it != childEnd(); ++it) {
            it->raiseFlag(DELETE_ME);
          }

          bg->raiseFlag(DELETE_ME);
          raiseFlag(DELETE_ME);
          noActiveWidgets--;
      }


        if(strcmp(id, "save") == 0 && m_nothingEmpty)
        {
            FILE * CustomerData = fopen("customerData/customerDataTry.txt", "a");
            fprintf(CustomerData, "%s\n", cn.c_str());
            fprintf(CustomerData, "%s\n", ca.c_str());
            fprintf(CustomerData, "%s\n", cc.c_str());
            fprintf(CustomerData, "%s\n", cp.c_str());
            fprintf(CustomerData, "%s\n", em.c_str());
            fprintf(CustomerData, "%s\n", ph.c_str());
            fprintf(CustomerData, "%s\n", st.c_str());
            fprintf(CustomerData, "%s\n\n", shoeType.c_str());
            fclose(CustomerData);

//            FILE * CustomerData = fopen("customerData/customerDataTry.txt", "a");
//            fprintf(CustomerData, "Customer Name: %s\n", cn.c_str());
//            fprintf(CustomerData, "Customer Address: %s\n", ca.c_str());
//            fprintf(CustomerData, "City: %s\n", cc.c_str());
//            fprintf(CustomerData, "Province: %s\n", cp.c_str());
//            fprintf(CustomerData, "Customer Email: %s\n", em.c_str());
//            fprintf(CustomerData, "Customer Phone Number: %s\n", ph.c_str());
//            fprintf(CustomerData, "Skill Test Answer: %s\n", st.c_str());
//            fprintf(CustomerData, "Shoe Type: %s\n\n", shoeType.c_str());
//            fclose(CustomerData);

            CustomWidget::ImageWithClose * im = new CustomWidget::ImageWithClose(parent());
            float x1 = bg->location().x+bg->width()/2*cos(bg->rotation());
            float y1 = bg->location().y+bg->height()/2*cos(bg->rotation());
            im->setupTheImageWithClose("shoeWidget/thankYou.png", x1, y1, 0, 250,250);
            im->hide();
//            timer = new MultiWidgets::TimerDial(parent(), 60, 20);
//            timer->eventAddListener("timeout", "close", im);
//            timer->hide();

            for (ChildIterator it = childBegin(); it != childEnd(); ++it) {
              it->raiseFlag(DELETE_ME);
            }

            bg->raiseFlag(DELETE_ME);
            noActiveWidgets--;
        }

        if(strcmp(id, "save") == 0 && !m_nothingEmpty)
        {
            MultiWidgets::TextBox * warning = new MultiWidgets::TextBox(bg, "Please fully complete the form before submitting. Thank You.",
                                                                            MultiWidgets::TextBox::HCENTER);
            warning->CSSBoxModel::setLocation(60,255);
            warning->CSSBoxModel::setSize(650,16);
            warning->CSSBoxModel::setColor(255,0,0,255);
            warning->setDepth(5);
            warning->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);
            warning->setInputFlags(MultiWidgets::Widget::INPUT_NONE);
        }

        if(strcmp(id, "rules") == 0)
        {
            CustomWidget::ImageWithClose * rules1 = new CustomWidget::ImageWithClose(parent());
            rules1->setupTheImageWithClose("forms/rules.png",
                                           bg->location().x,bg->location().y, bg->rotation(), 550, 550);
            rules1->hide();
        }

        if(strcmp(id, "accepted") == 0)
        {
            m_accepted = !m_accepted;

            if(m_accepted)
            {
              accept->load("forms/register/accept2.png");
            }
            if(!m_accepted)
            {
                accept->load("forms/register/accept.png");
            }
        }

        if(strcmp(id, "cust_name") == 0)
        {
            cust_add->hideKeyboard();
            cust_city->hideKeyboard();
            cust_prov->hideKeyboard();
            cust_em->hideKeyboard();
            cust_ph->hideKeyboard();
            skill_test->hideKeyboard();
        }

        if(strcmp(id, "cust_add") == 0)
        {
            cust_name->hideKeyboard();
            cust_city->hideKeyboard();
            cust_prov->hideKeyboard();
            cust_em->hideKeyboard();
            cust_ph->hideKeyboard();
            skill_test->hideKeyboard();
        }

        if(strcmp(id, "cust_city") == 0)
        {
            cust_name->hideKeyboard();
            cust_add->hideKeyboard();
            cust_prov->hideKeyboard();
            cust_em->hideKeyboard();
            cust_ph->hideKeyboard();
            skill_test->hideKeyboard();
        }

        if(strcmp(id, "cust_prov") == 0)
        {
            cust_name->hideKeyboard();
            cust_add->hideKeyboard();
            cust_city->hideKeyboard();
            cust_em->hideKeyboard();
            cust_ph->hideKeyboard();
        }

        if(strcmp(id, "cust_em") == 0)
        {
            cust_name->hideKeyboard();
            cust_add->hideKeyboard();
            cust_city->hideKeyboard();
            cust_prov->hideKeyboard();
            cust_ph->hideKeyboard();
            skill_test->hideKeyboard();
        }

        if(strcmp(id, "cust_ph") == 0)
        {
            cust_name->hideKeyboard();
            cust_add->hideKeyboard();
            cust_city->hideKeyboard();
            cust_prov->hideKeyboard();
            cust_em->hideKeyboard();
            skill_test->hideKeyboard();
        }

        if(strcmp(id, "skill_test") == 0)
        {
            cust_name->hideKeyboard();
            cust_add->hideKeyboard();
            cust_city->hideKeyboard();
            cust_prov->hideKeyboard();
            cust_em->hideKeyboard();
            cust_ph->hideKeyboard();
        }


        if(strcmp(id, "860") == 0)
        {
            std::string p = id;
            shoeType = p;
            p.append(".png");
            p = "forms/register/a"+p;
            selected->load(p);
        }
        if(strcmp(id, "890") == 0)
        {
            std::string p = id;
            shoeType = p;
            p.append(".png");
            p = "forms/register/a"+p;
            selected->load(p);
        }
        if(strcmp(id, "890_2") == 0)
        {
            std::string p = id;
            shoeType = p;
            p.append(".png");
            p = "forms/register/a"+p;
            selected->load(p);
        }
        if(strcmp(id, "940") == 0)
        {
            std::string p = id;
            shoeType = p;
            p.append(".png");
            p = "forms/register/a"+p;
            selected->load(p);
        }
        if(strcmp(id, "1080") == 0)
        {
            std::string p = id;
            shoeType = p;
            p.append(".png");
            p = "forms/register/a"+p;
            selected->load(p);
        }
        if(strcmp(id, "1400") == 0)
        {
            std::string p = id;
            shoeType = p;
            p.append(".png");
            p = "forms/register/a"+p;
            selected->load(p);
        }
        if(strcmp(id, "road") == 0)
        {
            std::string p = id;
            shoeType = p;
            p.append(".png");
            p = "forms/register/a"+p;
            selected->load(p);
        }
        if(strcmp(id, "trail") == 0)
        {
            std::string p = id;
            shoeType = p;
            p.append(".png");
            p = "forms/register/a"+p;
            selected->load(p);
        }
        if(strcmp(id, "other") == 0)
        {
            std::string p = id;
            shoeType = p;
            p.append(".png");
            p = "forms/register/a"+p;
            selected->load(p);
        }
  }


  CUSTOM_WIDGET(FormWidgetTry, "queue.formwidgettry", "winkerVSbecks",
                "Form Widget Try", "NewBalance");
}
