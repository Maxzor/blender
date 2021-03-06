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
 */

#include "FN_generic_virtual_vector_array.hh"

namespace blender::fn {

void GVArray_For_GVVectorArrayIndex::get(const int64_t index_in_vector, void *r_value) const
{
  vector_array_.get_vector_element(index_, index_in_vector, r_value);
}

void GVArray_For_GVVectorArrayIndex::get_to_uninitialized(const int64_t index_in_vector,
                                                          void *r_value) const
{
  type_->default_construct(r_value);
  vector_array_.get_vector_element(index_, index_in_vector, r_value);
}

int64_t GVVectorArray_For_SingleGVArray::get_vector_size_impl(const int64_t UNUSED(index)) const
{
  return varray_.size();
}

void GVVectorArray_For_SingleGVArray::get_vector_element_impl(const int64_t UNUSED(index),
                                                              const int64_t index_in_vector,
                                                              void *r_value) const
{
  varray_.get(index_in_vector, r_value);
}

bool GVVectorArray_For_SingleGVArray::is_single_vector_impl() const
{
  return true;
}

int64_t GVVectorArray_For_SingleGSpan::get_vector_size_impl(const int64_t UNUSED(index)) const
{
  return span_.size();
}

void GVVectorArray_For_SingleGSpan::get_vector_element_impl(const int64_t UNUSED(index),
                                                            const int64_t index_in_vector,
                                                            void *r_value) const
{
  type_->copy_assign(span_[index_in_vector], r_value);
}

bool GVVectorArray_For_SingleGSpan::is_single_vector_impl() const
{
  return true;
}

}  // namespace blender::fn
