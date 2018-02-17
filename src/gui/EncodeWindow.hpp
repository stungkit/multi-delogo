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
#ifndef MDL_ENCODE_WINDOW_H
#define MDL_ENCODE_WINDOW_H

#include <memory>

#include <gtkmm.h>

#include "filter-generator/FilterData.hpp"


namespace mdl {
  class EncodeWindow : public Gtk::ApplicationWindow
  {
  public:
    EncodeWindow(std::unique_ptr<fg::FilterData> filter_data);

  private:
    std::unique_ptr<fg::FilterData> filter_data_;

    Gtk::Entry txt_file_;

    Gtk::Box* create_file_selection();

    void on_select_file();
  };
}

#endif // MDL_ENCODE_WINDOW_H
