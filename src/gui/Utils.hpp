/*
 * Copyright (C) 2018-2025 Werner Turing <werner.turing@protonmail.com>
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
#ifndef MDL_UTILS_H
#define MDL_UTILS_H

#include <string>

#include <gtkmm.h>


namespace mdl {
  bool file_exists(const std::string& file);

  bool confirmation_dialog(const Glib::ustring& msg,
                           const Glib::ustring& txt_destructive,
                           const Glib::ustring& txt_safe);
  bool confirmation_dialog(Gtk::Window& parent,
                           const Glib::ustring& msg,
                           const Glib::ustring& txt_destructive,
                           const Glib::ustring& txt_safe);

  std::string format_time(long ms);
  std::string format_time_with_hour(long ms);
  std::string format_time_based_on_total(long ms, long total_ms);
}

#endif // MDL_UTILS_H
