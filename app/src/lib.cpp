#include "main_lib.h"

All::All(int argc, char **argv) : m_argc(argc), m_argv(argv) {
    set_border_width(10);
    set_default_size(400, 400);
    set_title("utag");
    set_position(Gtk::WIN_POS_CENTER);
    create_main_window();
}

All::~All() {
    m_vitya.clear();
}

void All::show_warning(Glib::ustring text) {
    Gtk::MessageDialog dialog(*this, "WARNING");
    dialog.set_secondary_text(text);
    dialog.set_position(Gtk::WIN_POS_CENTER);
    dialog.activate_focus();
    dialog.run();
}

void All::work_with_dir() {
    DIR *directory = opendir(m_dirname.c_str());

    if (directory) {
        struct dirent *lupa = NULL;

        m_vitya.clear();
        while ((lupa = readdir(directory)) != NULL) {
            std::string buff = lupa->d_name;
            std::string right_name = m_dirname + "/" + buff;

            buff = &buff[buff.find_last_of(".") + 1];
            if (buff != "." && buff != "..") {
                if ("mp3" == buff) {
                    m_vitya.push_back(lupa->d_name);
                }
                // else if ("ogg" == buff) {
                //     std::cout << "ogg\n";
                // }
                // else if ("wav" == buff) {
                //     std::cout << "wav\n";
                // }
                // else if ("flac" == buff) {
                //     std::cout << "flac\n";
                // }
            }
        }
        closedir(directory);
        std::sort (m_vitya.begin(), m_vitya.end());
        print_files();/////////////////
    }
    else
        show_warning("ERROR WITH DIRECTORY");
}

void All::main_window() {    
    add(m_box);
    m_box.set_orientation(Gtk::ORIENTATION_VERTICAL);
    m_box.pack_start(m_upbox, false, false, 5);
    m_box.pack_start(m_list, true, true, 5);
    m_list.set_size_request(400);

    m_label.set_text("Set directory");
    m_upbox.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    m_upbox.pack_start(m_label, true, true, 10);
    m_upbox.pack_start(m_Button_Folder, true, true, 10);
    m_upbox.pack_start(m_box_1, true, true, 10);

    m_sort_des.join_group(m_sort_asc);
    m_box_1.set_orientation(Gtk::ORIENTATION_VERTICAL);
    m_box_1.pack_start(m_sort_asc, true, true, 2);
    m_box_1.pack_start(m_sort_des, true, true, 2);

    show_all_children();
    if (!m_dirname.empty())
        work_with_dir();
    m_sort_des.signal_toggled().connect( sigc::mem_fun(*this, &All::ifToggled_des));
    m_sort_asc.signal_toggled().connect( sigc::mem_fun(*this, &All::ifToggled_asc));
    m_Button_Folder.signal_clicked().connect( sigc::mem_fun(*this, &All::on_button_folder_clicked));
}

void All::on_button_folder_clicked() {
    Gtk::FileChooserDialog dialog("Please choose a folder",
            Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
    dialog.set_transient_for(*this);
    
    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("Select", Gtk::RESPONSE_OK);
    
    int result = dialog.run();
    
    //Handle the response:
    switch(result) {
        case(Gtk::RESPONSE_OK): {
            std::cout << "Folder selected: " << dialog.get_filename() << std::endl;
            m_list.api_Clear();
            m_dirname = dialog.get_filename();
            m_list.m_dirname = m_dirname;

            work_with_dir();
            break;
        }
        case(Gtk::RESPONSE_CANCEL): {
            //std::cout << "Cancel clicked";
            break;
        }
        default: {
            //std::cout << "Unexpected button clicked";
            break;
        }
    }
}

void All::ifToggled_asc() {
    m_list.api_Clear();
    std::sort (m_vitya.begin(), m_vitya.end());
    print_files();
}

void All::ifToggled_des() {
    m_list.api_Clear();
    for(auto r1_iter = m_vitya.begin(); r1_iter != m_vitya.end() - 1; r1_iter++)
        for(auto r_iter = m_vitya.begin(); r_iter != m_vitya.end() - 1; r_iter++)
            if (*r_iter <= *(r_iter + 1))
                std::swap(*r_iter, *(r_iter + 1));
    print_files();
}

void All::print_files() {
    for(const std::string& lol : m_vitya)
        m_list.api_AddRow(lol);
}


void All::create_main_window() {
    if (m_argc == 2) {
    	m_dirname = m_argv[1];
        m_list.m_dirname = m_dirname;
        main_window();
    }
    else if (m_argc == 1)
        main_window();
    else {
        show_warning("usage ./utag [dir_name]");
        exit(0);
    }
}