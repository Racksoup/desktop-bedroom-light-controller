#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/scale.h>
#include <gtkmm/label.h>
#include <gtkmm/grid.h>

class UI {
	public:
		UI();
		virtual ~UI();

		Gtk::Box m_box;

	protected:
		void slider_clicked(Gtk::Scale& slider, const std::string& option);
		void color_clicked(int color);
		void bri_clicked(const std::string& bri);
		void on_clicked();
		void off_clicked();

		Gtk::Label m_labelBri, m_labelHue, m_labelSat;
		Gtk::Scale m_slidBri, m_slidHue, m_slidSat;
		Gtk::Grid m_grid, m_grid1;
		Gtk::Box m_box1;
		std::array<Gtk::Button, 12> m_btnsColors;
		std::array<Gtk::Button, 4> m_btnsBri;
		Gtk::Button m_btnOn, m_btnOff;
};
