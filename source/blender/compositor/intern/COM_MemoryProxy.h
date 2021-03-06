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

#ifdef WITH_CXX_GUARDEDALLOC
#  include "MEM_guardedalloc.h"
#endif

#include "COM_defines.h"

namespace blender::compositor {

/* Forward declarations. */
class MemoryBuffer;
class ExecutionGroup;
class WriteBufferOperation;

/**
 * \brief A MemoryProxy is a unique identifier for a memory buffer.
 * A single MemoryProxy is used among all chunks of the same buffer,
 * the MemoryBuffer only stores the data of a single chunk.
 * \ingroup Memory
 */
class MemoryProxy {
 private:
  /**
   * \brief reference to the output operation of the executiongroup
   */
  WriteBufferOperation *write_buffer_operation_;

  /**
   * \brief reference to the executor. the Execution group that can fill a chunk
   */
  ExecutionGroup *executor_;

  /**
   * \brief the allocated memory
   */
  MemoryBuffer *buffer_;

  /**
   * \brief datatype of this MemoryProxy
   */
  DataType datatype_;

 public:
  MemoryProxy(DataType type);

  /**
   * \brief set the ExecutionGroup that can be scheduled to calculate a certain chunk.
   * \param group: the ExecutionGroup to set
   */
  void set_executor(ExecutionGroup *executor)
  {
    executor_ = executor;
  }

  /**
   * \brief get the ExecutionGroup that can be scheduled to calculate a certain chunk.
   */
  ExecutionGroup *get_executor() const
  {
    return executor_;
  }

  /**
   * \brief set the WriteBufferOperation that is responsible for writing to this MemoryProxy
   * \param operation:
   */
  void set_write_buffer_operation(WriteBufferOperation *operation)
  {
    write_buffer_operation_ = operation;
  }

  /**
   * \brief get the WriteBufferOperation that is responsible for writing to this MemoryProxy
   * \return WriteBufferOperation
   */
  WriteBufferOperation *get_write_buffer_operation() const
  {
    return write_buffer_operation_;
  }

  /**
   * \brief allocate memory of size width x height
   */
  void allocate(unsigned int width, unsigned int height);

  /**
   * \brief free the allocated memory
   */
  void free();

  /**
   * \brief get the allocated memory
   */
  inline MemoryBuffer *get_buffer()
  {
    return buffer_;
  }

  inline DataType get_data_type()
  {
    return datatype_;
  }

#ifdef WITH_CXX_GUARDEDALLOC
  MEM_CXX_CLASS_ALLOC_FUNCS("COM:MemoryProxy")
#endif
};

}  // namespace blender::compositor
