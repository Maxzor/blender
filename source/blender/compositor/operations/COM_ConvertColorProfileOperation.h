/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Copyright 2011, Blender Foundation.
 */

#pragma once

#include "COM_NodeOperation.h"

namespace blender::compositor {

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class ConvertColorProfileOperation : public NodeOperation {
 private:
  /**
   * Cached reference to the input_program
   */
  SocketReader *input_operation_;

  /**
   * \brief color profile where to convert from
   */
  int from_profile_;

  /**
   * \brief color profile where to convert to
   */
  int to_profile_;

  /**
   * \brief is color predivided
   */
  bool predivided_;

 public:
  /**
   * Default constructor
   */
  ConvertColorProfileOperation();

  /**
   * The inner loop of this operation.
   */
  void execute_pixel_sampled(float output[4], float x, float y, PixelSampler sampler) override;

  /**
   * Initialize the execution
   */
  void init_execution() override;

  /**
   * Deinitialize the execution
   */
  void deinit_execution() override;

  void set_from_color_profile(int color_profile)
  {
    from_profile_ = color_profile;
  }
  void set_to_color_profile(int color_profile)
  {
    to_profile_ = color_profile;
  }
  void set_predivided(bool predivided)
  {
    predivided_ = predivided;
  }
};

}  // namespace blender::compositor
