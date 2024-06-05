#include "UI.h"
#include <iostream>

UI::UI() :
 m_box(Gtk::Orientation::VERTICAL),
  m_box1(Gtk::Orientation::HORIZONTAL),
  m_labelBri("Brightness"),
  m_labelHue("Color"),
  m_labelSat("Saturation"),
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
	m_slidBri.set_range(0, 255);
	m_slidBri.set_value(0);
	m_slidBri.signal_value_changed().connect( [this] { this->slider_clicked(m_slidBri); } );
	m_slidSat.set_range(0, 255);
	m_slidSat.set_value(0);
	m_slidSat.signal_value_changed().connect( [this] { this->slider_clicked(m_slidSat); } );
	m_slidHue.set_range(0, 255);
	m_slidHue.set_value(0);
	m_slidHue.signal_value_changed().connect( [this] { this->slider_clicked(m_slidHue); } );

	int colors[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	m_grid.set_row_spacing(20); // Set spacing between rows
	m_grid.set_column_spacing(20); // Set spacing between columns
	m_grid.set_row_homogeneous(true); // Set rows to be homogeneous
	m_grid.set_column_homogeneous(true); // Set columns to be homogeneous

	for (size_t i = 0; i < m_btnsColors.size(); ++i) {
		m_btnsColors[i].signal_clicked().connect([this, colors, i] { this->color_clicked(colors[i]); });
		m_grid.attach(m_btnsColors[i], (i % 4) + 1, (i / 4) + 1, 1, 1);
	}

	m_grid1.set_row_spacing(5); // Set spacing between rows
	m_grid1.set_column_spacing(5); // Set spacing between columns
	m_grid1.set_row_homogeneous(true); // Set rows to be homogeneous
	m_grid1.set_column_homogeneous(true); // Set columns to be homogeneous

	for (size_t i = 0; i < m_btnsBri.size(); ++i) {
		m_btnsBri[i].signal_clicked().connect([this, i] { this->bri_clicked(i); });
		m_grid1.attach(m_btnsBri[i], (i % 4) + 1, (i / 4) + 1, 1, 1);
	}

	m_btnOn.signal_clicked().connect([this] { this->on_clicked(); });
	m_box1.append(m_btnOn);
	m_btnOff.signal_clicked().connect([this] { this->off_clicked(); });
	m_box1.append(m_btnOff);

	m_box.append(m_labelBri);
	m_box.append(m_slidBri);
	m_box.append(m_labelHue);
	m_box.append(m_slidHue);
	m_box.append(m_labelSat);
	m_box.append(m_slidSat);
	m_box.append(m_grid);
	m_box.append(m_grid1);
	m_box.append(m_box1);
}

UI::~UI() 
{
}

void UI::slider_clicked(Gtk::Scale& slider)
{
	std::cout << slider.get_value() << std::endl;
}

void UI::color_clicked(int color)
{
	std::cout << color << std::endl;
}

void UI::bri_clicked(size_t i)
{
	std::cout << i << std::endl;
}

void UI::on_clicked()
{
	std::cout << "on" << std::endl;
}

void UI::off_clicked()
{
	std::cout << "off" << std::endl;
}
