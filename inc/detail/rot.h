/*----------------------------------------------------------------------------
 * Copyright � Microsoft Corp.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not 
 * use this file except in compliance with the License.  You may obtain a copy 
 * of the License at http://www.apache.org/licenses/LICENSE-2.0  
 * 
 * THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION ANY IMPLIED 
 * WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A PARTICULAR PURPOSE, 
 * MERCHANTABLITY OR NON-INFRINGEMENT. 
 *
 * See the Apache Version 2.0 License for specific language governing 
 * permissions and limitations under the License.
 *---------------------------------------------------------------------------
 * 
 * rot.h
 *
 *---------------------------------------------------------------------------*/

#include "../ampblas_config.h"

namespace ampblas {

//-------------------------------------------------------------------------
// ROT
//-------------------------------------------------------------------------

template <int rank, typename x_type, typename y_type, typename c_type, typename s_type>
void rot(const concurrency::extent<rank>& e, x_type&& x, y_type&& y, c_type&& c, s_type&& s)
{
    concurrency::parallel_for_each(
        get_current_accelerator_view(), 
        e, 
        [=] (concurrency::index<rank> idx) restrict(amp) 
        {
            auto temp = c * x[idx] + s * y[idx];
            y[idx] = c * y[idx] - s * x[idx];
            x[idx] = temp;
        }
    );
}

template <typename value_type>
void rot(int n, value_type* x, int incx, value_type* y, int incy, value_type c, value_type s)
{
	// quick return
	if (n <= 0)
		return;

	// error check
	if (x == nullptr)
		argument_error("rot", 2);
	if (y == nullptr)
		argument_error("rot", 4);

    auto x_vec = make_vector_view(n, x, incx);
    auto y_vec = make_vector_view(n, y, incy);

    rot(make_extent(n), x_vec, y_vec, c, s); 
}

} // namespace ampblas
