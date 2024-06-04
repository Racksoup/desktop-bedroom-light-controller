#include "UI.h"
#include <iostream>

UI::UI() :
	m_box(Gtk::Orientation::VERTICAL),
	m_slidBri(Gtk::Orientation::HORIZONTAL),
	m_slidHue(Gtk::Orientation::HORIZONTAL),
	m_slidSat(Gtk::Orientation::HORIZONTAL),
	m_btnsColors{      
		Gtk::Button("Red"), Gtk::Button("Green"), Gtk::Button("Blue"),
		Gtk::Button("Yellow"), Gtk::Button("Orange"), Gtk::Button("Purple"),
		Gtk::Button("Pink"), Gtk::Button("Cyan"), Gtk::Button("Magenta"),
		Gtk::Button("Lime"), Gtk::Button("Teal"), Gtk::Button("Brown")
	},
	m_btnsBri{
		Gtk::Button("Bright"),Gtk::Button("High"), Gtk::Button("Medium"), Gtk::Button("Low")  
	},
	m_btnOn("On"),
	m_btnOff("Off")
{
	m_box.append(m_slidBri);
	m_box.append(m_slidHue);
	m_box.append(m_slidSat);

	m_slidBri.signal_value_changed().connect( sigc::mem_fun(*this, &UI::slider_clicked) );

	std::cout << "UI Plugged In!" << std::endl;
}

UI::~UI() 
{
}

void UI::slider_clicked()
{
	std::cout << m_slidBri.get_value() << std::endl;
}
