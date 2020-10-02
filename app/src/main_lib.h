#pragma once

#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <sstream>

#include <gtkmm.h>

#include <tag.h>
#include <tagutils.h>
#include <tagunion.h>
#include <fileref.h>
#include <taglib_export.h>
#include <audioproperties.h>

#include <sys/stat.h>
#include <dirent.h>

class New_Window : public Gtk::Window {
    public:
        New_Window(std::string title);
        ~New_Window();
        Gtk::Button m_button{"SAVE"};
        Gtk::Entry  m_artist;
        Gtk::Entry  m_title;
        Gtk::Entry  m_album;
        Gtk::Entry  m_genre;
        Gtk::Label  m_path;
    private:
        Gtk::Box    m_box;
        Gtk::Label  m_artist_l{"Artist"};
        Gtk::Label  m_title_l{"Title"};
        Gtk::Label  m_album_l{"Album"};
        Gtk::Label  m_genre_l{"Genre"};
};

class MyListRow : public Gtk::ListBoxRow {
public:
    MyListRow(const std::string text) : m_label{text} {
        add(m_label);
        set_halign(Gtk::Align::ALIGN_START);
        show_all_children();
    }
    Gtk::Label m_label;
};

class ListBoxScroll : public Gtk::ScrolledWindow {
    public:
        ListBoxScroll();
        void api_AddRow(std::string text);
        void api_Clear();
        void print_tags();
        void window_4_tag();
        void aboutWinClose();
        void on_click_button_save();
        std::string m_dirname;
        std::string m_filename;
        Glib::ustring m_us;
        int m_i;

    protected:
        Gtk::Box               m_hbox {Gtk::ORIENTATION_HORIZONTAL};
        Gtk::ListBox           m_listbox;

        void sig_row_selected(Gtk::ListBoxRow* listboxrow);
        New_Window* m_new_w;
};

class All : public Gtk::Window {
    public:
        All(int argc, char **argv);
        ~All();
        void create_main_window();
        void main_window();
        void work_with_dir();
        void on_button_folder_clicked();
        void show_warning(Glib::ustring text);

        void aboutWinClose();
        void onButtonClicked();
        void ifToggled_asc();
        void ifToggled_des();

        void print_files();
    private:
        std::string m_dirname;

        Gtk::Box m_box;
        Gtk::Box m_box_1;
        Gtk::Box m_upbox;
        Gtk::Button m_Button_Folder{"Choose Folder"};
        Gtk::RadioButton m_sort_des{"Descending sort"};
        Gtk::RadioButton m_sort_asc{"Ascending sort"};
        Gtk::Label m_label;
        ListBoxScroll m_list; //лист бокс для списка друзей
        std::vector<std::string> m_vitya;
    public:
        int m_argc;
        char **m_argv;
        int err;
};
