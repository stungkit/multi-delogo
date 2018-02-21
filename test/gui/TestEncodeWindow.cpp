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
#include <memory>
#include <string>
#include <vector>

#include <gtkmm.h>

#include "filter-generator/FilterData.hpp"

#include "EncodeWindow.hpp"

using namespace mdl;


#define BOOST_TEST_MODULE encode window
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "../TestHelpers.hpp"


class GtkInitialization
{
public:
  GtkInitialization()
  {
    Gtk::Main();
  }
};
BOOST_GLOBAL_FIXTURE(GtkInitialization);


namespace mdl {
class EncodeWindowTestFixture
{
public:
  EncodeWindowTestFixture()
    : window(std::move(std::unique_ptr<fg::FilterData>(new fg::FilterData())))
  {
    window.filter_data_->set_movie_file("input.mp4");
    window.txt_file_.set_text("output.mp4");
  }

  void set_codec_h264()
  {
    window.codec_ = EncodeWindow::Codec::H264;
  }

  void set_codec_h265()
  {
    window.codec_ = EncodeWindow::Codec::H265;
  }

  void set_quality(int quality)
  {
    window.txt_quality_.set_value(quality);
  }

  std::vector<std::string> get_ffmpeg_cmd_line()
  {
    return window.get_ffmpeg_cmd_line("filters.ffm");
  }

  EncodeWindow window;
};
}
BOOST_FIXTURE_TEST_SUITE(encode_window, mdl::EncodeWindowTestFixture)


BOOST_AUTO_TEST_CASE(test_ffmpeg_command_line_h264)
{
  set_codec_h264();
  set_quality(20);

  std::vector<std::string> expected{
    "ffmpeg",
    "-y", "-v", "quiet", "-stats",
    "-i", "input.mp4",
    "-filter_script:v", "filters.ffm",
    "-c:v", "libx264", "-crf", "20",
    "-c:a", "copy",
    "output.mp4"};
  BOOST_TEST(get_ffmpeg_cmd_line() == expected,
             boost::test_tools::per_element());
}


BOOST_AUTO_TEST_CASE(test_ffmpeg_command_line_h265)
{
  set_codec_h265();
  set_quality(25);

  std::vector<std::string> expected{
    "ffmpeg",
    "-y", "-v", "quiet", "-stats",
    "-i", "input.mp4",
    "-filter_script:v", "filters.ffm",
    "-c:v", "libx265", "-crf", "25",
    "-c:a", "copy",
    "output.mp4"};
  BOOST_TEST(get_ffmpeg_cmd_line() == expected,
             boost::test_tools::per_element());
}

BOOST_AUTO_TEST_SUITE_END()