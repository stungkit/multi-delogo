/*
 * Copyright (C) 2018 Werner Turing <werner.turing@protonmail.com>
 *
 * This file is part of multi-delogo.
 *
 * multi-delogo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * multi-delogo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with multi-delogo.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MDL_MULTI_DELOGO_APP_H
#define MDL_MULTI_DELOGO_APP_H

#include <gtkmm.h>

#include <boost/optional.hpp>

#include "filter-generator/FilterData.hpp"


namespace mdl {
  typedef boost::optional<Glib::RefPtr<Gio::File>> maybe_file;

  class MultiDelogoApp : public Gtk::Application
  {
  protected:
    MultiDelogoApp();

  public:
    static Glib::RefPtr<MultiDelogoApp> create();

    void save_project(const std::string& project_file, fg::FilterData* filter_data);

    const static std::string ACTION_NEW;
    const static std::string ACTION_OPEN;

  protected:
    void on_activate();
    void on_open(const Gio::Application::type_vec_files& files,
                 const Glib::ustring& hint);

  private:
    const static std::string EXTENSION_;

    Gtk::ApplicationWindow* initial_window_;

    void create_movie_window(const Glib::RefPtr<Gio::File>& file);
    void register_window(Gtk::ApplicationWindow* window);

    void new_project();
    void open_project();
    bool select_new_movie_file_if_necessary(fg::FilterData& filter_data);

    maybe_file select_movie_file();
    maybe_file select_project_file();
    maybe_file select_file_for_open(const std::string& title,
                                    const Glib::RefPtr<Gtk::FileFilter>& filter);

    void on_hide_window(Gtk::ApplicationWindow* window);
  };
}

#endif // MDL_MULTI_DELOGO_APP_H